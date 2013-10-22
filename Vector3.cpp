
#include "Vector3.hpp"
#include "Matrix3.hpp"
#include "Matrix4.hpp"

Vector3::Vector3(){
	x = y = z = 0;
}

Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z){}

Vector3::Vector3(const Vector3& v){
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

Vector3& Vector3::set(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;

	return *this;
}

Vector3& Vector3::operator=(const Vector3& v){
	x = v.x;
	y = v.y;
	z = v.z;

	return *this;
}

Vector3& Vector3::operator+=(const Vector3& v){
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}

Vector3& Vector3::operator+=(double s){
	x += s;
	y += s;
	z += s;

	return *this;
}

Vector3& Vector3::operator-=(const Vector3& v){
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}

Vector3& Vector3::operator-=(double s){
	x -= s;
	y -= s;
	z -= s;

	return *this;
}

Vector3& Vector3::operator*=(const Vector3& v){
	x *= v.x;
	y *= v.y;
	z *= v.z;

	return *this;
}

Vector3& Vector3::operator*=(double s){
	x *= s;
	y *= s;
	z *= s;

	return *this;
}

/**
 * Essentially Matrix * Vector
 */
Vector3& Vector3::applyMatrix3(const Matrix3& m){
	double x = this->x;
	double y = this->y;
	double z = this->z;

	const double* e = m.toArray();

	this->x = e[0] * x + e[3] * y + e[6] * z;
	this->y = e[1] * x + e[4] * y + e[7] * z;
	this->z = e[2] * x + e[5] * y + e[8] * z;

	return *this;
}

/**
 * What Matrix4 x Vector3 would be.
 */
Vector3& Vector3::applyMatrix4(const Matrix4& m){
	double x = this->x;
	double y = this->y;
	double z = this->z;

	const double* e = m.toArray();

	this->x = e[0] * x + e[4] * y + e[8]  * z + e[12];
	this->y = e[1] * x + e[5] * y + e[9]  * z + e[13];
	this->z = e[2] * x + e[6] * y + e[10] * z + e[14];

	return *this;
}

Vector3& Vector3::operator/=(double s){
	if (s!=0){
		x /= s;
		y /= s;
		z /= s;
	} else {
		x = 0;
		y = 0;
		z = 0;
	}

	return *this;
}

Vector3& Vector3::operator/=(const Vector3& v){
	x /= v.x;
	y /= v.y;
	z /= v.z;

	return *this;
}

Vector3& Vector3::negate(){
	return *this *= -1;
}

Vector3& Vector3::normalize(){
	return *this/=this->length();
}

Vector3 Vector3::cross(const Vector3& v) const{
	Vector3 ret;

	ret.x = y * v.z - z * v.y;
	ret.y = z * v.x - x * v.z;
	ret.z = x * v.y - y * v.x;

	return ret;
}

Vector3& Vector3::crossVectors(const Vector3& a, const Vector3& b){
	x = a.y * b.z - a.z * b.y;
	y = a.z * b.x - a.x * b.z;
	z = a.x * b.y - a.y * b.x;

	return *this;
}

double Vector3::distanceToSquared(const Vector3& v) const{
	double dx = x - v.x;
	double dy = y - v.y;
	double dz = z - v.z;

	return dx * dx + dy * dy + dz * dz;
}

bool Vector3::operator==(const Vector3& v) const{
	return (x == v.x && y == v.y && z == v.z);
}


