#ifndef MATRIX4_HPP__
#define MATRIX4_HPP__

#include "Vector3.hpp"

#include <vector>

class Matrix4{

	double* elements;

public:

	Matrix4();
	Matrix4(double n11, double n12, double n13, double n14,
			double n21, double n22, double n23, double n24,
			double n31, double n32, double n33, double n34,
			double n41, double n42, double n43, double n44);
	Matrix4(Matrix4&);

	Matrix4& set(double n11, double n12, double n13, double n14,
			double n21, double n22, double n23, double n24,
			double n31, double n32, double n33, double n34,
			double n41, double n42, double n43, double n44);

	Matrix4& identity();

	Matrix4& operator=(Matrix4& m);
	Matrix4* operator*(Matrix4& m);
	Matrix4& operator*=(Matrix4& m);
	Matrix4& operator*=(double s);
	std::vector<Vector3>& operator*(std::vector<Vector3>&);
	double det();
	Matrix4& transpose();
	Matrix4& setPosition(Vector3& v);
	Matrix4& scale(Vector3& v);
	Matrix4& makeTranslation(double x, double y, double z){
		this->set(
				1, 0, 0, x,
				0, 1, 0, y,
				0, 0, 1, z,
				0, 0, 0, 1
		);
		return *this;
	}
	//TODO Rotations. Not needed yet.
	Matrix4& makeScale(double x, double y, double z){
		this->set(
				x, 0, 0, 0,
				0, y, 0, 0,
				0, 0, z, 0,
				0, 0, 0, 1
		);

		return *this;
	}

	const double* toArray() const{
		return elements;
	}

};

#endif

