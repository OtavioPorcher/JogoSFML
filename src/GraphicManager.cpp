#include "..\Include\Managers\GraphicManager.h"
using namespace Managers;

#include <iostream>

GraphicManager::GraphicManager():
    window(sf::VideoMode(RES_X, RES_Y), "IntoTheWoods++"),
    view(window.getView())
{
    
}
GraphicManager* GraphicManager::getInstance()
{
    if (!instance)
    {
        instance = new GraphicManager();
        if (!instance)
        {
            std::cout << "ERROR: Failed to Allocate the GraphicManager" << std::endl;
            exit(1);
        }
    }
    return instance;
}

GraphicManager::~GraphicManager() 
{

}

void GraphicManager::render(sf::RectangleShape* body) 
{
    window.draw(*body);
}
void GraphicManager::render(sf::Text* text) 
{
    window.draw(*text);
}

void GraphicManager::display()
{
    window.display();
}

void GraphicManager::clear()
{
    window.clear();
}

const bool GraphicManager::isWindowOpen()const
{
    return window.isOpen();
}

void GraphicManager::closeWindow()
{
    window.close();
}

sf::RenderWindow* GraphicManager::getWindow()
{
    return (&window);
}

void GraphicManager::centerView(sf::Vector2f pos)
{
    view.setCenter(pos);
    window.setView(view);
}

void GraphicManager::checkStutter(float dt)
{
    if (dt > 0.3f)
    {
        std::cout << "STUTTER DETECTED" << std::endl;
    }
}

GraphicManager* GraphicManager::instance(NULL);