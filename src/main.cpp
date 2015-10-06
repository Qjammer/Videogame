#include <iostream>
#include "myvector.hpp"
#include "controls.hpp"
#include "objects.hpp"

#include "render.hpp"
#include "events.hpp"


//Testing
#include <ctime>
#include <cstdlib>

const double Pi= 3.14159265358979323846f;
const double E = 2.71828182845904523536f;


int main(){
	srand(time(0));

	std::shared_ptr<myWindow> wndw(new myWindow);
	wndw->evntHandler->wndw=std::weak_ptr<myWindow>(wndw);

	wndw->rWindow->setKeyRepeatEnabled(false);

	std::shared_ptr<myPlayer> a(new myPlayer);
	std::shared_ptr<myNPC> b(new myNPC);
	std::shared_ptr<myObject> map(new myObject);

	myObjectHandler::addPlayer(a);
	myObjectHandler::addNPC(b);
	myObjectHandler::addBackgroundObject(map);

	a->setTex("../Sprites/Chars/Jacob.png");
	b->setTex("../Sprites/Chars/Kung.png");
	map->setTex("../Sprites/Maps/Maptest3.png");

	a->updateSpriteTex();
	b->updateSpriteTex();
	map->updateSpriteTex();

	a->sprite.setScale(5,5);
	b->sprite.setScale(5,5);
	b->maxVel=2;
	b->pos={150.0f,150.0f};
	wndw->rWindow->setKeyRepeatEnabled(false);
	a->height=3;
	b->height=2;
	map->height=1;

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
					break;
				default:
					wndw->evntHandler->handleEvent(event);
					break;
			}
		}
		a->move();
		b->moving.east=rand()%2;
		b->moving.west=rand()%2;
		b->moving.north=rand()%2;
		b->moving.south=rand()%2;
		b->move();
		a->updateSpritePos(wndw->rWindow.get());
		b->updateSpritePos(wndw->rWindow.get());
		wndw->fillQueue();
		wndw->rWindow->clear(sf::Color(128,128,128));
		wndw->drawQueue();
		wndw->rWindow->display();
	}
}
