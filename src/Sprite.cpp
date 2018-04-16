/*
 * Sprite.cpp
 *
 *  Created on: 28/03/2018
 *      Author: carloslinux
 */

#include "../include/Sprite.h"
#include "../include/Game.h"
#include "../include/GameObject.h"
#include "../include/Resources.h"

Sprite::Sprite(GameObject& associated):Component(associated){
	texture = nullptr;
}
Sprite::Sprite(GameObject& associated, string file):Component(associated){
	texture = nullptr;
	Open(file);
}
Sprite::~Sprite(){
	/*if(IsOpen())
		SDL_DestroyTexture(texture);*/
}
void Sprite::Open(string file){
	//printf("Chamou o open!\n");
	/*if(IsOpen())
		SDL_DestroyTexture(texture);*/
	//texture = IMG_LoadTexture(Game::GetInstance()->GetRenderer(), file.c_str());
	texture = Game::GetInstance()->GetState().recursos.GetImage(file);
	//printf("Voltou proOpen\n");
	if(texture == nullptr){
		printf("Erro texture = nullptr - %s\n", SDL_GetError());
		exit(7);
	}
	if(SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) ==-1){
		printf("Textura invalida!\n");
	}
	//printf("W:%d, H:%d\n",width, height);
	associated.box.w = width;
	associated.box.h = height;
	SetClip(0,0,width,height);
}
void Sprite::SetClip(int x, int y, int w, int h){
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}
void Sprite::Render(){
	Render(associated.box.x,associated.box.y);
	//printf("DestR:X[%.1f]Y[%.f]W[%.1f]H[%.1f]\n",DestR.x,DestR.y,DestR.w,DestR.h);
	//printf("ClipRect:X[%.1f]Y[%.f]W[%.1f]H[%.1f]\n",clipRect.x,clipRect.y,clipRect.w,clipRect.h);
	
}
void Sprite::Render(float x, float y){
	SDL_Rect DestR;
	DestR.x = x;
	DestR.y = y;
	DestR.w = clipRect.w;//width;
	DestR.h = clipRect.h;//height;
	//printf("(x:%.1f,y:%.1f)Clip(x:%d,y:%d)\n",x,y,clipRect.x,clipRect.y);
	if(SDL_RenderCopy(Game::GetInstance()->GetRenderer(), texture, &clipRect, &DestR)!=0){
		printf("Erro render = 0 - %s\n", SDL_GetError());
		exit(8);
	}
}

int Sprite::GetHeight(){
	return clipRect.h;
}
int Sprite::GetWidth(){
	return clipRect.w;
}


bool Sprite::IsOpen(){
	if(texture!=nullptr)
		return true;
	else
		return false;
}
bool Sprite::Is(string type){
	if(type == "Sprite"){
		return true;
	}else{
		return false;
	}
}
void Sprite::Update(float dt){

}
