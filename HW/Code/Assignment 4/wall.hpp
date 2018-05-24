#ifndef WALL_HPP
#define WALL_HPP

#include "class_includes.hpp"
#include "insect.hpp"
using namespace std;


class Wall:public Insect{
    public:
        Wall();
        void turn(vector<vector<Insect*> > & board, int &food, int current);

};
#endif