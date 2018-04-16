/*
 * TileSet.h
 *
 *  Created on: 08/04/2018
 *      Author: carloslinux
 */

#ifndef TILESET_H_
#define TILESET_H_
#include "Sprite.h"
#include "GameObject.h"
using std::string;

class TileSet{
public:
	//TileSet(int tileWidth, int tileHeight, string file);
	TileSet(GameObject& associated,int tileWidth, int tileHeight, string file);
	void RenderTile(unsigned index, float x, float y);
	int GetTileWidth();
	int GetTileHeight();
private:
	Sprite *tileSet;

	int rows;
	int columns;

	int tileWidth;
	int tileHeight;
};



#endif /* TILESET_H_ */