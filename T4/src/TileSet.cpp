/*
 * TileSet.cpp
 *
 *  Created on: 23/03/2018
 *      Author: carloslinux
 */
#include "../include/TileSet.h"

TileSet::TileSet(GameObject& associated,int tileWidth, int tileHeight, string file): tileWidth(tileWidth), tileHeight(tileHeight)
{
	tileSet = new Sprite(associated,file);
	//TileSet::tileHeight = tileHeight;
	//TileSet::tileWidth = tileWidth;
	//tileSet.Open(file);
	//printf("Construtor Tileset W:%dH:%d\n",tileWidth,tileHeight);
	if(tileSet->IsOpen()){
		rows = tileSet->GetHeight()/tileHeight;
		columns = tileSet->GetWidth()/tileWidth;
	}
}

void TileSet::RenderTile(unsigned index, float x, float y){
	//printf("(x:%.1f,y:%.1f)(W:%d,H:%d)\n",x,y,tileWidth,tileHeight);
	if(index<=(unsigned)(rows*columns - 1)){//Index unsigned é sempre maior ou igual a 0
		int nx, ny;
		nx = index%columns;
		ny = index/columns;
		tileSet->SetClip(nx*tileWidth,ny*tileHeight,tileWidth,tileHeight);
		//printf("CLIP X:%d,Y:%d\n",nx*tileWidth,ny*tileHeight);
		tileSet->Render(x,y);
	}//else
		//printf("\n");
}

int TileSet::GetTileWidth(){
	return tileWidth;
}

int TileSet::GetTileHeight(){
	return tileHeight;
}