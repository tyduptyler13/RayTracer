
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

	if (std::abs(t2) < 0.00000001){
		return false;
	}

	double r = t1 / t2;

	if (r < 0){ //Wrong direction.
		return false;
	}

	Vector3 point = a + p.ray.direction * r;

	double uu, uv, vv, wu, wv, D;
	uu = u.dot(u);
	uv = u.dot(v);
	vv = v.dot(v);
	Vector3 w = point - a;
	wu = w.dot(u);
	wv = w.dot(v);
	D = uv * uv - uu * vv;

	double s, t;
	s = (uv * wv - vv * wu) / D;
	if (s < 0 || s > 1){
		return false;
	}

	t = (uv * wu - uu * wv) / D;
	if (t < 0 || (s+t) > 1){
		return false;
	}

	double dist = point.distanceTo(p.ray.origin);

	if (dist < p.near || dist > p.far){
		return false;
	}

	i.point = point;
	i.distance = dist - p.near;//Adjusted distance.

	return true;

}