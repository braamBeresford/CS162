#include "pizza.hpp"
#include "menu.hpp"
#include "driver.hpp"

using namespace std;
Menu::Menu() {
	this-> num_pizzas = 0;
	this-> pizzas = NULL;
}

Menu::~Menu(){
	delete [] pizzas;
}


//Accesors
void Menu::view_num_pizzas() const {cout << num_pizzas; }
void Menu::view_menu() const {
	for(int i =0; i < num_pizzas; i++){
		cout << pizzas[i].get_name_without_underscores()<< " \n\tSmall Cost: " << pizzas[i].get_small_cost() << "\n\tMedium Cost: " <<pizzas[i].get_medium_cost();
		cout << "\n\tLarge Cost: " << pizzas[i].get_large_cost() << ' ' << endl;
		view_ingredients(i);
	}
}

void Menu::view_ingredients(int index) const {
	printf("\n\tIngredients: \n");
	string *  temp = pizzas[index].get_ingredients();
	remove_underscores(temp, pizzas[index].get_num_ingredients());
	for (int i = 0; i < pizzas[index].get_num_ingredients(); i++)
		cout << "\t\t" << temp[i] << endl;

	delete [] temp;
	putchar('\n');
}

//Mutators
void Menu::load_data() {
	string name;
	int smll_cost, med_cost, lg_cost, num_ingredients;
	fstream f;
	verify_file_open(f, MENU_NAME);
	this->num_pizzas = get_num_lines(f);
	pizzas = new Pizza [(this->num_pizzas)*2];
	f.clear();
	f.seekg(0, ios::beg); //Go to begining of file again
	for (int i = 0; i < this->num_pizzas; i++) {
		f >> name >> smll_cost >> med_cost >> lg_cost >> num_ingredients;
		pizzas[i].set_name(name);
		pizzas[i].set_small_cost(smll_cost);
		pizzas[i].set_medium_cost(med_cost);
		pizzas[i].set_large_cost(lg_cost);
		pizzas[i].set_num_ingredients(num_ingredients);
		pizzas[i].create_ingredients_arr(num_ingredients);
		load_ingredients(f, num_ingredients, i);
	}
}

void Menu::load_ingredients(fstream &f, int num_ingredients, int curr_pizza) {
	string temp[num_ingredients];
	for (int i = 0; i < num_ingredients; i ++) {
		f >> temp[i];
	}
	pizzas[curr_pizza].fill_ingredients_arr(num_ingredients, temp);
}

void Menu::add_item_to_menu(){
    Pizza p;
    string input = "", name = "";
    int small, medium, large, num_ingredients;
    string * ingredients;
    printf("What would you like to call your pizza? ");
   	getline(cin, name);
    p.set_name(name);

    printf("\nPrice for a small: ");
	getline(cin, input);
    small = get_int(input);
    p.set_small_cost(small);

    printf("\nPrice for a medium: ");
	getline(cin, input);
    medium = get_int(input);
    p.set_medium_cost(medium);

    printf("\nPrice for a large: ");
    getline(cin, input);
    large = get_int(input);
    p.set_large_cost(large);

    printf("\nHow many ingredients are there? ");
    getline(cin, input);
    num_ingredients = get_int(input);
    p.set_num_ingredients(num_ingredients);

    string * temp = new string[num_ingredients];
    p.create_ingredients_arr(num_ingredients);

    for(int i = 0; i < num_ingredients; i++){
        printf("\n Ingredients: ");
        getline(cin, temp[i]);
    }

    p.fill_ingredients_arr(num_ingredients, temp);

    pizzas[num_pizzas-1] = p;
}

void Menu::remove_iterm_from_menu(){
	string input = "", temp = "";
	bool valid =false;
	int index = 0;
	printf("Please give me the name of the item that you would like to remove: ");
	getline(cin, input);

	while(true){
		for(int i =0; i < input.length(); i++){
			if(input[i] == ' ')
				input[i] = '_';
		} 


		if(input == "Q")
			return;

		
		for(int i =0; i < this->num_pizzas; i++){

			temp = pizzas[i].get_name();
			if(temp == input){
				cout << "this shoudlnt work\n";
				index = i;
				valid = true;
				break;
			}
		}
		if(valid == true)
			break;
		printf("\nThat pizza does not appear to be on the menu, re-enter or type Q for quit ");
		getline(cin, input);
	}
	
	
	for(int i = index; i < this->num_pizzas; i++){
		if(i+1 == this-> num_pizzas){
			continue;
		}
		else
			pizzas[i] = pizzas[i+1];
	}
	// pizzas[this->num_pizzas-1] = NULL;
	this->num_pizzas--;

}