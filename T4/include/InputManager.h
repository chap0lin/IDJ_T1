/*
 * InputManager.h
 *
 *  Created on: 02/04/2018
 *      Author: carloslinux
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_
#define LEFT_ARROW_KEY    SDLK_LEFT
#define RIGHT_ARROW_KEY   SDLK_RIGHT
#define UP_ARROW_KEY      SDLK_UP
#define DOWN_ARROW_KEY    SDLK_DOWN
#define ESCAPE_KEY        SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT
#define ESPACE_KEY SDLK_SPACE
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <unordered_map>

//using std::unordered_map;

class InputManager{
public:
	void Update();
	bool KeyPress(int key);
	bool KeyRelease(int key);
	bool IsKeyDown(int key);

	bool MousePress(int button);
	bool MouseRelease(int button);
	bool IsMouseDown(int button);

	int GetMouseX();
	int GetMouseY();

	bool QuitRequested();

	static InputManager& GetInstance();

	InputManager();
	~InputManager();
private:
	bool mouseState[6];
	int mouseUpdate[6];

	std::unordered_map<int, bool> keyState;
	std::unordered_map<int, int> keyUpdate;

	bool quitRequested;

	int updateCounter;

	int mouseX;
	int mouseY;
};

#endif /* INPUTMANAGER_H_ */