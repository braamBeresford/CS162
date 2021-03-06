#ifndef PLAYER
#define PLAYER
#include "includes.hpp"

using namespace std;

class Player{
    private:
        string name;
        int balance;
        int num_properties;
	    int num_owned;
        

    public:
        Player();
        
        //Getters
        string get_name() const;
        int get_balance() const;
        int get_num_properties() const;
        int get_num_owned() const;

        //Setters

        void set_name(string name);
        void set_balance(int i);
        void change_balace(int i);



};




#endif