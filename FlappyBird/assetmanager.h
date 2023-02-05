#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>

#include <SFML/Graphics.hpp>

namespace FlappyBirdClone{
    /*!
     * \class AssetManager
     * \brief Менеджер активов
     * \details Позволяет эффективно загружать ресурсы, такие как текстуры и шрифты,
     *          которые можно повторно использовать
     */
    class AssetManager{
    public:
        AssetManager();
        ~AssetManager();
        // Загрузка текстуры
        void loadTexture(std::string name, std::string filePath);
        // Получение текстуры по ключу
        sf::Texture& getTexture(std::string name);
        // Загрузка шрифта
        void loadFont(std::string name, std::string filePath);
        // Получение шрифта по ключу
        sf::Font& getFont(std::string name);
    private:
        // Словарь текстур
        std::map<std::string, sf::Texture> mTextures;
        // Словарь шрифтов
        std::map<std::string, sf::Font> mFonts;
    };
}

#endif // ASSETMANAGER_H
