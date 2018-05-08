#include "driver.hpp"

using namespace std;

void print_properties(const Property* props, const int num){
    for(int i = 0; i < num; i++){
		// printf("Property: %s Value: %f.0 Mortgage Left: %f.0\n", props[i].get_type(), props[i].get_value(), props[i].get_mortgage());
		if(props[i].get_type() == HOUSE)
			printf("\tRent: %d Tenant:&s \n",  props[i].get_tenant().get_rent(), props[i].get_tenant().get_name())
		
		else
			for(int j = 0; j < props[i].get_num_tenants())
				printf("\tRent: %d Tenant:&s \n", props[i].get_tenant(j).get_rent(), props[i].get_tenant(j).get_name());

    }
}

void set_prop_array(Property* properties, const int num_properties){
// 	int temp = 0;
	
// 	for(int i = 0; i < num_properties; i++){
// 		temp = rand()&3;
// 		if(temp ==0)
// 			properties[i] = House();
		
// 		else if(temp == 1)
// 			properties[i] = Apartment();
		
// 		else 
// 			properties[i] = Business();
// 	}
}