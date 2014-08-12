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

Ray::Ray(const Vector3& origin, const Vector3& direction){
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

Vector3 Ray::at(double t) const{
	Vector3 v;
	return at(t, v);
}

Vector3& Ray::at(double t, Vector3& target) const{
	target = direction * t + origin;
	return target;
}

Ray& Ray::recast(double t){
	origin = at(t);

	return *this;
}

Vector3 Ray::closestPointToPoint(const Vector3& point) const{
	Vector3 t;
	closestPointToPoint(point, t);
	return t;
}

Vector3& Ray::closestPointToPoint(const Vector3& point, Vector3& target) const{
	target = point - origin;
	double directionDistance = target.dot(direction);

	if (directionDistance < 0){
		target = origin;
		return target;
	}

	target = direction * directionDistance + origin;

	return target;
}

double Ray::distanceToPoint(const Vector3& point) const{
	Vector3 v1(point);

	double directionDistance = ( v1 - origin ).dot(origin);

	if (directionDistance < 0){
		return (origin.distanceTo(point));
	}

	v1 = direction * directionDistance + origin;

	double distanceTo = v1.distanceTo(point);

	return distanceTo;
}

bool Ray::operator ==(const Ray& r) const{
	return (r.origin == origin && r.direction == this->direction);
}
