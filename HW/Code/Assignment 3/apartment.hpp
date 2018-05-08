#ifndef APART_H
#define APART_H

#include "includes.hpp"
#include "tenant.hpp"
#include "property.hpp"

using namespace std;

class Apartment:public Property{
    private:
        int num_tenants;
        Tenant * tenants;

    public:
        Apartment();
        ~Apartment();

        int get_num_tenants() const;
        Tenant get_tenant(int i) const; //TODO
        
};



#endif