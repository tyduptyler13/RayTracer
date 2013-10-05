/*
 * Camera.hpp
 *
 *  Created on: Oct 4, 2013
 *      Author: Tyler
 */

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Object.hpp"
#include "Vector3.hpp"

class Camera : Object{

	int width;
	int height;

public:
	Vector3 direction;
	double near;
	double far;

	/**
	 * Camera settings are expected on creation.
	 * To change them later, a new camera should be
	 * created.
	 */
	Camera(int width, int height, double near, double far) :
		width(width), height(height), near(near), far(far) {}

	Camera& setPosition(Vector3& v){
		position = v;
		return *this;
	}

	Camera& setDirection(Vector3& v){
		direction = v;
		return *this;
	}

	void render();

	Camera& operator=(const Camera&);
	bool operator==(const Camera&) const;

};


#endif /* CAMERA_HPP_ */
