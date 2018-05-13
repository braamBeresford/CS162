#ifndef TENANT
#define TENANT
#include "includes.hpp"

using namespace std;

class Tenant{
	private:
		string name;
		int type;
		int agreeability;
		int budget;
		int rent;

	public:
		Tenant();
		Tenant(int type);
		// ~Tenant();
		Tenant(const Tenant&);
		Tenant & operator=(const Tenant&);

		void set_rent(int rent);
		void set_name(string name);
		void set_budget(int budg);

		string get_name() const;
		int get_type() const;
		int get_agreeability() const;
		int get_budget() const;
		int get_rent() const;
		

};

#endif
