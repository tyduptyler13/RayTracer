#include <iostream>
#include <string>
#include <regex>

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

//Moved the parsing functions to their own file to clean things up.
#include "FileParser.hpp"

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

		if (argc == 3){

			std::string obj(argv[1]);
			std::string cmd(argv[2]);

			parseObj(obj, raytracer->scene);
			parseCmd(cmd, raytracer->scene);

		} else {

			for (int i = 1; i < argc; ++i){

				std::string arg = std::string(argv[i]);

				std::string objTest = ".+\\.(obj)";
				if (matches(objTest, arg)){

					parseObj(arg, raytracer->scene);

				} else if (arg == "-c"){

					if (i + 1 < argc){

						arg = std::string(argv[++i]);

						parseCmd(arg, raytracer->scene);

					} else {

						std::cout << "Expected an argument after '-c'. This parameter will be ignored!" << std::endl;

					}

				}

			}

		}

		delete raytracer;

	}

}

