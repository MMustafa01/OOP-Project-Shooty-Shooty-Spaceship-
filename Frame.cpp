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
        
    }
    for (coin_ptr = coin1.begin(); coin_ptr < coin1.end(); coin_ptr++)
    {
        (*coin_ptr)->draw();
        (*coin_ptr)->fly();
        int c1_loc_x = (*coin_ptr)->getLocation_x();
        int c1_loc_y = (*coin_ptr)->getLocation_y();
        int s1_loc_x = the_actual_spaceship.getLocation_x();
        int s1_loc_y = the_actual_spaceship.getLocation_y();
        if ((*coin_ptr)->getLocation_y() > 600) // condition if enemy leaves screen
        {
            coin_ptr = coin1.erase(coin_ptr); // this deletes the current enemy
        }
        if (((c1_loc_x<= s1_loc_x + 50  & s1_loc_x + 50 <= c1_loc_x + 11) || (c1_loc_x<= s1_loc_x + 50  & c1_loc_x  <= s1_loc_x + 11)) &
                &  ((c1_loc_y <= s1_loc_y + 50  & s1_loc_y + 50 <= c1_loc_y + 11 ) || (c1_loc_y <= s1_loc_y + 50  & c1_loc_y <= s1_loc_y + 11 )))
        { // collision with spaceship
            the_actual_spaceship.increment_coins_collected();
            coin_ptr = coin1.erase(coin_ptr);
            
        }
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
                if (((b_loc_x<= e1_loc_x + 50  & e1_loc_x + 50 <= b_loc_x + 20) || (b_loc_x<= e1_loc_x + 50  & e1_loc_x  <= b_loc_x + 20)) &&  ((b_loc_y <= e1_loc_y + 50  & e1_loc_y + 50 <= b_loc_y + 20 ) || (b_loc_y <= e1_loc_y + 50  & e1_loc_y <= b_loc_y + 20 )))
                {
                    bullet_ptr = bullets.erase(bullet_ptr);
                    enemy_ptr = enemy1.erase(enemy_ptr);
                }
            }
        }
        if (((s1_loc_x<= e1_loc_x + 50  & e1_loc_x + 50 <= s1_loc_x + 20) || (s1_loc_x<= e1_loc_x + 50  & e1_loc_x  <= s1_loc_x + 20)) &&  ((s1_loc_y <= e1_loc_y + 50  & e1_loc_y + 50 <= s1_loc_y + 20 ) || (s1_loc_y <= e1_loc_y + 50  & e1_loc_y <= s1_loc_y + 20 )))
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
void Frame::createCoin()
{
    coin1.push_back(new Coin());
}

void Frame::createObject()
{
    int rand_enemy = rand() % 3;
    cout << "the rand_enemy == : " << rand_enemy << endl;
    if (rand_enemy == 0)
        enemy1.push_back(new BasicEnemy1());
    else if (rand_enemy == 1 )
        {
            enemy1.push_back(new BasicEnemy2());
            cout << " \n This is the new basic enemy can you see it??? \n";
        }
    else if (rand_enemy == 2)
    {
        enemy1.push_back(new BasicEnemy4());
    }
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
    for (int i = 0; i < coin1.size(); i++)
    {
        delete coin1[i];
    }
    bullets.clear();
    enemy1.clear();
    coin1.clear();
}


void Frame::reset()
{
    the_actual_spaceship.reset_health();
    the_actual_spaceship.reset_coins();
    for (enemy_ptr = enemy1.begin(); enemy_ptr < enemy1.end(); enemy_ptr++)
    {
        enemy_ptr = enemy1.erase(enemy_ptr);
    }
    for (bullet_ptr = bullets.begin(); bullet_ptr < bullets.end(); bullet_ptr++)
    {
        bullet_ptr = bullets.erase(bullet_ptr);
    }
    for (coin_ptr = coin1.begin(); coin_ptr < coin1.end(); coin_ptr++)
    {
        coin_ptr = coin1.erase(coin_ptr);
    }
}