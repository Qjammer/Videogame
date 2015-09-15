#ifndef CONTROLS_H_
#define CONTROLS_H_
#include <SFML/Graphics.hpp>
#include <unordered_map>

class myKeyPress{
public:
	sf::Event::KeyEvent keyEvent;
	bool pressed;
	myKeyPress(const sf::Event::KeyEvent&,bool);
};

class basicControls{
	myKeyPress up;
	myKeyPress down;
	myKeyPress left;
	myKeyPress right;
	myKeyPress attack;
	myKeyPress action;
};

class myAction{
	virtual void operator()();

};

class keyHandler{
	//std::unordered_map<sf::Event::KeyEvent,> map;
};


#endif