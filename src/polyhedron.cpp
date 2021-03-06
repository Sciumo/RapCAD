/*
 *   RapCAD - Rapid prototyping CAD IDE (www.rapcad.org)
 *   Copyright (C) 2010-2014 Giles Bathgate
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
#include "polyhedron.h"

Polyhedron::Polyhedron()
{
}

Polyhedron::~Polyhedron()
{
	qDeleteAll(children);
	children.clear();
}

Polygon* Polyhedron::createPolygon()
{
	Polygon* pg = new Polygon(this);
	polygons.append(pg);
	return pg;
}

void Polyhedron::createVertex(Point p)
{
	points.append(p);
}

void Polyhedron::add(Primitive* p, bool)
{
	this->appendChild(p);
}

Primitive* Polyhedron::group(Primitive* p)
{
	return join(p);
}

Primitive* Polyhedron::join(Primitive* p)
{
	this->appendChild(p);
	return this;
}

Primitive* Polyhedron::combine()
{
	return this;
}

Primitive* Polyhedron::intersection(Primitive* p)
{
	return join(p);
}

Primitive* Polyhedron::difference(Primitive* p)
{
	return join(p);
}

Primitive* Polyhedron::symmetric_difference(Primitive* p)
{
	return join(p);
}

Primitive* Polyhedron::minkowski(Primitive* p)
{
	return join(p);
}

Primitive* Polyhedron::copy()
{
	Polyhedron* c=new Polyhedron();
	foreach(Point p, points) {
		c->createVertex(p);
	}
	foreach(Polygon* pg, polygons) {
		Polygon* npg=c->createPolygon();
		npg->setIndexes(pg->getIndexes());
	}
	return c;
}

void Polyhedron::transform(TransformMatrix* m)
{
	QList<Point> nps;
	foreach(Point p,points) {
		nps.append(p.transform(m));
	}
	points=nps;

	foreach(Primitive* p, children)
		p->transform(m);
}

bool Polyhedron::isEmpty()
{
	return polygons.isEmpty();
}

QList<Polygon*> Polyhedron::getPolygons() const
{
	return polygons;
}

QList<Point> Polyhedron::getPoints() const
{
	return points;
}

QList<Primitive*> Polyhedron::getChildren()
{
	return children;
}

void Polyhedron::appendChild(Primitive* p)
{
	children.append(p);
}

void Polyhedron::discrete(int)
{
}
