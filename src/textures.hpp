#ifndef TEXTURES_H_
#define TEXTURES_H_

#include <unordered_map>
#include <memory>
#include <SFML/Graphics.hpp>

class myTextureHandler{
public:
	static std::unordered_map<std::string,std::shared_ptr<sf::Texture>> textures;
	static bool pollTex(const std::string&);
};

#endif //TEXTURES_H_
