/*
 * Camera.hpp
 *
 *  Created on: Oct 4, 2013
 *      Author: Tyler
 */

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <vector>
#include <string>

#include "Object.hpp"
#include "Vector3.hpp"
#include "ImageTools.hpp"

class Camera{

public:
	std::string name;

	Vector3 position;
	Vector3 direction;//Aka vpn
	double near;
	double far;

	Camera(Vector3& prp, Vector3& vpn, double near, double far) : near(near), far(far) {
		position = prp;
		direction = vpn;
	}

	Camera& setName(std::string s){
		name = s;
		return *this;
	}

	/**
	 * The image is expected to be already created with the correct dimensions.
	 */
	void render(MonoImage* distance, ColorImage* color, const std::vector<Object*>* const objects,
			std::size_t width, std::size_t height, unsigned recursion);


};


#endif /* CAMERA_HPP_ */
