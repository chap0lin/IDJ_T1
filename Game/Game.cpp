#include "SDL_image.h"
#include "SDL_mixer.h"
#include "Game.h"
using namespace std;
Game* Game::instance = nullptr;


Game::Game(string title, int width, int height){
	if(instance != nullptr){
		exit(1);
	}else{
		instance = this;
	}
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
	//adicionar o tratamento de erros
	Mix_Init(MIX_INIT_FLAC | MIX_INIT_OGG | MIX_INIT_MP3| MIX_INIT_MOD);
	Mix_OpenAudio( MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT , MIX_DEFAULT_CHANNELS,1024);
	Mix_AllocateChannels(8);
	//adicionar o tratamento de erros

	window = SDL_CreateWindow("Boi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);


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

		return new Game("Oi",600,400);
	}
};


