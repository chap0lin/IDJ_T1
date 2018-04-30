/*
 * Face.h
 *
 *  Created on: 04/04/2018
 *      Author: carloslinux
 */

#ifndef FACE_H_
#define FACE_H_
#include <string>
#include "Component.h"
#include "InputManager.h"

class Face:public Component{
public:
	Face(GameObject& associated);
	void Damage(int damage);
	void Update(float dt);
	void Render();
	bool Is(std::string type);
private:
	InputManager &inputManager;
	int hitpoints;
};


#endif /* FACE_H_ */
