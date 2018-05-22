#include "gameEngine.hpp"
using namespace std;

GameEngine::GameEngine(){
    this->food = 50;
}

void GameEngine::start_game(vector<vector<Insect*> > & board){
    board[1][1] = new Harvester;
    board[1][2] = new Thrower; 
    board[2].push_back(new Bee);
    board[2].push_back(new Bee);
    cout << "Armor " << board[2][0]->get_armor() << endl;
        cout << "Armor " << board[2][1]->get_armor() << endl;



	board[1][2]->turn(board, this->food, 1);
    cout << "Armor " << board[2][0]->get_armor() << endl;
        cout << "Armor " << board[2][1]->get_armor() << endl;


}