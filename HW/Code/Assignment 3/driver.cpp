#include "driver.hpp"


using namespace std;



int main(){
	srand(time(NULL));
	int num_properties = 9;
	int num_owned = 0;
	Property ** properties;
	
	properties = set_prop_array( num_properties);
	// print_properties(properties, num_properties);


	
	Property * base;
	Business derived;
	base = &derived;

	cout << "Paid: " << properties[2]->get_type() << ' '<< properties[2]->get_tenant(0).get_agreeability() << endl;
	for(int i =0; i < num_properties; i++)
		delete properties[i];
	delete [] properties;
}
