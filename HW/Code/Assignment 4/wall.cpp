#include "wall.hpp"

using namespace std;

Wall::Wall(){
    this->armor = 4;
    this->food_cost = 4;
    this->attack = 0;
    this->type = WALL;
}


void Wall::turn(vector<vector<Insect*> > & board, int &food, int current){
    //I'm pretty lazy, I don't do anything

}