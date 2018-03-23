/*
 * Game.h
 *
 *  Created on: 22/03/2018
 *      Author: carloslinux
 */
#include "SDL.h"
#include "State.h"
#include <string>
using namespace std;

class Game{
	public:
		Game(string title, int width, int height);
		~Game();
		void Run();
		SDL_Renderer *GetRenderer();
		State& GetState();
		static Game *GetInstance();
	private:
		static Game* instance;
		SDL_Window *window;
		SDL_Renderer *renderer;
		State *state;
};
