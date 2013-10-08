
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



bool Sphere::getIntersection(const Ray& r, Intersect& i) const{

	//Shortest distance from ray to sphere.
	double sdistance = position.dot(r.direction);

	if (sdistance > radius || sdistance < 0){//Missed the sphere. (If distance is negative, it is behind the ray plane.)
		return false;
	}

	//Shortest distance squared.
	double sdistance2 = pow(sdistance, 2);
	//Distance from origin to intersection plane of the origin of the sphere.
	double distance = sqrt(r.origin.distanceToSquared(position) - sdistance2);

	//Distance from the point on the ray to both intersections. (could be 0 if hitting edge)
	double innerDistance = sqrt(pow(radius, 2) - sdistance2);

	i.distance = distance - innerDistance;
	i.point = *(r.at(i.distance));

	return true;

}
