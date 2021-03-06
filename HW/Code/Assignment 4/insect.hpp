#ifndef INSECT_HPP
#define INSECT_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Insect{
    protected:
        int armor;
        int attack;
        int food_cost;
        int type;

    public:
        Insect();
        // virtual ~Insect(){};
        // Insect(const Insect&);
        Insect & operator=(const Insect &);
        virtual void turn(vector<vector<Insect*> > & board, int &food, int current)=0;

        //Getters
        int get_armor() const;
        int get_attack() const;
        int get_food_cost() const;
        int get_type() const;


        //Setters

        void set_armor(int a);
        void set_attack(int a);
        void set_food_cost(int f);
        virtual void change_armor(int a);

};

#endif