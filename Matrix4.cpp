
#include "Matrix4.hpp"

Matrix4::Matrix4(double n11, double n12, double n13, double n14,
		double n21, double n22, double n23, double n24,
		double n31, double n32, double n33, double n34,
		double n41, double n42, double n43, double n44){

	double* te = elements = new double[16];

	te[0] = n11; te[4] = n12; te[8] = n13; te[12] = n14;
	te[1] = n21; te[5] = n22; te[9] = n23; te[13] = n24;
	te[2] = n31; te[6] = n32; te[10] = n33; te[14] = n34;
	te[3] = n41; te[7] = n42; te[11] = n43; te[15] = n44;

}

Matrix4& Matrix4::set(double n11, double n12, double n13, double n14,
		double n21, double n22, double n23, double n24,
		double n31, double n32, double n33, double n34,
		double n41, double n42, double n43, double n44){

	double* te = elements;

	te[0] = n11; te[4] = n12; te[8] = n13; te[12] = n14;
	te[1] = n21; te[5] = n22; te[9] = n23; te[13] = n24;
	te[2] = n31; te[6] = n32; te[10] = n33; te[14] = n34;
	te[3] = n41; te[7] = n42; te[11] = n43; te[15] = n44;

	return *this;
}

Matrix4& Matrix4::operator=(Matrix4& m){

	if (&m != this){

		for (int i = 0; i < 16; ++i){

			elements[i] = m.elements[i];

		}

	}

	return *this;

}


std::unique_ptr<Matrix4> Matrix4::operator*(Matrix4& m){
	Matrix4* ret = new Matrix4(*this);
	*ret *= m;
	return std::unique_ptr<Matrix4>(ret);
}

Matrix4& Matrix4::operator *=(Matrix4& m){
	double* ae = elements;
	double* be = m.elements;
	double* te = elements;

	double a11 = ae[0], a12 = ae[4], a13 = ae[8], a14 = ae[12];
	double a21 = ae[1], a22 = ae[5], a23 = ae[9], a24 = ae[13];
	double a31 = ae[2], a32 = ae[6], a33 = ae[10], a34 = ae[14];
	double a41 = ae[3], a42 = ae[7], a43 = ae[11], a44 = ae[15];

	double b11 = be[0], b12 = be[4], b13 = be[8], b14 = be[12];
	double b21 = be[1], b22 = be[5], b23 = be[9], b24 = be[13];
	double b31 = be[2], b32 = be[6], b33 = be[10], b34 = be[14];
	double b41 = be[3], b42 = be[7], b43 = be[11], b44 = be[15];

	te[0] = a11 * b11 + a12 * b21 + a13 * b31 + a14 * b41;
	te[4] = a11 * b12 + a12 * b22 + a13 * b32 + a14 * b42;
	te[8] = a11 * b13 + a12 * b23 + a13 * b33 + a14 * b43;
	te[12] = a11 * b14 + a12 * b24 + a13 * b34 + a14 * b44;

	te[1] = a21 * b11 + a22 * b21 + a23 * b31 + a24 * b41;
	te[5] = a21 * b12 + a22 * b22 + a23 * b32 + a24 * b42;
	te[9] = a21 * b13 + a22 * b23 + a23 * b33 + a24 * b43;
	te[13] = a21 * b14 + a22 * b24 + a23 * b34 + a24 * b44;

	te[2] = a31 * b11 + a32 * b21 + a33 * b31 + a34 * b41;
	te[6] = a31 * b12 + a32 * b22 + a33 * b32 + a34 * b42;
	te[10] = a31 * b13 + a32 * b23 + a33 * b33 + a34 * b43;
	te[14] = a31 * b14 + a32 * b24 + a33 * b34 + a34 * b44;

	te[3] = a41 * b11 + a42 * b21 + a43 * b31 + a44 * b41;
	te[7] = a41 * b12 + a42 * b22 + a43 * b32 + a44 * b42;
	te[11] = a41 * b13 + a42 * b23 + a43 * b33 + a44 * b43;
	te[15] = a41 * b14 + a42 * b24 + a43 * b34 + a44 * b44;

	return *this;
}

double Matrix4::det(){
	double* te = elements;

	float n11 = te[0], n12 = te[4], n13 = te[8], n14 = te[12];
	float n21 = te[1], n22 = te[5], n23 = te[9], n24 = te[13];
	float n31 = te[2], n32 = te[6], n33 = te[10], n34 = te[14];
	float n41 = te[3], n42 = te[7], n43 = te[11], n44 = te[15];

	return (
			n41 * (
					+n14 * n23 * n32
					-n13 * n24 * n32
					-n14 * n22 * n33
					+n12 * n24 * n33
					+n13 * n22 * n34
					-n12 * n23 * n34
			) +
			n42 * (
					+n11 * n23 * n34
					-n11 * n24 * n33
					+n14 * n21 * n33
					-n13 * n21 * n34
					+n13 * n24 * n31
					-n14 * n23 * n31
			) +
			n43 * (
					+n11 * n24 * n32
					-n11 * n22 * n34
					-n14 * n21 * n32
					+n12 * n21 * n34
					+n14 * n22 * n31
					-n12 * n24 * n31
			) +
			n44 * (
					-n13 * n22 * n31
					-n11 * n23 * n32
					+n11 * n22 * n33
					+n13 * n21 * n32
					-n12 * n21 * n33
					+n12 * n23 * n31
			)

	);

}

Matrix4& Matrix4::transpose(){
	double* te = elements;
	double tmp;

	tmp = te[1]; te[1] = te[4]; te[4] = tmp;
	tmp = te[2]; te[2] = te[8]; te[8] = tmp;
	tmp = te[6]; te[6] = te[9]; te[9] = tmp;

	tmp = te[3]; te[3] = te[12]; te[12] = tmp;
	tmp = te[7]; te[7] = te[13]; te[13] = tmp;
	tmp = te[11]; te[11] = te[14]; te[14] = tmp;

	return *this;
}

Matrix4& Matrix4::scale(Vector3& v){
	double* te = elements;
	double x = v.x, y = v.y, z = v.z;

	te[0] *= x; te[4] *= y; te[8] *= z;
	te[1] *= x; te[5] *= y; te[9] *= z;
	te[2] *= x; te[6] *= y; te[10] *= z;
	te[3] *= x; te[7] *= y; te[11] *= z;

	return *this;
}

