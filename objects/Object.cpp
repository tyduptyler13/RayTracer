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

long Object::idCount = 0;

Color Object3D::shade(const Ray& ray, const Intersect& i, const Scene& s) const {

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

		if (rc.cast(s.getObjects(), p, 0).size() > 0){
			continue; //An object is in the way.
		}

		N = i.normal;

		R = 2 * (dir.dot(N)) * N - dir;//Reflection ray.

		final += l->color * material.diffuse * (dir.dot(N)); //Diffuse
		final += l->color * material.specular * std::pow((v.dot(R)), 50); //Specular

	}

	if (!final.isValid()){
		//This checks for and fixes rounding errors.
		final.clamp();//Values that weren't valid were REALLY close to 0.
	}

	return final;

}


