/********************************************************************* 
 ** Program Filename: player.cpp
 ** Author: Braam Beresford
 ** Date: 05/13/18
 ** Description: Implementation of player class
 ** Input: N/A
 ** Output: Screen print
 *********************************************************************/
#include "player.hpp"

using namespace std;

/********************************************************************* 
 ** Function: Player constructor
 ** Description: Handles initial game elemnts of the player
 ** Parameters: A name input
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
Player::Player(){
    cout << "What is your name? \n";
    getline(cin, this->name);

    this->balance = 500000;
    this->num_properties = 9;
    this->num_owned = 0;
}

/********************************************************************* 
 ** Function: Player copy constructor
 ** Description: Creates deep copy of player object
 ** Parameters:  N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
Player::Player(const Player& copy){
    this->name = copy.name;
    this->balance = copy.balance;
    this->num_properties =  copy.num_properties;
    this->num_owned = copy.num_owned;
}

/********************************************************************* 
 ** Function: Player assignment operator overload
 ** Description: Overloads assignment, similar to above
 ** Parameters:  Vlaid player object
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
Player& Player::operator=(const Player& copy){
    this->name = copy.name;
    this->balance = copy.balance;
    this->num_properties =  copy.num_properties;
    this->num_owned = copy.num_owned;

    return *this;
}

/********************************************************************* 
 ** Function: Player getters
 ** Description: Gets values for simple vars in player
 ** Parameters: Vald input calls
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
//Getters
string Player::get_name() const{return this->name;}

int Player::get_balance() const{return this->balance;}

int Player::get_num_properties() const{return this->num_properties;}

int Player::get_num_owned() const{return this->num_owned;}

/********************************************************************* 
 ** Function: Player setters
 ** Description: Sets values of most common vairables
 ** Parameters:  Valid inputs
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
//Setters
void Player::set_name(string name){this->name = name;}
void Player::set_balance(int bal){this->balance = bal;}

void Player::change_balance(int change){this->balance += change;}

void Player::change_num_owned(int change){this->num_owned += change;}
