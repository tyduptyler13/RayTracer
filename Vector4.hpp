
#ifndef Vector4_H__
#define Vector4_H__

#include "Matrix4.hpp"

#include <memory>

/*
 * Coded with the idea of allowing the compiler to
 * make improvements. Sections with a low count of
 * operations are in the header. Those that are high
 * complexity are in the source file.
 *
 * Essentially all of these functions could be inlined.
 */

class Vector4{


public:
	double x;
	double y;
	double z;
	double w;

	Vector4(){
		x = y = z = 0;
		w = 1;
	}

	Vector4(double x, double y, double z, double w){
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Vector4(Vector4& v){
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = v.w;
	}

	Vector4& set(double x, double y, double z, double w){
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;

		return *this;
	}

	Vector4& operator=(Vector4& v){
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;

		return *this;
	}

	std::unique_ptr<Vector4> operator+(Vector4& v){
		Vector4* ret = new Vector4(*this);
		*ret += v;
		return std::unique_ptr<Vector4>(ret);
	}

	Vector4& operator+=(Vector4& v){
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;

		return *this;
	}

	std::unique_ptr<Vector4> operator+(double s){
		Vector4* ret = new Vector4(*this);
		*ret += s;
		return std::unique_ptr<Vector4>(ret);
	}

	Vector4& operator+=(double s){
		x += s;
		y += y;
		z += z;
		w += w;

		return *this;
	}

	std::unique_ptr<Vector4> operator-(Vector4& v){
		Vector4* ret = new Vector4(*this);
		*ret -= v;
		return std::unique_ptr<Vector4>(ret);
	}

	Vector4& operator-=(Vector4& v){
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;

		return *this;
	}

	std::unique_ptr<Vector4> operator-(double s){
		Vector4* ret = new Vector4(*this);
		*ret -= s;
		return std::unique_ptr<Vector4>(ret);
	}

	Vector4& operator-=(double s){
		x -= s;
		y -= y;
		z -= z;
		w -= w;

		return *this;
	}

	Vector4& operator*=(double s){
		x *= s;
		y *= s;
		z *= s;
		w *= s;

		return *this;
	}

	Vector4& applyMatrix4(Matrix4&);

	Vector4& operator/=(double s){
		if (s != 0){

			x /= s;
			y /= s;
			z /= s;
			w /= s;

		} else {

			x = y = z = 0;
			w = 1;

		}

		return *this;
	}

	Vector4& negate(){
		*this *= -1;
		return *this;
	}

	double dot(const Vector4& v) const{
		return (x * v.x + y * v.y + z * v.z + w * v.w);
	}

	double lengthSq() const{
		return x * x + y * y + z * z + w * w;
	}

	double length() const{
		return sqrt(lengthSq());
	}

	Vector4& normalize(){
		*this /= length();
		return *this;
	}

	bool operator==(const Vector4& v) const{
		return (x == v.x && y == v.y && z == v.z && w == v.w);
	}

};

#endif
