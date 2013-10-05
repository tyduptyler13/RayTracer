#ifndef SCENE_HPP__
#define SCENE_HPP__

#include <vector>

#include "Object.hpp"
#include "Camera.hpp"

class Scene{

	std::vector<Object*> objects;
	std::vector<Camera*> cameras;

public:

	Scene();
	~Scene();

	void addObject(Object* s);
	void removeObject(Object* s);

	void addCamera(Camera* c);
	void removeCamera(Camera* c);

};

#endif
