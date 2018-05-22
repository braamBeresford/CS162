#ifndef FIRE_HPP
#define FIRE_HPP

#include "class_includes.hpp"
#include "insect.hpp"
using namespace std;


class Fire:public Insect{
    public:
        Fire();
        void turn(vector<vector<Insect*> > & board, int &food, int current);

};
#endif