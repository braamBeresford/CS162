#ifndef BEE_HPP
#define BEE_HPP

#include "class_includes.hpp"
using namespace std;


class Bee:public Insect{
    public:
        Bee();
        void turn(vector<vector<Insect*> > & board, int &food, int current);

};
#endif