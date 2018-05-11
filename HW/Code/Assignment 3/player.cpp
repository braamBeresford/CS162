#include "player.hpp"

using namespace std;


Player::Player(){
    cout << "What is your name? \n";
    cin >> this->name;

    this->balance = 500000;
    this->num_properties = 9;
    this->num_owned = 0;
}

Player::Player(const Player& copy){
    this->name = copy.name;
    this->balance = copy.balance;
    this->num_properties =  copy.num_properties;
    this->num_owned = copy.num_owned;
}


Player& Player::operator=(const Player& copy){
    this->name = copy.name;
    this->balance = copy.balance;
    this->num_properties =  copy.num_properties;
    this->num_owned = copy.num_owned;
}
//Getters
string Player::get_name() const{return this->name;}

int Player::get_balance() const{return this->balance;}

int Player::get_num_properties() const{return this->num_properties;}

int Player::get_num_owned() const{return this->num_owned;}


//Setters

void Player::set_name(string name){this->name = name;}
void Player::set_balance(int bal){this->balance = bal;}

void Player::change_balace(int change){this->balance += change;}

void Player::change_num_owned(int change){this->num_owned += change;}
