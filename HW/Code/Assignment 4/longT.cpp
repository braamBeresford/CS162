#include "longT.hpp"

using namespace std;

LongT::LongT(){
    this->armor = 1;
    this->food_cost = 3;
    this->attack = 1;
    this->type = LONG;
}


void LongT::turn(vector<vector<Insect*> > & board, int &food, int current){
    bool attack_complete = false;
    for(int j = current+4; j < board.size(); j++){ //From the four away to end of the board
        if(board[j].size()!= 0 ){
            for(int i =0; i < board[j].size(); i++){
                if(board[j][i]->get_type() == BEE && attack_complete == false && board[j][i]->get_armor() > 0){
                    board[j][i]->change_armor(-1);
                    attack_complete = true;
                }
            }
        }
    }
}