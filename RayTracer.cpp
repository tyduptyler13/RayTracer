
#include<thread>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<regex>
#include<vector>

#include "Scene.hpp"
#include "Sphere.hpp"
#include "Vector3.hpp"

class RayTracer{

public:
	const unsigned concurentThreadsSupported = std::thread::hardware_concurrency();

	//std::cout << r->concurentThreadsSupported << std::endl;

	Scene scene;

	RayTracer(){
		scene = Scene();
	}


};

RayTracer* raytracer;//Global ratracer object.

std::vector<std::string> split(std::string& input, char delimiter){
	std::vector<std::string> result;
	std::istringstream iss(input);

	std::string out;
	while(std::getline(iss, out, delimiter)){
		result.push_back(out);
	}

	return result;
}

void parseObj(std::string& filename){
	std::ifstream file(filename);

	std::string line;

	while(std::getline(file, line)){

		std::vector<std::string> parts = split(line, ' ');

		if (parts.size() != 9){

			std::cerr << "This version does not support this line: \"" << line << "\"" << std::endl;

		} else {

			if (parts[0] == "s"){
				double x, y, z, r;
				std::stringstream ss;

				ss << parts[2];
				ss >> x;
				ss << parts[3];
				ss >> y;
				ss << parts[4];
				ss >> z;
				ss << parts[5];
				ss >> r;

				float red, green, blue;

				ss << parts[6];
				ss >> red;
				ss << parts[7];
				ss >> blue;
				ss << parts[8];
				ss >> green;

				Vector3 v = Vector3(x, y, z);
				Sphere* s = new Sphere(v, r);
				s->name = parts[1];
				float color [3] = { red, blue, green };

				for (int i = 0; i < 3; ++i){
					s->color[i] = color[i];
				}

			} else {

				std::cerr << "This program does not support non sphere objects yet!" << std::endl;

			}

		}

	}

}

void parseCmd(std::string& filename){
	std::ifstream file(filename);



}

bool matches(std::string& regex, std::string input){

	return std::regex_match(input, std::regex(regex));

}

int main(int argc, char** argv){

	if (argc < 3){

		if (argc == 2){
			std::string arg = std::string(argv[1]);
			if (arg == "-h" || arg == "--help"){
				std::cout << "Please see the README.md for help." << std::endl;
			}
		}
		std::cout << "This program expects at least 2 arguments." << std::endl;
		return 0;
	} else {
		raytracer = new RayTracer();

		for (int i = 1; i < argc; ++i){

			std::string arg = std::string(argv[i]);

			if (matches(arg, std::string("*.obj$"))){

			}

		}
	}

}

