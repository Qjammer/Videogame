#include "objects.hpp"

myVector myBoolBox::dir(){
	myVector v((int)this->east-this->west,(int)this->north-this->south);
	return v.unit();
}

void myObject::move(const myVector& v){
	this->pos+=v;
}

void myMovableObject::move(void){
	this->move(this->moving.dir()*this->maxVel);
	
}

void myObject::setPos(const myVector& v){
	this->pos=v;
}

void myObject::setTex(const std::string& addr){
	if(myTextureHandler::pollTex(addr)){
		this->tex=myTextureHandler::textures[addr];
	} else {
		this->tex=std::shared_ptr<sf::Texture>(new sf::Texture);
		this->tex->loadFromFile(addr);
		myTextureHandler::textures.emplace(addr,std::shared_ptr<sf::Texture>(this->tex));
	}
}

void myObject::updateSpriteTex(){
	this->sprite.setTexture(*(this->tex));
}

void myObject::updateSpritePos(const sf::Window* win){//TODO: Based on the world map, not screen
	this->sprite.setPosition(this->pos.x,this->pos.y);
}

std::list<std::shared_ptr<myObject>> myObjectHandler::backgroundObjects;
std::list<std::shared_ptr<myObject>> myObjectHandler::unmovableObjects;
std::list<std::shared_ptr<myMovableObject>> myObjectHandler::movableObjects;
std::list<std::shared_ptr<myNPC>> myObjectHandler::NPCs;
std::list<std::shared_ptr<myPlayer>> myObjectHandler::players;

myInvItem::myInvItem() : ID(0), mod(0), amount(0){}

myInventory::myInventory(int _slots){
	this->slots=_slots;
	this->items= std::vector<myInvItem>(_slots);
};