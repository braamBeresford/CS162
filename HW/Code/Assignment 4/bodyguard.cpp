#include "bodyguard.hpp"

using namespace std;

Bodyguard::Bodyguard(){
    this->armor = 2;
    this->food_cost = 2;
    this->attack = 0;
    this->type = BODYGUARD;
}


void Bodyguard::turn(vector<vector<Insect*> > & board, int &food, int current){
    // I'm pretty lazy, I don't do anything
    return;
}