#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<regex>
#include<vector>

#include "Scene.hpp"
#include "Sphere.hpp"
#include "Vector3.hpp"
#include "Camera.hpp"

class RayTracer{

public:

	Scene scene;

	RayTracer(){
		scene = Scene();
	}

};

void parseObj(std::string& filename, RayTracer* raytracer){
	std::ifstream file(filename);

	std::string line;

	while(std::getline(file, line)){

		if (line.length() == 0) continue;//Empty line.

		std::stringstream ss;
		std::string part1;

		ss << line;

		ss >> part1;

		if (part1 == "s"){
			double x, y, z, r;
			std::string name;

			ss >> name;

			ss >> x;
			ss >> y;
			ss >> z;
			ss >> r;

			float red, green, blue;

			ss >> red;
			ss >> green;
			ss >> blue;

			Vector3 v = Vector3(x, y, z);
			Sphere* s = new Sphere(v, r);
			s->name = name;

			s->setColor(red/255, green/255, blue/255);

			raytracer->scene.addObject(s);

		}

	}

	file.close();

}

void parseCmd(std::string& filename, RayTracer* raytracer){
	std::ifstream file(filename);

	std::string line, part1;

	while(std::getline(file, line)){

		//std::cout << "Debug: Line: " << line << std::endl;

		if (line.length() == 0) continue;//Empty line.

		std::stringstream ss;

		ss << line;

		ss >> part1;

		//std::cout << "Debug: command = " << part1 << std::endl;

		if (part1 == "c"){

			double x, y, z, near, far;
			std::string name;

			ss >> name;
			ss >> x;
			ss >> y;
			ss >> z;

			Vector3 prp(x, y, z);

			ss >> x;
			ss >> y;
			ss >> z;

			Vector3 pnp(x, y, z);

			ss >> near;
			ss >> far;

			Camera* c = new Camera(prp, pnp, near, far);
			c->setName(name);

			raytracer->scene.addCamera(c);

		} else if (part1 == "r"){

			std::string name;
			std::size_t width, height;
			unsigned recursion;

			ss >> name;
			ss >> width;
			ss >> height;
			ss >> recursion;

			raytracer->scene.render(name, width, height, recursion);

		}

	}

	file.close();

}

bool matches(const std::string& regex, const std::string& input){

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
		RayTracer* raytracer = new RayTracer();

		for (int i = 1; i < argc; ++i){

			std::string arg = std::string(argv[i]);

			std::string objTest = ".+\\.(obj)";
			if (matches(objTest, arg)){

				parseObj(arg, raytracer);

			} else if (arg == "-c"){

				if (i + 1 < argc){

					arg = std::string(argv[++i]);

					parseCmd(arg, raytracer);

				} else {

					std::cout << "Expected an argument after '-c'. This parameter will be ignored!" << std::endl;

				}

			}

		}

		delete raytracer;

	}

}

