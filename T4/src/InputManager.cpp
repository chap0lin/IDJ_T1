#include "../include/InputManager.h"

InputManager& InputManager::GetInstance(){
	static InputManager instancia;
	return instancia;
}

InputManager::InputManager():quitRequested(false), updateCounter(0), mouseX(0), mouseY(0){
	for(int i=0;i<6;i++){
		mouseState[i] = false;
		mouseUpdate[i] = 0;
	}
	//memset(mouseState, 0, 6*sizeof(bool));
	//memset(mouseUpdate, 0, 6*sizeof(int));
}
InputManager::~InputManager(){
	
}

void InputManager::Update(){
	SDL_Event event;
	//int mouseX, mouseY;
	//enum mousecode {SDL_BUTTON_LEFT,SDL_BUTTON_MIDDLE,SDL_BUTTON_RIGHT,SDL_BUTTON_X1,SDL_BUTTON_X2};
	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);
	quitRequested = false;
	updateCounter++;

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {
		if(event.key.repeat != 1){
			// Se o evento for quit, setar a flag para terminação
			if(event.type == SDL_QUIT) {
				quitRequested = true;
			}
			// Se o evento for clique...
			if(event.type == SDL_MOUSEBUTTONDOWN) {
				mouseState[event.button.button] = true;
				mouseUpdate[event.button.button] = updateCounter;
			}

			if(event.type == SDL_MOUSEBUTTONUP) {
				mouseState[event.button.button] = false;
			}

			if( event.type == SDL_KEYDOWN ) {
				keyState[event.key.keysym.sym] = true;
				keyUpdate[event.key.keysym.sym] = updateCounter;
				//keyUpdate[event.key.keysym.sym] = 
			}
			if( event.type == SDL_KEYUP){
				keyState[event.key.keysym.sym] = false;
			}
		}
	}
}

int InputManager::GetMouseX(){
	return mouseX;
}

int InputManager::GetMouseY(){
	return mouseY;
}

bool InputManager::QuitRequested(){
	return quitRequested;
}

bool InputManager::KeyPress(int key){
	if(keyUpdate[key]==updateCounter && keyState[key]==true)
		return true;
	else
		return false;
}
bool InputManager::KeyRelease(int key){
	if(keyUpdate[key]==updateCounter-1 && keyState[key]==false)
		return true;
	else
		return false;
}
bool InputManager::IsKeyDown(int key){
	if(keyState[key]==true)
		return true;
	else
		return false;
}
bool InputManager::MousePress(int button){
	if(mouseUpdate[button]==updateCounter && mouseState[button]==true)
		return true;
	else
		return false;
}
bool InputManager::MouseRelease(int button){
	if(mouseUpdate[button]==updateCounter-1 && mouseState[button]==false)
		return true;
	else
		return false;
}
bool InputManager::IsMouseDown(int button){
	if(mouseState[button]==true)
		return true;
	else
		return false;
}