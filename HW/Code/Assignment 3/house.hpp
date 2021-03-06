/********************************************************************* 
 ** Program Filename: house.hpp
 ** Author: Braam Beresford
 ** Date: 05/13/18
 ** Description: Decleration of house class
 ** Input: N/A
 ** Output: Screen print
 *********************************************************************/
#ifndef HOUSE_H
#define HOUSE_H
#include "includes.hpp"
#include "tenant.hpp"
#include "property.hpp"

using namespace std;

/********************************************************************* 
 ** Function: House
 ** Description: House specific property
 ** Parameters:  N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
class House:public Property{
	private:
		Tenant t;

	public:
		House();


		Tenant& get_tenant(int index); 
		void remove_tenant(int index);
		
};


#endif
