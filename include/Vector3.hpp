/*
 * Custom Vector implementation.
 */
#ifndef VECTOR3_HPP_
#define VECTOR3_HPP_

#include <cmath>

class Vector3{

public:
	double x, y, z;

	Vector3();
	Vector3(double x, double y, double z);
	Vector3(const Vector3&);

	Vector3& set(double, double, double);

	Vector3& operator=(const Vector3&);

	Vector3 operator+(double s) const{
		Vector3 ret(*this);
		ret += s;
		return ret;
	}
	Vector3& operator+=(double);
	Vector3 operator+(const Vector3& v) const{
		Vector3 ret(*this);
		ret += v;
		return ret;
	}
	Vector3& operator+=(const Vector3&);

	Vector3 operator-(double s) const{
		Vector3 tmp(*this);
		tmp -= s;
		return tmp;
	}
	Vector3& operator-=(double);
	Vector3 operator-(const Vector3& v) const{
		Vector3 tmp(*this);
		tmp -= v;
		return tmp;
	}
	Vector3& operator-=(const Vector3&);

	Vector3 operator*(const Vector3& v) const{
		Vector3 tmp(*this);
		tmp *= v;
		return tmp;
	}
	Vector3& operator*=(double);
	Vector3 operator*(double s) const{
		Vector3 tmp(*this);
		tmp *= s;
		return tmp;
	}
	friend Vector3 operator*(double s, const Vector3& v){
		return v * s;
	}
	Vector3& operator*=(const Vector3&);

//	Vector3& applyMatrix3(const Matrix3&);
//	Vector3& applyMatrix4(const Matrix4&);

	Vector3& operator/=(const Vector3&);
	Vector3& operator/=(double);

	Vector3& negate();
	friend Vector3 operator-(const Vector3& v){
		Vector3 tmp(v);
		return tmp.negate();
	}

	double dot(const Vector3& v) const{
		return x * v.x + y * v.y + z * v.z;
	};

	double lengthSq() const{
		return x * x + y * y + z * z;
	};

	double length() const{
		return std::sqrt(this->lengthSq());
	}

	Vector3& normalize();

	Vector3 cross(const Vector3&) const;
	Vector3& crossVectors(const Vector3&, const Vector3&);

	double distanceToSquared(const Vector3&) const;
	double distanceTo(const Vector3& v) const{
		return std::sqrt(this->distanceToSquared(v));
	};

	bool operator==(const Vector3&) const;
	bool operator!=(const Vector3& v) const{
		return !(*this == v);
	};

};

#endif //VECTOR3_HPP_
