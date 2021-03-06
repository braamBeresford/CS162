/********************************************************************* 
 ** Program Filename: driver_functions.cpp
 ** Author: Braam Beresford
 ** Date: 05/13/18
 ** Description: Non-main non-class functions
 ** Input: N/A
 ** Output: Screen print
 *********************************************************************/
#include "driver.hpp"

using namespace std;

/*********************************************************************
 ** Function: is_int
 ** Description: Checks if a string is a valid integer
 ** Parameters: Input string and output bool
 ** Pre-Conditions: String that should contain integer
 ** Post-Conditions: true or false bool, true if string contains only int
 Taken from a previous program
 *********************************************************************/
bool is_int(string num) {
	for (int a = 0; a < num.length(); a++) {
		if (num[a] >= 48 && num[a] <= 57)
			;
		else
			return false;
	}
	return true;

}

/*********************************************************************
 ** Function: get_int
 ** Description: Takes string with integer and turns into integer
 ** Parameters: Input string and output intger
 ** Pre-Conditions: String that should contain integer
 ** Post-Conditions: Returns integer version of string
 ** Taken from previous file
 *********************************************************************/
int get_int(string usr_input) {
	int return_int = 0;
	for (int i = 0; i < usr_input.length(); i++) {
		return_int *= 10;
		return_int += (int(usr_input[i]) - 48);
	}
	return return_int;
}

/********************************************************************* 
 ** Function: print_properties
 ** Description: Prints properties
 ** Parameters:  Sold bool decides if tenants should be printed
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
void print_properties(Property** props, const int num, bool with_tenants, bool sold_only){
	if(!sold_only){
		for(int i = 0; i < num; i++){
			cout << "\nProperty ID: " << props[i]->get_ID() << " Property type: " << props[i]->get_type() << "  Location: " << props[i]->get_location() << " \tValue: ";
			cout << props[i]->get_value() << " \tMortgage Left: " << props[i]->get_value() - props[i]->get_mortgage_paid() << endl;
			if(with_tenants){
				if(props[i]->get_type() == HOUSE)
					cout << "\tRent: " << props[i]->get_tenant(1).get_rent() << " Tenant: " << props[i]->get_tenant(1).get_name() << endl; //The param in get tenant are irelevant but required

				else
					for(int j = 0; j < props[i]->get_num_tenants(); j++)
						cout << "\tID: " << j << " Rent: " << props[i]->get_tenant(j).get_rent() << " Tenant: " << props[i]->get_tenant(j).get_name() << endl;
			}
		}
	}

	else{
		for(int i = 0; i < num; i++){

			if(props[i]->get_sold()){
				cout << "\nProperty ID: " << props[i]->get_ID() << " Property type: " << props[i]->get_type() << "Location: " << props[i]->get_location() << " \tValue: ";
				cout << props[i]->get_value() << " \tMortgage Left: " << props[i]->get_value() - props[i]->get_mortgage_paid() << endl;
				if(with_tenants){
					if(props[i]->get_type() == HOUSE)
						cout << "\tRent: " << props[i]->get_tenant(1).get_rent() << " Tenant: " << props[i]->get_tenant(1).get_name() << endl; //The param in get tenant are irelevant but required

					else
						for(int j = 0; j < props[i]->get_num_tenants(); j++)
							cout << "\tID: " << j << " Rent: " << props[i]->get_tenant(j).get_rent() << " Tenant: " << props[i]->get_tenant(j).get_name() << endl;
				}
			}
		}
	}
}

/********************************************************************* 
 ** Function: set_prop_array
 ** Description: Sets up property array with three of each
 ** Parameters: Given parameter higher than 1 
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
Property ** set_prop_array(const int &num_properties){
	Property ** properties  = new Property*[num_properties];
	
	for(int i = 0; i < num_properties; i++){
		properties[i] = new House();
		properties[i]->set_ID(i);
		properties[++i] = new Apartment();
		properties[i]->set_ID(i);
		properties[++i] = new Business();
		properties[i]->set_ID(i);
	}


	return properties;
}

/********************************************************************* 
 ** Function: get_mortgage_payments
 ** Description: Gets mortgage payments
 ** Parameters:  Valid properties, mortgage reference, and player
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
void get_mortgage_payments(Property ** properties, int & mortgage_due, const Player& p){
	for(int i = 0; i < p.get_num_properties(); i++){
				if(properties[i]->get_sold() && (properties[i]->get_mortgage_paid() < properties[i]->get_value())){
					mortgage_due += properties[i]->get_mortgage();
					properties[i]->increase_mortgage_paid();
				}

			}
}

/********************************************************************* 
 ** Function: get_rent
 ** Description: collects rent from all properties
 ** Parameters: correctly setup properties array
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
void get_rent(Property ** properties, int & rent_collected, const Player& p){
	for(int i =0; i < p.get_num_properties(); i++){
		if(properties[i]->get_sold()){ 
			for(int j = 0; j < properties[i]->get_num_tenants(); j++){
				if(properties[i]->get_tenant(j).get_budget() >= properties[i]->get_tenant(j).get_rent())
					rent_collected += properties[i]->get_tenant(j).get_rent();				
			}
		}
	}
}

/********************************************************************* 
 ** Function: get_taxes
 ** Description: collects taxes from all properties in the array
 ** Parameters:  valid properties array
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
void get_taxes(Property** properties, int& taxes_collected, const Player& p){
	for(int i =0; i < p.get_num_properties(); i++){
		if(properties[i]->get_sold()){ 
			taxes_collected+= properties[i]->get_value() * 0.015;
		}
	}
}

/********************************************************************* 
 ** Function: buy_property
 ** Description: allows the user to buy property
 ** Parameters: Valid property array and player object
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
void buy_property(Property ** prop, const Player& p){
	int first = rand()% p.get_num_properties(), second = rand()% p.get_num_properties(), third = rand()% p.get_num_properties();
	string input;
	
	while(true){
		first = rand()% p.get_num_properties();
		second = rand()% p.get_num_properties();
		third = rand()% p.get_num_properties();
		if(!prop[first]->get_sold() && !prop[second]->get_sold() && !prop[third]->get_sold()){
			cout << "Would you like to buy one of the following? " << endl;
			cout << "1. "; print_properties(&(prop[first]), 1, true, false);
			cout << "2. "; print_properties(&(prop[second]), 1, true, false);
			cout << "3. "; print_properties(&(prop[third]), 1, true, false);
			break;
		}
	}

	printf("Which of the following would you like to buy? (Q) for quit\n");
	getline(cin, input);
	if (input == "1")
		prop[first]->set_sold(true);

	else if(input == "2")
		prop[second]->set_sold(true);
	
	else if(input == "3")
		prop[third]->set_sold(true); 
}

/********************************************************************* 
 ** Function: sell_property
 ** Description: sells property array
 ** Parameters:  property array and player object
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
void sell_property(Property** prop, Player& p){
	string input = "";
	bool quit = false;
	while(true){
		printf("What property would you like to sell? ");
		getline(cin, input);
		if(input == "q" || input == "Q"){
			quit = true;
			break;
		}
		if(prop[get_int(input)]->get_sold() && (prop[get_int(input)]->get_num_tenants() == 0 || prop[get_int(input)]->get_tenant(1).get_rent() ==0))
			break;

		printf("You don't own that property or it has tenant! Please input a valid one! \n");
	}
	if(!quit){
		int index = get_int(input);
		int money_back = prop[index]->get_mortgage_paid();

		printf("You'll recieve %d for this property\n", money_back);
		p.change_balance(money_back);
		prop[index]->set_sold(false);
	}
	else
		printf("You chose not to sell!\n");

}

/********************************************************************* 
 ** Function: change_rent_house
 ** Description: changes rent of a house property
 ** Parameters:  valid house index
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
void change_rent_house(Property** prop, const Player& p, const int &property_id){
	string input;
	cout << "Current rent : " << prop[property_id]->get_tenant(1).get_rent() << endl;
	cout << "What would you like the new rent to be? ";
	getline(cin, input);
	prop[property_id]->get_tenant(1).set_rent(get_int(input));

	if(prop[property_id]->get_tenant(1).get_rent() > prop[property_id]->get_tenant(1).get_budget()){
		if(prop[property_id]->get_tenant(1).get_agreeability() >= 3){
			printf("The rent was too high for this tenant! They have left! \n");
			printf("You have no more tenants!\n " );
			prop[property_id]->remove_tenant(1);
		}
	}
	else
		printf("New rent is set!\n");
}

/********************************************************************* 
 ** Function: change rent apartement
 ** Description: Changes the rent and apartment block
 ** Parameters:  valid property array and player constant
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
void change_rent_apart(Property** prop, const Player& p, const int &property_id){
	string input;
	cout << "What would you like the new rent to be? ";
	getline(cin, input);

	for(int i = 0; i < prop[property_id]->get_num_tenants(); i++){
		prop[property_id]->get_tenant(i).set_rent(get_int(input));
		cout << "Current rent " << prop[property_id]->get_tenant(i).get_rent() << endl; 
		cout << "BUDGET FOR APART  " <<  prop[property_id]->get_tenant(i).get_budget() << endl;
		if(get_int(input) > prop[property_id]->get_tenant(i).get_budget()){

			if(prop[property_id]->get_tenant(i).get_agreeability() >= 3){
				cout << "The rent is too high for this tenant! " << endl;
				cout << "The tenant has decided to leave!" << endl;
				prop[property_id]->remove_tenant(i);
				
			}

			else if(prop[property_id]->get_tenant(i).get_agreeability() < 3){
				cout << "The rent is too high for this tenant, they won't leave though!" << endl;
				cout << "They will continue to live here and not pay rent until it is below their budget again " << endl;
			}
		}

		else{
			prop[property_id]->get_tenant(i).set_rent(get_int(input));
		}
	}

	
}

/********************************************************************* 
 ** Function: changes the rent on a business
 ** Description: allows user to change rent on an apartment
 ** Parameters: valid property array and player constant
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
void change_rent_biz(Property** prop, const Player& p, const int &property_id){
	string input;
	int index = 0;
	printf("Which unit of your business complex would you like to adjust the rent on? \n");
	getline(cin, input);
	index = get_int(input);
	cout << "What would you like the new rent to be? ";
	getline(cin, input);
	prop[property_id]->get_tenant(index).set_rent(get_int(input));
	cout << "Rent check " << prop[property_id]->get_tenant(index).get_rent() << endl;
	cout << "Budget check " << prop[property_id]->get_tenant(index).get_budget() << endl;

	if(prop[property_id]->get_tenant(index).get_rent() > prop[property_id]->get_tenant(index).get_budget()){
		if(prop[property_id]->get_tenant(index).get_agreeability() >= 3){
			printf("The rent was too high for this tenant! They have left! \n");
			prop[property_id]->remove_tenant(index);
		}
	}
	else
		printf("New rent is set!\n");
	
}

/********************************************************************* 
 ** Function: change rent
 ** Description: general function for rent changing
 ** Parameters: Access to property specific change rent functions
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
void change_rent(Property** prop, const Player& p){
	string input;
	int property_id;
	while(true){
		printf("Which property would you like to change the rent on? ");
		getline(cin, input);
		if(is_int(input) && (property_id = get_int(input)) < p.get_num_properties()){
			break;
		}

		printf("Please provide a valid integer in the range of the number of properties!\n ");
	}

	if(prop[property_id]->get_type() == HOUSE){
		// cout << "Help " << prop[property_id]->get_tenant(1).get_budget() << endl;
		change_rent_house(prop, p, property_id);
	}

	else if(prop[property_id]->get_type() == APART){
		change_rent_apart(prop, p, property_id);
	}

	else if(prop[property_id]->get_type() == BIZ){
		 change_rent_biz(prop, p, property_id);
	}


	printf("Press enter to continue");
	getline(cin, input);

}

/********************************************************************* 
 ** Function: random_event
 ** Description: Produces a random event every turn
 ** Parameters:  Must be called
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
void random_event(Property ** prop, const Player & p){
	int event = rand()%6;
	int loc = 0;
	int change = 0;
	float mult = 0;
	string location = "";
	bool crash = false;
	if(event == 1){
		printf("A hurricane has hit! All properties in SE have decrease value by 50 percent! \n");
		location = "SE";
		mult = -0.5;
	}
	else if(event == 2){
		printf("A tornado has hit your properties in the MID, value decrease of 30 percent! \n");
		location = "MID";
		mult = -0.3;
	}

	else if(event == 3){
		printf("An earthquake has hit your properties in the NW! Value decreased by 10 percent! \n");
		location = "NW";
		mult = -0.1;
	}

	else if(event == 4){
		printf("A wildfire has hit your properties in the SW! Value decreased by 25 percent! \n");
		location = "SW";
		mult = -0.25;

	}
	else if(event == 5){
		printf("Double trouble! Goldman made a mistake! Stock crash! All properties decrease by 30 percent! \n");
		mult = -0.3;
		crash = true;

	}

	else if(event == 0){
		loc = rand()%5;
		switch(event){
			case(0): location = "SW"; break;
			case(1): location = "MID"; break;
			case(2): location = "NW"; break;
			case(3): location = "NE"; break;
			case(4): location = "SE"; break;
		}
		mult = 0.2;
		printf("Economic growth! %s see's 20 percent value growth! \n", location.c_str());

	}

	for(int i = 0; i < p.get_num_properties(); i++){
		if(crash == true){
			if(prop[i]->get_sold()){
				change = prop[i]->get_value() + prop[i]->get_value()*mult;
				prop[i]->set_value(change);
			}
		}


		else{
			if(prop[i]->get_location() == location && prop[i]->get_sold()){
				change = prop[i]->get_value() + prop[i]->get_value()*mult;
				prop[i]->set_value(change);
			}
		}

	}
}


/********************************************************************* 
 ** Function: turn
 ** Description: handles every turn
 ** Parameters:  properties array and player constant
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/ 
void turn(Property ** properties, Player & p){
	int turn =0;
	string input = "";
	int taxes_collected = 0;
	int mortgage_due = 0;
	int rent_collected = 0;
	bool win = false;
	bool lose = false;
	while(!win && !lose){
		if(p.get_balance() >= 1000000)
			win = true;
		if(p.get_balance() <= 0)
			lose = true;

		taxes_collected = 0; mortgage_due = 0; rent_collected = 0;
		system("clear");
		get_mortgage_payments(properties, mortgage_due, p);
		p.change_balance(-mortgage_due);
		get_rent(properties, rent_collected, p);
		p.change_balance(rent_collected);
		if(turn%12 == 0){
			cout << "It's tax season! " << endl;
			get_taxes(properties, taxes_collected, p);
			p.change_balance(-taxes_collected);
		}
		cout << "Current Balance  " << p.get_balance() <<  "  Current Turn  " << turn << endl;
		printf("Taxes: -%d  Mortgage: -%d  Rent: %d\n", taxes_collected, mortgage_due, rent_collected);
		printf("Total revenue this turn: %d\n", (-1)*taxes_collected + (-1)*mortgage_due + rent_collected);
		random_event(properties, p);
		printf("This is your current portfolio: ");
		print_properties(properties, p.get_num_properties(), true, true);
		printf("\nWould you like to buy or sell any property (B)/(S)/(No)? ");
		getline(cin, input);
		if(input == "B" || input == "b")
			buy_property( properties,  p);
		else if(input == "s" || input == "S")
			sell_property(properties, p);

		printf("Would you like to change rents? (Y/N) ");
		getline(cin, input);
		if(input == "Y" || input == "y")
			change_rent(properties, p);
		for(int i =0; i < properties[1]->get_num_tenants(); i++)
			cout << "OUTSIDE EVERYTHNG " << properties[1]->get_tenant(i).get_rent() << endl;
		turn++;
	}

	if(win)
		printf("Congratulations! You have won the game! You have over a MILLION dollars\n");

	if(lose)
		printf("You have lost :( Better luck next time \n");
} 



