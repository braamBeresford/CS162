#include "driver.hpp"

using namespace std;

void print_properties(const Property* props, const int num){
    for(int i = 0; i < num; i++){
		// printf("Property: %s Value: %f.0 Mortgage Left: %f.0\n", props[i].get_type(), props[i].get_value(), props[i].get_mortgage());
		// if(props[i].get_type() == HOUSE)
			// printf("\tRent: %d Tenant:&s \n",  props[i].get_tenant().get_rent(), props[i].get_tenant().get_name())
		
		// else
		// 	for(int j = 0; j < props[i].get_num_tenants())
		// 		printf("\tRent: %d Tenant:&s \n", props[i].get_tenant(j).get_rent(), props[i].get_tenant(j).get_name());

    }
}

Property ** set_prop_array(const int num_properties){
	Property ** properties  = new Property*[num_properties];
	
	for(int i = 0; i < num_properties; i++){
		properties[i] = new House();
		properties[++i] = new Apartment();
		properties[++i] = new Business();
	}


	return properties;
}