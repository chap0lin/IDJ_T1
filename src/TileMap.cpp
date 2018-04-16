#include "../include/TileMap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

TileMap::TileMap(GameObject& associated, string file, TileSet* tileSet):Component(associated),tileSet(tileSet){
	//printf("Construtor Tilemap\n");
	//printf("W:%d,H:%d\n",tileSet->GetTileWidth(),tileSet->GetTileHeight());
	//tileSet = new TileSet(associated,file,tileSet);
	//tileSet->Load(file);//vai dar erro aqui
	Load(file);
	//tileSet.SetTileSet(tileSet);
}

void TileMap::Load(string file){
	FILE *p= fopen(file.c_str(), "r");
	fscanf(p, "%d,%d,%d,", &mapWidth, &mapHeight, &mapDepth);
	int total= mapWidth*mapHeight*mapDepth;
	tileMatrix.resize(total);//assim ele não desperdiça memória nem muda de tamanho no for abaixo
	int aux;
	for(int count=0; count < total; count++){
		fscanf(p, " %d,", &aux);
		tileMatrix[count]= aux-1;
	}

	fclose(p);
	/*for(int count=0; count < total; count++){
		printf("%d,",tileMatrix[count]);

	}*/
	/*FILE *p;
	p = fopen(file.c_str(),"r");
	if(p == NULL){
		printf("Erro ao abrir o tilemap.txt\n");
		exit(34);
	}
	printf("Abriu o arquivo txt\n");
	fscanf(p,"%d,",&mapWidth);
	fscanf(p,"%d,",&mapHeight);
	fscanf(p,"%d,",&mapDepth);
	int i,j,k, leitor;
	printf("MW:%d, MH:%d,MD:%d\n",mapWidth,mapHeight,mapDepth);
	string aux;
	//std::getline (p,aux,',');
	//mapWidth = atoi(aux.c_str());

	while(getline(p,aux,',')){
		tileMatrix.push_back(atoi(aux.c_str())-1);
	}
	for(auto it = tileMatrix.begin();it!=tileMatrix.end();it++){
		printf("%d,",tileMatrix[it-tileMatrix.begin()]);
	}*/

	/*for(k=0;k<mapDepth;k++){
		for(i=0;i<mapHeight;i++){
			for(j=0;j<mapWidth;j++){
				fscanf(p,"%d,",&leitor);
				printf("%d,",leitor);
				tileMatrix[i*mapWidth+j+k*mapWidth*mapHeight] = leitor - 1;
			}
			if(k != mapDepth-1)
				fscanf(p,"\n");
		}
		if(k != mapDepth-1)
			fscanf(p,"\n");
	}*/
	
	//fclose(p);
	//printf("Terminou o Load\n");
}

void TileMap::SetTileSet(TileSet *tileSet){
	this->tileSet = tileSet;
}

int& TileMap::At(int x, int y, int z){
	//printf("index:%d - ",tileMatrix[z*mapHeight*mapWidth + y*mapWidth + x]);
	return ((int&)tileMatrix[z*mapHeight*mapWidth + y*mapWidth + x]);
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
	int x,y;
	/*printf("\n");
	for(int i = layer*mapHeight*mapWidth;i<mapHeight*mapWidth*(layer+1);i++){
		y = i%mapWidth;//compensar layer
		x = i/mapWidth;//compensar layer
		tileSet->RenderTile(At(x,y,layer),x*tileSet->GetTileWidth(), y*tileSet->GetTileHeight());
	}*/
	for(y=0; y < mapHeight; y++){
		for(x=0; x < mapWidth; x++){
			if(At(x, y, layer)!=-1)
				tileSet->RenderTile(At(x, y, layer), x*tileSet->GetTileWidth(), y*tileSet->GetTileHeight());
		}
	}
}

void TileMap::Render(){
	/*int index = (associated.box.y/tileSet->GetTileHeight())*mapWidth + associated.box.x/tileSet->GetTileWidth();
	tileSet->RenderTile(,associated.box.x,associated.box.y);*/
	//printf("MP:%d\n",mapDepth);
	for(int count =0; count < mapDepth; count++)
	{
		RenderLayer(count, 0, 0);
	}
}

int TileMap::GetWidth(){
	return mapWidth;
}
int TileMap::GetHeight(){
	return mapHeight;
}
int TileMap::GetDepth(){
	return mapDepth;
}
bool TileMap::Is(string type){
	if(type == "TileMap"){
		return true;
	}else{
		return false;
	}
}
void TileMap::Update(float dt){

}