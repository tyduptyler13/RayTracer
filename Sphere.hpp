#ifndef SPHERE_HPP__
#define SPHERE_HPP__

#include<string>

#include "Vector3.hpp"
#include "ImageTools.hpp"
#include "Object.hpp"

class Sphere : public Object{

public:
	double radius;
	Color color;

	Sphere();
	Sphere(Vector3& center, double radius);
	Sphere(const Sphere& s);

	Sphere& set(const Vector3& center, double radius){
		position = center;
		this->radius = radius;

		return *this;
	}

	Sphere& setColor(float r, float g, float b);

	Sphere& operator=(const Sphere& s){
		position = s.position;
		radius = s.radius;

		return *this;
	}

	bool operator==(const Sphere& s) const;

	double distanceToPoint(const Vector3& point) const{
		return (point.distanceTo(position) - radius);
	}

	Sphere& translate(const Vector3&);

};

#endif
