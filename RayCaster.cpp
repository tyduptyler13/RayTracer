/*
 * RayCaster.cpp
 *
 *  Created on: Oct 2, 2013
 *      Author: Tyler
 */

#include <algorithm>

#include "RayCaster.hpp"

Vector3 origin;

/**
 * Sorting function to find the closest match.
 */
bool closer(Match a, Match b){
	return (a.intersect.distance < b.intersect.distance);
}


RayCaster::RayCaster(const std::size_t x, const std::size_t y, const std::vector<Object*>* const objects, const Camera* const c,
		const std::size_t width, const std::size_t height, unsigned recursion) : objects(objects), recursion(recursion), x(x), y(y) {

	isFinished = false;

	near = -(c->near);
	far = -(c->far);

	//Hacky temporary solution to unprojecting screen coordinates to world coordinates.
	//This only works if the camera is looking down the z axis.

	double tmpx, tmpy;
	double halfw = width / 2;
	double halfh = height / 2;
	tmpx = (-halfw + x) / halfw;//Range from -1 to 1 from the image width. (Corrected for 0 starting on the left.)
	tmpy = (halfh - y) / halfh;//Range from -1 to 1 from the image height. (Corrected for 0 starting at the top.)

	Vector3 other = Vector3(tmpx, tmpy, -(c->direction.z));//Point the vector at the image plane where the image pixels should be.

	r = Ray(c->position, other);
}

RayCaster& RayCaster::run(){

	origin = r.origin;//Globalize(ish) the origin for sort function.

	//Treating the ray as a vector to calculate distance to the near plane.
	r.direction *= near / r.direction.z; //Project the ray out to the near plane. We will use this distance.
	double distanceToNear = r.origin.distanceTo(r.direction);//Length of ray while it is cast out to the near plane.

	r.direction.normalize();//Need this to be normalized to get proper results.

	for (Object* object : *objects){

		Intersect i = Intersect();

		//std::cout << "Finding the center of the object(" << object->name << ")" << std::endl;

		if (object->getIntersection(r, i)){

			Match m;
			m.intersect = i;
			m.object = object;
			matches.push_back(m);

		}

	}

	//Sort results.
	std::sort(matches.begin(), matches.end(), closer);

	if (matches.size() >= 1){
		//Get closest match and copy it as the result.
		Match closest = matches[0];
		result.color = closest.object->color;
		result.distance = closest.intersect.distance - distanceToNear;//Distance from image plane to point.

		//Delete all matches and flush the matches vector.
		matches.empty();
	} else {
		result.color = Color();
	}

	isFinished = true;

	return *this;
}
