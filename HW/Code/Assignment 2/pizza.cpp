#include "pizza.hpp"
/*********************************************************************
 ** Program Filename:  pizza.cpp
 ** Author: Braam Beresford
 ** Date: 5th of May 2018
 ** Description: Pizza implementation
 ** Input: User
 ** Output: 
 *********************************************************************/


/*********************************************************************
 ** Function: Constructor
 ** Description: Creates and initializes the object
 ** Parameters:  
 ** Pre-Conditions: 
 ** Post-Conditions: 
 *********************************************************************/
Pizza::Pizza() {
	name = "N/A";
	ID = -1;
	small_cost = -1;
	medium_cost = -1;
	large_cost = -1;
	num_ingredients = -1;
	ingredients = NULL;
}


Pizza::~Pizza(){
	if (this->ingredients != NULL) 
		delete[] this->ingredients;
}

Pizza::Pizza(const Pizza& pie) {
	this->name = pie.name;
	this->ID = pie.ID;
	this->small_cost = pie.small_cost;
	this->medium_cost = pie.medium_cost;
	this->large_cost = pie.large_cost;
	this->num_ingredients = pie.num_ingredients;
	if (num_ingredients == 0)
		ingredients = NULL;
	else {
		for (int i = 0; i <this-> num_ingredients; i++) {
			this->ingredients[i] = pie.ingredients[i];
		}
	}
};


Pizza & Pizza::operator=(const Pizza & pie) {
	this->name = pie.name;
	this->ID = pie.ID;
	this->small_cost = pie.small_cost;
	this->medium_cost = pie.medium_cost;
	this->large_cost = pie.large_cost;
	this->num_ingredients = pie.num_ingredients;
	if (ingredients != NULL)
		delete [] ingredients;
	
	this->ingredients = new string [this->num_ingredients];
	if (num_ingredients == 0)
		ingredients = NULL;
	else {
		for (int i = 0; i < num_ingredients; i++) {
			this->ingredients[i] = pie.ingredients[i];
		}
	}

	return *this;
}

// int main() {


//Accesors
string Pizza::get_name() const {return name; }
string Pizza::get_name_without_underscores() const {
	string temp = name;
	for(int i =0; i < temp.length(); i++)
		if(temp[i] == '_')
			temp[i] = ' ';

	return temp;
}
int Pizza::get_small_cost() const {return small_cost;}
int Pizza::get_medium_cost() const {return medium_cost; }
int Pizza::get_large_cost() const {return large_cost;}
int Pizza::get_num_ingredients() const {return num_ingredients;}
string * Pizza::get_ingredients() const{ 
	
	// std::cout << num_ingredients << std::endl;
	string* temp = new string[num_ingredients];
	for(int i =0; i < num_ingredients; i++){
		temp[i] = ingredients[i];
	}
	return temp;
}


//Mutators
void Pizza::set_name(string new_name)  { name = new_name;}
void Pizza::set_small_cost(int cost) { small_cost = cost;}
void Pizza::set_medium_cost(int cost) { medium_cost = cost;}
void Pizza::set_large_cost(int cost) { large_cost = cost; }
void Pizza::set_num_ingredients(int num) { num_ingredients = num;}


/*********************************************************************
 ** Function: create_ingredients
 ** Description: Creates the ingredients array
 ** Parameters: Access to private variables
 ** Pre-Conditions: Access to private variables
 ** Post-Conditions: ingredients array of num_ingrients long
 *********************************************************************/
void Pizza::create_ingredients_arr(int num_ingredients) {
	ingredients = new string [num_ingredients];
}

void Pizza::fill_ingredients_arr(int num, string temp[]){
	for(int i =0; i < num; i++){
		ingredients[i] = temp[i];
	}
}


