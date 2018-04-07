/*
 * Sound.h
 *
 *  Created on: 04/04/2018
 *      Author: carloslinux
 */

#ifndef SOUND_H_
#define SOUND_H_
#include <string>
#include "SDL2/SDL_mixer.h"
#include "Component.h"
#include "GameObject.h"
using std::string;

class Sound:public Component{
public:
	Sound(GameObject& associated);
	Sound(GameObject& associated, string file);
	~Sound();
	void Play(int times = -1);
	void Stop();
	void Open(string file);
	bool IsOpen();
	void Update(float dt);
	void Render();
	bool Is(string type);
	int getChannel();
private:
	Mix_Chunk* chunk;
	int channel;
};



#endif /* SOUND_H_ */
