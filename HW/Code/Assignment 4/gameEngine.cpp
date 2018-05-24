#include "gameEngine.hpp"


using namespace std;

GameEngine::GameEngine(){
    this->food = 50;
}

void GameEngine::startGame(vector<vector<Insect*> > & board){
    board[2].push_back(new Thrower);
    board[3].push_back(new Bee);
    board[4].push_back(new Wall);
    board[5].push_back(new Bee);
    board[6].push_back(new Bee);
    board[5].push_back(new Bee);
    board[2].push_back(new Bee);
    // cout << "Size " << board[2].size() << endl;

    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);

	// board[1][2]->turn(board, this->food, 1);

    // cout << "health 3 " <<  board[3][0]->get_armor() << endl;
    // cout << "health 4 " <<  board[4][0]->get_armor() << endl;

    // cout << "health 5 " <<  board[5][0]->get_armor() << endl;
    cout << "health 4 " <<  board[4][0]->get_armor() << endl;

    // board[2][0]->turn(board, food, 2);

    // cout << "\nhealth 3 " <<  board[3][0]->get_armor() << endl;
    // cout << "health 4 " <<  board[4][0]->get_armor() << endl;

    // cout << "health 5 " <<  board[5][0]->get_armor() << endl;
    // cout << "health 2 " <<  board[2][1]->get_armor() << endl;

    // cout << "health " <<  board[2][0]->get_armor() << endl;
    // cout << "health2 " << board[2][1]->get_armor() << endl;
    // cout << "Health3 " << board[2][2]->get_armor() << endl;
    // delete [] board[2][0];
    // board[2].erase(board[2].begin());
}


void GameEngine::printBoard(vector<vector<Insect*> > & board){
    int largest_col = 0;
    int board_size = board.size();
    for(int i = 0; i < board_size; i ++){
        if(largest_col < board_size)
            largest_col = board_size;
    }
    putchar(' ');
    putchar(' ');
    for(int j = 0; j < board_size; j++){
            cout << " " << j << ' ';
    }
    // putchar('\n');
    // for(int j = 0; j < board_size; j++){
    //         cout << "_ ";
    // }
    putchar('\n');
    // putchar(' ');
    for(int i = 0; i < largest_col; i++){
        for(int j = 0; j < board_size; j++){
            cout << ' ' <<  "|" << "W";


        }
        putchar('\n');
    }

}