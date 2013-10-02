#ifndef MATRIX3_HPP__
#define MATRIX3_HPP__

#include "Vector3.hpp"

class Matrix3{

	double* elements;

public:

	Matrix3();
	Matrix3(double n11,  double n12, double n13,
			double n21, double n22, double n23,
			double n31, double n32, double n33);
	~Matrix3();

	bool operator==(const Matrix3&) const;
	bool operator!=(const Matrix3& rhs) const;


	Matrix3& operator=(Matrix3& rhs);

	Matrix3& set(double n11,  double n12, double n13,
			double n21, double n22, double n23,
			double n31, double n32, double n33);

	Matrix3& identity();
	Matrix3& operator=(const Matrix3&);
	Vector3& operator*(Vector3&);
	Matrix3& operator*(double);
	Matrix3& operator*=(double);
	double det();
	Matrix3& transpose();
	Matrix3& clone();
	double operator[](unsigned);


};

#endif
