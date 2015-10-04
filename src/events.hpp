#ifndef EVENTS_H_
#define EVENTS_H_

#include <memory>
class myWindow;
#include "render.hpp"

class myEventHandler {
public:
	std::weak_ptr<myWindow> wndw;

	void handleEvent(const sf::Event&);

	void keyPressed(const sf::Event&);
	void keyReleased(const sf::Event&);
	void resized(const sf::Event&);
	void closeWindow();

};

#endif