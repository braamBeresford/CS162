#include "pizza.hpp"
#include "menu.hpp"
#include "driver.hpp"
/*********************************************************************
 ** Program Filename:  menu.cpp
 ** Author: Braam Beresford
 ** Date: 10th of April 2018
 ** Description: Function file for entire program
 ** Input: User input and command line arguments
 ** Output: To screen and to file
 *********************************************************************/

using namespace std;
/*********************************************************************
 ** Function: Distructor and Creator
 ** Description: Handles creation and distruction of objects
 ** Parameters: Being run
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
Menu::Menu() {
	this-> num_pizzas = 0;
	this-> pizzas = NULL;
}

Menu::~Menu(){
	if(pizzas != NULL)
		delete [] pizzas;
	pizzas = NULL;
}


//Accesors
/*********************************************************************
 ** Function: Accessors
 ** Description: Allows access to the the private objects
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
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


int Menu::get_cost(int index, string size) const{
	if(size == "small")
		return pizzas[index].get_small_cost();
		
	else if(size == "medium")
		return pizzas[index].get_medium_cost();
	
	else
		return pizzas[index].get_large_cost();
		
}

Menu Menu::search_pizza_by_cost(int upper_bound, string size){
	Menu searched;
	searched = *this;

	for(int i =0; i < searched.num_pizzas; i++){
		if(searched.get_cost(i, size) > upper_bound){
			searched.remove_item_at_index(i);
			i--;
		}
	}
    return searched;
}


void Menu::remove_item_at_index(int index){
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


Menu & Menu::operator=(const Menu & m) {
	this->num_pizzas = m.num_pizzas;
	if(pizzas!= NULL)
		delete [] pizzas;
	
	if(num_pizzas==0)
		pizzas = NULL;
	
	else{
		pizzas = new Pizza[this->num_pizzas];
		for(int i = 0; i < num_pizzas; i++){
			this->pizzas[i] = m.pizzas[i];
		}
	}

	return *this;
}



void Menu::search_pizza_by_ingredients_to_include(Menu &results, string* ingredients, int num_ingredients){
	bool* present = new bool[num_ingredients];
	string *temp_ingredients;
	

	for(int i = 0; i < this->num_pizzas; i++){ //Pizzas
		for(int v =0; v < num_ingredients; v ++)
			present[v] = false;


		for(int j = 0; j < num_ingredients; j++){ //Ingredients want to include
			for(int k = 0; k < pizzas[i].get_num_ingredients(); k++){ //Ingredients of each pizzas
				temp_ingredients = pizzas[i].get_ingredients();
				if(ingredients[j] == temp_ingredients[k])
					present[j] = true;

				delete [] temp_ingredients;
			}
		}


		if(check_all_true( present, num_ingredients)){
			results.pizzas[results.num_pizzas] = this->pizzas[i];
			results.num_pizzas++;
		}

	}

	delete [] present;
}


bool Menu::check_all_true( bool* arr, int num){
    for(int i =0; i < num; i++)
        if(arr[i] == false)
            return false;
    return true;
}

void Menu::search_pizza_by_ingredients_to_exclude(Menu &results, string* ingredients, int num_ingredients){
	
	bool present = false;
	string *temp_ingredients;

	for(int i = 0; i < this->num_pizzas; i++){ //Pizzas
		for(int j = 0; j < num_ingredients; j++){ // Ingredients want to exclude
			present = false;
			for(int k = 0; k < pizzas[i].get_num_ingredients(); k++){ //Ingredients of pizza
				temp_ingredients = pizzas[i].get_ingredients();
				if(ingredients[j] == temp_ingredients[k]){
					present = true;
					break;
				}

				delete [] temp_ingredients;
			}
		}
		

		if(present != true){
			results.pizzas[results.num_pizzas] = this->pizzas[i];
			results.num_pizzas++;
		}
	}
}


void Menu::create_array(int length){
	pizzas = new Pizza[length];
	
}


//Mutators
/*********************************************************************
 ** Function: Load data	
 ** Description: Handles data loading for the menu
 ** Parameters: Data must be available
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
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

	f.close();
}

/*********************************************************************
 ** Function: Load ingredients
 ** Description: Loads the ingredients for each pizza
 ** Parameters: Rqequires ingredients
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void Menu::load_ingredients(fstream &f, int num_in, int curr_pizza) {
	string* temp = new string[num_in];

	for (int i = 0; i < num_in; i ++) {
		f >>  temp[i];
	}

	pizzas[curr_pizza].fill_ingredients_arr(num_in, temp);
	delete [] temp;
}

/*********************************************************************
 ** Function: Add item to menu
 ** Description: This function allows users to add to menu
 ** Parameters: Valid names and prices
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
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
	num_pizzas++;
    this->pizzas[num_pizzas-1] = p;
	delete [] temp;
	// (*this).view_menu();
	// p.~Pizza();
}

/*********************************************************************
 ** Function: Save data
 ** Description: Saves all data to files when program ends
 ** Parameters: Ending program
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void Menu::save_data(fstream &f){
	string* temp;
	
	for(int i = 0; i < num_pizzas; i++){
		f << pizzas[i].get_name() << ' ' << pizzas[i].get_small_cost() << ' ' << pizzas[i].get_medium_cost();
		f << ' ' << pizzas[i].get_large_cost() << ' ' << pizzas[i].get_num_ingredients() << ' ';
		temp = pizzas[i].get_ingredients();
		for(int j = 0; j < pizzas[i].get_num_ingredients(); j++){
			f << temp[j] << ' ';
		}
		if(i!= num_pizzas-1)
			f << endl;
		delete [] temp;
	}

}


/*********************************************************************
 ** Function: Place order
 ** Description: Allows user to place and order
 ** Parameters: Order must be in array
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void Menu::place_order(order & temp){
	string input = "";
	bool valid = false;
    printf("What pizza would you like? ");
    while(!valid){
        getline(cin, input);
		if(input == "Q" || input == "q")
			return;

        for(int i =0; i < input.length(); i++)
		    if(input[i] == ' ')
			    input[i] = '_';
  
        for(int i =0; i < this->num_pizzas; i++){
            if(input == pizzas[i].get_name())
				valid = true;
        }
		if(!valid)
			printf("We don't appear to have that pizza, re-enter or press Q to exit\n");
    }
	temp.pizza = input;
	valid = false;
	printf("What size would you like? (large, medium, or small) ");
	while(!valid){
		getline(cin, input);
		if(input == "small" || input == "Small"){
			temp.size = "S";
			valid = true;
		}
		
		else if(input == "medium" || input == "Medium"){
			temp.size = "M";
			valid = true;
		}
		else if(input == "large" || input == "Large"){
			temp.size = "L";
			valid = true;
		}
		if(!valid)
			printf("We don't appear to have that size, re-enter or press Q to exit ");
	}

	valid = false;
	printf("How many would you like?");
	while(!valid){
        getline(cin, input);
		if(input == "Q" || input == "q")
			return;

        for(int i =0; i < input.length(); i++)
		    if(input[i] == ' ')
			    input[i] = '_';
		
		if(is_int(input))
			valid = true;
		if(!valid)
			printf("That doesn't appear to be a realy number  ");
    }
	temp.quantity = get_int(input);
	printf("What is your first name? ");
	getline(cin, temp.customer_first);

	printf("What is your last name? ");
	getline(cin, temp.customer_last);

	printf("What is your address? ");
	getline(cin, temp.address);
 
	printf("What is your phone number? ");
	getline(cin, temp.phone);

	printf("What is your credit card? ");
	getline(cin, temp.credit_card);
	
	// temp.order_num = "69";
}

/*********************************************************************
 ** Function: remove item from menu
 ** Description: This function allows users to remove items
 ** Parameters: Item must exist
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void Menu::remove_iterm_from_menu(){
	string input = "", temp = "";
	bool valid = false;
	int index = 0;
	printf("Please give me the name of the item that you would like to remove: ");
	getline(cin, input);

	while(true){
		for(int i =0; i < input.length(); i++){
			if(input[i] == ' ')
				input[i] = '_';
		} 
		if(input == "Q" || input == "q")
			return;
		for(int i =0; i < this->num_pizzas; i++){

			temp = pizzas[i].get_name();
			if(temp == input){
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
