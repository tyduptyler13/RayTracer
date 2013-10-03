
#include "Sphere.hpp"

Sphere::Sphere(){
	center = Vector3();
	radius = 0;
}

Sphere::Sphere(Vector3& center, double radius){
	this->center = center;
	this->radius = radius;
}

Sphere::Sphere(const Sphere& s){
	center = s.center;
	radius = s.radius;
}

Sphere& Sphere::translate(const Vector3& v){
	center += v;

	return *this;
}
