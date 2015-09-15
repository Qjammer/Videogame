#include "myvector.hpp"
#include "objects.hpp"
#include "render.hpp"
#include <iostream>

const double Pi= 3.14159265358979323846f;
const double E = 2.71828182845904523536f;


int main(){
	myBoolBox bbox;
	bbox.east=false;
	bbox.west=false;
	bbox.north=false;
	bbox.south=false;
	std::cout<<bbox.dir()<<std::endl;
	std::unique_ptr<myWindow> wndw(new myWindow);
	std::shared_ptr<myMovableObject> a(new myMovableObject);
	std::shared_ptr<myMovableObject> b(new myMovableObject);
	a->setTex("../Sprites/Chars/Jacob.png");
	b->setTex("../Sprites/Chars/Kung.png");
	a->updateSpriteTex();
	b->updateSpriteTex();
	a->sprite.setScale(5,5);
	wndw->rWindow->setKeyRepeatEnabled(false);

	myObjectHandler::movableObjects.push_back(std::shared_ptr<myMovableObject>(a));
	myObjectHandler::movableObjects.push_back(std::shared_ptr<myMovableObject>(b));
	while(wndw->rWindow->isOpen()){
		sf::Event event;
		while(wndw->rWindow->pollEvent(event)){
			switch(event.type){
				case sf::Event::KeyPressed:
				std::cout<<event.key.code<<std::endl;
					if(event.key.code==sf::Keyboard::Key::A){
						a->moving.west=true;
					} else if(event.key.code==sf::Keyboard::Key::D){
						a->moving.east=true;
					} else if(event.key.code==sf::Keyboard::Key::W){
						a->moving.north=true;
					} else if(event.key.code==sf::Keyboard::Key::S){
						a->moving.south=true;
					}
					//event.key;
					break;
				case sf::Event::KeyReleased:
					if(event.key.code==sf::Keyboard::Key::A){
						a->moving.west=false;
					} else if(event.key.code==sf::Keyboard::Key::D){
						a->moving.east=false;
					} else if(event.key.code==sf::Keyboard::Key::W){
						a->moving.north=false;
					} else if(event.key.code==sf::Keyboard::Key::S){
						a->moving.south=false;
					}
				case sf::Event::Resized:
					break;
				case sf::Event::Closed:
					wndw->rWindow->close();
					break;
				default:
					break;
			}
		}
		a->move();
		//a->move(myVector(0.707,0.707));
		b->move(myVector(0,1));
		a->updateSpritePos(wndw->rWindow.get());
		b->updateSpritePos(wndw->rWindow.get());
		wndw->fillQueue();
		wndw->rWindow->clear(sf::Color(128,128,128));
		wndw->drawQueue();
		wndw->rWindow->display();
		
	}

}