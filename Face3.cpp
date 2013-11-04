
#include "Face3.hpp"

#include <cmath>

/**
 * This uses the logic that a point when related to
 * a point known to exist on the plane,
 * the dot of this new vector and the normal will
 * be 0 if the point is on the plane.
 */
bool Face3::containsPoint(const Vector3& point) const{

	return ((point-b).dot(normal) == 0);

}

bool Face3::getIntersection(const Projector& p, Intersect& i) const{

	if (normal == Vector3(0, 0, 0)){//Bad triangle.
		return false;
	}

	double t1 = -normal.dot(p.ray.origin - a);
	double t2 = normal.dot(p.ray.direction);

	if (std::abs(b) < 0.00000001){
		if (a == 0){
			//TODO
		}
	}

}
