#ifndef SPHERE_HPP__
#define SPHERE_HPP__

#include<string>

#include "Object.hpp"

class Sphere : public Object{

public:
	double radius;

	Sphere();
	Sphere(Vector3& center, double radius);
	Sphere(const Sphere& s);

	Sphere& set(const Vector3& center, double radius){
		position = center;
		this->radius = radius;

		return *this;
	}

	Sphere& setColor(float r, float g, float b);

	Sphere& setName(std::string s){
		name = s;
		return *this;
	}

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

	bool containsPoint(const Vector3& point) const{
		return (point.distanceTo(position) <= radius);
	}

	bool getIntersection(const Ray& r, Intersect& i) const;

};

#endif
