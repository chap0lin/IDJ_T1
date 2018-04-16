#include "../include/Resources.h"
#include "../include/Game.h"
#include <stdio.h>
using std::unordered_map;
using std::string;

std::unordered_map<string, SDL_Texture*> Resources::imageTable;
SDL_Texture* Resources::GetImage(string file){
	//printf("Chamou o GetImage\n");
	//printf("Criou o iterador\n");
	SDL_Texture* texture;
	if(imageTable.find(file) == imageTable.end()){
		//printf("Entrou no IF\n");
		texture = IMG_LoadTexture(Game::GetInstance()->GetRenderer(), file.c_str());
		//printf("Carregou a textura\n");
		if(texture == nullptr){
			printf("Erro ao carregar texture!\n");
			return nullptr;
		}else{
			imageTable[file]= texture;
			//printf("Jogou a textura no hash\n");
			return texture;
		}
	}
	return imageTable[file];
}

void Resources::ClearImages(){
	/*for(unsigned int i = 0; i < imageTable.bucket_count();i++){
		SDL_DestroyTexture(imageTable.begin()+i);
	}*/
	for(unordered_map<string, SDL_Texture*>::iterator i= imageTable.begin(); i != imageTable.end(); i++)
	{
		SDL_DestroyTexture((*i).second);
	}
	imageTable.clear();
	printf("Tudo limpo senhor!\n");
}

