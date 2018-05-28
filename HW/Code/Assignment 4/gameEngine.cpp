#include "gameEngine.hpp"


using namespace std;

GameEngine::GameEngine(){
    this->food = 50;
}

void GameEngine::startGame(vector<vector<Insect*> > & board){
    // board[2].push_back(new Thrower);
    // board[3].push_back(new LongT);
    displayBoard(board);
    board[3].push_back(new Harvester);
    board[3].push_back(new Bee);
    board[3].push_back(new Bee);
    
    displayBoard(board);
    board[3][0]->turn(board, food, 2);
    removeDead(board);
    board[3][1]->turn(board, food, 3);
    removeDead(board);
    board[3][2]->turn(board, food, 3);
    removeDead(board);

    displayBoard(board);
    cout << "tyep " << board[3][0]->get_type() << endl;


    // board[4].push_back(new LongT);
    // board[5].push_back(new ShortT);
    // board[6].push_back(new Wall);
    // board[9].push_back(new Ninja);
    // board[9].push_back(new Bodyguard);
    // board[9].push_back(new Bee);
    // cout << "Size " << board[2].size() << endl;
    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);

	// board[1][2]->turn(board, this->food, 1);

    // cout << "health 3 " <<  board[3][0]->get_armor() << endl;
    // cout << "health 4 " <<  board[4][0]->get_armor() << endl;

    // cout << "health 5 " <<  board[5][0]->get_armor() << endl;

    // cout << "health 4 " <<  board[3][0]->get_armor() << endl;
    // cout << "health 4 " <<  board[3][1]->get_armor() << endl;
    // cout << "health 4 " <<  board[3][2]->get_armor() << endl;


    // cout << endl << endl;
    // cout << "health 3 " <<  board[3][1]->get_armor() << endl;
    // cout << "health 4 " <<  board[4][0]->get_armor() << endl;
    // cout << "health 5 " <<  board[5][0]->get_armor() << endl;
    // cout << "health 6 " <<  board[6][0]->get_armor() << endl;
    // cout << "health 4 " <<  board[7][0]->get_armor() << endl;

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

void GameEngine::Turn(vector<vector<Insect*> > & board){
    for(int i =0; i < board.size(); i++)[
        for(int j = 0; j < board[i].size(); j++){
            board[i][j]->turn(board, food, i);

        }
    ]
}

void GameEngine::removeDead(vector<vector<Insect*> > & board){
    for(int i =0; i < board.size(); i++){
        for(int j =0; j < board[i].size(); j++)
            if(board[i][j]->get_armor() <= 0){
                board[i].erase(board[i].begin()+j);
                removeDead(board);
            }
    }
}
string PrintEntity(vector<vector<Insect*> > & board, int y, int x){
    const string red("\033[0;31m");
    const string green("\033[0;32m");
    const string reset("\033[0m");
    string temp = "";
    if(board[x][y]->get_type() == BEE){ 
        if(board[x][y]->get_armor() == 3)
            temp =  green + "B" + reset;
        else if(board[x][y]->get_armor() == 2)
            temp =  "B" ;
        else if(board[x][y]->get_armor() == 1)
            temp =  red + "B" + reset;
    }

    else if(board[x][y]->get_type() == BODYGUARD){ 
        if(board[x][y]->get_armor() == 2)
            temp =  green + "G" + reset;
        else
            temp =  red + "G" + reset;
    }

    else if(board[x][y]->get_type() == FIRE){ 
        if(board[x][y]->get_armor() == 1)
            temp =  red + "F" + reset;
    }

    else if(board[x][y]->get_type() == HARVESTER){ 
         if(board[x][y]->get_armor() == 1)
            temp =  red + "H" + reset;
        else   
            temp = " ";
    }

    else if(board[x][y]->get_type() == LONG){ 

         if(board[x][y]->get_armor() == 1)
            temp =  red + "L" + reset;
    }

    else if(board[x][y]->get_type() == SHORT){ 
         if(board[x][y]->get_armor() == 1)
            temp =  red + "S" + reset;
    }
    else if(board[x][y]->get_type() == THROWER){ 
         if(board[x][y]->get_armor() == 1)
            temp =  red + "T" + reset;
    }
    else if(board[x][y]->get_type() == WALL){ 
        if(board[x][y]->get_armor() == 4)
            temp =  green + "W" + reset;
        else if(board[x][y]->get_armor() == 1)
            temp =  red + "W" + reset;
        else
            temp = "W";
    }
    else if(board[x][y]->get_type() == NINJA){ 
         if(board[x][y]->get_armor() == 1)
            temp =  green + "N" + reset;
    }

    else
        temp = " ";
    return temp;
}

void GameEngine::displayBoard(vector < vector <Insect*> > & vec){
    // system("clear");
    const string red("\033[0;31m");
    const string green("\033[0;32m");
    const string reset("\033[0m");
    int VEC_SIZE = 10;
    int temp = 0;
    cout << "Health:\nFull: \033[42m \033[0m Intermediat: \033[47m \033[0m One Left: \033[41m \033[0m" << endl;
    for (int i = 0; i < vec.size(); i++){
        if (vec[i].size() > temp){
            temp = vec[i].size();
        }
        else{
            continue;
        }
    }
    for (int i = 0 ; i < VEC_SIZE; i++){
        cout << "   " << i  << "  ";
    }
    cout << endl;
    for (int j = 0; j < temp; j++){
        for (int i = 0; i < VEC_SIZE; i++){
            if ( j < vec[i].size()){
                if(i == VEC_SIZE - 1){
                    cout << "|  " << PrintEntity(vec, j, i) << "  |";
                }
                else{
                    cout << "|  " << PrintEntity(vec, j, i)  << "  ";
                }
            }
            else {
                if(i == VEC_SIZE - 1){
                    cout << "|  " << " " << "  |";
                }
                else{
                    cout << "|  " << " " << "  ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

