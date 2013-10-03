
#include "Matrix3.hpp"

Matrix3::Matrix3(){
	elements = new double[9];
	identity();
}

Matrix3::Matrix3(double n11,  double n12, double n13,
		double n21, double n22, double n23,
		double n31, double n32, double n33){

	double* te = elements = new double[9];

	te[0] = n11; te[3] = n12; te[6] = n13;
	te[1] = n21; te[4] = n22; te[7] = n23;
	te[2] = n31; te[5] = n32; te[8] = n33;

}

Matrix3::Matrix3(Matrix3& ref){
	elements = new double[9];

	for (int i = 0; i < 9; ++i){
		elements[i] = ref.elements[i];
	}

}

Matrix3::~Matrix3(){
	delete[] elements;
}

Matrix3& Matrix3::set(double n11,  double n12, double n13,
		double n21, double n22, double n23,
		double n31, double n32, double n33){

	double* te = elements;

	te[0] = n11; te[3] = n12; te[6] = n13;
	te[1] = n21; te[4] = n22; te[7] = n23;
	te[2] = n31; te[5] = n32; te[8] = n33;

	return *this;

}

Matrix3& Matrix3::identity(){

	this->set(
			1, 0, 0,
			0, 1, 0,
			0, 0, 1
	);

	return *this;

}

std::vector<Vector3>& Matrix3::operator*(std::vector<Vector3>& vectors){

	for (Vector3 v : vectors){
		v.applyMatrix3(*this);
	}

	return vectors;

}

Matrix3& Matrix3::operator*(double s){

	Matrix3* m = new Matrix3(*this);
	*m *= s;
	return *m;

}



Matrix3& Matrix3::operator*=(double s){

	double* te = elements;

	te[0] *= s; te[3] *= s; te[6] *= s;
	te[1] *= s; te[4] *= s; te[7] *= s;
	te[2] *= s; te[5] *= s; te[8] *= s;

	return *this;
}

double Matrix3::det(){

	double* te = elements;

	double  a = te[0], b = te[1], c = te[2],
			d = te[3], e = te[4], f = te[5],
			g = te[6], h = te[7], i = te[8];

	return a*e*i - a*f*h - b*d*i + b*f*g + c*d*h - c*e*g;

}

Matrix3& Matrix3::transpose(){

	double tmp;
	double* m = elements;

	tmp = m[1]; m[1] = m[3]; m[3] = tmp;
	tmp = m[2]; m[2] = m[6]; m[6] = tmp;
	tmp = m[5]; m[5] = m[7]; m[7] = tmp;

	return *this;

}

Matrix3& Matrix3::operator=(const Matrix3& rhs){

	if (this != &rhs){

		for (int i = 0; i < 9; ++i){
			elements[i] = rhs.elements[i];
		}

	}

	return *this;

}

bool Matrix3::operator==(const Matrix3& rhs) const{

	for (int i = 0; i < 9; ++i){
		if (elements[i] != rhs.elements[i]){
			return false;
		}
	}

	return true;

}

const double* Matrix3::toArray() const{
	return elements;
}


