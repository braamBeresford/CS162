#ifndef LONGT_HPP
#define LONGT_HPP

#include "class_includes.hpp"
#include "insect.hpp"
using namespace std;


class LongT:public Insect{
    public:
        LongT();
        void turn(vector<vector<Insect*> > & board, int &food, int current);

};
#endif