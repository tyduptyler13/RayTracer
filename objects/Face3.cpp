
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

	double ddnorm = p.ray.direction.dot(normal);
	double sign; //Easier than casting it all the time.

	if (ddnorm > 0){

		if (p.backfaceCulling) return false;
		sign = 1;

	} else if (ddnorm < 0){

		sign = -1;
		ddnorm = -ddnorm;

	} else {

		return false;

	}

	Vector3 diff = p.ray.origin - a;
	//Direction dot diff cross v
	double dddxv = sign * p.ray.direction.dot(diff.cross(v));

	if (dddxv < 0){

		return false;

	}

	//Direction dot u cross diff
	double dduxd = sign * p.ray.direction.dot(u.cross(diff));

	if (dduxd < 0){

		return false;

	}

	if (dddxv + dduxd > ddnorm){

		return false;

	}

	double diffdnorm = -sign * diff.dot(normal);

	if (diffdnorm < 0){

		return false;

	}

	double dist = diffdnorm / ddnorm;

	if (dist < p.near || dist > p.far){
		return false;
	}

	i.point = p.ray.at(dist);
	i.distance = dist - p.near;//Adjusted distance.
	i.material = material;
	i.normal = normal;

	return true;

}
