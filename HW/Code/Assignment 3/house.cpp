/********************************************************************* 
 ** Program Filename: house.hpp
 ** Author: Braam Beresford
 ** Date: 05/13/18
 ** Description: Implimentation of house class
 ** Input: N/A
 ** Output: Screen print
 *********************************************************************/
#include "house.hpp"

using namespace std;

House::House(){
	this->value = ((rand()%500)+100)*100;
	this->type = HOUSE;
	Tenant t(PERSON);
	this->num_tenants = 1;
	this->t.set_rent((rand()%500) + 100);
	this->t.set_budget(t.get_rent() - (rand()%50)); // Insure budget is at or below rent
	
}


House::~House(){
}


Tenant& House::get_tenant(int index){
	return t;
}


void House::remove_tenant(int index){
	t.set_rent(0);

	this->num_tenants = 0;
	this->t.set_name("No tenant");
}