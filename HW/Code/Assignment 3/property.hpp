#ifndef PROPERTY
#define PROPERTY
#include "includes.hpp"
using namespace std;

class Property{
	protected:
		float value;
		string type;
		string location;
		float mortgage;
		static const float tax = 0.015;
		
	public:
		Property();
		// ~Property();

		
		// Getters
		float get_value() const;
		string get_location() const;
		float get_mortgage() const;
		string get_type() const;

		//Setters

		void set_value(float value);
		void set_location(string location);
		void set_mortgage(float mortage);

};


#endif