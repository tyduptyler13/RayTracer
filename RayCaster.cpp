/*
 * RayCaster.cpp
 *
 *  Created on: Oct 2, 2013
 *      Author: Tyler
 */

#include <algorithm>

#include "RayCaster.hpp"
#include "Vector3.hpp"

Vector3 origin;

std::vector<Intersect> RayCaster::cast(const std::vector<Object*>& objects, const Ray& r, unsigned recursion) const{

	std::vector<Intersect> intersects;

	for (Object* object : objects){

		Intersect i = Intersect();

		if (object->getIntersection(r, i)){

			intersects.push_back(i);

		}

	}

	return intersects;
}
