/*
 * RayCaster.hpp
 *
 *  Created on: Sep 30, 2013
 *      Author: tydup13
 */

#ifndef RAYCASTER_HPP_
#define RAYCASTER_HPP_

#include <vector>

#include "ImageTools.hpp"
#include "Object.hpp"
#include "Projector.hpp"

class RayCaster{

public:

	//The following will be set when its complete.

	RayCaster(){}

	std::vector<Intersect> cast(const std::vector<Object3D*>&, const Projector&) const;

};


#endif /* RAYCASTER_HPP_ */
