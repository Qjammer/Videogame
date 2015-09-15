#include "render.hpp"

void myWindow::drawQueue(){
	while(!this->rQueue.empty()){
		this->drawSprite(*this->rQueue.front());
		this->rQueue.pop();
	}
}

void myWindow::fillQueue(){
	for(std::list<std::shared_ptr<myObject>>::iterator it = myObjectHandler::backgroundObjects.begin();it!=myObjectHandler::backgroundObjects.end();++it){
		this->rQueue.push(&(*it)->sprite);
	}
	for(std::list<std::shared_ptr<myObject>>::iterator it = myObjectHandler::unmovableObjects.begin();it!=myObjectHandler::unmovableObjects.end();++it){
		this->rQueue.push(&(*it)->sprite);
	}
	for(std::list<std::shared_ptr<myMovableObject>>::iterator it = myObjectHandler::movableObjects.begin();it!=myObjectHandler::movableObjects.end();++it){
		this->rQueue.push(&(*it)->sprite);
	}
	for(std::list<std::shared_ptr<myNPC>>::iterator it = myObjectHandler::NPCs.begin();it!=myObjectHandler::NPCs.end();++it){
		this->rQueue.push(&(*it)->sprite);
	}
	for(std::list<std::shared_ptr<myPlayer>>::iterator it = myObjectHandler::players.begin();it!=myObjectHandler::players.end();++it){
		this->rQueue.push(&(*it)->sprite);
	}
}

myWindow::myWindow(){
	this->rWindow = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(600,400),"MyWindow"));
	this->rQueue = std::queue<const sf::Sprite*>();
}
