#include "gameEngine.hpp"


using namespace std;

GameEngine::GameEngine(){
    this->food = 50;
}

void GameEngine::userChoice(vector<vector<Insect*> > & board, int & food){
    string input = "";
    int choice = 0;
    int position = 0;

    while(true){
        input = "";
        choice = 0;
        position = 0;
        cout << "Would you like to place an ant?(Y/N) ";
        
        getline(cin, input);
        if(input == "killall"){
            cout << "Cheat activated" << endl;
            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[i].size(); j++){
                    if(board[i][j]->get_type() == BEE){
                        board[i][j]->set_armor(0);
                    }
                }
            }
            cout << "Place ant? Y/N" << endl;
            getline(cin, input);
        }

        if(input == "y" || input == "Y"){
            cout << "Would you like to place a: " << endl;
            cout << "\t1. Harverster" << endl;
            cout << "\t2. Thrower" << endl;
            cout << "\t3. Fire" << endl;
            cout << "\t4. Long Thrower" << endl;
            cout << "\t5. Short Thrower" << endl;
            cout << "\t6. Wall" << endl;
            cout << "\t7. Ninja" << endl;
            cout << "\t8. Bodyguard" << endl;
            cout << "\t0. None" << endl;
        }
        else
            break;

        getline(cin, input);
        choice = atoi(input.c_str());

        if(choice <1 || choice >8){
            return;
        }

        int temp_food = food;
        switch(choice){
            case 1: temp_food -= 2; break;
            case 2: temp_food -= 4; break;
            case 3: temp_food -= 4; break;
            case 4: temp_food -= 3; break;
            case 5: temp_food -= 3; break;
            case 6: temp_food -= 4; break;
            case 7: temp_food -= 6; break;
            case 8: temp_food -= 4; break;

        }
        
        if(food<0){
            cout << "You don't have enough food! " << endl;
            continue;
        }

        food = temp_food;

        cout << "Which position would you like to place it on? ";
        getline(cin, input);
        position = atoi(input.c_str());
        bool body_pres = false;
        int ant_present = 0;    
            for(int j =0; j < board[position].size(); j++){
                if(board[position][j]->get_type() == BEE ){
                }
                else if(board[position][j]->get_type() == BODYGUARD){
                ant_present++;
                body_pres = true;
                }
                else 
                    ant_present++;
            }
        if((ant_present == 1 && body_pres)|| ant_present == 0 || (ant_present == 1 && choice ==8)){
            switch(choice){
                case 1: board[position].push_back(new Harvester); break;
                case 2: board[position].push_back(new Thrower); break;
                case 3: board[position].push_back(new Fire); break;
                case 4: board[position].push_back(new LongT); break;
                case 5: board[position].push_back(new ShortT); break;
                case 6: board[position].push_back(new Wall); break;
                case 7: board[position].push_back(new Ninja); break;
                case 8: board[position].push_back(new Bodyguard); break;

            }
            break;
        }
        else
            cout << "You can't double stack " << endl;

    }

}

void GameEngine::countBees(vector<vector<Insect*> > & board, int & num_bees){
    num_bees = 0;
    for(int i =0; i < board.size(); i++){
        for(int j =0; j < board[i].size(); j++)
            if(board[i][j]->get_type() == BEE){
                num_bees++;
            }
    }
}

void GameEngine::fireDeath(vector<vector<Insect*> > & board){
    for(int i =0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j]->get_type() == FIRE)
                board[i][j]->turn(board, food, i);

        }
    }
}

bool GameEngine::checkBeeWin(vector<vector<Insect*> > & board){
    for(int i = 0; i < board[0].size(); i++)
        if(board[0][i]->get_type() == BEE)
            return true;
    
    return false;
}

bool GameEngine::playerWin(int num_bees){
    if(num_bees <= 0)
        return true;

    return false;
}


void GameEngine::startGame(vector<vector<Insect*> > & board){
    int num_bees = 1;
    bool win = false;
    bool lost = false;

    while(!win && !lost){
        board[9].push_back(new Bee);

        displayBoard(board, food);
        userChoice(board, food);
        turn(board);
        fireDeath(board);        
        removeDead(board);
        countBees(board, num_bees);


        lost = checkBeeWin(board);
        win = playerWin(num_bees);

        for(int j = 0; j < board[6].size(); j++)
            cout << "Health " << board[6][j]->get_armor() << endl;
    }

    if(lost){
        displayBoard(board, food);
        cout << "The bees have reached your queen! You have lost! " << endl;
    }

    if(win){
        displayBoard(board, food);
        cout << "Congratulations! You have killed all the bees! " << endl;
    }

    // board[2].push_back(new Thrower);
    // board[3].push_back(new LongT);
    // displayBoard(board);
    // board[3].push_back(new Harvester);
    // board[3].push_back(new Harvester);
    // board[3].push_back(new Bee);
    // board[3].push_back(new Bee);
    
    // board[5].push_back(new Harvester);
    // board[5].push_back(new Bee);

    // turn(board);
    // removeDead(board);
    
    // board[3][0]->turn(board, food, 2);
    // removeDead(board);
    // board[3][1]->turn(board, food, 3);
    // removeDead(board);
    // board[3][2]->turn(board, food, 3);
    // removeDead(board);

    // displayBoard(board);


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

void GameEngine::turn(vector<vector<Insect*> > & board){
    for(int i =0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            board[i][j]->turn(board, food, i);

        }
    }
}
void GameEngine::removeDead(vector<vector<Insect*> > & board){
    for(int i =0; i < board.size(); i++){
        for(int j =0; j < board[i].size(); j++)
            if(board[i][j]->get_armor() <= 0){
                cout << "Im cleaning !" << endl;
                board[i].erase(board[i].begin()+j);
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
        else
            temp =  green + "F" + reset;
    }

    else if(board[x][y]->get_type() == HARVESTER){ 
         if(board[x][y]->get_armor() == 1)
            temp =  red + "H" + reset;
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

void GameEngine::displayBoard(vector < vector <Insect*> > & vec, int food){
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

    cout << "Food: " << food << endl;
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