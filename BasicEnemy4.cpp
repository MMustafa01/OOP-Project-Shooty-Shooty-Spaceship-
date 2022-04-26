#include "BasicEnemy4.hpp"
#include <iostream>
using namespace std;

BasicEnemy4::BasicEnemy4() : Enemy("BasicEnemy4") {}

void BasicEnemy4::fly()
{
    moverRect.y += 9;
}