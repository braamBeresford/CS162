#include "harvester.hpp"

using namespace std;

Harvester::Harvester(){
    this->armor = 1;
    this->food_cost = 2;
    this->attack = 0;
}

void Harvester::turn(vector<vector<Insect*> > & board, int &food, int current){
    food++;
}