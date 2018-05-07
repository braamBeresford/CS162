#include "driver.hpp"
using namespace std;

class Property{
	protected:
		float value;
		int location;
		float mortgage;
		static const float tax = 0.015;
		
	public:
		Property();
		~Property();
		// Getters
		float get_value() const;
		string get_location() const;
		float get_mortgage() const;
		int get_num_tenants() const;

		//Setters

		void set_value(float value);
		void set_location(int location);
		void set_mortage(float mortage);

};
