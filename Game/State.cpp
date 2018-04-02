/*
 * State.cpp
 *
 *  Created on: 23/03/2018
 *      Author: carloslinux
 */
#include "State.h"
#include "Music.h"

State::State(){
	quitRequested = false;
	bg.Open("/home/carloslinux/workspace/Game/img/ocean.jpg");
	bg.SetClip(0,0,1024,600);
	bg.Render(0,0);
	music.Open("audio/stageState.ogg");
	music.Play(1);


}

void State::LoadAssets(){

}

void State::Update(float dt){
	if( SDL_QuitRequested() == true){
		quitRequested = true;
	}
}

void State::Render(){

}

bool State::QuitRequested(){
	return quitRequested;
}



