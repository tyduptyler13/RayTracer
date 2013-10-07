#ifndef SCENE_HPP__
#define SCENE_HPP__

#include <vector>
#include <string>

#include "Object.hpp"
#include "Camera.hpp"
#include "ImageTools.hpp"

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

	const std::vector<Object*>& getObjects() const{
		return objects;
	}

	void render(std::string name, std::size_t width, std::size_t height, unsigned recursion){

		for (Camera* c : cameras){

			ColorImage* color = new ColorImage(width, height);
			MonoImage* depth = new MonoImage(width, height);

			c->render(depth, color, &objects, width, height, recursion);

			color->save(name + "_" + c->name + "_color.ppm");
			depth->save(name + "_" + c->name + "_depth.ppm");
		}

	}

};

#endif
