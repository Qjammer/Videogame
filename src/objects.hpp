#ifndef OBJECTS_H_
#define OBJECTS_H_
#include <SFML/Graphics.hpp>
#include <memory>
#include <list>
#include "myvector.hpp"
#include "textures.hpp"
//#include "render.hpp"


class myBoolBox{
public:
	bool east;
	bool west;
	bool north;
	bool south;
	myVector dir();
};

class myObject{
public:
	myBoolBox collisions;
	myVector pos={0.0f,0.0f};
	myVector size={0.0f,0.0f};
	float height;
	std::shared_ptr<sf::Texture> tex;
	sf::Sprite sprite;
	void move(const myVector&);
	void setTex(const std::string&);
	void setPos(const myVector&);
	void updateSpriteTex();
	void updateSpritePos(const sf::Window* win);
};

class myMovableObject : public myObject{
public:
	using myObject::move;
	float maxVel=5;
	myVector vel={0.0f,0.0f};
	void move(void);
	myBoolBox moving;

};

class myCharacterObject : public myMovableObject{//TODO:Health bar?
public:
	float health;
};

class myNPC : public myCharacterObject{

};

class myPlayer : public myCharacterObject{

};

class myObjectHandler{
public:
	static std::list<std::shared_ptr<myObject>> Objects;
	static std::list<std::shared_ptr<myObject>> backgroundObjects;
	static std::list<std::shared_ptr<myObject>> unmovableObjects;
	static std::list<std::shared_ptr<myMovableObject>> movableObjects;
	static std::list<std::shared_ptr<myNPC>> NPCs;
	static std::list<std::shared_ptr<myPlayer>> players;

	template<typename PTR>
	static void addObject(const PTR&);
	template<typename PTR>
	static void removeObject(const PTR&);

	static void addBackgroundObject(const std::shared_ptr<myObject>&);
	static void removeBackgroundObject(const std::shared_ptr<myObject>&);

	static void addUnmovableObject(const std::shared_ptr<myObject>&);
	static void removeUnmovableObject(const std::shared_ptr<myObject>&);

	static void addMovableObject(const std::shared_ptr<myMovableObject>&);
	static void removeMovableObject(const std::shared_ptr<myMovableObject>&);

	static void addNPC(const std::shared_ptr<myNPC>&);
	static void removeNPC(const std::shared_ptr<myNPC>&);

	static void addPlayer(const std::shared_ptr<myPlayer>&);
	static void removePlayer(const std::shared_ptr<myPlayer>&);
};

class myInvItem{
public:
	unsigned int ID;
	unsigned int mod;
	unsigned int amount;
	myInvItem();
};

class myInventory{
	std::vector<myInvItem> items;
	unsigned int slots;
	myInventory(int);
};

class myHUDObject : public myObject{

};


class HUDHandler{
	static std::list<std::shared_ptr<myHUDObject>> baseHUD;
	static std::list<std::shared_ptr<myHUDObject>> activeHUD;

};

bool compare_height(const std::shared_ptr<myObject>&, const std::shared_ptr<myObject>&);


#endif //OBJECTS_H_