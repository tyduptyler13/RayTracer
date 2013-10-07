/*
 * ImageTools.hpp
 *
 *  Created on: Oct 5, 2013
 *      Author: Tyler
 */

#ifndef IMAGETOOLS_HPP_
#define IMAGETOOLS_HPP_

#include<string>
#include<fstream>
#include<iostream>

#define MAX 256

struct Color{
	float r, g, b;
};

class ColorImage{

	Color* data;
	std::size_t width;
	std::size_t height;

public:

	ColorImage(std::size_t width, std::size_t height) : width(width), height(height){
		data = new Color[width * height];//Smashed into single dimension.
	}

	~ColorImage(){
		delete[] data;
	}

	Color& get(std::size_t x, std::size_t y){
		return data[x * y - 1];
	}

	void save(std::string filename){

		std::ofstream file(filename);

		if (file.is_open()){
			file << "P3" << std::endl;
			file << "# (width) (height) (max_value)" << std::endl;
			file << width << " " << height << " " << MAX << std::endl;
			file << "# [color (RGB)]..." << std::endl;

			for (std::size_t y = 0; y < height; ++y){

				for (std::size_t x = 0; x < width; ++x){

					printColor(get(x, y), file);

				}

				file << std::endl;//Split between lines.

			}

			file.close();
		} else {
			std::cout << "Could not open file! (" << filename << ")" << std::endl;
		}

	}

	void printColor(Color& c, std::ofstream& out){

		out << c.r << " " << c.g << " " << c.b << " ";

	}

	inline int map(float in){
		return MAX * in;
	}

};

class MonoImage{

	float* data;
	std::size_t width;
	std::size_t height;

public:

	MonoImage(std::size_t width, std::size_t height) : width(width), height(height){
		data = new float[width * height];//Smashed into single dimension.
	}

	~MonoImage(){
		delete[] data;
	}

	float get(std::size_t x, std::size_t y){
		return data[x * y - 1];
	}

	void set(std::size_t x, std::size_t y, float value){
		data[x * y - 1] = value;
	}

	void save(std::string filename){

		std::ofstream file(filename);

		if (file.is_open()){
			file << "P2" << std::endl;
			file << "# (width) (height) (max_value)" << std::endl;
			file << width << " " << height << " " << MAX << std::endl;
			file << "# [level]..." << std::endl;

			for (std::size_t y = 0; y < height; ++y){

				for (std::size_t x = 0; x < width; ++x){

					printColor(get(x, y), file);

				}

				file << std::endl;//Split between lines.

			}

			file.close();
		} else {
			std::cout << "Could not open file! (" << filename << ")" << std::endl;
		}

	}

	void printColor(float f, std::ofstream& out){

		out << map(f) << " ";

	}

	inline int map(float in){
		return MAX * in;
	}

};

#endif /* IMAGETOOLS_HPP_ */
