/********************************************************************* 
 ** Program Filename: apartment.cpp
 ** Author: Braam Beresford
 ** Date: 05/13/18
 ** Description: Implementation of apartment class
 ** Input: N/A
 ** Output: Screen print
 *********************************************************************/ 
#include "apartment.hpp"

using namespace std;

Apartment::Apartment(){
    int lowest_rent = 1000000;
    this->value = ((rand()%300)+300)*100;
    this->num_tenants = (rand()%7)+4;
    this->tenants =  new Tenant[this->num_tenants];
    for(int i = 0; i < this->num_tenants; i++){
        this->tenants[i] = Tenant(PERSON);
        if(lowest_rent > this->tenants[i].get_rent())
            lowest_rent =  this->tenants[i].get_rent();
    }

    for(int i = 0; i < this->num_tenants; i++){
        this->tenants[i].set_rent(lowest_rent);
    }
    this->type = APART;
}

Apartment::~Apartment(){
    delete [] tenants;
}

Tenant& Apartment::get_tenant(int index){
    return (tenants[index]);
}

void Apartment::remove_tenant(int index){
	Tenant * temp = new Tenant[this->num_tenants-1];
    for(int i = 0; i < num_tenants; i++){
        if(i < index){
            temp[i] = this->tenants[i];
        }
        else if(i == index){
            continue;
        }

        else if(i < index){
            temp[i-1] = this->tenants[i];
        }
    }
    this->num_tenants--;

    delete [] tenants;
    tenants = temp;
    temp = NULL;
}
