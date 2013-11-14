/*
 * ImageTools.cpp
 *
 *  Created on: Nov 12, 2013
 *      Author: Tyler
 */

#include<iostream>

#include "ImageTools.hpp"

void ColorImage::save(const std::string& filename) const{

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

void MonoImage::save(const std::string& filename) const{

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

