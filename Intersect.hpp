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

#include <limits>

//Some tools
class Box{

public:
	Vector3 min, max;

	/**
	 * Setup to miss until really created.
	 * Also allows for points to be added.
	 */
	Box(){
		double inf = std::numeric_limits<double>::infinity();
		min(inf, inf, inf);
		max(-inf, -inf, -inf);
	}

	Box(const Vector3& min, const Vector3& max) : min(min), max(max){}

	Box(Box& b){
		min = b.min;
		max = b.max;
	}

	Box& set(const Vector3& min, const Vector3& max){
		this->min = min;
		this->max = max;
		return *this;
	}

	Box& addPoint(const Vector3& point){
		if ( point.x < min.x ) {

			min.x = point.x;

		} else if ( point.x > max.x ) {

			max.x = point.x;

		}

		if ( point.y < min.y ) {

			min.y = point.y;

		} else if ( point.y > max.y ) {

			max.y = point.y;

		}

		if ( point.z < min.z ) {

			min.z = point.z;

		} else if ( point.z > max.z ) {

			max.z = point.z;

		}

		return *this;
	}

	Box& reset(){
		return *this();
	}

	Vector3 size() const{
		return max - min;
	}

	bool containsPoint(const Vector3& point) const{
		if ( point.x < min.x || point.x > max.x ||
			point.y < min.y || point.y > max.y ||
			point.z < min.z || point.z > max.z ) {

			return false;

		}

		return true;
	}

	bool operator==(const Box& b) const{
		return ((max == b.max) && (min == b.min));
	}

	Box& operator=(const Box& b){
		min = b.min;
		max = b.max;
		return *this;
	}


};

#endif /* INTERSECT_HPP_ */
