#include "driver.hpp"
using namespace std;

int main(){
	srand(time(NULL));
	House h;
	Apartment a;
	Business b;

	
	cout << "Apart " << a.get_tenant(1).get_agreeability() << endl;
	cout << "Biz " << b.get_num_tenants() << endl;
	cout << "value " << h.get_value() << endl;
}
