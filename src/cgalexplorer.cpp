/*
 *   RapCAD - Rapid prototyping CAD IDE (www.rapcad.org)
 *   Copyright (C) 2010-2011 Giles Bathgate
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "cgalexplorer.h"
#include "float.h"
//#include <stdio.h>

CGALExplorer::CGALExplorer(const CGAL::NefPolyhedron3& p) : poly(p)
{
}

void CGALExplorer::evaluate()
{
	typedef typename CGAL::NefPolyhedron3::SNC_structure SNC;
	typedef typename SNC::Halffacet_const_iterator HalfFacetIterator;
	typedef typename SNC::Halffacet_cycle_const_iterator HalfFacetCycleIterator;
	typedef typename SNC::SHalfedge_const_handle SHalfEdgeHandle;
	typedef typename SNC::SHalfedge_around_facet_const_circulator SHalfEdgeCirculator;

	HalfFacetIterator f;
	CGAL_forall_facets(f,*poly.sncp()) {
		HalfFacetCycleIterator fc;
		CGAL_forall_facet_cycles_of(fc,f) {
			SHalfEdgeHandle h = fc;
			SHalfEdgeCirculator hc(h), he(hc);
			//printf("Polygon\n");
			CGAL_For_all(hc,he) {
				CGAL::Point3 sp = hc->source()->source()->point();
				points.append(sp);
				double x=to_double(sp.x()),y=to_double(sp.y()),z=to_double(sp.z());
				//printf("Point: [%f,%f,%f]\n",x,y,z);
			}
		}
	}
}

QList<CGAL::Point3> CGALExplorer::getPoints()
{
	evaluate();
	return points;
}

CGAL::Bbox_3 CGALExplorer::getBounds()
{
	evaluate();

	double minX=DBL_MAX,maxX=-DBL_MAX;
	double minY=DBL_MAX,maxY=-DBL_MAX;
	double minZ=DBL_MAX,maxZ=-DBL_MAX;
	foreach(CGAL::Point3 pt,points) {
		double x=to_double(pt.x());
		double y=to_double(pt.y());
		double z=to_double(pt.z());
		minX=fmin(x,minX);
		maxX=fmax(x,maxX);
		minY=fmin(y,minY);
		maxY=fmax(y,maxY);
		minZ=fmin(z,minZ);
		maxZ=fmax(z,maxZ);
	}

	return CGAL::Bbox_3(minX,minY,minZ,maxX,maxY,maxZ);
}
