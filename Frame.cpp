#include <iostream>
#include "Frame.hpp"



void Frame::drawObjects(int key)
{
    // call draw functions of all the objects here
    for (int i =0 ; i<shooters.size() ; i++) // iterates through the list/vector of pigeons
    {
        shooters[i]->draw();
        shooters[i]->fly(key);
    }
    for (int i =0 ; i<bullets.size() ; i++) // iterates through the list/vector of pigeons
    {
        bullets[i]->draw();
        bullets[i]->fly();
        if (bullets[i]->getLocation() < 100)
        {
            bullets.erase(bullets.begin()+i);
            delete bullets[i];
        }
    }
}

void Frame::createObject(int x, int y)
{
    shooters.push_back(new Shooter(x,y));
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
}

void Frame::shootytime()
{
    bullets.push_back(new Bullet(shooters[0]->getLocox(),shooters[0]->getLocoy()));
}

Frame::~Frame()
{
    for (int i =0; i<shooters.size(); i++)
    {
        delete shooters[i];
    }
    for (int i = 0; i<bullets.size();i++)
    {
        delete bullets[i];
    }
    bullets.clear();
    shooters.clear();
}