/********************************************************************* 
 ** Program Filename: business.hpp 
 ** Author: Braam Beresford
 ** Date: 05/13/18
 ** Description: decleration of business class
 ** Input: N/A
 ** Output: Screen print
 *********************************************************************/
#ifndef BIZ_H
#define BIZ_H

#include "includes.hpp"
#include "tenant.hpp"
#include "property.hpp"

using namespace std;

/********************************************************************* 
 ** Function: Business class
 ** Description: Handles business specific proeprties
 ** Parameters: Inherit property
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
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