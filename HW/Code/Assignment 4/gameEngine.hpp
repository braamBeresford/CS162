#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP
#include "class_includes.hpp"
#include "stdio.h"
#include "insect.hpp"
#include "thrower.hpp"
#include "bee.hpp"
#include "longT.hpp"
#include "shortT.hpp"
#include "fire.hpp"
#include "wall.hpp"



using namespace std;

class GameEngine{
    protected:
        int food;
    public:
        GameEngine();
        void startGame(vector<vector<Insect*> > & board);
        void printBoard(vector<vector<Insect*> > & board);
};


#endif