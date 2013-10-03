
#include "Scene.hpp"

Scene::Scene(){
	objects = std::vector<Sphere*>();
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
