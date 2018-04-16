/*
 * GameObject.h
 *
 *  Created on: 02/04/2018
 *      Author: carloslinux
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <string>
#include <vector>
#include "Component.h"
#include "Rect.h"
#include <memory>
using std::string;
using std::vector;
using std::unique_ptr;
class GameObject{
public:
	GameObject();
	~GameObject();
	void Update(float dt);
	void Render();
	bool IsDead();
	void RequestDelete();
	void AddComponent(Component* cpt);
	void RemoveComponent(Component* cpt);
	Component* GetComponent(string type);
	Rect box;
private:
	vector <unique_ptr<Component>> components;
	bool isDead;
};



#endif /* GAMEOBJECT_H_ */
