#ifndef MENU
#define MENU
#include "pizza.hpp"
using namespace std;

class Menu{
private:
	int num_pizzas;
	Pizza * pizzas;

public:
	//Constructor
	Menu();
	~Menu();
	// Accesors
	void view_num_pizzas() const;
	void view_menu() const;
	void view_ingredients(int index) const;

	//Mutators
	void load_data();
	void load_ingredients(fstream &f, int num_ingredients, int curr_pizza);
	void add_item_to_menu();
	void remove_iterm_from_menu();

};

#endif