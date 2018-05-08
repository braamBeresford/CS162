#include "driver.hpp"
using namespace std;


// 
int main(){
	srand(time(NULL));
	int num_properties = 9;
	int temp =0;
	Property * properties = new Property[9];
	for(int i = 0; i < num_properties; i++){
		temp = rand()&3;
		if(temp ==0)
			properties[i] = House();
		
		else if(temp == 1)
			properties[i] = Apartment();
		
		else 
			properties[i] = Business();
	}
	
// 
	print_properties(properties, num_properties);
	House h;
	Apartment a;
	Business b;

	
	// cout << "Apart " << properties[1].get_type()  << endl;
	// cout << "Biz " << properties[2].get_type() << endl;
	// cout << "value " << properties[3].get_type()  << endl;

	delete [] properties;
}
