#include "driver.hpp"
using namespace std;

int main(){
	GameEngine game;

	vector<vector<Insect*> > board(10);
	game.startGame(board);
	for(int i = 0; i < board.size(); i++){
		for(int j = 0; j < board[i].size(); j++){
			delete [] board[i][j];
		}
	}
	return 0;		
}
