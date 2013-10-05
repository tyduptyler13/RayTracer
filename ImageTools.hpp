/*
 * ImageTools.hpp
 *
 *  Created on: Oct 5, 2013
 *      Author: Tyler
 */

#ifndef IMAGETOOLS_HPP_
#define IMAGETOOLS_HPP_

#include<string>

struct Color{
	float r, g, b;
};

class Image{

	Color* data;
	unsigned short width;
	unsigned short height;

public:

	Image(unsigned short width, unsigned short height) : width(width), height(height){
		data = new Color[width * height];//Smashed into single dimension.
	}

	~Image(){
		delete[] data;
	}

	Color& get(unsigned int x, unsigned int y){
		return data[x * y - 1];
	}

	void save(std::string filename){
		//TODO
	}

};


#endif /* IMAGETOOLS_HPP_ */
