
#include "Scene.hpp"

Scene::Scene(){
	objects = std::vector<Sphere*>();
}

/**
 * If a scene is ever deleted, its contents will also be
 * deleted as well, including all objects!
 */
Scene::~Scene(){
	for (Sphere* s : objects){
		delete s;
	}
	objects.clear();
}

void Scene::addObject(Sphere* s){

	for (std::size_t i = 0; i < objects.size(); ++i){
		if (objects[i] == s){
			return; //Already in the list.
		}
	}

	objects.push_back(s);
}

void Scene::removeObject(Sphere* s){

	for(std::size_t i = 0; i < objects.size();++i){

		if (objects[i] == s){
			objects.erase(objects.begin()+i);
			break;
		}

	}

}
