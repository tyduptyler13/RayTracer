/*
 * Camera.hpp
 *
 *  Created on: Oct 4, 2013
 *      Author: Tyler
 */

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <vector>
#include <string>

#include "Object.hpp"
#include "Vector3.hpp"
#include "ImageTools.hpp"
#include "Projector.hpp"
#include "Ray.hpp"
//#include "Scene.hpp"

class Scene;

/**
 * Rotation will be treated as a unit vector instead of a
 * rotation in x, y, z. It can also be thought of as direction.
 */
class Camera : public Object{

	Projector getProjector(size_t x, size_t y, size_t width, size_t height) const;

public:

	//Data now inherited from object. Direction is rotation.
	double near;
	double far;

	Camera(const Vector3& prp,const Vector3& vpn, double near, double far) : near(near), far(far) {
		position = prp;
		rotation = vpn;
		rotation.normalize();
	}

	/**
	 * The image is expected to be already created with the correct dimensions.
	 */
	void render(MonoImage& distance, ColorImage& color, const Scene&,
			std::size_t width, std::size_t height, unsigned recursion) const;

};


#endif /* CAMERA_HPP_ */
