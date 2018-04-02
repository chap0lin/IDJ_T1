/*
 * Music.h
 *
 *  Created on: 29/03/2018
 *      Author: carloslinux
 */

#ifndef MUSIC_H_
#define MUSIC_H_
using namespace std;
#include <string>
#include "SDL_mixer.h"

class Music{
public:
	Music();
	Music(string file);
	~Music();
	void Play(int times = -1);
	void Stop(int msToStop = 1500);
	void Open(string file);
	bool IsOpen();
private:
	Mix_Music* music;
};



#endif /* MUSIC_H_ */
