#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

struct mult_div_values{
        int mult;
        float div;
};

bool is_valid_column(char* column);
bool is_valid_row(char* row);
mult_div_values** create_table(int row, int column);

void set_mult_values(mult_div_values** table, int rows, int columns);
void set_div_values(mult_div_values** table, int rows, int columns);
void delete_table(mult_div_values** table, int m);