#include "tenant.hpp"

using namespace std;

Tenant::Tenant(){
	name = "Average Joe";
	type = PERSON;
	agreeability = (rand()%5)+1;
	budget = ((((rand()%450)+1)+50) *10);
}


Tenant::Tenant(int type){
	
	this->type = type;
	this->agreeability = (rand()%5)+1;

	if(type == PERSON){
		this->name = "Average Joe";
		this->budget = (((rand()%450)+50) *10);
		this->rent = this->budget;
	}
	else if(type == BUSINESS){
		this->name = "Average Business";
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


string Tenant::get_name() const{return this->name;}
int Tenant::get_type() const{return this->type;}
int Tenant::get_agreeability() const{return this->agreeability;}
int Tenant::get_budget() const{return this->budget;}
int Tenant::get_rent() const{ return this->rent;}
