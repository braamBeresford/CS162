/*********************************************************************
 ** Program Filename:  state_facts.cpp
 ** Author: Braam Beresford
 ** Date: 10th of April 2018
 ** Description: Function file for entire program
 ** Input: User input and command line arguments
 ** Output: To screen and to file
 *********************************************************************/
#include "state_facts.h"
using namespace std;
/*********************************************************************
 ** Function: is_valid_arguments
 ** Description: Checks that the input is functionally
 ** Parameters:  Requires flags
 ** Pre-Conditions: Must be given valid inputs
 ** Post-Conditions: True is flags present, false otherwise
 *********************************************************************/
bool is_valid_arguments(char* argv[], int argc) {
	bool valid_input = false;
	if (argc != 5) {
		printf("You haven't inputted the flags correctly! Please re-run the program correctly \n");
		return false;
	}

	for (int i = 0; i < argc; i++) {
		if (!strcmp(argv[i], "-f"))
			for (int j = 0; j < argc; j++)
				if (!strcmp(argv[j], "-s")) {
					return true;

				}

		if (!strcmp(argv[i], "-s"))
			for (int j = 0; j < argc; j++)
				if (!strcmp(argv[i], "-f")) {
					return true;
				}
	}
	printf("You haven't inputted the flags correctly! Please re-run the program correctly \n");

	return false;
}



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
 ** Function: check_contents
 ** Description: Checks
 ** Parameters: Requires argv and argc
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
int check_contents(char * argv[], int argc) {
	check_state_input(argv, argc);
	chec_file_name(argv, argc);

	for (int i = 0; i < argc - 1; i++) {
		if ((int(strcmp(argv[i], "-f"))) == 0) {
			return get_int(argv[i + 1]);
		}
	}
	return 1;

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
 ** Function: check_state_input
 ** Description: Checks that the actual state none zero positive
 ** Parameters: argv and argc
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
int check_state_input(char * argv[], int argc) {
	string input = "";
	for (int i = 0; i < argc; i++) {
		if (!strcmp(argv[i], "-s")) {
			if (is_int(argv[i + 1]) && (get_int(argv[i + 1]) > 0)) {
				return true;
			}
			else {
				while (true) {
					printf("Your state number input was not an integer, please input another! ");
					// getline(cin, input);
					cin >> input;
					if (is_int(input) && (get_int(input) > 0))
						return get_int(input);
					input = "";
				}

			}
		}
	}
}


/*********************************************************************
 ** Function: chec_filed_name
 ** Description: Checks if the file name actually
 ** Parameters: argv and argc
 ** Pre-Conditions: N/A
 ** Post-Conditions:  N/A
 *********************************************************************/
string chec_file_name(char * argv[], int argc) {
	fstream file;
	string input = "";
	bool tester = true;
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-f") == 0) {
			file.open(argv[i + 1]);

			while (tester) {
				if (file.is_open()) {
					file.close();
					return input;
				};
				printf("The file name you entered does not appear to exist, please enter another one: ");
				getline(cin, input);
				file.open(input.c_str());

			}

		}
	}
}

/*********************************************************************
 ** Function: get_all_states
 ** Description: Gets the data from all datas
 ** Parameters: states array, number of states, and fstream object
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void get_all_states(state * states, int num_states, fstream &f) {
	for (int i = 0; i < num_states; i++)
		get_state_data(states, i, f);
}

/*********************************************************************
 ** Function: create_states
 ** Description: Creates an array of states structs
 ** Parameters: The number of states
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
state * create_states(int num_states) {
	state * states = new state[num_states];
	return states;
}

/*********************************************************************
 ** Function: sort_state_names
 ** Description: Sorts the states alphebetically
 ** Parameters: States array and num of states
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void sort_state_names(state * states, int num_states) {
	for (int j = 0; j < num_states - 1; j++) {

		for (int i = 0; i < num_states - j - 1; i++)
			if (states[i].name > states[i + 1].name)
				swap(states[i], states[i + 1]);
	}
}

/*********************************************************************
 ** Function: sort_county_names
 ** Description: Sorts counties alphebetically
 ** Parameters: States array and number of states
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void sort_county_names(state * states, int num_states) {
	for (int k = 0; k < num_states; k++) {
		for (int j = 0; j < states[k].counties - 1; j++) {
			for (int i = 0; i < states[k].counties - j - 1; i++)
				if (states[k].c[i].name > states[k].c[i + 1].name)
					swap(states[k].c[i], states[k].c[i + 1]);
		}
	}
}

/*********************************************************************
 ** Function: sorting_choice
 ** Description: Presents what sorting you would like to do
 ** Parameters: States array and num of states
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void sorting_choice(state * states, int num_states) {
	string operation_choice  = "";
	string input = "";
	printf("You're file was sucessfully inported! \n");
	printf("1. State with largest population \n");
	printf("2. County with largest population\n");
	printf("3. Counties above a specified income \n");
	printf("4. Average income across all counties for each states\n");
	printf("5. States sorted by name \n");
	printf("6. States sorted by population\n");
	printf("7. Counties sorted by name \n");
	printf("8. Counties sorted by population\n");
	printf("Enter a non integer to exit \n");

	cin >> operation_choice;

	if (!is_int(operation_choice))
		return;

	printf("Would you like to output to screen (1) or file(2) \n");
	cin >> input;

	if (get_int(input) == 2)
		output_to_file(states, num_states, get_int(operation_choice));

	else if (get_int(input) == 1)
		output_to_screen( states,  num_states,  get_int(operation_choice));
}
/*********************************************************************
 ** Function: output_to_screen
 ** Description: Handles data outputting to screen
 ** Parameters: Requires states array, num of states, sort type
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void output_to_screen(state * states, int num_states, int operation) {

	if (operation == 1) {
		int largest = largest_state_population(states, num_states);
		cout << "Largest state population: \n";
		cout << states[largest].name << " Population: " << states[largest].population << '\n';
	}

	else if (operation == 2) {
		largest_county largest = largest_county_population( states,  num_states);
		cout << "Largest county population: \n";
		cout << states[largest.state_index].c[largest.county_index].name;
		cout  << " Population: " << states[largest.state_index].c[largest.county_index].population << '\n';
	}

	else if (operation == 3) {
		county_above_income_screen(states,  num_states);
	}

	else if (operation == 4) {
		putchar('\n');
		int * average_income = new int[num_states];
		average_county_income(states,  num_states, average_income);
		for (int i = 0; i < num_states; i++) {
			cout << states[i].name << " Average county income: ";
			cout << average_income[i] << endl;
		}
		delete [] average_income;

	}

	else if (operation == 5) {
		sort_state_names(states, num_states);
		print_all_states(states, num_states, true);

	}
	else if (operation == 6) {
		sort_states_pop(states, num_states);
		print_all_states(states, num_states, true);
	}

	else if (operation == 7) {
		sort_county_names(states, num_states);
		print_all_states(states, num_states, true);
	}

	else if (operation == 8) {
		sort_county_pop(states, num_states);
		print_all_states(states, num_states, true);
	}
}


/*********************************************************************
 ** Function: output_to_file
 ** Description: Output the info to the file
 ** Parameters: States array and num of state and operation
 ** Pre-Conditions:  N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void output_to_file(state * states, int num_states, int operation) {
	string output_file = "";
	printf("Please input an ouput file name \n");
	cin >> output_file;
	fstream f;
	f.open(output_file.c_str(), fstream::in | fstream::out | fstream::app);

	if (!f.is_open()) {
		printf("I couldn't open that file\n");
	}

	if (operation == 1) {
		int largest = largest_state_population(states, num_states);
		f << "Largest state population: \n";
		f << states[largest].name << " Population: " << states[largest].population << '\n';
	}

	else if (operation == 2) {
		largest_county largest = largest_county_population( states,  num_states);
		f << "Largest county population: \n";
		f << states[largest.state_index].c[largest.county_index].name;
		f << " Population: " << states[largest.state_index].c[largest.county_index].population << '\n';
	}

	else if (operation == 3) {
		county_above_income_file(states, num_states, f);
	}

	else if (operation == 4) {
		putchar('\n');
		int * average_income = new int[num_states];
		average_county_income(states,  num_states, average_income);
		for (int i = 0; i < num_states; i++) {
			f << states[i].name << " Average county income: ";
			f << average_income[i] << endl;
		}
		delete [] average_income;

	}

	else if (operation == 5) {
		sort_state_names(states, num_states);
		save_all_states( states,  num_states, f);

	}
	else if (operation == 6) {
		sort_states_pop(states, num_states);
		save_all_states( states,  num_states, f);
	}

	else if (operation == 7) {
		sort_county_names(states, num_states);
		save_all_states( states,  num_states, f);
	}

	else if (operation == 8) {
		sort_county_pop(states, num_states);
		save_all_states( states,  num_states, f);
	}

	f.close();

}

/*********************************************************************
 ** Function: average_county_income
 ** Description: Computes the average county income
 ** Parameters: Requires states array, number of states, and average array
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void average_county_income(state * states, int num_states, int * average) {
	int temp = 0;
	for (int i = 0; i < num_states; i++) {
		temp = 0;
		for (int j = 0; j < states[i].counties; j++) {
			temp += states[i].c[j].avg_income;
		}
		temp /= states[i].counties;

		average[i] = temp;

	}
}

/*********************************************************************
 ** Function: county_above_incoe_file
 ** Description: Find county that has income above threshold
 ** Parameters: States array, num of states, fstream object
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void county_above_income_file(state * states, int num_states, fstream & f) {
	int input = 0;
	printf("Please enter an income: \n");
	cin >> input;
	for (int i = 0; i < num_states; i++) {
		f << states[i].name << " Population: " << states[i].population;
		f << " Number of counties: " << states[i].counties << endl;
		county * c = states[i].c;

		for (int j = 0; j < states[i].counties; j++) {
			if (states[i].c[j].population >= input) {
				f << c[j].name << " " << c[j].population << " " << c[j].avg_income;
				f << ' ';
				f << c[j].avg_house << ' ' << c[j].cities << endl;
			}

		}
	}
}

/*********************************************************************
 ** Function: save_all_states
 ** Description: Saves all the state data to a specified file
 ** Parameters: States, num of states, fstream, and filename
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void save_all_states(state * states, int num_states, fstream & f) {
	for (int i = 0; i < num_states; i++) {
		f << states[i].name << " Population: " << states[i].population;
		f << " Number of counties: " << states[i].counties << endl;

		county * c = states[i].c;
		f << "Counties:" << endl;
		for (int current = 0; current < states[i].counties; current++) {
			f << c[current].name << " " << c[current].population << " " << c[current].avg_income;
			f << ' ';
			f << c[current].avg_house << ' ' << c[current].cities << endl;
		}

		putchar('\n');
	}
}

/*********************************************************************
 ** Function: get_state_data
 ** Description: Gets data for each state, individually
 ** Parameters: States array, current state index, and fstream
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void get_state_data(state * states, int curr_state, fstream & f) {
	string name;
	int pop;
	int counties; // Number of counties
	f >> name >> pop >> counties;
	states[curr_state].name = name;
	states[curr_state].population = pop;
	states[curr_state].counties = counties;
	states[curr_state].c = create_counties(counties);
	get_county_data(states[curr_state].c, counties, f);
}

/*********************************************************************
 ** Function: larfgest_state_population
 ** Description: Returns index of largest state
 ** Parameters: States array and number of states
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
int largest_state_population(state * states, int num_states) { // Returns an index
	int largest_pop = 0;
	int largest_index = 0;
	for (int i = 0; i < num_states; i++) {
		if (states[i].population > largest_pop) {
			largest_pop = states[i].population;
			largest_index = i;
		}
	}
	return largest_index;
}

/*********************************************************************
 ** Function: largest_county_population
 ** Description: Gets the largest county population, retunr index
 ** Parameters: States array and number of states
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
largest_county largest_county_population(state * states, int num_states) {
	largest_county temp;
	temp.state_index = 0;
	temp.county_index = 0;
	int largest = 0;
	for (int i = 0; i < num_states; i++) {
		for (int j = 0; j < states[i].counties; j++) {
			if (states[i].c[j].population > largest) {
				largest = states[i].c[j].population;
				temp.state_index = i;
				temp.county_index = j;
			}
		}
	}

	return temp;
}

/*********************************************************************
 ** Function: county_above_income_screen
 ** Description: Prints each state above threshold
 ** Parameters: States array and num of states
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void county_above_income_screen(state * states, int num_states) {
	int input = 0;
	printf("Please enter an income: \n");
	cin >> input;
	for (int i = 0; i < num_states; i++) {
		cout << states[i].name << " Population: " << states[i].population;
		cout << " Number of counties: " << states[i].counties << endl;
		county * c = states[i].c;

		for (int j = 0; j < states[i].counties; j++) {
			if (states[i].c[j].population >= input) {
				cout << c[j].name << " " << c[j].population << " " << c[j].avg_income;
				cout << ' ';
				cout << c[j].avg_house << ' ' << c[j].cities << endl;
			}

		}
	}
}

/*********************************************************************
 ** Function: Create_counties
 ** Description: Creates an array of county structs
 ** Parameters: How large array should be made
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
county * create_counties(int num_counties) {
	county * counties = new county[num_counties];
	return counties;
}

/*********************************************************************
 ** Function: sort_states_pop
 ** Description: Sorts the states by their population
 ** Parameters: Valid states array and number of states
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void sort_states_pop(state * states, int num_states) {
	for (int j = 0; j < num_states - 1; j++) {

		for (int i = 0; i < num_states - j - 1; i++)
			if (states[i].population < states[i + 1].population)
				swap(states[i], states[i + 1]);
	}
}

/*********************************************************************
 ** Function: sort_county_pop
 ** Description: Sorts the county array by population
 ** Parameters:  States array and num of states
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void sort_county_pop(state * states, int num_states) {
	for (int k = 0; k < num_states; k++) {

		for (int j = 0; j < states[k].counties - 1; j++) {

			for (int i = 0; i < states[k].counties - j - 1; i++)
				if (states[k].c[i].population < states[k].c[i + 1].population)
					swap(states[k].c[i], states[k].c[i + 1]);
		}

	}
}

/*********************************************************************
 ** Function: get_county_data
 ** Description: Gets data for individual county
 ** Parameters: County array, number of counties, fstream object
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void get_county_data(county * c, int num_counties, fstream & f) {
	for (int current = 0; current < num_counties; current++) {
		string name;
		int cities, population;
		float avg_income, avg_house;
		f >> name >> population >> avg_income >> avg_house >> cities;
		c[current].name = name;
		c[current].cities = cities;
		c[current].population = population;
		c[current].avg_income = avg_income;
		c[current].avg_house = avg_house;
		c[current].city = new string [cities];

		for (int i = 0; i < cities; i++)
			f >> c[current].city[i];
	}
}

/*********************************************************************
 ** Function: Print_states
 ** Description: Prints individual state
 ** Parameters: States array and index to print
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void print_state(state * states, int curr_state) {
	cout << states[curr_state].name << " Population: " << states[curr_state].population;
	cout << " Number of counties: " << states[curr_state].counties << endl;
}

/*********************************************************************
 ** Function: print_all_states
 ** Description: Prints all states in states array
 ** Parameters: States array, num of states, and bool
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void print_all_states(state * states, int num_states, bool include_counties) {
	putchar('\n');
	if (!include_counties)
		for (int i = 0; i < num_states; i++)
			print_state(states, i);

	else
		for (int i = 0; i < num_states; i++) {
			print_state(states, i);
			putchar('\n');
			print_all_counties(states, i);
			putchar('\n');
		}
}

/*********************************************************************
 ** Function: print_all_counties
 ** Description: Prints all counties to the screen
 ** Parameters: states array and current states
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void print_all_counties(state * states, int curr_state) {
	county * c = states[curr_state].c;
	cout << "Counties: " << endl;
	for (int current = 0; current < states[curr_state].counties; current++) {
		cout << c[current].name << " " << c[current].population << " " << c[current].avg_income;
		putchar(' ');
		cout << c[current].avg_house << ' ' << c[current].cities << endl;
	}
}

/*********************************************************************
 ** Function: delete_info
 ** Description: clear all memory
 ** Parameters: states as double pointer and number of states
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void delete_info(state ** states , int num_states) {
	if (!states) {
		for (int i = 0; i < num_states; i++) {

			for (int j = 0; j < (*states)[i].counties; j++) {

				delete [] (*states)[i].c[j].city;
			}
			delete [] (*states)[i].c;

		}
		delete [] *states;
		states = NULL;
	}

}