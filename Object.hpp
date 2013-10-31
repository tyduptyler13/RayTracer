/*
 * Object.hpp
 *
 *  Created on: Oct 4, 2013
 *      Author: Tyler
 */

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include<string>

#include "Vector3.hpp"
#include "ImageTools.hpp"
#include "Intersect.hpp"
#include "Projector.hpp"

class Object{

public:

	std::string name;

	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	Vector3 up = Vector3(0, 1, 0);//Default up.

	Object& setName(std::string name){
		this->name = name;
		return *this;
	}

	Object& setUp(Vector3& v){
		this->up = v;
		return *this;
	}

};

class Object3D : public Object{

public:

	virtual ~Object3D(){};

	Color color;

	virtual bool containsPoint(const Vector3& point) const = 0;
	virtual bool getIntersection(const Projector&, Intersect&) const = 0;

};



#endif /* OBJECT_HPP_ */
