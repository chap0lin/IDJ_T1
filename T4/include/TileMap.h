/*
 * TileMap.h
 *
 *  Created on: 13/04/2018
 *      Author: carloslinux
 */

#ifndef TILEMAP_H_
#define TILEMEP_H_
#include <vector>
#include "TileSet.h"
#include "GameObject.h"

using std::string;
using std::vector;

class TileMap{//: public Component {
public:
	//TileMap(GameObject& associated, string file, TileSet* tileSet);
	TileMap(string file, TileSet* tileSet);
	void Load(string file);
	void SetTileSet(TileSet* tileSet);
	int& At(int x, int y, int z = 0);
	void Render(int cameraX=0, int cameraY=0);
	void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
	int GetWidth();
	int GetHeight();
	int GetDepth();
	void Update(float dt);
	bool Is(string type);
private:
	vector<int> tileMatrix;
	TileSet *tileSet;
	int ParallaxScrolling(int num, int camera, int layer);
	int mapWidth;
	int mapHeight;
	int mapDepth;
};



#endif /* TILEMAP_H_ */