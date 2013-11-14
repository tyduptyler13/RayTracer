#ifndef PROJECTOR_HPP_
#define PROJECTOR_HPP_

#include "Ray.hpp"

class Projector{

public:

	Projector(Ray& r, double near, double far) : ray(r), near(near), far(far) {}

	Ray ray;
	double near;
	double far;

};

#endif
