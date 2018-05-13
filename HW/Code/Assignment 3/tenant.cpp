#include "tenant.hpp"

using namespace std;

Tenant::Tenant(){
	name = "Average Joe";
	type = PERSON;
	agreeability = (rand()%5)+1;
	budget = ((((rand()%450)+1)+50) *10);
	rent = budget;
}


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

Tenant::Tenant(const Tenant& copy){
	this->name = copy.name;
	this->agreeability = copy.agreeability;
	this->budget = copy.budget;
}

Tenant& Tenant::operator=(const Tenant& copy){
	this->name = copy.name;
	this->agreeability = copy.agreeability;
	this->budget = copy.budget;

	return *this;

	
}


string Tenant::get_name() const{return this->name;}
int Tenant::get_type() const{return this->type;}
int Tenant::get_agreeability() const{return this->agreeability;}
int Tenant::get_budget() const{return this->budget;}
int Tenant::get_rent() const{ return this->rent;}


void Tenant::set_rent(int rent) { this->rent = rent;}

void Tenant::set_name(string name) {this->name = name;}
void Tenant::set_budget(int budg) {this->budget =  budg;}
