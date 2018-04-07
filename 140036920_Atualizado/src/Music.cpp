/*
 * Music.cpp
 *
 *  Created on: 29/03/2018
 *      Author: carloslinux
 */
#include "../include/Music.h"
#include <string>
using std::string;

Music::Music(){
	music = nullptr;
}
Music::Music(string file){
	Open(file);
}
Music::~Music(){
	Stop(40);
	Mix_FreeMusic(music);
}

void Music::Play(int times){
	Mix_PlayMusic(music, times);

}

void Music::Stop(int msToStop){
	Mix_FadeOutMusic(msToStop);
}
void Music::Open(string file){
	music = Mix_LoadMUS(file.c_str());
}
bool Music::IsOpen(){
	if(music!=nullptr){
		return true;
	}else{
		return false;
	}
}
