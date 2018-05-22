#include "fire.hpp"

using namespace std;

Fire::Fire(){
    this->armor = 1;
    this->food_cost = 4;
    this->attack = 0;
    this->type = FIRE; 
}

void Fire::turn(vector<vector<Insect*> > & board, int &food, int current){
    if(this->armor <= 0){
        for(int i =0; i < board[current].size(); i++){
            if(board[current][i]->get_type == BEE){
                board[current][i]->set_armor(0);
                delete []board[current][i];
            }
        }
    }
}