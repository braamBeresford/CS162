#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP
#include "class_includes.hpp"


using namespace std;

class GameEngine{
    protected:
        int food;
    public:
        GameEngine();
        void start_game(vector<vector<Insect*> > & board);
    
};


#endif