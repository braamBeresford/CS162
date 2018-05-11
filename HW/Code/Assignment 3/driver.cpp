#include "driver.hpp"


using namespace std;



int main(){
	srand(time(NULL));

	Player p;
	Property ** properties;
	properties = set_prop_array(p.get_num_properties());


		// cout << "Paid: " << properties[2]->get_type() << ' '<< properties[2]->get_tenant(0).get_agreeability() << endl;

	turn(properties, p);

	for(int i =0; i < p.get_num_properties(); i++)
		delete properties[i];
	delete [] properties;
}
