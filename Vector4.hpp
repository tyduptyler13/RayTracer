
#ifndef __Vector4_H__
#define __Vector4_H__

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
	
};

#endif
