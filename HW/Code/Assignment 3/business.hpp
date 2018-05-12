#ifndef BIZ_H
#define BIZ_H

#include "includes.hpp"
#include "tenant.hpp"
#include "property.hpp"

using namespace std;

class Business:public Property{
    private:
        Tenant * tenants;

    public:
        Business();
        ~Business();

        Tenant& get_tenant(int index); //TODO
        
        
        void remove_tenant(int index);
};



#endif