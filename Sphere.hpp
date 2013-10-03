#ifndef SPHERE_HPP__
#define SPHERE_HPP__

#include "Vector3.hpp"

class Sphere{

public:
	double radius;
	Vector3 center;

	Sphere();
	Sphere(Vector3& center, double radius);
	Sphere(const Sphere& s);

	Sphere& set(const Vector3& center, double radius){
		this->center = center;
		this->radius = radius;

		return *this;
	}

	Sphere& operator=(const Sphere& s){
		center = s.center;
		radius = s.radius;

		return *this;
	}

	double distanceToPoint(const Vector3& point) const{
		return (point.distanceTo(center) - radius);
	}

	Sphere& translate(const Vector3&);

};

#endif
