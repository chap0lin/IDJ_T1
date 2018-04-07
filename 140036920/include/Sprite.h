/*
 * Sprite.h
 *
 *  Created on: 28/03/2018
 *      Author: carloslinux
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include <string>
#include "Rect.h"
#include "Component.h"

using std::string;

class Sprite:public Component{
public:
	Sprite(GameObject& associated);
	Sprite(GameObject& associated, string file);
	~Sprite();
	void Open(string file);
	void SetClip(int x, int y, int w, int h);
	void Render();
	int GetWidth();
	int GetHeight();
	void Update(float dt);
	bool IsOpen();
	bool Is(string type);
private:
	SDL_Texture* texture;
	int width;
	int height;
	SDL_Rect clipRect;
};



#endif /* SPRITE_H_ */
