
#include "Sphere.hpp"

Sphere::Sphere(){
	position = Vector3();
	radius = 0;
	color = Color();
}

Sphere::Sphere(Vector3& center, double radius){
	position = center;
	this->radius = radius;
}

Sphere::Sphere(const Sphere& s){
	position = s.position;
	radius = s.radius;
}

Sphere& Sphere::setColor(float r, float g, float b){
	color.r = r;
	color.g = g;
	color.b = b;

	return *this;
}

Sphere& Sphere::translate(const Vector3& v){
	position += v;

	return *this;
}

bool Sphere::operator==(const Sphere& s) const{
	return (position == s.position) && (radius == radius);
}



bool Sphere::getIntersection(const Ray& r, Intersect& i) const{

	double distance = position.dot(r.direction);

	double a = r.direction.dot(r.direction);
	double b = 2 * r.direction.dot(r.origin);
	double c = r.origin.dot(r.origin) - pow(radius, 2);

	double disc = (pow(b,2) - 4 * a * c);

	if (disc < 0){
		return false; //Miss
	} else {
		disc = sqrt(disc);
		double q;

		if (b<0){
			q = (-b - disc)/2;
		} else {
			q = (-b + disc)/2;
		}

		double t0 = q/a, t1 = c/q;

		if (t0 > t1){
			std::swap(t0, t1);
		}

		if (t1 < 0){
			return false; //Miss (Its on the wrong side)
		}

		if (t0 < 0){
			i.distance = t1;
			i.point = *(r.at(distance - t1));
			return true;
		} else {
			i.distance = t0;
			i.point = *(r.at(distance - t0));
			return true;
		}

	}

}
