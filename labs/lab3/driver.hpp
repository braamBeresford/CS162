#ifndef DRIVER
#define DRIVER

using namespace std;

#include "property.hpp"
#include "apartment.hpp"
#include "business.hpp"
#include "house.hpp"
#include "player.hpp"
#include "driver_functions.cpp"

Property ** set_prop_array( const int num_properties);
void print_properties( const Property* props, const int num);
#endif
