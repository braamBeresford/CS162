/********************************************************************* 
 ** Program Filename: property.hpp
 ** Author: Braam Beresford
 ** Date: 05/13/18
 ** Description: Decleration of property class
 ** Input: N/A
 ** Output: Screen print
 *********************************************************************/
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
		int ID;
		
	public:
		Property();
		virtual ~Property();
		Property& operator=(const Property& copy);


		void test() {}
		// Getters
		float get_value() const;
		string get_location() const;
		float get_mortgage() const;
		string get_type() const;
		virtual int get_num_tenants() const;
		int get_mortgage_paid() const;
		virtual Tenant& get_tenant(int index){}
		bool get_sold() const;
		int get_ID() const;


		//Setters

		void set_value(float value);
		void set_location(string location);
		void set_mortgage(float mortage);
		void increase_mortgage_paid();
		void set_sold(bool sold);
		void set_ID(int ID);


		virtual void remove_tenant(int index){};

};


#endif
