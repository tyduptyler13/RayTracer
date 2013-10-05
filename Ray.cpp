/*
 * Ray.cpp
 *
 *  Created on: Oct 2, 2013
 *      Author: Tyler
 */

#include "Ray.hpp"

Ray::Ray(){
	origin = Vector3();
	direction = Vector3();
}

Ray::Ray(Vector3& origin, Vector3& direction){
	this->origin = origin;
	this->direction = direction;
}

Ray::Ray(const Ray& r){
	origin = r.origin;
	direction = r.direction;
}

Ray& Ray::set(const Vector3& origin, const Vector3& direction){
	this->origin = origin;
	this->direction = direction;

	return *this;
}

Ray& Ray::operator=(const Ray& r){
	origin = r.origin;
	direction = r.direction;

	return *this;
}

Vector3* Ray::at(double t){
	Vector3* v = new Vector3();
	return at(t, v);
}

Vector3* Ray::at(double t, Vector3* target){
	((*target = direction) *= t) += origin;
	return target;
}

Ray& Ray::recast(double t){
	//Need extra vector for values.
	Vector3* tmp = at(t);
	origin = *tmp;
	delete tmp;

	return *this;
}

Vector3* Ray::closestPointToPoint(const Vector3& point, Vector3* target = new Vector3()) const{
	*target = point;
	*target -= origin;
	double directionDistance = target->dot(direction);

	if (directionDistance < 0){
		return &(*target = origin);
	}

	return &(((*target = direction) *= directionDistance) += origin);
}

double Ray::distanceToPoint(const Vector3& point) const{
	Vector3* v1 = new Vector3(point);

	double directionDistance = ( *v1 -= origin ).dot(origin);

	if (directionDistance < 0){
		return (origin.distanceTo(point));
	}

	*v1 = direction;
	*v1 *= directionDistance;
	*v1 += origin;

	double distanceTo = v1->distanceTo(point);

	delete v1;

	return distanceTo;
}

bool Ray::isIntersectionSphere(const Sphere& sphere) const{
	return (distanceToPoint(sphere.position) <= sphere.radius);
}

bool Ray::operator ==(const Ray& r) const{
	return (r.origin == origin && r.direction == this->direction);
}
