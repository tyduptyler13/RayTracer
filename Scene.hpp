#ifndef SCENE_HPP__
#define SCENE_HPP__

#include <vector>
#include <string>

#include "Object.hpp"
#include "Camera.hpp"
#include "ImageTools.hpp"

class Scene{

	std::vector<Object3D*> objects;
	std::vector<Camera*> cameras;

public:

	Scene(){};
	~Scene();

	void addObject(Object3D* s);
	void removeObject(Object3D* s);

	void addCamera(Camera* c);
	void removeCamera(Camera* c);

	const std::vector<Object3D*>& getObjects() const{
		return objects;
	}

	void render(std::string name, std::size_t width, std::size_t height, unsigned recursion){

		for (Camera* c : cameras){

			ColorImage color = ColorImage(width, height);
			MonoImage depth = MonoImage(width, height);

			c->render(depth, color, objects, width, height, recursion);

			color.save(name + "_" + c->name + "_color.ppm");
			depth.save(name + "_" + c->name + "_depth.ppm");

		}

	}

};

#endif
