/*
 * Camera.cpp
 *
 *  Created on: Oct 4, 2013
 *      Author: Tyler
 */

#include "Camera.hpp"
#include "RayCaster.hpp"

#include <cmath>

Ray Camera::getProjector(size_t x, size_t y, size_t width, size_t height) const{

	double near = -(this->near);
	double far = -(this->far);

	//Hacky temporary solution to unprojecting screen coordinates to world coordinates.
	//This only works if the camera is looking down the z axis.

	double tmpx, tmpy;
	double halfw = width / 2;
	double halfh = height / 2;
	tmpx = (-halfw + x) / halfw;//Range from -1 to 1 from the image width. (Corrected for 0 starting on the left.)
	tmpy = (halfh - y) / halfh;//Range from -1 to 1 from the image height. (Corrected for 0 starting at the top.)

	Vector3 other = Vector3(tmpx, tmpy, near);//Point the vector at the image plane where the image pixels should be.

	other.normalize();

	Ray ray = Ray(position, other);

	return ray;

}

void Camera::render(MonoImage* distance, ColorImage* color, const std::vector<Object*>& objects,
		std::size_t width, std::size_t height, unsigned recursion) const{

#pragma omp parallel for
	for (std::size_t x = 0; x < width; ++x){

		for (std::size_t y = 0; y < height; ++y){

			Ray ray = getProjector(x, y, width, height);

			RayCaster rc;

			Intersect closest;
			for (Intersect i : rc.cast(objects, ray, recursion)){
				if ((i.point.z > std::abs(near)) && (i.point.z < std::abs(far))){
					closest = i;
					break;
				}
			}

			//TODO New rendering stuff. Needs shading and color.
			//Should check for no intersect.


		}

	}

}
