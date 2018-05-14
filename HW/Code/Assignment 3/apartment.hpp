/********************************************************************* 
 ** Program Filename: apartment.hpp
 ** Author: Braam Beresford
 ** Date: 05/13/18
 ** Description: Apartment definition
 ** Input: N/A
 ** Output: Screen print
 *********************************************************************/ 
#ifndef APART_H
#define APART_H

#include "includes.hpp"
#include "tenant.hpp"
#include "property.hpp"

using namespace std;

class Apartment:public Property{
    private:
        Tenant * tenants;

    public:
        Apartment();
        ~Apartment();

        Tenant& get_tenant(int index); 
        void remove_tenant(int index);
        
};



#endif