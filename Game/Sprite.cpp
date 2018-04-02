/*
 * Sprite.cpp
 *
 *  Created on: 28/03/2018
 *      Author: carloslinux
 */

#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(){
	texture = nullptr;
}
Sprite::Sprite(string file){
	texture = nullptr;
	Open(file);
}
Sprite::~Sprite(){
	if(IsOpen())
		SDL_DestroyTexture(texture);
}
void Sprite::Open(string file){
	if(IsOpen())
		SDL_DestroyTexture(texture);
	texture = IMG_LoadTexture(Game::GetInstance()->GetRenderer(), file.c_str());
	if(texture == nullptr){
		FILE *p;
		p = fopen("novo.txt","w");
		fprintf(p,"%s",SDL_GetError());
		fclose(p);
		printf("Erro texture = nullptr - %s\n", SDL_GetError());
		exit(7);
	}
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}
void Sprite::SetClip(int x, int y, int w, int h){
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}
void Sprite::Render(int x, int y){
	SDL_Rect DestR;
	DestR.x=x;
	DestR.y=y;
	DestR.w=GetWidth();
	DestR.h=GetHeight();
	if(SDL_RenderCopy(Game::GetInstance()->GetRenderer(), texture, &clipRect, &DestR)!=0){
		FILE *p;
		p = fopen("novo.txt","w");
		fprintf(p,"%s",SDL_GetError());
		fclose(p);
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
