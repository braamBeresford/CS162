#ifndef PROPERTY
#define PROPERTY
#include "includes.hpp"
#include "tenant.hpp"
using namespace std;

class Property{
	protected:
		int value;
		string type;
		string location;
		int mortgage;
		int mortgage_paid;
		static const float tax = 0.015;
		int num_tenants;
		bool sold;
		
	public:
		Property();
		~Property();
		Property& operator=(const Property& copy);


		
		// Getters
		float get_value() const;
		string get_location() const;
		float get_mortgage() const;
		string get_type() const;
		int get_num_tenants() const;
		int get_mortgage_paid() const;
		virtual Tenant& get_tenant(int index){}


		//Setters

		void set_value(float value);
		void set_location(string location);
		void set_mortgage(float mortage);
		void increase_mortgage_paid();

};


#endif