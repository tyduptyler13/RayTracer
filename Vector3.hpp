/*
 * Custom Vector implementation.
 */
#ifndef VECTOR3_HPP_
#define VECTOR3_HPP_

#include <math.h>
#include <memory>

//#include "Matrix3.hpp" Cyclic
class Matrix3;
//#include "Matrix4.hpp" Cyclic
class Matrix4;


class Vector3{

public:
	double x, y, z;

	Vector3();
	Vector3(double x, double y, double z);
	Vector3(const Vector3&);

	Vector3& set(double, double, double);

	Vector3& operator=(const Vector3&);

	std::unique_ptr<Vector3> operator+(double) const;
	Vector3& operator+=(double);
	std::unique_ptr<Vector3> operator+(const Vector3&) const;
	Vector3& operator+=(const Vector3&);

	std::unique_ptr<Vector3> operator-(double) const;
	Vector3& operator-=(double);
	std::unique_ptr<Vector3> operator-(const Vector3&) const;
	Vector3& operator-=(const Vector3&);

	std::unique_ptr<Vector3> operator*(double) const;
	Vector3& operator*=(double);
	std::unique_ptr<Vector3> operator*(const Vector3&) const;
	Vector3& operator*=(const Vector3&);

	Vector3& applyMatrix3(const Matrix3&);
	Vector3& applyMatrix4(const Matrix4&);

	Vector3& operator/=(const Vector3&);
	Vector3& operator/=(double);

	Vector3& negate();

	double dot(const Vector3& v) const{
		return x * v.x + y * v.y + z * v.z;
	};

	double lengthSq() const{
		return x * x + y * y + z * z;
	};

	double length() const{
		return sqrt(this->lengthSq());
	}

	Vector3& normalize();

	std::unique_ptr<Vector3> cross(const Vector3&) const;
	Vector3& crossVectors(const Vector3&, const Vector3&);

	double distanceToSquared(const Vector3&) const;
	double distanceTo(const Vector3& v) const{
		return sqrt(this->distanceToSquared(v));
	};

	bool operator==(const Vector3&) const;
	bool operator!=(const Vector3& v) const{
		return !(*this == v);
	};

};

#endif //VECTOR3_HPP_
