#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "../include/Game.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
Game* Game::instance = nullptr;


Game::Game(string title, int width, int height){
	if(instance != nullptr){
		exit(1);
	}else{
		instance = this;
	}

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0){
		//cout << "Erro ao inicializar o SDL!\n";
	    printf("SDL_Init failed: %s\n", SDL_GetError());

		exit(1);
	}
	int flags=IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF;
	int initted=IMG_Init(flags);
	if((initted&flags) != flags) {
	    printf("IMG_Init: Failed to init required jpg and png support!\n");
	    printf("IMG_Init: %s\n", IMG_GetError());
	    exit(2);
	    // handle error
	}
	flags=MIX_INIT_FLAC|MIX_INIT_OGG|MIX_INIT_MP3;
	initted=Mix_Init(flags);
	if((initted & flags) != flags) {
	    printf("Mix_Init: Failed to init required ogg and mod support!\n");
	    printf("Mix_Init: %s\n", Mix_GetError());
	    exit(3);
	    // handle error
	}
	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT , MIX_DEFAULT_CHANNELS,1024)==-1) {
	    printf("Mix_OpenAudio: %s\n", Mix_GetError());
	    exit(4);
	}

	Mix_AllocateChannels(8);

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	if(window == nullptr){
		printf("Erro ao abrir a janela!Window\n");
		exit(5);
	}
	renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);
	if(renderer == nullptr){
		printf("Erro ao Renderizar a janela!Renderer\n");
		exit(6);
	}
	srand(time(NULL));
	state = new State();
}

Game::~Game(){
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();


}

State& Game::GetState(){
	return *state;
}

void Game::Run(){
	while(state->QuitRequested() == false){
		state->Update(0);//float dt
		state->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(33);




	}
}

SDL_Renderer *Game::GetRenderer(){
	return renderer;
}



Game* Game::GetInstance(){
	if(instance != nullptr){
		return instance;
	}else{

		return new Game("CarlosRocha140036920",1024,600);
	}
};


