/*
 * Camera.cpp
 *
 *  Created on: Oct 4, 2013
 *      Author: Tyler
 */

#include "Camera.hpp"
#include "RayCaster.hpp"

#include <cmath>

void Camera::render(MonoImage* distance, ColorImage* color, const std::vector<Object*>* const objects,
		std::size_t width, std::size_t height, unsigned recursion){

	for (std::size_t x = 0; x < width; ++x){

		for (std::size_t y = 0; y < height; ++y){

			try{

				Result r = RayCaster(x, y, objects, this, width, height, recursion).run().getResult();

				//Set distance value;
				float value = r.distance / std::abs(far - near);
				distance->set(x, y, value);

				//Set color value;
				color->set(x, y, r.color);

			} catch (int e) {
				if (e == NotFinishedError){
					std::cerr << "The Raycaster was not finished fetching the results. The program likely has an error or race condition." << std::endl;
				} else {
					throw e;
				}
			} catch (...) {
				std::cout << "A problem has occurred in the render loop! Check your Camera.render function." << std::endl;
			}

		}

	}

}
