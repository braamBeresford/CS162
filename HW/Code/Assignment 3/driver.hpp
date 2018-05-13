#ifndef DRIVER
#define DRIVER

using namespace std;

#include "property.hpp"
#include "apartment.hpp"
#include "business.hpp"
#include "house.hpp"
#include "player.hpp"
#include "driver_functions.cpp"

Property ** set_prop_array( const int &num_properties);
bool is_int(string num);
int get_int(string usr_input);
void print_properties( const Property* props, const int num, bool with_tenants, bool sold_only);
void get_mortgage_payments(Property ** properties, int &mortgage_due, const Player& p);
void turn(Property ** properties, Player & p);
void check_for_leaving_residents(Property** properties, const Player &p, const int &property_id);
void buy_property(Property ** prop, const Player& p);
void get_taxes(Property** properties, int& taxes_collected, const Player& p);
void change_rent_biz(Property** prop, const Player& p, const int &property_id);
void sell_property(Property** prop, Player& p);
void random_event(Property ** prop, const Player & p);
#endif
