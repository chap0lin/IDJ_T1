/*
 * Component.h
 *
 *  Created on: 02/04/2018
 *      Author: carloslinux
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_
#include <string>
using namespace std;

class GameObject;

class Component{
public:
	Component(GameObject& associated);
	virtual ~Component();
	void virtual Update(float dt)=0;
	void virtual Render()=0;
	bool virtual Is(string type)=0;
protected:
	GameObject& associated;
};



#endif /* COMPONENT_H_ */
