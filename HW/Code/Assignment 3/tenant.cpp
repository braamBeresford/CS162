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
	this->agreeability = (rand()%5)+1;

	if(type == PERSON){
		this->budget = (((rand()%450)+50) *10);
		this->rent = this->budget;
	}
	else if(type == BUSINESS){
		this->budget = (((rand()%800)+200)*10);
		this->rent = this->budget;
	}
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
