/*
 * Intersect.hpp
 *
 *  Created on: Oct 31, 2013
 *      Author: tydup13
 */

#ifndef INTERSECT_HPP_
#define INTERSECT_HPP_

#include "ImageTools.hpp"
#include "Vector3.hpp"

class Object3D;

/**
 * Distance is the distance down the ray that a intersection exists.
 * The point is the point of intersection.
 */
class Intersect{

public:
	Vector3 point;
	Vector3 normal;
	Material material;
	double distance;
	Object3D* object;

	Intersect(Object3D* object) : object(object){
		distance = 0;
	}

	Intersect(Object3D* object, const Intersect& i) : object(object) {

		point = i.point;
		material = i.material;
		distance = i.distance;
		normal = i.normal;

	}

	bool operator<(const Intersect& rhs) const{
		return (distance < rhs.distance);
	}

	bool operator>(const Intersect& rhs) const{
		return (distance > rhs.distance);
	}

	Intersect& operator=(const Intersect& i){

		point = i.point;
		material = i.material;
		distance = i.distance;
		normal = i.normal;

		object = i.object;

		return *this;

	}

};

#endif /* INTERSECT_HPP_ */
