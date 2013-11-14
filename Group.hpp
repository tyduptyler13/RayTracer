/*
 * Group.hpp
 *
 *  Created on: Nov 13, 2013
 *      Author: tydup13
 */

#ifndef GROUP_HPP_
#define GROUP_HPP_

#include <vector>

#include "Object.hpp"
#include "Intersect.hpp"
#include "Vector3.hpp"
#include "Box.hpp"

/**
 * This class contains multiple faces that could be considered
 * a single group or object. This speeds up rendering by checking
 * basic intersection on the group first.
 */
class Group : public Object3D{

	std::vector<Object3D> children;
	Box box;

public:

	Group(){}
	Group(std::string& name) : name(name) {}

	bool containsPoint(const Vector3& point) const{
		if (box.containsPoint(point)){

			for (size_t i = 0; i < children.size(); ++i){

				if (children[i].containsPoint(point)){
					return true;
				}

			}

		}

		return false;
	}

	bool getIntersection(const Projector& p, Intersect& i) const{

		if (box.containsPoint(p.ray.closestPointToPoint(box.center()))){

			std::vector<Intersect> intersections;

			for (size_t x = 0; x < children.size(); ++x){

				if (children[x].getIntersection(p, i)){

					intersections.push_back(i);

				}

			}

			if (intersections.size() > 0){

				std::sort(intersections.begin(), intersections.end());

				i = intersections[0];

				return true;

			} else {

				return false; //No hits.

			}

		} else {

			return false;

		}

	}

};

#endif /* GROUP_HPP_ */
