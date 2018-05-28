#ifndef THROWER_HPP
#define THROWER_HPP

#include "class_includes.hpp"
#include "insect.hpp"
using namespace std;


class Thrower:public Insect{
    public:
        Thrower();
        void turn(vector<vector<Insect*> > & board, int &food, int current);
};
#endif