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
typedef CGAL::NefPolyhedron3::Volume_const_iterator VolumeIterator;
typedef CGAL::NefPolyhedron3::Shell_entry_const_iterator ShellIterator;

CGALExplorer::CGALExplorer(const CGAL::NefPolyhedron3& p) : poly(p)
{
}

void CGALExplorer::visit(VertexHandle v)
{
	CGAL::Point3 p = v->point();
	points.append(p);
}

QList<CGAL::Point3> CGALExplorer::getPoints()
{
	VolumeIterator c;
	CGAL_forall_volumes(c,poly) {
		ShellIterator it;
		CGAL_forall_shells_of(it,c){
			poly.visit_shell_objects(SFaceHandle(it),*this);
		}
	}
	return points;
}