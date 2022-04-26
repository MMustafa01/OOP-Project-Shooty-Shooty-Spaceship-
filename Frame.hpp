#pragma once
#include <SDL.h>
#include "spaceship.hpp"
#include "bullet.hpp"
#include "enemy1.hpp"
#include "BasicEnemy1.hpp"
#include "BasicEnemy2.hpp"
#include "BasicEnemy4.hpp"
#include "Coin.hpp"
#include <vector>
#include <list>
using namespace std;

class Frame
{

    
    vector<Bullet *> bullets;
    vector<Bullet *>::iterator bullet_ptr;
    vector<Enemy *> enemy1;
    vector <Coin *> coin1;
    vector <Coin *>::iterator coin_ptr;
    vector<Enemy *>::iterator enemy_ptr;
    bool has_the_spaceship_spawned = 0;

public:
    spaceship the_actual_spaceship = spaceship();
    void drawObjects(int);
    void createObject(int, int);
    void createObject();
    void createCoin();
    void shootytime();
    void reset();
    void collison();


    ~Frame();
};