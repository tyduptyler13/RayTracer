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
	Material material;
	double distance;

	Intersect(){
		distance = 0;
	}

	Intersect(const Intersect& i){

		point = i.point;
		material = i.material;
		distance = i.distance;

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

		return *this;

	}

};

#endif /* INTERSECT_HPP_ */
