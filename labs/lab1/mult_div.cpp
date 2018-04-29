#include "mult_div.h"
using namespace std;

/*struct mult_div_values {
	int mult;
	float div;
} typedef mult_div_values;
*/
bool is_valid_column(char* column){
	if('0' < column[0] && column[0] <= '9')
		return true;
	return false;
}

bool is_valid_row(char* row){
	if('0' < row[0] && row[0] <= '9')
		return true;
	return false;
}
void set_mult_values(mult_div_values** table, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			table[i][j].mult = (i + 1)*(j + 1);
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << table[i][j].mult;
		}
		putchar('\n');
	}

}


void set_div_values(mult_div_values** table, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			table[i][j].div = float(i + 1) / (j + 1);
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << table[i][j].div;
		}
		putchar('\n');
	}
}

void delete_table(mult_div_values** table, int rows) {
	for (int i = 0; i < rows; i++) {
		delete [] table[i];
	}
	delete [] table;
}




mult_div_values ** create_table(int rows, int column) {
	struct mult_div_values ** arr = new struct mult_div_values *[rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new mult_div_values[column];
	}

	return arr;

}


int main(int argc, char **argv) {
	char* char_row = argv[1];
	char* char_column = argv[2];
	

	while(!is_valid_row(char_row)){
		printf("Please input a row: ");
		cin >> char_row; 
		putchar('\n');
	}

	while(!is_valid_column(char_column)){
		printf("Please input a column: ");
		cin >> char_column; 
		putchar('\n');
	}

	int columns = atoi(char_column);
	int rows = atoi(char_row);
    mult_div_values** table;
	table = create_table(rows, columns);

	set_div_values(table, rows, columns);
	set_mult_values(table, rows, columns);

}



