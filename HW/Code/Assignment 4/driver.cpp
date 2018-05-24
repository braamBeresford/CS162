#include "driver.hpp"
using namespace std;

int main(){
	GameEngine game;

	vector<vector<Insect*> > board(10);

	game.startGame(board);
	// game.printBoard(board);
	return 0;		
}
