#include "events.hpp"

void myEventHandler::handleEvent(const sf::Event& evnt){
	switch(evnt.type){
		case sf::Event::KeyPressed:
			break;
		case sf::Event::KeyReleased:
			break;
		case sf::Event::Resized:
			this->resized(evnt);
			break;
		case sf::Event::Closed:
			this->closeWindow();
			break;
		default:
			break;
	}
}


void myEventHandler::resized(const sf::Event& evnt){
	std::shared_ptr<myWindow>(this->wndw)->resize(evnt.size.width,evnt.size.height);
}

void myEventHandler::closeWindow(){//TODO: Save game before quit, etc...
	std::shared_ptr<myWindow>(this->wndw)->rWindow->close();
}
