#include "gameEngine.hpp"


using namespace std;

GameEngine::GameEngine(){
    this->food = 50;
}

void GameEngine::start_game(vector<vector<Insect*> > & board){
    board[2].push_back(new Bee);
    board[2].push_back(new Fire);
    board[2].push_back(new Bee);
    board[2].push_back(new Bee);
    board[2].push_back(new Bee);
    board[2].push_back(new Bee);
    board[2].push_back(new Bee);
    // cout << "Size " << board[2].size() << endl;

    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);

	// board[1][2]->turn(board, this->food, 1);

    cout << "health " <<  board[2][1]->get_armor() << endl;
    cout << "Size " << board[2].size() << endl;



    board[2][1]->set_armor(0);
    cout << "health " <<  board[2][1]->get_armor() << endl;

    board[2][1]->turn(board, food, 2);

    // cout << "health " <<  board[2][0]->get_armor() << endl;
    // cout << "health2 " << board[2][1]->get_armor() << endl;
    // cout << "Health3 " << board[2][2]->get_armor() << endl;
    cout << "Size2 " << board[2].size() << endl;
    // delete [] board[2][0];
    // board[2].erase(board[2].begin());

}