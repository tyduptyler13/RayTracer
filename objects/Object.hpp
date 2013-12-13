/*
 * Object.hpp
 *
 *  Created on: Oct 4, 2013
 *      Author: Tyler
 */

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <string>

#include "Vector3.hpp"
#include "ImageTools.hpp"
#include "Intersect.hpp"
#include "Projector.hpp"

class Scene;

class Object{

	static long idCount;

	long id;

public:

	std::string name;

	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	Vector3 up = Vector3(0, 1, 0);//Default up.

	Object(){
		id = idCount++;
	}

	Object& setName(std::string name){
		this->name = name;
		return *this;
	}

	Object& setUp(Vector3& v){
		this->up = v;
		return *this;
	}

	bool operator==(const Object& o){
		return id == o.id;
	}

};

class Object3D : public Object{

protected:

	Object3D() : Object() {}

	Object3D(const Object3D& o) : Object() {
		material = o.material;
	}

	Object3D& operator=(const Object3D& o){
		material = o.material;
		return *this;
	}

public:

	virtual ~Object3D(){};

	Material material;

	virtual bool containsPoint(const Vector3& point) const = 0;
	virtual bool getIntersection(const Projector&, Intersect&) const = 0;

	Color shade(const Ray& ray, const Intersect& i, const Scene& s) const;

};



#endif /* OBJECT_HPP_ */
