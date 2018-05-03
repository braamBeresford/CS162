#ifndef PIZZA
#define PIZZA
/*********************************************************************
 ** Program Filename:  pizza.cpp
 ** Author: Braam Beresford
 ** Date: 5th of May 2018
 ** Description: Pizza header
 ** Input: 
 ** Output: 
 *********************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Pizza{
private:
    string name;
    int ID;
    int small_cost;
    int medium_cost;
    int large_cost;
    int num_ingredients;
    string* ingredients;

public:
    Pizza();
    ~Pizza();
    Pizza(const Pizza& pie);
    Pizza & operator=(const Pizza &);

    //Accessors
    string get_name() const;
    string get_name_without_underscores() const;

    int get_small_cost() const;
    int get_medium_cost() const;
    int get_large_cost() const;
    int get_num_ingredients() const;
    string * get_ingredients() const;


    //Mutators
    void set_name(string name);
    void set_small_cost(int cost);
    void set_medium_cost(int cost);
    void set_large_cost(int cost);
    void set_num_ingredients(int num);
    void create_ingredients_arr(int num);
    void fill_ingredients_arr(int num_ingredients, string temp[]);



};

#endif
