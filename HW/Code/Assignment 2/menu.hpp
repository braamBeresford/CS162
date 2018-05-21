/*********************************************************************
 ** Program Filename:  menu.hpp
 ** Author: Braam Beresford
 ** Date: 10th of April 2018
 ** Description: Function file for entire program
 ** Input: User input and command line arguments
 ** Output: To screen and to file
 *********************************************************************/
#ifndef MENU
#define MENU
#include "pizza.hpp"

using namespace std;

struct order{
    string order_num;
    string customer_first;
    string customer_last;
    string credit_card;
    string address;
    string phone ; 
    string pizza;
    string size;
    int quantity;
};
class Menu{
private:
	int num_pizzas;
	Pizza * pizzas;

public:
	//Constructor
	Menu();
	~Menu();
	Menu(const Menu&);
	Menu & operator=(const Menu &);

	// Accesors
	void view_num_pizzas() const;
	void view_menu() const;
	void view_ingredients(int index) const;
	int get_cost(int index, string size) ;

	//Mutators
	void load_data();
	void load_ingredients(fstream &f, int num_in, int curr_pizza);
	void add_item_to_menu();
	void remove_iterm_from_menu();
	void remove_item_at_index(int index);
	void place_order(order & temp);
	void save_data(fstream &f);
	void create_array(int length);
	

	void search_pizza_by_ingredients_to_exclude(Menu &results, string* ingredients, int num_ingredients);
	Menu search_pizza_by_cost(int upper_bound, string size);
	void search_pizza_by_ingredients_to_include(Menu &results, string* ingredients, int num_ingredients);
	bool check_all_true( bool* arr, int num);


};

#endif
