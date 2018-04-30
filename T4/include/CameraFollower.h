/*
 * CameraFollower.h
 *
 *  Created on: 30/04/2018
 *      Author: carloslinux
 */
#ifndef CAMERAFOLLOWER_H_
#define CAMERAFOLLOWER_H_
#include <string>
#include "Component.h"
#include "GameObject.h"

class CameraFollower:public Component{
public:
	CameraFollower(GameObject& go);
	void Update(float dt);
	void Render();
	bool Is(std::string type);
};
#endif /* CAMERAFOLLOWER_H_ */