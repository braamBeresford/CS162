#include "tenant.hpp"

using namespace std;

Tenant::Tenant(){
	name = "Average Joe";
	type = PERSON;
	agreeability = (rand()%5)+1;
	budget = ((((rand()%450)+1)+50) *10);
}


Tenant::Tenant(int type){
	name = "Average Joe";
	this->type = type;
	agreeability = (rand()%5)+1;
	budget = ((((rand()%450)+1)+50) *10);
}

Tenant::Tenant(const Tenant& copy){
	this->name = copy.name;
	this->agreeability = copy.agreeability;
	this->budget = copy.budget;
}

Tenant& Tenant::operator=(const Tenant& copy){
	this->name = copy.name;
	this->agreeability = copy.agreeability;
	this->budget = copy.budget;
	
}
