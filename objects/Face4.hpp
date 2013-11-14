/*
 * Face4.hpp
 *
 *  Created on: Oct 31, 2013
 *      Author: tydup13
 */

#ifndef FACE4_HPP_
#define FACE4_HPP_

#include "Object.hpp"
#include "Intersect.hpp"
#include "Vector3.hpp"
#include "Projector.hpp"

class Face4 : public Object3D{

public:
	Vector3 a, b, c, d, normal;

	Face4(){}
	Face4(const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& d)
	: a(a), b(b), c(c), d(d){
		computeNormal();
	}
	Face4(const Face4& f){
		a = f.a;
		b = f.b;
		c = f.c;
		d = f.d;

		computeNormal();
	}

	Face4& set(const Vector3& a, const Vector3& b, const Vector3& c){
		this->a = a;
		this->b = b;
		this->c = c;
		return *this;
	}

	Face4& operator=(const Face4& f){
		a = f.a;
		b = f.b;
		c = f.c;
		d = f.d;

		computeNormal();
		return *this;
	}

	bool operator==(const Face4& f) const{
		return ((a == f.a) && (b == f.b) && (c == f.c) && (d == f.d));
	}

	bool containsPoint(const Vector3& point) const;
	bool getIntersection(const Projector&, Intersect&) const;
	std::vector<Vector3> getPoints() const{

		std::vector<Vector3> points;

		points.push_back(a);
		points.push_back(b);
		points.push_back(c);
		points.push_back(d);

		return points;

	}

	/**
	 * This assumes the quad is flat!
	 * If this is not true then a specialized subclass will be required
	 * that computes all of the normals for each vertices.
	 */
	void computeNormal(){
		normal = (b-a).cross(c-a);
	}

};


#endif /* FACE4_HPP_ */
