/*
 * State.cpp
 *
 *  Created on: 23/03/2018
 *      Author: carloslinux
 */
#include "../include/State.h"
#include "../include/Music.h"
#include <string>
#include "../include/GameObject.h"
#include "../include/Sprite.h"
#include "../include/Face.h"
#include "../include/Sound.h"
#include "../include/TileSet.h"
#include "../include/TileMap.h"
#include <stdio.h>
#define PI 3.14159265
using std::string;



State::State(){
	//printf("State\n");
	quitRequested = false;
	GameObject *background = new GameObject();
	background->box.x = 0;
	background->box.y = 0;
	//printf("O Object vai de bobs!\n");
	Sprite *backgroundimg = new Sprite(*background,"assets/img/ocean.jpg");
	//printf("State - depois do background\n");
	//backgroundimg->Open();
	background->AddComponent(backgroundimg);
	music.Open("assets/audio/stageState.ogg");
	music.Play(1);
	objectArray.emplace_back(background);
	GameObject *Maptile= new GameObject();
	Maptile->box.x=0;
	Maptile->box.y=0;
	tileSet = new TileSet(*Maptile,64, 64,"assets/img/tileset.png");
	//printf("Ate aqui foi - State depois do tileset(w:%d,H:%d\n",tileSet->GetTileWidth(),tileSet->GetTileHeight());
	//TileSet *setzin = new TileSet(*Maptile,64,64,"assets/img/tileset.jpg");
	TileMap *tilezin = new TileMap(*Maptile,"assets/map/tileMap.txt",tileSet);
	//printf("Foi até depois do TileMap\n");
	Maptile->AddComponent(tilezin);
	objectArray.emplace_back(Maptile);
	/*tileSet->RenderTile(4,0,0);
	tileSet->RenderTile(3,64,0);
	tileSet->RenderTile(3,128,0);
	tileSet->RenderTile(5,196,0);
	tileSet->RenderTile(4,256,0);*/
	//tilezin->Render();




}
State::~State(){
	objectArray.clear();
	//delete setzin;
	//delete tile;
}

void State::LoadAssets(){

}

void State::Update(float dt){
	/*if( SDL_QuitRequested() == true){
		quitRequested = true;
	}*/

	/*No começo do método, chame Input(). Depois, percorra o vetor de
	GameObjects chamando o Update dos mesmos. No final, percorra o array de
	objetos testando se algum dos GameObjects morreu. Se sim, remova-a do
	array   (
	erase
	).   O   loop   de   percorrimento   do   array   precisa   usar   índices
	numéricos, já que iteradores se tornam inválidos caso um elemento seja
	adicionado ao vetor (o que vai acontecer em trabalhos futuros).
	Sendo   assim,   para   obter   o   iterador   exigido   como   argumento   de
	vector::erase
	, use o iterador de início (
	vector::begin)
	 somado à posição
	do elemento.
	*/
	Input();
	unsigned int i;
	for(i=0;i<objectArray.size();i++){
		objectArray.at(i)->Update(dt);
	}
	for(i=0;i<objectArray.size();i++){
		if(objectArray.at(i)->IsDead()){
			Sound *keepPlay = (Sound*)objectArray.at(i).get()->GetComponent("Sound");
			if(keepPlay == nullptr){
				objectArray.erase(objectArray.begin()+i);
			}else{
				if(!Mix_Playing(keepPlay->getChannel())){
					objectArray.erase(objectArray.begin()+i);
				}
			}
			//objectArray.erase(objectArray.begin()+i);
		}
	}

}

void State::Render(){
	unsigned int i;
	for(i=0;i<objectArray.size();i++){
		objectArray.at(i)->Render();
	}
}

bool State::QuitRequested(){
	return quitRequested;
}

void State::AddObject(int mouseX, int mouseY){
	GameObject *enemy = new GameObject();
	Sprite *novo = new Sprite(*enemy,"assets/img/penguinface.png");
	enemy->AddComponent(novo);
	enemy->box.x = mouseX - novo->GetWidth()/2;
	enemy->box.y = mouseY - novo->GetHeight()/2;
	Sound *musiquinha = new Sound(*enemy,"assets/audio/boom.wav");
	//musiquinha->Play(1);
	Face *cara = new Face(*enemy);
	enemy->AddComponent(musiquinha);
	enemy->AddComponent(cara);
	objectArray.emplace_back(enemy);

}


void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}

		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(go->box.Contains( {(float)mouseX, (float)mouseY} ) ) {
					printf("Deu true no contains!\n");
					Face* face = (Face*)go->GetComponent( "Face" );
					if ( nullptr != face ) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				double angle = (rand()%360)*PI/180;;
				Vec2 objPos = { (float)mouseX + (float)sin(angle)*200 ,(float)mouseY + (float)cos(angle)*200 };
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}
