
#include "Scene.hpp"

Scene::Scene(){
	objects = std::vector<Object*>();
	cameras = std::vector<Camera*>();
}

/**
 * If a scene is ever deleted, its contents will also be
 * deleted as well, including all objects!
 */
Scene::~Scene(){
	for (Object* o : objects){
		delete o;
	}
	objects.clear();

	for (Camera* c : cameras){
		delete c;
	}

	cameras.clear();
}

void Scene::addObject(Object* o){

	for (Object* object : objects){
		if (object == o){
			return; //Already in the list.
		}
	}

	objects.push_back(o);
}

void Scene::removeObject(Object* o){

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
