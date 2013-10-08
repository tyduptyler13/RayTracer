
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

	//Clostest point on the ray to the sphere.
	//pdistance = plane of intersection with the center of the sphere.
	double pdistance = position.dot(r.direction);
	std::unique_ptr<Vector3> p = r.at(pdistance);

	double shortestDistance = p->distanceTo(position);

	if (shortestDistance > radius || pdistance < 0){//Missed the sphere. (If distance is negative, it is behind the ray plane.)
		return false;
	}



	//Distance from the point on the ray to both intersections. (could be 0 if hitting edge)
	double innerDistance = sqrt(pow(radius, 2) - pow(shortestDistance, 2));

	i.distance = pdistance - innerDistance;//Intersection "should" always be closer. The RayCaster will fix this otherwise.
	i.point = *(r.at(i.distance));

	return true;

}
