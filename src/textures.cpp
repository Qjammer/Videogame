#include "textures.hpp"

bool myTextureHandler::pollTex(const std::string& addr){
	try{
		textures.at(addr);
	} catch(const std::out_of_range& oor) {
		return false;
	} catch(...){
		return false;
	}
	return true;
}

std::unordered_map<std::string,std::shared_ptr<sf::Texture>> myTextureHandler::textures;
