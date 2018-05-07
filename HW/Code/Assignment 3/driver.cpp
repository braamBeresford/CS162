#include "driver.hpp"
using namespace std;

int main(){
	srand(time(NULL));
	House h;
	Apartment a;

	
	cout << "Apart " << a.get_tenant(1).get_agreeability() << endl;
	cout << "value " << h.get_value() << endl;
}
