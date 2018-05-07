#include "property.hpp"

using namespace std;

Property::Property(){
    int temp = rand()%5;
	switch(temp){
		case(0):
			this->location = "SW"; break;
		case(1):
			this->location = "NE"; break;
		case(2):
			this->location = "MID"; break;
		case(3):
			this->location = "SW"; break;
		case(4):
			this->location = "NW"; break;
	}
}


float Property::get_value() const{
    return this->value;
}

string Property::get_location() const{
    return this-> location;
}

float Property::get_mortgage() const{
    return this->mortgage;
}

void Property::set_value(float value) {
    this->value = value;
}

void Property::set_location(string loc){
    this->location = loc;
}

void Property::set_mortgage(float mortgage){
    this->mortgage = mortgage;
}