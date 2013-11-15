/*
 * Face3.hpp
 *
 *  Created on: Oct 31, 2013
 *      Author: tydup13
 */

#ifndef FACE3_HPP_
#define FACE3_HPP_

#include "Object.hpp"
#include "Intersect.hpp"
#include "Vector3.hpp"

class Face3 : public Object3D{

	Vector3 u, v, a, b, c, normal;

public:

	Face3();
	Face3(const Vector3& a, const Vector3& b, const Vector3& c) : a(a), b(b), c(c) {
		compute();
	}
	Face3(const Face3& f) : Object3D(f){
		a = f.a;
		b = f.b;
		c = f.c;

		normal = f.normal;
	}

	/**
	 * Finds extra needed info about the face for intersection.
	 * This allows for cached data to speed things up.
	 */
	void compute(){
		u = (b - a);
		v = (c - a);
		normal = u.cross(v).normalize();
	}

	Face3& set(const Vector3& a, const Vector3& b, const Vector3& c){
		this->a = a;
		this->b = b;
		this->c = c;
		compute();

		return *this;
	}

	bool operator==(const Face3& f) const{
		return ((a == f.a) && (b == f.b) && (c == f.c));
	}

	Face3& operator=(const Face3& f){

		Object3D::operator=(f);

		a = f.a;
		b = f.b;
		c = f.c;

		normal = f.normal;
		return *this;
	}

	bool containsPoint(const Vector3& point) const;
	bool getIntersection(const Projector&, Intersect&) const;
	std::vector<Vector3> getPoints() const{

		std::vector<Vector3> points;

		points.push_back(a);
		points.push_back(b);
		points.push_back(c);

		return points;

	}

};


#endif /* FACE3_HPP_ */
