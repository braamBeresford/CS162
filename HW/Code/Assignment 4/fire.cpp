#include "fire.hpp"

using namespace std;

Fire::Fire(){
    this->armor = 1;
    this->food_cost = 4;
    this->attack = 0;
    this->type = FIRE; 
}

void Fire::turn(vector<vector<Insect*> > & board, int &food, int current){
    int * counts = new int[board[current].size()];
    int iterator =0;
    if(this->armor <= 0){
        for(int i =0; i < board[current].size(); i++){
            if(board[current][i]->get_type() == BEE){
                board[current][i]->set_armor(0);
            }
        }

        for(int i =0; i < board[current].size(); i++){
            if(board[current][i]->get_type() == BEE){
                counts[iterator++]=i;
            }
        }
    }
    
    for(int i =0; i < iterator; i++){
        board[current].erase(board[current].begin()+counts[i]);
    }

    delete [] counts;
}