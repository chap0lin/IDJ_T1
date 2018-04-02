/*
 * State.h
 *
 *  Created on: 23/03/2018
 *      Author: carloslinux
 */

#ifndef STATE_H_
#define STATE_H_
#include "SDL.h"
#include "Sprite.h"
#include "Music.h"
using namespace std;

class State{
public:
	State();
	bool QuitRequested();
	void LoadAssets();
	void Update(float dt);
	void Render();
private:
	Sprite bg;
	Music music;
	bool quitRequested;
};



#endif /* STATE_H_ */
