
#include "Sphere.hpp"

Sphere::Sphere(){
	position = Vector3();
	radius = 0;
	color = Color();
}

Sphere::Sphere(Vector3& center, double radius){
	position = center;
	this->radius = radius;
}

Sphere::Sphere(const Sphere& s){
	position = s.position;
	radius = s.radius;
}

Sphere& Sphere::setColor(float r, float g, float b){
	color.r = r;
	color.g = g;
	color.b = b;

	return *this;
}

Sphere& Sphere::translate(const Vector3& v){
	position += v;

	return *this;
}

bool Sphere::operator==(const Sphere& s) const{
	return (position == s.position) && (radius == radius);
}



Vector3& Sphere::getIntersection(const Ray& r, const Vector3& point, Vector3& in) const{



	return in;
}
