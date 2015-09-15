#include <thread>
#include <list>
#include <mutex>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <X11/Xlib.h>
#include <iostream>

std::mutex WindowMutex;

class myObject{
	sf::Texture tex;
	sf::Sprite sprite;

};

void gameRenderTH(sf::RenderWindow* window){
	sf::Texture tex;
	tex.loadFromFile("../../Sprites/Chars/Jacob.png",sf::IntRect(1,1,16,16));
	sf::Sprite sprite;
	sprite.setTexture(tex);
	sprite.scale(sf::Vector2f(10,10));
	float pos=0;
	float step=2;
	float max=250;
	float min=0;

	while(window->isOpen()){
		if(pos>max||pos<min){
			step=-step;
		} 
		pos +=step;
		sprite.setPosition(sf::Vector2f(pos,0));
		if(WindowMutex.try_lock()){
			window->clear(sf::Color(128,128,128));
			//draw everything here
			window->draw(sprite);
			window->display();
			WindowMutex.unlock();
		}
		std::this_thread::sleep_for(std::chrono::seconds(0));
	}
}


int main(){
	XInitThreads();
	sf::RenderWindow window(sf::VideoMode(600,400),"MyWindow");

	std::thread renderThread(gameRenderTH,&window);


	while(window.isOpen()){

		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type==sf::Event::Closed){
				std::cout<<"Closed event"<<std::endl;
				WindowMutex.lock();
				window.close();
				WindowMutex.unlock();

			}
			switch(event.type){
				case sf::Event::KeyPressed:
					event.key;
					break;
				case sf::Event::Resized:
					break;
				/*case sf::Event::Closed:
					std::cout<<"Closed event"<<std::endl;
					WindowMutex.lock();
					window.close();
					WindowMutex.unlock();
					break;*/
				
				default:
					break;
			}
		}

		
	}
	renderThread.join();
	return 1;
	
}