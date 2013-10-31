#ifndef PROJECTOR_HPP_
#define PROJECTOR_HPP_

#include "Ray.hpp"

class Projector{

public:

	Projector(Ray& r, double dist, double depth) : ray(r), dist(dist), depth(depth) {}

	Ray ray;
	double dist;
	double depth;

};

#endif
