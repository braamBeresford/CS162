#include "insect.hpp"

using namespace std;


Insect::Insect(){
    this->armor = -1;
    this->attack = -1;
    this->food_cost = -1;
    this->type = -1;
}

Insect & Insect::operator=(const Insect &copy){
    this->armor = copy.armor;
    this->attack = copy.attack;
    this->food_cost = copy.food_cost;
}

int Insect::get_armor() const{return this->armor;}
int Insect::get_attack() const{return this->attack;}
int Insect::get_food_cost() const{return this->food_cost;}
int Insect::get_type() const {return this-> type;}



void Insect::set_armor(int a){this->armor = a;}
void Insect::set_attack(int a){this->attack = a;}
void Insect::set_food_cost(int f){this->food_cost = f;}
void Insect::change_armor(int c){this->armor += c;}