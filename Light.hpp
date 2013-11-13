/*
 * Light.hpp
 *
 *  Created on: Nov 12, 2013
 *      Author: Tyler
 */

#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "Vector4.hpp"
#include "ImageTools.hpp"

class Light{

public:

	Vector4 position;
	Color color;

	Light(){}
	Light(Vector4& position, Color& color) : position(position), color(color) {}

};

#endif /* LIGHT_HPP_ */
