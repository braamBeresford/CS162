#ifndef TENANT
#define TENANT
#include "driver.hpp"

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
		~Tenant();
		Tenant(const Tenant&);
		Tenant & operator=(const Tenant&);

		void set_rent(int rent);

		string get_name() const;
		int get_type() const;
		int get_agreeability() const;
		int get_budget() const;
		int get_rent() const;
		
};

#endif
