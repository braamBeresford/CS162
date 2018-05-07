#include "house.hpp"

using namespace std;

House::House{
	int temp = rand()%5;
	this->value = ((rand()%500)+1)*100;
	switch(temp){
		case(0):
			this->location = SW; break;
		case(1):
			this->location = NE; break;
		case(2):
			this->location = MID; break;
		case(3):
			this->location = SW; break;
		case(4):
			this->location = NW; break;
	}

	mortgage = ((rand()%400)+101)*10;
}
