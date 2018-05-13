#include "house.hpp"

using namespace std;

House::House(){
	this->value = ((rand()%500)+100)*100;
	this->type = HOUSE;
	Tenant t(PERSON);
	this->num_tenants = 1;
}


House::~House(){
}


Tenant& House::get_tenant(int index){
	return t;
}