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
#include <memory>

#include "Vector3.hpp"
#include "ImageTools.hpp"
#include "Ray.hpp"

/**
 * Distance is the distance down the ray that a intersection exists.
 * The point is the point of intersection.
 */
struct Intersect{
	double distance = 0;
	Vector3 point = Vector3();
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
