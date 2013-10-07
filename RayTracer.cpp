
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
#include "Camera.hpp"

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

std::vector<std::string> split(std::string& input){
	std::vector<std::string> result;
	std::stringstream ss;
	ss << input;

	std::string out;
	while(ss >> out){
		result.push_back(out);
	}

	return result;
}

void parseObj(std::string& filename){
	std::ifstream file(filename);

	std::string line;

	while(std::getline(file, line)){

		if (line.length() == 0) continue;//Empty line.

		std::vector<std::string> parts = split(line);

		if (parts.size() != 9){

			//Do Nothing.
			std::cout << "Debug: Found line that was " << parts.size() << " units." << std::endl;

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

				s->setColor(red, green, blue);

				raytracer->scene.addObject(s);

				std::cout << "Debug: A sphere was added to the scene." << std::endl;
				std::cout << "Debug: The scene has " << raytracer->scene.getObjects().size() << " objects." << std::endl;

			} else {

				std::cout << "Debug: Skipped a line that was 9 words. Error?" << std::endl;

			}

		}

	}

}

void parseCmd(std::string& filename){
	std::ifstream file(filename);

	std::string line;

	while(std::getline(file, line)){

		if (line.length() == 0) continue;//Empty line.

		std::vector<std::string> parts = split(line);

		if (parts.size() == 10){

			if (parts[0] == "c"){

				double x, y, z, near, far;
				std::stringstream ss;

				ss << parts[2];
				ss >> x;
				ss << parts[3];
				ss >> y;
				ss << parts[4];
				ss >> z;

				Vector3 prp(x, y, z);

				ss << parts[5];
				ss >> x;
				ss << parts[6];
				ss >> y;
				ss << parts[7];
				ss >> z;

				Vector3 pnp(x, y, z);

				ss << parts[8];
				ss >> near;
				ss << parts[9];
				ss >> far;

				Camera* c = new Camera(prp, pnp, near, far);
				c->setName(parts[1]);

				raytracer->scene.addCamera(c);

			} else {

				std::cout << "A line was not recognized! (" << filename << ") "
						<< line << std::endl;

			}

		} else if (parts.size() == 5){

			if (parts[0] == "r"){

				std::stringstream ss;

				std::string name = parts[1];
				std::size_t width, height;
				unsigned recursion;

				ss << parts[2];
				ss >> width;
				ss << parts[3];
				ss >> height;
				ss << parts[4];
				ss >> recursion;

				raytracer->scene.render(name, width, height, recursion);

			} else {

				std::cout << "A line was not recognized! (" << filename << ") "
						<< line << std::endl;

			}

		}

	}

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
		raytracer = new RayTracer();

		for (int i = 1; i < argc; ++i){

			std::string arg = std::string(argv[i]);

			std::string objTest = ".+\\.(obj)";
			if (matches(objTest, arg)){

				parseObj(arg);

			} else if (arg == "-c"){

				if (i + 1 < argc){

					arg = std::string(argv[++i]);

					parseCmd(arg);

				} else {

					std::cout << "Expected an argument after '-c'. This parameter will be ignored!" << std::endl;

				}

			}

		}
	}

}

