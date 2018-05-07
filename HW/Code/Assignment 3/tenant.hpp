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

	public:
		Tenant();
		~Tenant();
		Tenant(const Tenant&);
		Tenant & operator=(const Tenant&);

		string get_name() const;
		int get_type() const;
		int get_agreeability() const;
		int get_budget() const;
		
};

#endif
