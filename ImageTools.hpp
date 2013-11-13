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

/**
 * By default this will always go to black.
 */
class Color{

public:
	float r;
	float g;
	float b;

	Color(){
		r = 0;
		g = 0;
		b = 0;
	}

	Color(float r, float g, float b) : r(r), g(g), b(b) {}

	void set(float r, float g, float b){

		this->r = r;
		this->g = g;
		this->b = b;

	}

};

template<class T>
class Image{

protected:
	T** data;
	std::size_t width;
	std::size_t height;

public:

	Image(std::size_t width, std::size_t height) : width(width), height(height){
		data = new T*[width];
		for (std::size_t i = 0; i < width; ++i){
			data[i] = new T[height];
		}
	}

	virtual ~Image(){
		for (std::size_t i = 0; i < width; ++i){
			delete[] data[i];
		}

		delete[] data;
	}

	T& get(std::size_t x, std::size_t y){
		return data[x][y];
	}

	virtual void save(const std::string&) = 0;

	/**
	 * Assuming the input is between 0 and 1.
	 */
	inline int map(float in){
		return (int)(MAX * in);
	}

};

class ColorImage : public Image<Color>{

	void printColor(Color& c, std::ofstream& out){

		out << map(c.r) << " " << map(c.g) << " " << map(c.b) << " ";

	}

public:

	ColorImage(std::size_t width, std::size_t height) : Image<Color>(width, height){}

	void set(std::size_t x, std::size_t y, const Color& c){
		data[x][y] = c;
	}

	void save(const std::string& filename){

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

};

class MonoImage : Image<float>{

	void printColor(float f, std::ofstream& out){

		out << map(f) << " ";

	}

public:

	MonoImage(std::size_t width, std::size_t height) : Image<float>(width, height){}

	/**
	 * Had to change the get signature because the inherited one returns a reference.
	 * To change values of this image, use set.
	 */
	float get(std::size_t x, std::size_t y){
		return data[x][y];
	}

	void set(std::size_t x, std::size_t y, float value){
		data[x][y] = value;
	}

	void save(const std::string& filename){

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

};

#endif /* IMAGETOOLS_HPP_ */
