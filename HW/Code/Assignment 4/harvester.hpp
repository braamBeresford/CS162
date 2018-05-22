#ifndef HARVESTER_HPP
#define HARVESTER_HPP
#include "class_includes.hpp"
#include "insect.hpp"

using namespace std;

class Harvester:public Insect{
    public:
        Harvester();
        // ~Harvester() {};
        
        void turn(vector<vector<Insect*> > & board, int &food, int current);
};

#endif