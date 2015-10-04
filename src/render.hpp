#ifndef RENDER_H_
#define RENDER_H_
#include <queue>
#include <memory>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "objects.hpp"
#include "events.hpp"
class myEventHandler;

class myWindow{
public:
	myVector pos;//Center
	std::shared_ptr<sf::RenderWindow> rWindow;//Only weak_ptr's should point ot this object
	std::shared_ptr<myEventHandler> evntHandler;
	std::queue<const sf::Sprite*> rQueue;
	void drawSprite(const sf::Sprite&);
	void drawQueue();
	void fillQueue();
	void resize(unsigned int, unsigned int);
	myWindow();
};

inline void myWindow::drawSprite(const sf::Sprite& spr){
	this->rWindow->draw(spr);
}

#endif
