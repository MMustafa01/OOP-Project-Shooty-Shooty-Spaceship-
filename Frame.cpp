#include <iostream>
#include "Frame.hpp"

void Frame::drawObjects(int key)
{
    // call draw functions of all the objects here
    if (has_the_spaceship_spawned)
    {
        the_actual_spaceship.draw();
        the_actual_spaceship.fly(key);
    }
    for (int i = 0; i < bullets.size(); i++) // iterates through the list/vector of pigeons
    {
        bullets[i]->draw();
        bullets[i]->fly();
        if (bullets[i]->getLocation() < 0)
        {
            delete bullets[i];
            bullets.erase(bullets.begin() + i);
        }
    }

    for (int i = 0; i < enemy1.size(); i++) // iterates through the list/vector of pigeons
    {
        enemy1[i]->draw();
        enemy1[i]->fly();
        if (enemy1[i]->getLocation_y() > 600)
        {
            delete enemy1[i];
            enemy1.erase(enemy1.begin() + i);

            cout << "enenmy has been deleted" << endl;
            //  need to write collide logic here
        }
    }
}
/*Frame.createObject creates spaceship*/
void Frame::createObject(int x, int y)
{
    if (1) // supposed to be if clicked on the start button then summon the spaceship
    {
        has_the_spaceship_spawned = 1; // Multiple spaceship problem traced till here. There is no need for a spaceship vector
        std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    }
}

void Frame::createObject()
{
    enemy1.push_back(new Enemy());
}

void Frame::shootytime()
{
    if (has_the_spaceship_spawned)
        bullets.push_back(new Bullet(the_actual_spaceship.getLocation_x(), the_actual_spaceship.getLocation_y(), the_actual_spaceship.direction_spaceship()));
}

Frame::~Frame()
{

    for (int i = 0; i < bullets.size(); i++)
    {
        delete bullets[i];
    }
    bullets.clear();
}