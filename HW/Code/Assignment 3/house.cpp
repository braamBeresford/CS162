#include "house.hpp"

using namespace std;

House::House(){
	this->value = ((rand()%500)+100)*100;
	
	Tenant t(PERSON);
}
