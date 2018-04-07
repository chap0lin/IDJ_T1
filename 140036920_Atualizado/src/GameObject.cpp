/*
 * GameObject.cpp
 *
 *  Created on: 04/04/2018
 *      Author: carloslinux
 */
#include "../include/GameObject.h"

GameObject::GameObject(){
	isDead = false;
}
GameObject::~GameObject(){
	//percorrer o vetor e deletar de tras pra frente
	components.clear();
}
void GameObject::Update(float dt){
	//percorrer o vetor  chamando update(dt) dos mesmos
	unsigned int i;
	for(i=0;i<components.size();i++){
		components.at(i)->Update(dt);
		/*if(components.at(i).isDead == true){
			RemoveComponent(components.at(i).get());
		}*/
	}
}
void GameObject::Render(){
	unsigned int i;
	for(i=0;i<components.size();i++){
		components.at(i)->Render();
	}

}
bool GameObject::IsDead(){
	return isDead;
}
void GameObject::RequestDelete(){
	isDead = true;
}
void GameObject::AddComponent(Component* cpt){
	components.emplace_back(cpt);
}
void GameObject::RemoveComponent(Component* cpt){
	//Procura e remove cpt do vetor de componentes
	unsigned int i;
	for(i=0;i<components.size();i++){
		if(components.at(i).get() == cpt){
			components.erase(components.begin()+i);
			delete cpt;//se der um seg fault talvez seja aqui
		}
	}
}
Component* GameObject::GetComponent(string type){
	unsigned int i;
	for(i=0;i<components.size();i++){
		if(components.at(i)->Is(type))
			return components.at(i).get();
	}


	return nullptr;
}
