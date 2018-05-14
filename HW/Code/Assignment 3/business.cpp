/********************************************************************* 
 ** Program Filename: business.cpp
 ** Author: Braam Beresford
 ** Date: 05/13/18
 ** Description: implementation of business class
 ** Input: N/A
 ** Output: Screen print
 *********************************************************************/
#include "business.hpp"

using namespace std;

Business::Business(){
    int lowest_rent = 1000000;
    this->value = ((rand()%200)+400)*100;
    this->num_tenants = (rand()%5)+1;
    this->tenants =  new Tenant[this->num_tenants];
    for(int i = 0; i < this->num_tenants; i++){
        this->tenants[i] = Tenant(BUSINESS);
    }
    
    type = BIZ;
}

Business::~Business(){
    delete [] tenants;
}

Tenant& Business::get_tenant(int index){
    return (tenants[index]);
}


void Business::remove_tenant(int index){
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