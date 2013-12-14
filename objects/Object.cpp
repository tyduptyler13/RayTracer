/*
 * Object.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: tyler
 */

#include "Object.hpp"
#include "Scene.hpp"
#include "Light.hpp"
#include "RayCaster.hpp"

#include <cmath>
#include <iostream>
#include <limits>

long Object::idCount = 0;

Color Object3D::shade(const Ray& ray, const Intersect& i, const Scene& s, unsigned recursion) const {

	const std::vector<Light*> lights = s.getLights();

	Color final = material.ambient * .2 * material.diffuse;//Ambient light.

	Vector3 v = -ray.direction;

	RayCaster rc;

	Vector3 dir, R, N;
	double ddn;

	for (const Light* l : lights){

		dir = l->getDirection(i.point);
		ddn = dir.dot(i.normal);

		if (ddn < 0){//Light is on the wrong side.
			continue;
		}

		double dist = dir.length();

		Ray r(i.point, dir.normalize());
		Projector p(r, 0, dist, this);

		//This tracks transparent shadows.
		double shadow = 1;
		for (Intersect& list : rc.cast(s.getObjects(), p)){
			shadow *= (1-list.object->material.transparency);
		}

		if (shadow == 0) continue; //Something solid is in the way. We can skip the light calculations.

		N = i.normal;

		R = 2 * (dir.dot(N)) * N - dir;//Reflection ray.

		final += shadow * l->color * material.diffuse * (dir.dot(N)); //Diffuse
		final += shadow * l->color * material.specular * std::pow((v.dot(R)), material.Ns); //Specular

	}

	//We can reuse R (reflection ray)

	//If recursion has run out, we can't calculate this. (A mirror could go on forever.)
	if (recursion-- > 0){
		//Reflectivity
		if (material.Kr > 0){
			Ray r(i.point, R);
			Projector p(r, 0, std::numeric_limits<double>::infinity(), this);
			std::vector<Intersect> list = rc.cast(s.getObjects(), p);
			if (list.size() > 0){
				Color reflection = list[0].object->shade(r, list[0], s, recursion);
				final = reflection * material.Kr + final * (1 - material.Kr);
			}

		}

		//Refraction
		if (material.transparency < 1){

		}

	}

	//This checks for and fixes rounding errors.
	final.clamp();

	return final;

}


