#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP
#include <stdlib.h>
#include "class_includes.hpp"
#include "stdio.h"
#include "insect.hpp"
#include "thrower.hpp"
#include "bee.hpp"
#include "longT.hpp"
#include "shortT.hpp"
#include "fire.hpp"
#include "wall.hpp"
#include "ninja.hpp"
#include "harvester.hpp"
#include "bodyguard.hpp"



using namespace std;

class GameEngine{
    protected:
        int food;
    public:
        GameEngine();
        void startGame(vector<vector<Insect*> > & );
        void displayBoard(vector<vector<Insect*> > & , int);
        void removeDead(vector<vector<Insect*> > & );
        void turn(vector<vector<Insect*> > & bord);
        void userChoice(vector<vector<Insect*> > &, int& );
        void countBees(vector<vector<Insect*> > & , int & );
        void fireDeath(vector<vector<Insect*> > & );
        bool checkBeeWin(vector<vector<Insect*> > & );
};

#endif