#include "longT.hpp"

using namespace std;

LongT::LongT(){
    this->armor = 1;
    this->food_cost = 3;
    this->attack = 1;
    this->type = THROWER;
}


void LongT::turn(vector<vector<Insect*> > & board, int &food, int current){
    bool attack_complete = false;
    for(int j = 1; j < 3; j++){
        if(board[current+j].size()!= 0 ){
            for(int i =0; i < board[current+j].size(); i++){
                if(board[current+j][i]->get_type() == BEE && attack_complete == false){
                    board[current+j][i]->change_armor(-1);
                    attack_complete = true;
                }
            }
        }
    }
}