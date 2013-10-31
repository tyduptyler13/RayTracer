/*
 * Camera.cpp
 *
 *  Created on: Oct 4, 2013
 *      Author: Tyler
 */

#include "Camera.hpp"
#include "RayCaster.hpp"
#include "Ray.hpp"

#include <cmath>

#define direction rotation

Projector Camera::getProjector(size_t x, size_t y, size_t width, size_t height) const{

	double nx = (2 * x / width) - 1;
	double ny = (2 * y / height) - 1;

	//New camera coordinate system.
	Vector3 right = direction.cross(up);

	Vector3 point = right * nx + up * ny;

	double dist = point.length();

	//Similar Triangles.
	double depth = (dist / near) * far;

	//Normalize point. No need to call normalize as
	//it will call length again.
	Ray ray(position, point /= dist);

	Projector p(ray, dist, depth);

	return p;

}

void Camera::render(MonoImage& distance, ColorImage& color, const std::vector<Object3D*>& objects,
		std::size_t width, std::size_t height, unsigned recursion) const{

#pragma omp parallel for
	for (std::size_t x = 0; x < width; ++x){

		for (std::size_t y = 0; y < height; ++y){

			Projector p = getProjector(x, y, width, height);

			RayCaster rc;

			//TODO handle result.
			rc.cast(objects, p, recursion);

			//TODO New rendering stuff. Needs shading and color.
			//Should check for no intersect.


		}

	}

}
