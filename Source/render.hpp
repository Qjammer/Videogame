#ifndef RENDER_H_
#define RENDER_H_
#include <queue>
#include <memory>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "objects.hpp"

class myWindow{
public:
	myVector pos;//Top left corner
	std::unique_ptr<sf::RenderWindow> rWindow;
	std::queue<const sf::Sprite*> rQueue;
	void drawSprite(const sf::Sprite&);
	void drawQueue();
	void fillQueue();
	myWindow();

};

inline void myWindow::drawSprite(const sf::Sprite& spr){
	this->rWindow->draw(spr);
}


#endif