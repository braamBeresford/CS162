#ifndef UNIT
#define UNIT

#include "driver.hpp"

using namespace std;

class Unit{
	private:
		int rent;
		Tenant t;

	public:
		Unit();
		~Unit();

		int get_rent() const;
		const Tenant* get_tenant() const;
		
		void set_rent(int rent);


}



#endif
