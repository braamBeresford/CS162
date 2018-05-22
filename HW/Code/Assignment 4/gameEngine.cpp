#include "gameEngine.hpp"
using namespace std;

GameEngine::GameEngine(){
    this->food = 50;
}

void GameEngine::start_game(vector<vector<Insect*> > & board){
    board[1][1] = new Harvester;
	board[1][1]->turn(board, this->food, 1);

}