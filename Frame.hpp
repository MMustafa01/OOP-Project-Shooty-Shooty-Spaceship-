#include <SDL.h>
#include "spaceship.hpp"
#include "bullet.hpp"
#include "enemy1.hpp"
#include <vector>
#include <list>
using namespace std;

class Frame
{

    // Right now we're creating one pigeon,
    //  In the solution you have to create vectors of pigeons, eggs, and nests
public:
    spaceship the_actual_spaceship = spaceship();
    vector<Bullet *> bullets;
    vector<Enemy *> enemy1;
    bool has_the_spaceship_spawned = 0;

public:
    void drawObjects(int);
    void createObject(int, int);
    void createObject();
    void shootytime();

    void collison();

    ~Frame();
};