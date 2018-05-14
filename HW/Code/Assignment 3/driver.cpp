/********************************************************************* 
 ** Program Filename: driver.cpp
 ** Author: Braam Beresford
 ** Date: 05/13/18
 ** Description: implementation of main
 ** Input: N/A
 ** Output: Screen print
 *********************************************************************/
#include "driver.hpp"

using namespace std;

int main(){
	srand(time(NULL));

	Player p;
	Property ** properties;
	properties = set_prop_array(p.get_num_properties());
		
	turn(properties, p);

	for(int i =0; i < p.get_num_properties(); i++)
		delete properties[i];
	delete [] properties;
}
