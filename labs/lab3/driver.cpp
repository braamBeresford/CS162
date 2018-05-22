#include "driver.hpp"


using namespace std;

#endif
#ifdef DEBUG
void test(){
cout << "HELLO!" << endl;}


int main(){
	srand(time(NULL));
	test();
	Player p;
	
	Property ** properties;
	cout << "Get num properties: " << p.get_num_properties() << endl;
	properties = set_prop_array(p.get_num_properties());
	Property * base;
	Business derived;
	base = &derived;

	cout << "Paid: " << properties[2]->get_type() << ' '<< properties[2]->get_tenant(0).get_agreeability() << endl;
	for(int i =0; i < p.get_num_properties(); i++)
		delete properties[i];
	delete [] properties;
}
