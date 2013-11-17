
#include "Sphere.hpp"

Sphere::Sphere(){
	radius = 0;
}

Sphere::Sphere(Vector3& center, double radius){
	position = center;
	this->radius = radius;
}

Sphere::Sphere(const Sphere& s) : Object3D(s){
	position = s.position;
	radius = s.radius;
}

Sphere& Sphere::translate(const Vector3& v){
	position += v;

	return *this;
}

bool Sphere::operator==(const Sphere& s) const{
	return (position == s.position) && (radius == radius);
}

bool Sphere::containsPoint(const Vector3& point) const{
	return (point.distanceTo(position) <= radius);
}

bool Sphere::getIntersection(const Projector& p, Intersect& i) const{

	//Modified closestPointToPoint{
	Vector3 point = position - p.ray.origin;
	double directionDistance = point.dot(p.ray.direction);

	if (directionDistance < 0){ //Miss
		return false;
	}

	point = p.ray.direction * directionDistance + p.ray.origin;
	//}

	double shortestDistance = point.distanceTo(position);

	if (shortestDistance > radius ){//Miss
		return false;
	}


	//Distance from the point on the ray to both intersections. (could be 0 if hitting edge)
	double innerDistance = sqrt(pow(radius, 2) - pow(shortestDistance, 2));

	double totalDistance = directionDistance - innerDistance;

	if (totalDistance < p.near || totalDistance > p.far){
		return false;
	}

	i.distance = totalDistance - p.near; //Adjusted distance value.
	i.point = p.ray.at(totalDistance);
	i.material = material;
	i.normal = (i.point - position).normalize();

	return true;

}
