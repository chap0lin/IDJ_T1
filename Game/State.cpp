/*
 * State.cpp
 *
 *  Created on: 23/03/2018
 *      Author: carloslinux
 */
#include "State.h"

State::State(){
	quitRequested = false;

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



