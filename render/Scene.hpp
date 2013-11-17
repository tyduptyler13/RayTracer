#ifndef SCENE_HPP__
#define SCENE_HPP__

#include <vector>
#include <string>

#include "Object.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "ImageTools.hpp"

class Scene{

	std::vector<Object3D*> objects;
	std::vector<Camera*> cameras;
	std::vector<Light*> lights;

public:

	Scene(){};
	~Scene();

	void addObject(Object3D* s);
	void removeObject(Object3D* s);

	void addCamera(Camera* c);
	void removeCamera(Camera* c);

	void addLight(Light* l);

	const std::vector<Object3D*>& getObjects() const{
		return objects;
	}

	const std::vector<Light*>& getLights() const{
		return lights;
	}

	void render(std::string name, std::size_t width, std::size_t height, unsigned recursion) const;

};

#endif
