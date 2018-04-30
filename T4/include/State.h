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
#include "TileMap.h"
#include "Resources.h"
#include "InputManager.h"
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
	TileMap *tileMap;
	GameObject *background;
	bool quitRequested;
	//void Input();
	InputManager &inputManager;
	void AddObject(int mouseX, int mouseY);
	vector<unique_ptr<GameObject>> objectArray;
};



#endif /* STATE_H_ */
