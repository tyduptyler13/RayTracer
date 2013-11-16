/*
 * Face4.hpp
 *
 *  Created on: Oct 31, 2013
 *      Author: tydup13
 */

#ifndef FACE4_HPP_
#define FACE4_HPP_

#include "Object.hpp"
#include "Face3.hpp"
#include "Intersect.hpp"
#include "Projector.hpp"

/**
 * Facade for two three sided faces.
 *
 * It seems to be equally efficient.
 */
class Face4 : public Object3D{

	Face3 f1, f2;

public:

	/**
	 *   A---------B
	 *   |         |
	 *   D---------C
	 */
	Face4(){}
	Face4(const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& d){
		f1 = Face3(a, b, c);
		f2 = Face3(a, c, d);
	}

	Face4(const Face4& f) : Object3D(f){
		f1 = f.f1;
		f2 = f.f2;
	}

	Face4& set(const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& d){
		f1 = Face3(a, b, c);
		f2 = Face3(a, c, d);

		return *this;
	}

	Face4& operator=(const Face4& f){

		Object3D::operator=(f);

		f1 = f.f1;
		f2 = f.f2;

		return *this;
	}

	bool operator==(const Face4& f) const{
		return (f1 == f.f1 && f2 == f.f2);
	}

	bool containsPoint(const Vector3& point) const{

		return (f1.containsPoint(point) || f2.containsPoint(point));

	}

	/**
	 * This finds if the ray comes closer to a or d and then calculates
	 * the intersection based on the fact that this quad can be split
	 * into two triangles.
	 */
	bool getIntersection(const Projector& p, Intersect& i) const{

		if (f1.getIntersection(p, i) || f2.getIntersection(p, i)){
			i.material = material;
			return true;
		}

		return false;

	}

};


#endif /* FACE4_HPP_ */
