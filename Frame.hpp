#include<SDL.h>
#include "shooter.hpp"
#include "bullet.hpp"
#include<vector>
#include<list>
using namespace std;

class Frame{

    //Right now we're creating one pigeon, 
    // In the solution you have to create vectors of pigeons, eggs, and nests    

    vector<Shooter*> shooters;
    vector<Bullet*> bullets;

    public:
    void drawObjects(int); 
    void createObject(int, int);
    void shootytime();
    ~Frame();
};