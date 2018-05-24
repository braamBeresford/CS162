#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP
#include "class_includes.hpp"
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
        void start_game(vector<vector<Insect*> > & board);
    
};


#endif