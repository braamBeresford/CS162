/*********************************************************************
 ** Program Filename:  state_facts.cpp
 ** Author: Braam Beresford
 ** Date: 10th of April 2018
 ** Description: Function file for entire program
 ** Input: User input and command line arguments
 ** Output: To screen and to file
 *********************************************************************/
#include "driver.hpp"


/*********************************************************************
 ** Function: Main
 ** Description: Handles main logic
 ** Parameters: Requires starting the program
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
int main() {
	Restaurant r;
	r.load_data();
	user_choice(r);
	r.save_data();
}