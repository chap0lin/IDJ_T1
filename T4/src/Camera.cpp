#include "../include/Camera.h"
#include "../include/InputManager.h"

GameObject* Camera::focus= nullptr;
Vec2 Camera::pos = {0,0};
Vec2 Camera::speed = {5,5};

void Camera::Follow(GameObject* newFocus){
	focus = newFocus;
}
void Camera::Unfollow(){
	focus = nullptr;
}
void Camera::Update(float dt){
	if(focus!=nullptr){
		//possui um foco (centraliza na tela)
	}else{
		//responder ao input setar velocidade da camera de acordo com dt
		// e com as teclas pressionadas
		if(InputManager::GetInstance().IsKeyDown('w')){
			pos.y -= speed.y;
		}
		if(InputManager::GetInstance().IsKeyDown('a')){
			pos.x -= speed.x;
			//if(pos.x <0 )
			//	pos.x=0;
		}
		if(InputManager::GetInstance().IsKeyDown('s')){
			pos.y += speed.y;
			//if(pos.y <0 ) 
			//	pos.y=0;
		}
		if(InputManager::GetInstance().IsKeyDown('d')){
			pos.x += speed.x;
		}



		
	}
}