#include "driver.hpp"
#include "restaurant.hpp"
/*********************************************************************
 ** Function:
 ** Description:
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/


/*********************************************************************
 ** Function: get_num_lines
 ** Description: Gets the number of lines in a file
 ** Parameters: Requires a file object, return an int
 ** Pre-Conditions: File object that is confirmed to be open
 ** Post-Conditions: An int return for num of lines
 *********************************************************************/
int get_num_lines(fstream &f) {
    int count = 0;
    string s;
    while (!f.eof()) {
        getline(f, s);
        count++;
    }
    f.clear();
    f.seekg(0, ios::beg); //Go to begining of file again
    return count;
}



/*********************************************************************
 ** Function: verify_file_open
 ** Description: Opens file and verifies it exists
 ** Parameters: An fstream object and file name
 ** Pre-Conditions: Requires the fstream object and file name
 ** Post-Conditions: Completes when file can be opened
 *********************************************************************/
void verify_file_open(fstream &f, string filename) {

    do {
        f.open(filename.c_str());
        if (f.is_open())
            break;
        cout << filename << " does not appear to exist, please input a valid file \n";
        getline(cin, filename);
    } while (true);
}




void user_choice(Restaurant &r){
    string input = "";
    while(true){
        printf("Are you a customer (C),an employee (E), or logout (Q)\n");
        getline(cin, input);
        if(input == "C")
            customer_selection(r);
        else if(input == "E"){
            if(!r.validate_login(r))
                continue;
            employee_selection(r);
        }
        else
            return;
    }
}


void print_employee_selection() {
    // system("clear");
    printf("Welcome dedicated employee \n");
    printf("1. Change hours \n");
    printf("2. View Orders\n");
    printf("3. Remove Order \n");
    printf("4. Add Item to Menu\n");
    printf("5. Remove Item from Menu\n");
    printf("6. View Menu\n");
    printf("7. View Hours\n");
    printf("8. View Address\n");
    printf("9. View phone\n");
    printf("10. Logout\n");
}

void employee_selection(Restaurant & r) {
    bool logout = false;
    string input = "";
    int input_int = -1;
    do {
        print_employee_selection();
        getline(cin, input);
        if (!is_int(input)) {
            printf("That isn't a valid integer input!\n");
            continue;
        }
        input_int = get_int(input);

        switch (input_int) {
        case 1: r.change_hours(); break;
        case 2: system("clear"); printf("ORDERS:\n");
        r.view_orders(); putchar('\n'); break;
        case 3: cout << "Nothing here"  << endl; break;
        case 4: r.add_item_to_menu(); break;
        case 5: r.remove_iterm_from_menu(); break;
        case 6: r.view_menu(); break;
        case 7: r.view_hours(); break;
        case 8: printf("ADDRESS: \n"); r.view_address(); putchar('\n'); break;
        case 9: printf("PHONE:\n"); r.view_phone(); putchar('\n'); break;
        case 10: return; break;
        default: cout << "uh oh" << endl; break;

        }

    } while (!logout);
}



void remove_underscores(string * arr, int length){
    for(int i =0; i < length; i++)
        for(int j = 0; j < arr[i].length(); j++)
            if(arr[i][j] == '_')
                arr[i][j] = ' ';
}

void print_customer_selection() {
    // system("clear");
    printf("Welcome valued customer!\n");
    printf("1. View menu\n");
    printf("2. Search by Cost\n");
    printf("3. Search by Ingredients\n");
    printf("4. Place Order\n");
    printf("5. View Hours\n");
    printf("6. View Address\n");
    printf("7. View Phone\n");
    printf("8. Log out\n");
}


void customer_selection(Restaurant & r) {
    bool logout = false;
    string input = "";
    int input_int = -1;

    do {
        print_customer_selection();
        getline(cin, input);
        if (!is_int(input)) {
            printf("That isn't a valid integer input!\n");
            continue;
        }
        input_int = get_int(input);

        switch (input_int) {
        case 1: r.view_menu(); break;
        case 2: r.search_by_cost(); break;
        case 3: cout << "nothing here" << endl; break;
        case 4: r.place_order(); break;
        case 5: r.view_hours(); break;
        case 6: printf("ADDRESS: \n"); r.view_address(); putchar('\n'); break;
        case 7:  printf("PHONE:\n"); r.view_phone(); putchar('\n'); break;
        case 8: return; break;
        default: cout << "I don't understnad what you're saying" << endl; break;

        }

    } while (!logout);
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