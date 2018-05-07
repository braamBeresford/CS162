#ifndef APART
#define APART

#include "includes.hpp"
#include "tenant.hpp"
#include "property.hpp"

using namespace std;

class Apartment{
    private:
        int num_tenants;
        Tenant * tenants;

    public:
        Apartment();
        ~Apartment();

        int get_num_tenants() const;
        Tenant get_tenants() const;
        
}



#endif