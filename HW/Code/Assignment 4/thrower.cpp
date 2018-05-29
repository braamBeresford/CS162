#include "thrower.hpp"

using namespace std;

Thrower::Thrower(){
    this->armor = 1;
    this->food_cost = 4;
    this->attack = 1;
    this->type = THROWER;
}


void Thrower::turn(vector<vector<Insect*> > & board, int &food, int current){
    bool attack_complete = false;
    for(int i =0; i < board[current].size(); i++){
        if(board[current][i]->get_type() == BEE && attack_complete == false && board[current][i]->get_armor() > 0){
            board[current][i]->change_armor(-1);
            attack_complete = true;
        }
    }
}