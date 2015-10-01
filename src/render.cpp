#include "render.hpp"

void myWindow::drawQueue(){
	while(!this->rQueue.empty()){
		this->drawSprite(*this->rQueue.front());
		this->rQueue.pop();
	}
}
bool compare_height(const std::shared_ptr<myObject>& ptr1, const std::shared_ptr<myObject>& ptr2){
	if(ptr1->height<ptr2->height){
		return true;
	}
	return false;
}
void myWindow::fillQueue(){
	std::list<std::shared_ptr<myObject>> rList(myObjectHandler::backgroundObjects);
	rList.insert(rList.end(),myObjectHandler::unmovableObjects.begin(),myObjectHandler::unmovableObjects.end());
	rList.insert(rList.end(),myObjectHandler::movableObjects.begin(),myObjectHandler::movableObjects.end());
	rList.insert(rList.end(),myObjectHandler::NPCs.begin(),myObjectHandler::NPCs.end());
	rList.insert(rList.end(),myObjectHandler::players.begin(),myObjectHandler::players.end());
	rList.sort(compare_height);
	for (std::list<std::shared_ptr<myObject>>::iterator it = rList.begin(); it!=rList.end();it++){
		this->rQueue.push(&(*it)->sprite);
	}
	/*for(std::list<std::shared_ptr<myObject>>::iterator it = myObjectHandler::backgroundObjects.begin();it!=myObjectHandler::backgroundObjects.end();++it){
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
	}*/
}

myWindow::myWindow(){
	this->rWindow = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(600,400),"MyWindow"));
	this->rQueue = std::queue<const sf::Sprite*>();
}
