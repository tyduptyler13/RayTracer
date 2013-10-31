/*
 * Intersect.hpp
 *
 *  Created on: Oct 31, 2013
 *      Author: tydup13
 */

#ifndef INTERSECT_HPP_
#define INTERSECT_HPP_

#include "Object.hpp"
#include "Vector3.hpp"

class Object;

/**
 * Distance is the distance down the ray that a intersection exists.
 * The point is the point of intersection.
 */
class Intersect{

public:
	Vector3 point;
	Object* object;
	double distance;

	Intersect(){
		point = Vector3();
		object = NULL;
		distance = 0;
	}

	Intersect(Vector3& point, Object* object, double distance): point(point), object(object), distance(distance){}

	bool operator<(const Intersect& rhs) const{
		return (distance < rhs.distance);
	}

	/**
	 * Both the distance and the object must be equal for this to be true.
	 *
	 * For instance two objects can have an intersect at the same point.
	 */
	bool operator==(const Intersect& rhs) const{
		return (distance == rhs.distance) && (object == rhs.object);
	}

	bool operator>(const Intersect& rhs) const{
		return (distance > rhs.distance);
	}
};


#endif /* INTERSECT_HPP_ */
