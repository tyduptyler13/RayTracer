/*
 * Box.hpp
 *
 *  Created on: Nov 13, 2013
 *      Author: tydup13
 */

#ifndef BOX_HPP_
#define BOX_HPP_

#include <limits>

//Some tools
class Box{

	static const double inf = std::numeric_limits<double>::infinity();

public:
	Vector3 min, max;

	/**
	 * Setup to miss until really created.
	 * Also allows for points to be added.
	 */
	Box(){
		min.set(inf, inf, inf);
		max.set(-inf, -inf, -inf);
	}

	Box(const Vector3& min, const Vector3& max) : min(min), max(max){}

	Box(Box& b){
		min = b.min;
		max = b.max;
	}

	Box& set(const Vector3& min, const Vector3& max){
		this->min = min;
		this->max = max;
		return *this;
	}

	Box& addPoint(const Vector3& point){
		if ( point.x < min.x ) {

			min.x = point.x;

		} else if ( point.x > max.x ) {

			max.x = point.x;

		}

		if ( point.y < min.y ) {

			min.y = point.y;

		} else if ( point.y > max.y ) {

			max.y = point.y;

		}

		if ( point.z < min.z ) {

			min.z = point.z;

		} else if ( point.z > max.z ) {

			max.z = point.z;

		}

		return *this;
	}

	Vector3 center() const{
		return (min + max) / 2;
	}

	Vector3 size() const{
		return max - min;
	}

	bool containsPoint(const Vector3& point) const{
		if ( point.x < min.x || point.x > max.x ||
			point.y < min.y || point.y > max.y ||
			point.z < min.z || point.z > max.z ) {

			return false;

		}

		return true;
	}

	Box& makeEmpty(){

		min.x = min.y = min.z = inf;
		max.x = max.y = max.z = -inf;

		return *this;

	}

	bool empty(){
		return ( max.x < min.x ) || ( max.y < min.y ) || ( max.z < min.z );
	}

	bool operator==(const Box& b) const{
		return ((max == b.max) && (min == b.min));
	}

	Box& operator=(const Box& b){
		min = b.min;
		max = b.max;
		return *this;
	}


};


#endif /* BOX_HPP_ */
