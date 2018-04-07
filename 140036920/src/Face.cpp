/*
 * Face.cpp
 *
 *  Created on: 04/04/2018
 *      Author: carloslinux
 */
#include "../include/Face.h"
#include "SDL2/SDL_mixer.h"
using std::string;
#include "../include/Sound.h"
#include "../include/GameObject.h"
#include "SDL2/SDL.h"

Face::Face(GameObject& associated):Component(associated){
	hitpoints = 30;
}
void Face::Damage(int damage){
	hitpoints = hitpoints - damage;
	printf("Vida:%d\n",hitpoints);
	if(hitpoints <= 0){
		Sound* s = dynamic_cast<Sound*>(associated.GetComponent("Sound"));
		s->Play(1);
		//SDL_Delay(2000);
		//s->Stop();
		/*Mix_Playing(associated.GetComponent("Sound"))*/
		associated.RequestDelete();
	}
}
void Face::Update(float dt){

}
void Face::Render(){

}
bool Face::Is(string type){
	if(type == "Face"){
		return true;
	}else{
		return false;
	}
}
