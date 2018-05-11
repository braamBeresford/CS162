#ifndef HOUSE_H
#define HOUSE_H
#include "includes.hpp"
#include "tenant.hpp"
#include "property.hpp"

using namespace std;

class House:public Property{
	private:
		Tenant t;

	public:
		House();
		~House();


		Tenant& get_tenant(int index); 
		
};


#endif
