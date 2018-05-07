#ifndef HOUSE
#define HOUSE
#include "driver.hpp"
#include "tenant.hpp"

using namespace std;

class House:public Property{
	private:
		Unit u();

	public:
		Tenant* get_tenant() const;
		Unit* get_unit() const;
		
};


#endif
