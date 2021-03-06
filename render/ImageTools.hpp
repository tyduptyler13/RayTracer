/*
 * ImageTools.hpp
 *
 *  Created on: Oct 5, 2013
 *      Author: Tyler
 */

#ifndef IMAGETOOLS_HPP_
#define IMAGETOOLS_HPP_

#include <fstream>
#include <string>

#define MAX 256

/**
 * By default this will always go to white.
 */
class Color{

	inline double clamp(double x){
		if (x < 0) return 0;
		if (x > 1) return 1;
		return x;
	}

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

	Color(const Color& c){
		r = c.r;
		g = c.g;
		b = c.b;
	}

	inline void set(float r, float g, float b){

		this->r = r;
		this->g = g;
		this->b = b;

	}

	Color& operator=(const Color& c){
		r = c.r;
		g = c.g;
		b = c.b;

		return *this;
	}

	Color operator*(const Color& c) const{
		Color ret(*this);
		ret *= c;
		return ret;
	}

	friend Color operator*(double s, const Color& c){
		return c * s;
	}

	Color& operator*=(const Color& c){

		r *= c.r;
		g *= c.g;
		b *= c.b;

		return *this;
	}

	Color operator*(double s) const{
		Color ret(*this);
		ret *= s;
		return ret;
	}

	Color& operator*=(double s){

		r *= s;
		g *= s;
		b *= s;

		return *this;

	}

	Color operator+(const Color& c) const{
		Color ret(*this);
		ret += c;
		return ret;
	}

	Color& operator+=(const Color& c){

		r += c.r;
		g += c.g;
		b += c.b;

		return *this;

	}

	Color operator/(const Color& c) const{
		Color ret(*this);
		ret /= c;
		return ret;
	}

	Color& operator/=(const Color& c){

		r /= c.r;
		g /= c.g;
		b /= c.b;

		return *this;

	}

	Color operator/(double s) const{
		Color ret(*this);
		ret /= s;
		return ret;
	}

	Color& operator/=(double s){

		r /= s;
		g /= s;
		b /= s;

		return *this;

	}

	inline bool isValid(){
		return ((r <= 1 && r >= 0) &&
				(g <= 1 && g >= 0) &&
				(b <= 1 && b >= 0));
	}

	inline void clamp(){
		r = clamp(r);
		g = clamp(g);
		b = clamp(b);
	}

};

class Material{

public:

	std::string name;

	Color diffuse;
	Color specular;
	Color ambient;

	int Ns = 200;

	/**
	 * Refractive index.
	 */
	double n1 = 1;

	double transparency = 1;

	/**
	 * Attenuation of relfection. (Kr)
	 */
	double Kr = 1;

	/**
	 * Attenuation of refraction. (Krf)
	 */
	double Krf = 1;

	Material(){}
	Material(std::string& name) : name(name) {}
	Material(std::string& name, Color& diffuse, Color& specular, Color& ambient)
	: name(name), diffuse(diffuse), specular(specular), ambient(ambient) {}

	Material(const Material& m) : name(m.name), diffuse(m.diffuse), specular(m.specular), ambient(m.ambient) {}

	Material& operator=(const Material& m){
		name = m.name;
		diffuse = m.diffuse;
		specular = m.specular;
		ambient = m.ambient;

		return *this;
	}

	bool operator==(const std::string& s){
		return (s == name);
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

	T& get(std::size_t x, std::size_t y) const{
		return data[x][y];
	}

	virtual void save(const std::string&) const = 0;

	/**
	 * Assuming the input is between 0 and 1.
	 */
	inline int map(float in) const{
		return (int)(MAX * in);
	}

};

class ColorImage : public Image<Color>{

	void printColor(const Color& c, std::ofstream& out) const{

		out << map(c.r) << " " << map(c.g) << " " << map(c.b) << " ";

	}

public:

	ColorImage(std::size_t width, std::size_t height) : Image<Color>(width, height){}

	void set(std::size_t x, std::size_t y, const Color& c){
		data[x][y] = c;
	}

	void save(const std::string& filename) const;
};

class MonoImage : Image<float>{

	void printColor(float f, std::ofstream& out) const{

		out << map(f) << " ";

	}

public:

	MonoImage(std::size_t width, std::size_t height) : Image<float>(width, height){}

	/**
	 * Had to change the get signature because the inherited one returns a reference.
	 * To change values of this image, use set.
	 */
	float get(std::size_t x, std::size_t y) const{
		return data[x][y];
	}

	void set(std::size_t x, std::size_t y, float value){
		data[x][y] = value;
	}

	void save(const std::string& filename) const;

};

#endif /* IMAGETOOLS_HPP_ */
