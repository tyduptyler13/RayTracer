#ifndef PROJECTOR_HPP_
#define PROJECTOR_HPP_

#include "Ray.hpp"

class Projector{

public:

	const Ray ray;
	const double near;
	const double far;
	const Object3D* exempt;

	/**
	 * Set this to true to ignore faces that have the wrong rotation.
	 */
	bool backfaceCulling;

	Projector(Ray& r, double near, double far, bool bc = true, const Object3D* exempt = NULL)
		: ray(r), near(near), far(far), exempt(exempt), backfaceCulling(bc) {}

};

#endif
