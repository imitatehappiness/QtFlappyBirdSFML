#include "assetmanager.h"

namespace FlappyBirdClone{
    AssetManager::AssetManager(){}

    AssetManager::~AssetManager(){}

    void AssetManager::loadTexture(std::string name, std::string filePath){
        sf::Texture texture;
        if(texture.loadFromFile(filePath)){
            mTextures[name] = texture;
        }
    }

    sf::Texture& AssetManager::getTexture(std::string name){
        return mTextures[name];
    }

    void AssetManager::loadFont(std::string name, std::string filePath){
        sf::Font font;
        if(font.loadFromFile(filePath)){
            mFonts[name] = font;
        }
    }

    sf::Font& AssetManager::getFont(std::string name){
        return mFonts[name];
    }
}
