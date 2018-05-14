/********************************************************************* 
 ** Program Filename: tenant.cpp
 ** Author: Braam Beresford
 ** Date: 05/13/18
 ** Description: implementation of tenant class
 ** Input: N/A
 ** Output: Screen print
 *********************************************************************/
#include "tenant.hpp"

using namespace std;

/********************************************************************* 
 ** Function: Tenant
 ** Description: Tenant construtor
 ** Parameters:  seeded srand
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
Tenant::Tenant(){
	name = "Average Joe";
	type = PERSON;
	agreeability = (rand()%5)+1;
	budget = ((((rand()%450)+1)+50) *10);
	rent = budget;
}

/********************************************************************* 
 ** Function: tenant(type)
 ** Description: Tenant constructor that should be called
 ** 	Handles each type of peroperty
 ** Parameters: Valid type input
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
Tenant::Tenant(int type){
	
	this->type = type;
	this->agreeability = (rand()%5)+1; 

	if(type == PERSON){
		this->name = "Average Joe";
		this->budget = (((rand()%450)+50) *10);
		this->rent = (((rand()%450)+50) *10);
		while(true){
			if(this->rent < this->budget)
				break;

			this->rent = (((rand()%450)+50) *10);
		}
				
	}

	else if(type == BUSINESS){
		this->name = "Average Business";
		this->budget = (((rand()%800)+200)*10);
		this->rent = (((rand()%800)+200)*10);
		while(true){
			if(this->rent < this->budget)
				break;

			this->rent = (((rand()%800)+200)*10);
		}
	}
}

/********************************************************************* 
 ** Function: Tenant copy constructor
 ** Description: Creates deep copy of tenant
 ** Parameters:  Valid object
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
Tenant::Tenant(const Tenant& copy){
	this->name = copy.name;
	this->agreeability = copy.agreeability;
	this->budget = copy.budget;
}

/********************************************************************* 
 ** Function: Tenant operator overoad
 ** Description: Overloads assignment, allows copying
 ** Parameters:  Valid object
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
Tenant& Tenant::operator=(const Tenant& copy){
	this->name = copy.name;
	this->agreeability = copy.agreeability;
	this->budget = copy.budget;

	return *this;

	
}

/********************************************************************* 
 ** Function: Tenant getters
 ** Description: Get basic values from tenant
 ** Parameters:  Valid input
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
string Tenant::get_name() const{return this->name;}
int Tenant::get_type() const{return this->type;}
int Tenant::get_agreeability() const{return this->agreeability;}
int Tenant::get_budget() const{return this->budget;}
int Tenant::get_rent() const{ return this->rent;}

/********************************************************************* 
 ** Function: Tenant setters
 ** Description: Set rent for basic values
 ** Parameters:  Valid input
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
void Tenant::set_rent(int rent) { this->rent = rent;}
void Tenant::set_name(string name) {this->name = name;}
void Tenant::set_budget(int budg) {this->budget =  budg;}
