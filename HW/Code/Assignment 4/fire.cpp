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
    int num_bees = 0;
    int iterator =0;
    bool bee_present = true;
    if(this->armor <= 0){
        for(int i =0; i < board[current].size(); i++){
            if(board[current][i]->get_type() == BEE){
                board[current][i]->set_armor(0);
            }
        }

    
    // cout << "Size -1: " << board[current].size()-1 << endl;

    while(bee_present){
        bee_present = false;
        for(int i = 0; i<board[current].size(); i++){
            if(board[current][i]->get_type() == BEE){
                bee_present = true;
                board[current].erase(board[current].begin()+i);
                break;
            }
        }
    }

    delete [] counts;
    }
}