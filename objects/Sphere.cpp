
#include "Sphere.hpp"

Sphere::Sphere() : Object3D() {
	radius = 0;
}

Sphere::Sphere(Vector3& center, double radius) : Object3D() {
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

	if (p.exempt == this) return false;

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
	double innerDistance = sqrt(radius * radius - shortestDistance * shortestDistance);

	double totalDistance = directionDistance - innerDistance;

	//if (totalDistance < 0.0000001) totalDistance = directionDistance + innerDistance;//For internal rays. (Inside a sphere)

	if (totalDistance < p.near || totalDistance > p.far){
		return false;
	}

	i.distance = totalDistance - p.near; //Adjusted distance value.
	i.point = p.ray.at(totalDistance);
	i.material = material;
	i.normal = (i.point - position).normalize();

	return true;

}

Ray& Sphere::getRefraction(Ray& r, const Vector3& normal) const{

	if (r.direction.dot(normal) < 0){
		double rc = sqrt(1 - material.Krf * material.Krf * (1 - (normal.dot(-r.direction))));
		if (rc >= 0){
			Vector3 tr = (material.Krf * (normal.dot(-r.direction)) - rc) * normal - (material.Kr * -r.direction);
			r.direction = tr;
		}
	} else { //Leaving sphere.
		double nr = 1 / material.Krf;
		double rc = sqrt(1 - nr * nr * (1-(-normal.dot(-r.direction) * -normal.dot(-r.direction))));
		if (rc >= 0){
			Vector3 tr = (nr * (-normal.dot(-r.direction)) - rc) * -normal - (nr * -r.direction);
			r.direction = tr;
		}
	}

	return r;

}
