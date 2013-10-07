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

class Object{

public:

	virtual ~Object(){};

	std::string name;

	Color color;

	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	virtual bool containsPoint(const Vector3& point) const = 0;
	virtual Vector3& getIntersection(const Ray& r, const Vector3& closest, Vector3& ret) const = 0;

};



#endif /* OBJECT_HPP_ */
