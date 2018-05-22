#include "driver.hpp"
using namespace std;

int main(){
	GameEngine game;

	vector<vector<Insect*> > board(10);

	board[1].resize(2);	
	game.start_game(board);
	return 0;
}
