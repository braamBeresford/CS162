#include "bee.hpp"

using namespace std;

Bee::Bee(){
    this->armor = 3;
    this->food_cost = 0;
    this->attack = 1;
    this->type = BEE;
}


void Bee::turn(vector<vector<Insect*> > & board, int &food, int current){
    bool move = true;
    bool attacked = false;

    for(int i =0; i < board[current].size() && attacked == false; i++){
        if(board[current][i]->get_type()== NINJA || board[current][i]->get_type()== BEE || board[current][i]->get_armor() <= 0)
            continue;
        cout << "I'm attacking" << endl;
        board[current][i]->change_armor(-1);
        attacked = true;
        move = false;
    }

    if(move == true){
         for(int i =0; i < board[current].size(); i++){
             
             if(board[current][i]->get_type() == BEE){
                 cout << "i'm moving"<<endl;
                board[current-1].push_back(board[current][i]);
                board[current].erase(board[current].begin()+i);
                break;
             }
         }
    }
}