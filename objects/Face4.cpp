
#include "Face4.hpp"

#include "Face3.hpp"

/**
 * Being rewritten.
 */
bool Face4::containsPoint(const Vector3& point) const{

	return false;

}

/**
 * This finds if the ray comes closer to a or d and then calculates
 * the intersection based on the fact that this quad can be split
 * into two triangles.
 */
bool Face4::getIntersection(const Projector& p, Intersect& i) const{

	Vector3 v1 = p.ray.closestPointToPoint(a);
	Vector3 v2 = p.ray.closestPointToPoint(d);

	/*
	 *     A ---------- B
	 *     |            |
	 *     D------------C
	 *
	 * This algorithm will cut the face into triangles based on
	 * closest points. It always will maintain the rotation of the
	 * face to keep the normal correct.
	 */
	if (a.distanceToSquared(v1) < d.distanceToSquared(v2)){
		//A to B and C
		//The edge between B and C is excluded but won't be required
		//Based on the exclusion from the distances.

		Face3 tmp(a, b, c);
		tmp.material = this->material;
		return tmp.getIntersection(p, i);

	} else { //C to B and D
		//The edge between D and B will be excluded in this test.

		Face3 tmp(a, c, d);
		tmp.material = this->material;
		return tmp.getIntersection(p, i);

	}
}
