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

void print_properties(Property** props, const int num, bool with_tenants, bool sold_only){
	if(!sold_only){
		for(int i = 0; i < num; i++){
			cout << "\nProperty ID: " << props[i]->get_ID() << " Property type: " << props[i]->get_type() << " \tValue: ";
			cout << props[i]->get_value() << " \tMortgage Left: " << props[i]->get_value() - props[i]->get_mortgage_paid() << endl;
			if(with_tenants){
				if(props[i]->get_type() == HOUSE)
					cout << "\tRent: " << props[i]->get_tenant(1).get_rent() << " Tenant: " << props[i]->get_tenant(1).get_name() << endl; //The param in get tenant are irelevant but required

				else
					for(int j = 0; j < props[i]->get_num_tenants(); j++)
						cout << "\tRent: " << props[i]->get_tenant(j).get_rent() << " Tenant: " << props[i]->get_tenant(j).get_name() << endl;
			}
		}
	}

	else{
		for(int i = 0; i < num; i++){

			if(props[i]->get_sold()){
				cout << "\nProperty ID: " << props[i]->get_ID() << " Property type: " << props[i]->get_type() << " \tValue: ";
				cout << props[i]->get_value() << " \tMortgage Left: " << props[i]->get_value() - props[i]->get_mortgage_paid() << endl;
				if(with_tenants){
					if(props[i]->get_type() == HOUSE)
						cout << "\tRent: " << props[i]->get_tenant(1).get_rent() << " Tenant: " << props[i]->get_tenant(1).get_name() << endl; //The param in get tenant are irelevant but required

					else
						for(int j = 0; j < props[i]->get_num_tenants(); j++)
							cout << "\tRent: " << props[i]->get_tenant(j).get_rent() << " Tenant: " << props[i]->get_tenant(j).get_name() << endl;
				}
			}
		}
	}
}

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

void get_mortgage_payments(Property ** properties, int & mortgage_due, const Player& p){
	for(int i = 0; i < p.get_num_properties(); i++){
				if(properties[i]->get_sold())
					mortgage_due += properties[i]->get_mortgage();

			}
}

void get_rent(Property ** properties, int & rent_collected, const Player& p){
	for(int i =0; i < p.get_num_properties(); i++){//
		if(properties[i]->get_sold()){ 
			for(int j = 0; j < properties[i]->get_num_tenants(); j++){
				rent_collected += properties[i]->get_tenant(j).get_rent();				
			}
		}
	}
}

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


void turn(Property ** properties, Player & p){
	string input = "";
	int taxes_due = 0;
	int mortgage_due = 0;
	int rent_collected = 0;
	while(true){
		system("clear");
		cout << "Current Balance  " << p.get_balance() << endl;
		get_mortgage_payments(properties, mortgage_due, p);
		p.change_balance(-mortgage_due);
		get_rent(properties, rent_collected,  p);
		p.change_balance(rent_collected);
		printf("This is your current portfolio: ");
		print_properties(properties, p.get_num_properties(), true, true);
		printf("\nWould you like to buy or sell any property (B)/(S)/(No)? ");
		getline(cin, input);
		if(input == "B" || input == "b")
			buy_property( properties,  p);
		
	}
} 



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

void change_rent_apart(Property** prop, const Player& p, const int &property_id){
	string input;
	cout << "Current rent : " << prop[property_id]->get_tenant(1).get_rent() << endl;
	cout << "What would you like the new rent to be? ";
	getline(cin, input);

	for(int i = 0; i < prop[property_id]->get_num_tenants(); i++){
		prop[property_id]->get_tenant(i).set_rent(get_int(input));
		cout << "BUDGET FOR APART" <<  prop[property_id]->get_tenant(i).get_budget() << endl;
		if(get_int(input) > prop[property_id]->get_tenant(i).get_budget()){

			if(prop[property_id]->get_tenant(i).get_agreeability() >= 3){
				cout << "The rent is too high for this tenant! " << endl;
				cout << "The tenant has decided to leave!" << endl;
				prop[property_id]->remove_tenant(i);
			}

			else if(prop[property_id]->get_tenant(i).get_agreeability() <= 3){
				cout << "The rent is too high for this tenant, they won't leave though!" << endl;
				cout << "They will continue to live here and not pay rent until it is below their budget again " << endl;
			}
		}

		else{
			prop[property_id]->get_tenant(i).set_rent(get_int(input));
		}
	}
}

void change_rent(Property** prop, const Player& p){
	string input;
	int property_id;
	while(true){
		printf("Which property would you like to change the rent on? ");
		getline(cin, input);
		if(is_int(input) && (property_id = get_int(input)) < p.get_num_properties())
			break;

		printf("Please provide a valid integer in the range of the number of properties!\n ");
	}

	if(prop[property_id]->get_type() == HOUSE){
		change_rent_house(prop, p, property_id);
	}

	else if(prop[property_id]->get_type() == APART){
		change_rent_apart(prop, p, property_id);
	}
	

}
