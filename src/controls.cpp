#include "controls.hpp"


myKeyPress::myKeyPress(const sf::Event::KeyEvent& _event,bool _pressed){
	this->keyEvent=_event;
	this->pressed=_pressed;
}
