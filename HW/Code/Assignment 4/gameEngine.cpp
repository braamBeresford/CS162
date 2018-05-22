#include "gameEngine.hpp"
using namespace std;

GameEngine::GameEngine(){
    this->food = 50;
}

void GameEngine::start_game(vector<vector<Insect*> > & board){
    board[2].push_back(new Bee);
    board[2].push_back(new Bee);
    board[3].push_back(new Bee);
    // cout << "Size " << board[2].size() << endl;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

	// board[1][2]->turn(board, this->food, 1);


    // cout << "Size " << v.size() << endl;

    // delete [] board[2][0];
    v.erase(1);
    // cout << "Size " << v.size() << endl;

}