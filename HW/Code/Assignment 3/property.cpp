/********************************************************************* 
 ** Program Filename: property.cpp
 ** Author: Braam Beresford
 ** Date: 05/13/18
 ** Description: implementation of property class
 ** Input: N/A
 ** Output: Screen print
 *********************************************************************/
#include "property.hpp"

using namespace std;

/********************************************************************* 
 ** Function: Property constructor
 ** Description: Creates property with baisc values
 ** Parameters:  Must be called
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
Property::Property(){
    int temp = rand()%5;
	this->mortgage = ((rand()%400)+10)*10;
	this->mortgage_paid = 0;
	this->sold = false;
	this->ID = -1;
	switch(temp){
		case(0):
			this->location = "SW"; break;
		case(1):
			this->location = "NE"; break;
		case(2):
			this->location = "MID"; break;
		case(3):
			this->location = "SE"; break;
		case(4):
			this->location = "NW"; break;
	}
}



/********************************************************************* 
 ** Function: Property operator overload
 ** Description: Overloads operator for deep copy
 ** Parameters:  Valid object
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
Property& Property::operator=(const Property& copy){
	this->value = copy.value;
	this->type = copy.type;
	this->location = copy.location;
	this->mortgage = copy.mortgage;
	this->sold = copy.sold;
	
	return *this;

}

/********************************************************************* 
 ** Function: Property Getters
 ** Description: Gets basic values from property
 ** Parameters: Valid inputs
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
int Property::get_num_tenants() const{
	return this->num_tenants;
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

int Property::get_mortgage_paid() const{return this-> mortgage_paid;}

string Property::get_type() const{return this->type;}

bool Property::get_sold() const{return this->sold;}

int Property::get_ID() const{return this->ID; }


/********************************************************************* 
 ** Function: Property setters
 ** Description: Set values for property class
 ** Parameters: Valid input
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
void Property::set_value(float value) {
    this->value = value;
}

void Property::set_location(string loc){
    this->location = loc;
}

void Property::set_mortgage(float mortgage){
    this->mortgage = mortgage;
}

void Property::increase_mortgage_paid(){
	this->mortgage_paid += this->mortgage;
}

void Property::set_sold(bool sold){
	this->sold = sold;
}

void Property::set_ID(int ID){
	this->ID = ID;
}

