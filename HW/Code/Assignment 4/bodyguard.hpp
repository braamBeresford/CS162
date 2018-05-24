#ifndef BODYGUARD_HPP
#define BODYGUARD_HPP

#include "class_includes.hpp"
#include "insect.hpp"
using namespace std;


class Bodyguard:public Insect{
    public:
        Bodyguard();
        void turn(vector<vector<Insect*> > & board, int &food, int current);

};
#endif