#ifndef SCENE_HPP__
#define SCENE_HPP__

#include <vector>

#include "Sphere.hpp"

class Scene{

	std::vector<Sphere*> objects;
	//TODO lights, fog, polymorphic objects

public:

	Scene();

	void addObject(Sphere* s);
	void removeObject(Sphere* s);

};

#endif
