#include "render.hpp"

void myWindow::drawQueue(){
	while(!this->rQueue.empty()){
		this->drawSprite(*this->rQueue.front());
		this->rQueue.pop();
	}
}

void myWindow::fillQueue(){
	myObjectHandler::Objects.sort(compare_height);
	for (std::list<std::shared_ptr<myObject>>::iterator it = myObjectHandler::Objects.begin(); it!=myObjectHandler::Objects.end();it++){
		this->rQueue.push(&(*it)->sprite);
	}
}

myWindow::myWindow(){
	this->rWindow = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(600,400),"MyWindow"));
	this->rQueue = std::queue<const sf::Sprite*>();
}
