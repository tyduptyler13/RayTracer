/*
 * Camera.cpp
 *
 *  Created on: Oct 4, 2013
 *      Author: Tyler
 */

#include "Camera.hpp"
#include "RayCaster.hpp"
#include "Ray.hpp"
#include "Scene.hpp"

#include <cmath>

#define direction rotation

Projector Camera::getProjector(size_t x, size_t y, size_t width, size_t height) const{

	double nx = (2 * x / width) - 1;
	double ny = (2 * y / height) - 1;

	//New camera coordinate system.
	Vector3 right = direction.cross(up);

	Vector3 point = right * nx + up * ny;

	double dist = point.length(); //Adjusted near.

	//Similar Triangles.
	double depth = (dist / near) * far; //Adjusted far.

	//Normalize point. No need to call normalize as
	//it will call length again.
	Ray ray(position, point /= dist);

	Projector p(ray, dist, depth);

	return p;

}

void Camera::render(MonoImage& distance, ColorImage& color, const Scene& scene,
		std::size_t width, std::size_t height, unsigned recursion) const{

	Color defaultColor = Color();

	#pragma omp parallel for
	for (std::size_t x = 0; x < width; ++x){

		for (std::size_t y = 0; y < height; ++y){

			Projector p = getProjector(x, y, width, height);

			RayCaster rc;

			std::vector<Intersect> intersections = rc.cast(scene.getObjects(), p, recursion);

			if (intersections.size() == 0){
				distance.set(x, y, 0); //Default black.
				color.set(x, y, defaultColor); //Default as default Color(black).
				continue;
			}

			Intersect nearest = intersections[0];

			distance.set(x, y, nearest.distance / (p.far - p.near)); //Normalized distance value.
			color.set(x, y, nearest.color); //Use this for now.

			//TODO New rendering stuff. Needs shading and color.
			//This shading will be on a per object basis.

		}

	}

}
