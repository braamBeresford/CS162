#ifndef NINJA_HPP
#define NINJA_HPP

#include "class_includes.hpp"
#include "insect.hpp"
using namespace std;


class Ninja:public Insect{
    public:
        Ninja();
        void turn(vector<vector<Insect*> > & board, int &food, int current);
        void change_armor(int a){}; //Deliberatly blank, Ninja can't take damage
};
#endif