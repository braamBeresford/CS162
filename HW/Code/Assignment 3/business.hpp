#ifndef BIZ_H
#define BIZ_H

#include "includes.hpp"
#include "tenant.hpp"
#include "property.hpp"

using namespace std;

class Business:public Property{
    private:
        int num_tenants;
        Tenant * tenants;

    public:
        Business();
        ~Business();

        int get_num_tenants() const;
        Tenant* get_tenant(int i) const; //TODO
        
};



#endif