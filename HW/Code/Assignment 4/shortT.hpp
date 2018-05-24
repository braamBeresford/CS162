#ifndef SHORT_HPP
#define SHORT_HPP

#include "class_includes.hpp"
#include "insect.hpp"
using namespace std;


class ShortT:public Insect{
    public:
        ShortT();
        void turn(vector<vector<Insect*> > & board, int &food, int current);

};
#endif