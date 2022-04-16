#include <iostream>
#include "Frame.hpp"



void Frame::drawObjects(int key)
{
    // call draw functions of all the objects here
    for (int i =0 ; i<spaceships.size() ; i++) // iterates through the list/vector of spaceships
    {
        spaceships[i]->draw();
        spaceships[i]->fly(key);
    }
    for (int i =0 ; i<bullets.size() ; i++) // iterates through the list/vector of pigeons
    {
        bullets[i]->draw();
        bullets[i]->fly();
        if (bullets[i]->getLocation() < 100)
        {
            delete bullets[i];
            bullets.erase(bullets.begin()+i);
        }
    }
}
/*Frame.createObject creates spaceship*/
void Frame::createObject(int x, int y)
{
    spaceships.push_back(new spaceship(x,y)); //Multiple spaceship problem traced till here. There is no need for a spaceship vector
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
}

void Frame::shootytime()
{
    bullets.push_back(new Bullet(spaceships[0]->getLocox(),spaceships[0]->getLocoy()));
}

Frame::~Frame()
{
    for (int i =0; i<spaceships.size(); i++)
    {
        delete spaceships[i];
    }
    for (int i = 0; i<bullets.size();i++)
    {
        delete bullets[i];
    }
    bullets.clear();
    spaceships.clear();
}