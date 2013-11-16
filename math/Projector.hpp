#ifndef PROJECTOR_HPP_
#define PROJECTOR_HPP_

#include "Ray.hpp"

class Projector{

public:

	Projector(Ray& r, double near, double far) : ray(r), near(near), far(far) {
		backfaceCulling = false;
	}

	Ray ray;
	double near;
	double far;

	/**
	 * Set this to true to ignore faces that have the wrong rotation.
	 */
	bool backfaceCulling;

};

#endif
