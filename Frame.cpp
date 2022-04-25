#include <iostream>
#include "Frame.hpp"
//#include "spaceship.hpp"

void Frame::drawObjects(int key)
{
    // call draw functions of all the objects here
    if (has_the_spaceship_spawned)
    {
        the_actual_spaceship.draw();
        the_actual_spaceship.fly(key);
    }
    for (int i = 0; i < bullets.size(); i++) // iterates through the list/vector of bullets
    {
        // use iterators
        bullets[i]->draw();
        bullets[i]->fly();
        if (bullets[i]->getLocation_y() < 0)
        {
            delete bullets[i];
            bullets.erase(bullets.begin() + i);
            // continue;
        }
        // for (int j = 0; j < enemy1.size(); j++) //use iterator
        // {
        //     if ((bullets[i]->getLocation_y() <= enemy1[i]->getLocation_y() + 60) & (bullets[i]->getLocation_x() <= enemy1[i]->getLocation_x() + 50) & (bullets[i]->getLocation_x() >= enemy1[i]->getLocation_x() /*- bullet width*/))
        //     {
        //         cout << "Enemy has been killed \n";
        //         // delete bullets[i];
        //         // bullets.erase(bullets.begin() + i);
        //         // delete enemy1[j];
        //         // enemy1.erase(enemy1.begin() + j);
        //         /*Very basic enemy killing logic, will be updated*/
        //     }
        // }
    }
    for (enemy_ptr = enemy1.begin(); enemy_ptr < enemy1.end(); enemy_ptr++)
    {
        (*enemy_ptr)->draw();
        (*enemy_ptr)->fly();
        int e1_loc_x = (*enemy_ptr)->getLocation_x();
        int e1_loc_y = (*enemy_ptr)->getLocation_y();
        int s1_loc_x = the_actual_spaceship.getLocation_x();
        int s1_loc_y = the_actual_spaceship.getLocation_y();

        if ((*enemy_ptr)->getLocation_y() > 600) // condition if enemy leaves screen
        {
            enemy_ptr = enemy1.erase(enemy_ptr); // this deletes the current enemy
        }
        else if (true)
        { // collision with bullet
            for (bullet_ptr = bullets.begin(); bullet_ptr < bullets.end(); bullet_ptr++)
            {
                int b_loc_x = (*bullet_ptr)->getLocation_x();
                int b_loc_y = (*bullet_ptr)->getLocation_y();
                if ((e1_loc_x >= b_loc_x - 20 & e1_loc_y >= b_loc_y - 20) & (e1_loc_x <= b_loc_x + 50 & e1_loc_y >= b_loc_y - 20))
                {
                    bullet_ptr = bullets.erase(bullet_ptr);
                    enemy_ptr = enemy1.erase(enemy_ptr);
                }
            }
        }
        if ((e1_loc_x >= s1_loc_x - 50 & e1_loc_y >= s1_loc_y - 60) & (e1_loc_x <= s1_loc_x + 50 & e1_loc_y >= s1_loc_y - 60))
        { // collision with spaceship
            enemy_ptr = enemy1.erase(enemy_ptr);
            cout << "Collsion \n";
            the_actual_spaceship.reduce_health();
            cout << "Health reduced one unit \n";
            if (the_actual_spaceship.is_dead())
            {
                cout << "Omaiwa mau shindairu \n";
            }
        }
    }
    // for (auto *enemy_pointer : enemy1)
    // {
    //     enemy_pointer->draw();
    //     enemy_pointer->fly();
    //     int e1_loc_x = enemy_pointer->getLocation_x();
    //     int e1_loc_y = enemy_pointer->getLocation_y();
    //     int s1_loc_x = the_actual_spaceship.getLocation_x();
    //     int s1_loc_y = the_actual_spaceship.getLocation_y();
    //     if (enemy_pointer->getLocation_y() > 600) // condition of if the enemy leaves the screen
    //     {
    //         delete enemy_pointer;

    //     }
    //     else if (false) // condition of enemy collides with bullet
    //     {

    //     }
    //     else if ((e1_loc_x >= s1_loc_x - 50 & e1_loc_y >= s1_loc_y - 60) & (e1_loc_x <= s1_loc_x + 50 & e1_loc_y >= s1_loc_y - 60))
    //     { // condition of enemy collides with spaceship
    //         delete enemy_pointer;
    //         cout<<"Collsion \n";
    //         the_actual_spaceship.reduce_health();
    //         cout << "Health reduced one unit \n";
    //         if (the_actual_spaceship.is_dead())
    //         {
    //             cout << "Omaiwa mau shindairu \n";
    //         }
    //         cout <<"temp" ;
    //     }
    //     cout<<"temp2";
    // }
    // cout <<"temp3";
    // enemy_pointer.clear();
    // for (int i = 0; i < enemy1.size(); i++) // iterates through the list/vector of Enemies
    // {
    //     enemy1[i]->draw();
    //     enemy1[i]->fly();
    //     if (enemy1[i]->getLocation_y() > 600)
    //     {
    //         delete enemy1[i];
    //         enemy1.erase(enemy1.begin() + i);

    //         cout << "enenmy has been deleted" << endl;
    //         //  need to write collide logic here
    //     }

    //     int e1_loc_x = enemy1[i]->getLocation_x();
    //     int e1_loc_y = enemy1[i]->getLocation_y();
    //     int s1_loc_x = the_actual_spaceship.getLocation_x();
    //     int s1_loc_y = the_actual_spaceship.getLocation_y();
    //     if ((e1_loc_x >= s1_loc_x - 50 & e1_loc_y >= s1_loc_y - 60) & (e1_loc_x <= s1_loc_x + 50 & e1_loc_y >= s1_loc_y - 60))
    //     {
    //         delete enemy1[i];
    //         enemy1.erase(enemy1.begin() + i);
    //         cout << "There has been a collision \n";
    //         the_actual_spaceship.reduce_health();
    //         cout << "Health reduced one unit \n";
    //         if (the_actual_spaceship.is_dead()) // not working properly check again
    //         {
    //             cout << "Omaiwa mau shindairu \n";
    //         }
    //     }
    // }
}
/*Frame.createObject creates spaceship*/
void Frame::createObject(int x, int y)
{
    // if (1) // supposed to be if clicked on the start button then summon the spaceship
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
    for (int i = 0; i < enemy1.size(); i++)
    {
        delete enemy1[i];
    }
    bullets.clear();
    enemy1.clear();
}

void Frame::resets_health()
{
    the_actual_spaceship.reset_health();
}
