/*
 * Rect.h
 *
 *  Created on: 02/04/2018
 *      Author: carloslinux
 */

#ifndef RECT_H_
#define RECT_H_
#include "Vec2.h"

class Rect{
public:
	float x;
	float y;
	float w;
	float h;
	bool Contains(Vec2 point);
};



#endif /* RECT_H_ */
