/*
 * RayCaster.hpp
 *
 *  Created on: Sep 30, 2013
 *      Author: tydup13
 */

#ifndef RAYCASTER_HPP_
#define RAYCASTER_HPP_

#include <vector>

#include "ImageTools.hpp"
#include "Object.hpp"
#include "Camera.hpp"
#include "Ray.hpp"
#include "Vector3.hpp"

#define NotFinishedError 12

struct Match{
	Intersect intersect;
	Object* object;
};

struct Result{
	double distance = 0;//All values are the same to create a grayscale color.
	Color color;//Color value of sphere.
};

class RayCaster{

	const std::vector<Object*>* const objects;
	std::vector<Match> matches;
	Ray r;
	Result result;
	double far, near;
	bool isFinished = false;
	unsigned recursion;

public:
	const std::size_t x;
	const std::size_t y;

	//The following will be set when its complete.

	RayCaster(const std::size_t x, const std::size_t y, const std::vector<Object*>* const, const Camera* const,
			const std::size_t width, const std::size_t height, unsigned recursion);

	RayCaster& run();//For multithreading.

	Result& getResult(){
		if (!isFinished)
			throw NotFinishedError;

		return result;
	}

};


#endif /* RAYCASTER_HPP_ */
