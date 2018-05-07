#include "house.hpp"

using namespace std;

House::House{
	this->value = ((rand()%500)+1)*100;
	this->mortgage = ((rand()%400)+101)*10;
	Tenant(PERSON) t;
}
