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

	Vector3 getDirection(const Vector3& point) const{

		Vector3 ret(position.x, position.y, position.z);

		if (position.w == 0){
			return ret.normalize();
		} else {
			return (ret -= point);
		}

	}

};

#endif /* LIGHT_HPP_ */
