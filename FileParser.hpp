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

#include "Group.hpp"
#include "Face3.hpp"
#include "Face4.hpp"

/**
 * This file will be included after RayTracer.
 * It exists to keep things clean.
 */

std::map<std::string, Material> materials;

void parsemtl(std::string& filename){
	std::ifstream file(filename);

	if (!file.is_open()){
		std::cout << "File " << filename << " does not seem to exist." << std::endl;
		return;
	}

	std::cout << "Fetching materials from " << filename << std::endl;

	std::string line;

	Material cm;

	float r,g,b;

	while(std::getline(file, line)){

		if (line.length() == 0 || line[0] == '#') continue;

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

		} else if (command == "Ns"){

			ss >> cm.Ns;

		} else if (command == "n1"){

			ss >> cm.n1;

		} else if (command == "Tr"){

			ss >> cm.transparency;

		} else if (command == "Kr"){

			ss >> cm.Kr;

		} else if (command == "Krf"){

			ss >> cm.Krf;

		}

	}

	//Add the last one because nothing comes after it.
	if (!cm.name.empty()){//If its empty then the file doesn't define anything.
		materials.insert(std::pair<std::string, Material>(cm.name, cm));
	}

}

void parseObj(std::string& filename, Scene& scene){
	std::ifstream file(filename);

	if (!file.is_open()){

		std::cout << "File " << filename << " does not seem to exist." << std::endl;
		return;

	}

	std::cout << "Reading in " << filename << std::endl;

	std::string line;

	//State machine parts.
	std::string cm; //Current material name.
	Group* cg = NULL;//Current group.
	std::vector<Vector3> vectorList;//Zero based list of vertices.

	while(std::getline(file, line)){

		if (line.length() == 0 || line[0] == '#') continue;//Empty line or comment.

		std::stringstream ss;
		std::string part1;

		ss << line;

		ss >> part1;

		if (part1 == "v"){

			double x, y, z;
			ss >> x >> y >> z;

			Vector3 tmp(x, y, z);

			vectorList.push_back(tmp);

		} else if (part1 == "s"){
			double x, y, z, r;
			std::string name;

			ss >> name;

			ss >> x;
			ss >> y;
			ss >> z;
			ss >> r;

			Vector3 v = Vector3(x, y, z);
			Sphere* s = new Sphere(v, r);
			s->name = name;

			s->material = materials.find(cm)->second;

			scene.addObject(s);

		} else if (part1 == "f"){

			//continue;//Skip for now.

			size_t a, b, c, d = 0;

			ss >> a >> b >> c;

			Object3D* face;

			if ((ss >> d).fail() || !(ss >> std::ws).eof()){
				face = new Face3(vectorList[a-1], vectorList[b-1], vectorList[c-1]);
			} else {
				face = new Face4(vectorList[a-1], vectorList[b-1], vectorList[c-1], vectorList[d-1]);
			}

			if (cm.empty()){
				std::cout << "WARNING: Material was not specified. The object will have no color!" << std::endl;
			} else {
				face->material = materials.find(cm)->second;
			}

			if (cg == NULL){

				std::cout << "WARNING: Group was not defined. Adding raw face." << std::endl;
				scene.addObject(face);

			} else {

				cg->addChild(face);

			}

		} else if (part1 == "g"){

			std::string name;
			ss >> name;

			cg = new Group();
			scene.addObject(cg);

		} else if (part1 == "usemtl"){

			std::string part2;
			ss >> cm;

		} else if (part1 == "mtllib"){

			std::string mtlfile;
			ss >> mtlfile;

			std::string path = filename.substr(0, filename.find_last_of("/\\") + 1);

			mtlfile = path + mtlfile;

			parsemtl(mtlfile);

		}

	}

	file.close();

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
			ss >> x >> y >> z;

			Vector3 prp(x, y, z);

			ss >> x >> y >> z;

			Vector3 pnp(x, y, z);

			ss >> x >> y >> z;

			Vector3 up(x, y, z);

			ss >> near;
			ss >> far;

			Camera* c = new Camera(prp, pnp, near, far);
			c->setName(name);
			c->up = up;

			scene.addCamera(c);

		} else if (part1 == "r"){

			std::string name;
			std::size_t width, height;
			unsigned recursion;

			ss >> name;
			ss >> width;
			ss >> height;
			ss >> recursion;

			std::cout << "Rendering " << name + "(" << width << "x" << height << ")" << std::endl;

			scene.render(name, width, height, recursion);

		} else if (part1 == "l"){

			double x, y, z, w, r, g, b;

			ss >> x >> y >> z >> w >> r >> g >> b; //light x y z r g b

			Vector4 pos(x, y, z, w);
			Color c(r/255, g/255, b/255);
			Light* l = new Light(pos, c);

			scene.addLight(l);

		}

	}

	file.close();

}



#endif /* FILEPARSER_HPP_ */
