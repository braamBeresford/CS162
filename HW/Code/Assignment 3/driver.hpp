#ifndef DRIVER
#define DRIVER

using namespace std;

#include "property.hpp"
#include "apartment.hpp"
#include "business.hpp"
#include "house.hpp"
#include "driver_functions.cpp"

void set_prop_array(Property* prop, const int num_props);
void print_properties( const Property* props, const int num);
#endif
