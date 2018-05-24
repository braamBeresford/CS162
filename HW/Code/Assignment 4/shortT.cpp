#include "shortT.hpp"

using namespace std;

ShortT::ShortT(){
    this->armor = 1;
    this->food_cost = 3;
    this->attack = 1;
    this->type = SHORT;
}


void ShortT::turn(vector<vector<Insect*> > & board, int &food, int current){
    int max = 2; //These make sure you don't try and access over the edge of the board
    if((board.size()-1) - current < 2) //The two is for attack distance (2 sqaures)
        max = (board.size()-1) - current;
    max += current;
    

    bool attack_complete = false;
    for(int j = current+1; j <  max; j++){ 
        if(board[j].size()!= 0 ){
            for(int i =0; i < board[j].size(); i++){
                if(board[j][i]->get_type() == BEE && attack_complete == false){
                    board[j][i]->change_armor(-1);
                    attack_complete = true;
                    cout << "j: " << j << " i: " << i << endl;

                }
            }
        }
    }
}