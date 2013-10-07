#ifndef MATRIX3_HPP__
#define MATRIX3_HPP__

#include <vector>

#include "Vector3.hpp"

class Matrix3{

	double* elements;

public:

	Matrix3();
	Matrix3(double n11,  double n12, double n13,
			double n21, double n22, double n23,
			double n31, double n32, double n33);
	Matrix3(Matrix3&);
	~Matrix3();

	bool operator==(const Matrix3&) const;
	bool operator!=(const Matrix3& rhs) const;

	Matrix3& set(double n11,  double n12, double n13,
			double n21, double n22, double n23,
			double n31, double n32, double n33);

	Matrix3& identity();
	Matrix3& operator=(const Matrix3&);
	std::vector<Vector3>& operator*(std::vector<Vector3>&);
	Matrix3& operator*=(double);
	double det();
	Matrix3& transpose();
	const double* toArray() const;

};

#endif
