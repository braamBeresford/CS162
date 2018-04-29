/********************************************************************* 
 ** Program Filename:  state_facts.h
 ** Author: Braam Berseford
 ** Date: 10th April 2018
 ** Description: Header file for state handlin
 ** Input: N/A
 ** Output: N/A
 *********************************************************************/ 
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <ctype.h>

using namespace std;

struct county{
	string name;
	string * city;
	int cities;
	int population;
	float avg_income;
	float avg_house;
};


struct state{ 
	string name;
	struct county *c;
	int counties;
	int population;
};

struct largest_county{
	int state_index;
	int county_index;
};

state * create_states(int num_states);
county * create_counties(int num_counties);
void get_state_data(state * states, int curr_state, fstream & f);
void print_state(state * states, int curr_state);
void get_county_data(county * c, int num_counties, fstream &f);
void print_all_counties(state * states, int curr_state);
void print_all_states(state * states, int num_states, bool include_counties= false);
void get_all_states(state * states, int num_states, fstream &f);
void delete_info(state ** states , int num_states);
void sort_states_pop(state * states, int num_states);
void sort_county_pop(state * states, int num_states);
bool is_valid_arguments(char*[], int);
bool is_int(string num);
int check_state_input(char * argv[], int argc);
string chec_file_name(char * argv[], int argc);
int check_contents(char * argv[], int argc);
int get_int(string usr_input);
void sort_state_names(state * states, int num_states);
int largest_state_population(state * states, int num_states);
largest_county largest_county_population(state * states, int num_states);
void output_to_file(state * states, int num_states, int operation);
void sorting_choice(state * states, int num_states);
void save_all_states(state * states, int num_states, fstream & f);
void sort_county_names(state * states, int num_states);
void county_above_income_file(state * states, int num_states, fstream & f);
void average_county_income(state * states, int num_states, int * average);
void output_to_screen(state * states, int num_states, int operation);
void county_above_income_screen(state * states, int num_states);