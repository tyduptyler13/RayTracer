/*
 * Object.hpp
 *
 *  Created on: Oct 4, 2013
 *      Author: Tyler
 */

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include<string>
#include<vector>

#include "Vector3.hpp"
#include "ImageTools.hpp"
#include "Ray.hpp"

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

class Object{

public:

	virtual ~Object(){};

	std::string name;

	Color color;

	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	virtual bool containsPoint(const Vector3& point) const = 0;
	virtual bool getIntersection(const Ray& r, Intersect& i) const = 0;

};



#endif /* OBJECT_HPP_ */
