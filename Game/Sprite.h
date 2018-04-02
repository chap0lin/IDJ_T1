/*
 * Sprite.h
 *
 *  Created on: 28/03/2018
 *      Author: carloslinux
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include <string>

using namespace std;

class Sprite{
public:
	Sprite();
	Sprite(string file);
	~Sprite();
	void Open(string file);
	void SetClip(int x, int y, int w, int h);
	void Render(int x, int y);
	int GetWidth();
	int GetHeight();
	bool IsOpen();
private:
	SDL_Texture* texture;
	int width;
	int height;
	SDL_Rect clipRect;
};



#endif /* SPRITE_H_ */
