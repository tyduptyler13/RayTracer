
#include "Scene.hpp"

/**
 * If a scene is ever deleted, its contents will also be
 * deleted as well, including all objects!
 */
Scene::~Scene(){
	for (Object3D* o : objects){
		delete o;
	}
	objects.clear();

	for (Camera* c : cameras){
		delete c;
	}

	cameras.clear();
}

void Scene::addObject(Object3D* o){

	for (Object* object : objects){
		if (object == o){
			return; //Already in the list.
		}
	}

	objects.push_back(o);
}

void Scene::removeObject(Object3D* o){

	for(std::size_t i = 0; i < objects.size();++i){

		if (objects[i] == o){
			delete objects[i];
			objects.erase(objects.begin()+i);
			break;
		}

	}

}

void Scene::addCamera(Camera* c){
	for (Camera* camera : cameras){
		if (camera == c){
			return; //Already in the list.
		}
	}

	cameras.push_back(c);
}

void Scene::removeCamera(Camera* c){
	for(std::size_t i = 0; i < cameras.size();++i){

		if (cameras[i] == c){
			delete cameras[i];
			cameras.erase(cameras.begin()+i);
			break;
		}

	}
}

//Nothing special to do for lights. They can exist on top of eachother.
void Scene::addLight(Light* l){
	lights.push_back(l);
}

void Scene::render(std::string name, std::size_t width, std::size_t height, unsigned recursion) const{

	for (Camera* c : cameras){

		ColorImage color = ColorImage(width, height);
		MonoImage depth = MonoImage(width, height);

		c->render(depth, color, *this, width, height, recursion);

		color.save(name + "_" + c->name + "_color.ppm");
		depth.save(name + "_" + c->name + "_depth.ppm");

	}

}
