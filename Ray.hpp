/*
 * Ray.hpp
 *
 *  Created on: Oct 1, 2013
 *      Author: tydup13
 */

#ifndef RAY_HPP_
#define RAY_HPP_

#include "Vector3.hpp"
#include "Sphere.hpp"
#include "Matrix4.hpp"

class Ray{

public:
	Vector3 origin;
	Vector3 direction;

	Ray();
	Ray(Vector3& origin, Vector3& direction);
	Ray(const Ray&);

	Ray& set(const Vector3& origin, const Vector3& direction);
	Ray& operator=(const Ray&);
	Vector3* at(double);
	Vector3* at(double, Vector3*);
	Ray& recast(double t);
	Vector3* closestPointToPoint(const Vector3& point,  Vector3* target) const;
	double distanceToPoint(const Vector3&) const;
	bool isIntersectionSphere(const Sphere&) const;
	Ray& applyMatrix4(const Matrix4&);
	bool operator==(const Ray&) const;
};


#endif /* RAY_HPP_ */
