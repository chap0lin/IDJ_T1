/*
 * State.h
 *
 *  Created on: 23/03/2018
 *      Author: carloslinux
 */

#ifndef STATE_H_
#define STATE_H_
#include "SDL2/SDL.h"
#include "Sprite.h"
#include "Music.h"
#include "TileSet.h"
#include "Resources.h"
#include <memory>
#include <vector>
using std::string;
using std::vector;
using std::unique_ptr;
class State{
public:
	State();
	~State();
	bool QuitRequested();
	void LoadAssets();
	void Update(float dt);
	void Render();
	Resources recursos;
private:
	Music music;
	TileSet *tileSet;
	bool quitRequested;
	void Input();
	void AddObject(int mouseX, int mouseY);
	vector<unique_ptr<GameObject>> objectArray;
};



#endif /* STATE_H_ */
