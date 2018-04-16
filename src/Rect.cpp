/*
 * Rect.cpp
 *
 *  Created on: 02/04/2018
 *      Author: carloslinux
 */

#include "../include/Rect.h"
#include <stdio.h>

bool Rect::Contains(Vec2 point){
	//printf("Px:%.1f, Py:%.1f\n",point.x,point.y);
	//printf("Alvo(x = %.1f, y = %.1f) H:%.1f W:%.1f\n",x,y,h,w);
	if(point.x>=x && point.x<=x+w && point.y>=y && point.y<=y+h ){
		return true;
	}else{
		return false;
	}
}
