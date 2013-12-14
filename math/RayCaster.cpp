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

std::vector<Intersect> RayCaster::cast(const std::vector<Object3D*>& objects, const Projector& p) const{

	std::vector<Intersect> intersects;

	for (Object3D* object : objects){

		Intersect i = Intersect(object);

		if (object->getIntersection(p, i)){

			intersects.push_back(i);

		}

	}

	sort(intersects.begin(), intersects.end());

	return intersects;

}
