#ifndef DRIVER
#define DRIVER
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

#include "menu.hpp"
#include "pizza.hpp"

#define REST_NAME "restaurant_info.txt"
#define MENU_NAME "menu.txt"
#define EMP_NAME "employee.txt"
#define ORD_NAME "orders.txt"

using namespace std;

struct hours{
    string day;
    string open_hour;
    string close_hour;
};

struct employee{
    string id;
    string first_name;
    string last_name;
    string password;
};


struct fileLengths{
    int pizza;
    int employees;
    int menu;
};



#include "restaurant.hpp"

void verify_file_open(fstream &f, string filename);
int get_num_lines(fstream &f);
void print_employee_selection();
void employee_selection(Restaurant & r);
bool is_int(string num);
int get_int(string usr_input);
void customer_selection(Restaurant & r);
void print_customer_selection();
void user_choice(Restaurant &r);
void remove_underscores(string * arr, int length);
bool check_all_true( bool arr, int num);
#endif