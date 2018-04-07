/*
 * Sound.cpp
 *
 *  Created on: 04/04/2018
 *      Author: carloslinux
 */
#include "../include/Sound.h"
#include "../include/Component.h"
using std::string;

Sound::Sound(GameObject& associated):Component(associated){
	chunk = nullptr;
}
Sound::Sound(GameObject& associated, string file):Component(associated){
	chunk = nullptr;
	Open(file);
}
void Sound::Play(int times){
	//printf("Deu play no Sound!\n");
	channel = Mix_PlayChannel(-1,chunk,times);
	
}
void Sound::Stop(){
	if(chunk != nullptr){
		Mix_HaltChannel(channel);
	}
}
void Sound::Open(string file){
	if(!Mix_LoadWAV(file.c_str())){
		printf("Mix_LoadWAV: %s\n",Mix_GetError());
		exit(8);
	}
}
Sound::~Sound(){
	if(chunk !=nullptr){
		Mix_HaltChannel(channel);
	}
	Mix_FreeChunk(chunk);
}
bool Sound::Is(string type){
	if(type == "Sound"){
		return true;
	}else{
		return false;
	}
}
int Sound::getChannel(){
	return channel;
}
void Sound::Render(){

}
void Sound::Update(float dt){

}



