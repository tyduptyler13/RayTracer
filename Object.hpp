/*
 * Object.hpp
 *
 *  Created on: Oct 4, 2013
 *      Author: Tyler
 */

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include<string>
#include<vector>

#include "Vector3.hpp"

class Object{

public:

	std::string name;

	//For improvements later.
	/*
	std::vector<Object*> children;
	Object* parent;
	*/

	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

};



#endif /* OBJECT_HPP_ */
