#include "bee.hpp"

using namespace std;

Bee::Bee(){
    this->armor = 3;
    this->food_cost = 0;
    this->attack = 1;
    this->type = BEE;
}


void Bee::turn(vector<vector<Insect*> > & board, int &food, int current){
    return;
}