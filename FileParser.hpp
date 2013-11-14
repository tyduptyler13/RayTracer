/*
 * FileParser.hpp
 *
 *  Created on: Nov 13, 2013
 *      Author: tydup13
 */

#ifndef FILEPARSER_HPP_
#define FILEPARSER_HPP_

#include <map>
#include <fstream>
#include <sstream>
#include <vector>

/**
 * This file will be included after RayTracer.
 * It exists to keep things clean.
 */

std::map<std::string, Material> materials;

void parseObj(std::string& filename, Scene& scene){
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

			//s->color.set(red/255, green/255, blue/255);

			scene.addObject(s);

		}

	}

	file.close();

}

void parsemtl(std::string& filename){
	std::ifstream file(filename);

	std::string line;

	Material cm;

	float r,g,b;

	while(std::getline(file, line)){

		if (line.length() == 0) continue;

		std::stringstream ss;

		ss << line;

		std::string command;


		ss >> command;

		if (command == "newmtl"){

			//Push the last material we were editing.
			if (!cm.name.empty()){
				materials.insert(std::pair<std::string, Material>(cm.name, cm));
			}

			std::string name;

			ss >> name;

			cm = Material(name);


		} else if (command == "Ka") {

			ss >> r >> g >> b;

			cm.ambient.set(r, g, b);

		} else if (command == "Kd") {

			ss >> r >> g >> b;

			cm.diffuse.set(r, g, b);

		} else if (command == "Ks") {

			ss >> r >> g >> b;

			cm.specular.set(r, g, b);

		}

	}

	//Add the last one because nothing comes after it.
	if (!cm.name.empty()){
		materials.insert(std::pair<std::string, Material>(cm.name, cm));
	}

}

void parseCmd(std::string& filename, Scene& scene){
	std::ifstream file(filename);

	std::string line, part1;

	while(std::getline(file, line)){

		if (line.length() == 0) continue;//Empty line.

		std::stringstream ss;

		ss << line;

		ss >> part1;

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

			scene.addCamera(c);

		} else if (part1 == "r"){

			std::string name;
			std::size_t width, height;
			unsigned recursion;

			ss >> name;
			ss >> width;
			ss >> height;
			ss >> recursion;

			scene.render(name, width, height, recursion);

		}

	}

	file.close();

}



#endif /* FILEPARSER_HPP_ */
