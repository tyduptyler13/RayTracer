
#include "Face4.hpp"

#include "Face3.hpp"

/**
 * This uses the logic that a point when related to
 * a point known to exist on the plane,
 * the dot of this new vector and the normal will
 * be 0 if the point is on the plane.
 */
bool Face4::containsPoint(const Vector3& point) const{

	return ((point-b).dot(normal) == 0);

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
	 *     C------------D
	 *
	 * This algorithm will cut the face into triangles based on
	 * closest points. It always will maintain the rotation of the
	 * face to keep the normal correct.
	 */
	if (a.distanceToSquared(v1) < d.distanceToSquared(v2)){
		//A to B and C
		//The edge between B and C is excluded but won't be required
		//Based on the exclusion from the distances.

		return Face3(a, b, c).getIntersection(p, i);

	} else { //C to D and B
		//The edge between D and B will be excluded in this test.

		return Face3(c, b, d).getIntersection(p, i);

	}
}
