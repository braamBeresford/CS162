#include "driver.hpp"


using namespace std;



int main(){
	srand(time(NULL));

	Player p;
	Property ** properties;
	properties = set_prop_array(p.get_num_properties());
	// print_properties(properties, p.get_num_properties(), false);
	// change_rent(properties, p);
	print_properties(properties, p.get_num_properties(), true);

	// turn(properties, p);

	for(int i =0; i < p.get_num_properties(); i++)
		delete properties[i];
	delete [] properties;
}
