/*
 * Resources.h
 *
 *  Created on: 13/04/2018
 *      Author: carloslinux
 */

#ifndef RESOURCES_H_
#define RESOURCES_H_
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include <unordered_map>
using std::unordered_map;
using std::string;

class Resources{
public:
	SDL_Texture* GetImage(string file);
	void ClearImages();
	Mix_Music* GetMusic(string file);
	void ClearMusivcs();
	Mix_Chunk* GetSound(string file);
	void ClearSounds();
private:
	static unordered_map<string,SDL_Texture*> imageTable;
	unordered_map<string,Mix_Music*> musicTable;
	unordered_map<string,Mix_Chunk*> soundTable;

};

#endif /* RESOURSES_H_ */
