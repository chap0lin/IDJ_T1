/*
 * Camera.h
 *
 *  Created on: 30/04/2018
 *      Author: carloslinux
 */
#ifndef CAMERA_H_
#define CAMERA_H_
#include "Vec2.h"
#include "GameObject.h"

class Camera{
public:
	static void Follow(GameObject* newFocus);
	static void Unfollow();
	static void Update(float dt);
	static Vec2 pos;
	static Vec2 speed;
private:
	static GameObject* focus;
};
#endif /* CAMERA_H_ */