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

void myWindow::resize(unsigned int width, unsigned int height){
	this->rWindow->setView(sf::View(sf::Vector2f((int)this->pos.x,(int)this->pos.y),sf::Vector2f(width,height)));
}

myWindow::myWindow(){
	this->rWindow = std::shared_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(600,400),"MyWindow"));
	this->rQueue = std::queue<const sf::Sprite*>();
	this->evntHandler = std::shared_ptr<myEventHandler>(new myEventHandler);
	this->pos={200,200};
	//this->evntHandler->wndw=std::shared_ptr<myWindow>(this);
}
