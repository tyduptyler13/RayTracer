
#include "Vector4.hpp"


Vector4& Vector4::applyMatrix4(Matrix4& m){
	double x = this->x;
	double y = this->y;
	double z = this->z;
	double w = this->w;

	const double* e = m.toArray();

	this->x = e[0] * x + e[4] * y + e[8] * z + e[12] * w;
	this->y = e[1] * x + e[5] * y + e[9] * z + e[13] * w;
	this->z = e[2] * x + e[6] * y + e[10] * z + e[14] * w;
	this->w = e[3] * x + e[7] * y + e[11] * z + e[15] * w;

	return *this;
}
