#include "business.hpp"

using namespace std;

Business::Business(){
    this->value = ((rand()%200)+400)*100;
    this->num_tenants = (rand()%5)+1;
    this->tenants =  new Tenant[this->num_tenants];
    for(int i = 0; i < this->num_tenants; i++){
        this->tenants[i] = Tenant(PERSON);
    }
}

int Business::get_num_tenants() const{
    return this->num_tenants;
}

Tenant Business::get_tenant(int index) const{
    return tenants[index];
}



