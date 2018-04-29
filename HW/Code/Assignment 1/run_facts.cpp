/*********************************************************************
 ** Program Filename:  run_facts.cpp
 ** Author: Braam Beresford
 ** Date: 10th April 2018
 ** Description: Driver file for state data handlin
 ** Input: Command line arguments
 ** Output: N/A
 *********************************************************************/
#include "state_facts.h"
using namespace std;


/*********************************************************************
 ** Function: main
 ** Description: handles main logic of program
 ** Parameters: accepts command line arguments
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
int main(int argc, char **argv) {
	string filename = "";
	if (!is_valid_arguments(argv, argc))
		return 1;
	check_contents(argv, argc);
	int  num_states = check_state_input(argv, argc);
	// for (int i = 0; i < argc; i++) {
	// 	if (strcmp(argv[i], "-f")) {
	// 		cout << "argv " << argv[i] << endl;
	// 		filename = argv[i];
	// 	}

	// }
	filename = chec_file_name(argv,argc) ;
	state * states = create_states(num_states);
	cout << "bad" << endl;
	fstream f;

	f.open(filename.c_str());
	cout << "NUm states" << num_states;
	get_all_states(states, num_states, f);
	cout << "double bad" << endl;
	f.close();
	sorting_choice(states, num_states);
	delete_info(&states, num_states);
	return 0;
}
