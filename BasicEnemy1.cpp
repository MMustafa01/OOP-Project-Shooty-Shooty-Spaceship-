#include "BasicEnemy1.hpp"
#include <iostream>
using namespace std;

BasicEnemy1::BasicEnemy1() : Enemy("BasicEnemy1") {}

void BasicEnemy1::fly()
{
    // actually moving the enemy ship (changing moverRect
    moverRect.y += 5;
    // movement should be lke butter fly
    
    
}