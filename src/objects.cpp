#include "objects.hpp"

bool compare_height(const std::shared_ptr<myObject>& ptr1, const std::shared_ptr<myObject>& ptr2){
	if(ptr1->height<ptr2->height){
		return true;//returns true if the object is lower
	}
	return false;
}
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

std::list<std::shared_ptr<myObject>> myObjectHandler::Objects;
std::list<std::shared_ptr<myObject>> myObjectHandler::backgroundObjects;
std::list<std::shared_ptr<myObject>> myObjectHandler::unmovableObjects;
std::list<std::shared_ptr<myMovableObject>> myObjectHandler::movableObjects;
std::list<std::shared_ptr<myNPC>> myObjectHandler::NPCs;
std::list<std::shared_ptr<myPlayer>> myObjectHandler::players;

template<typename PTR>
void myObjectHandler::addObject(const PTR& ptr){
	myObjectHandler::Objects.push_back(std::shared_ptr<myObject>(ptr));
	myObjectHandler::Objects.sort(compare_height);
}
template<typename PTR>
void myObjectHandler::removeObject(const PTR& ptr){
	myObjectHandler::Objects.remove(std::shared_ptr<myObject>(ptr));
}


void myObjectHandler::addBackgroundObject(const std::shared_ptr<myObject>& ptr){
	myObjectHandler::backgroundObjects.push_back(ptr);
	myObjectHandler::addObject(ptr);
}
void myObjectHandler::removeBackgroundObject(const std::shared_ptr<myObject>& ptr){
	myObjectHandler::backgroundObjects.remove(ptr);
	myObjectHandler::removeObject(ptr);
}

void myObjectHandler::addUnmovableObject(const std::shared_ptr<myObject>& ptr){
	myObjectHandler::unmovableObjects.push_back(ptr);
	myObjectHandler::addObject(ptr);
}
void myObjectHandler::removeUnmovableObject(const std::shared_ptr<myObject>& ptr){
	myObjectHandler::unmovableObjects.remove(ptr);
	myObjectHandler::removeObject(ptr);
}

void myObjectHandler::addMovableObject(const std::shared_ptr<myMovableObject>& ptr){
	myObjectHandler::movableObjects.push_back(ptr);
	myObjectHandler::addObject(ptr);
}
void myObjectHandler::removeMovableObject(const std::shared_ptr<myMovableObject>& ptr){
	myObjectHandler::movableObjects.remove(ptr);
	myObjectHandler::removeObject(ptr);
}

void myObjectHandler::addNPC(const std::shared_ptr<myNPC>& ptr){
	myObjectHandler::NPCs.push_back(ptr);
	myObjectHandler::addObject(ptr);
}
void myObjectHandler::removeNPC(const std::shared_ptr<myNPC>& ptr){
	myObjectHandler::NPCs.remove(ptr);
	myObjectHandler::removeObject(ptr);
}

void myObjectHandler::addPlayer(const std::shared_ptr<myPlayer>& ptr){
	myObjectHandler::players.push_back(ptr);
	myObjectHandler::addObject(ptr);
}
void myObjectHandler::removePlayer(const std::shared_ptr<myPlayer>& ptr){
	myObjectHandler::players.remove(ptr);
	myObjectHandler::removeObject(ptr);
}

myInvItem::myInvItem() : ID(0), mod(0), amount(0){}

myInventory::myInventory(const int _slots){
	this->slots=_slots;
	this->items= std::vector<myInvItem>(_slots);
}
