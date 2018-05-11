#include "apartment.hpp"

using namespace std;

Apartment::Apartment(){
    this->value = ((rand()%300)+300)*100;
    this->num_tenants = (rand()%7)+4;
    this->tenants =  new Tenant[this->num_tenants];
    for(int i = 0; i < this->num_tenants; i++){
        this->tenants[i] = Tenant(PERSON);
    }
    this->type = APART;
}

Apartment::~Apartment(){
    delete [] tenants;
}

Tenant& Apartment::get_tenant(int index){
    return (tenants[index]);
}

