#include "driver.hpp"
#include "restaurant.hpp"
#include "menu.hpp"

//Constructor
Restaurant::Restaurant() {
    Menu menu;
    orders = NULL;
    employees = NULL;
    num_orders = 0;
    num_days = 0;
    week = NULL;
    name = "NA";
    phone = "000-000-0000";
    address = "NA";
    num_employees = 0;

}


Restaurant::~Restaurant(){
    if(employees != NULL)
        delete [] employees;
    if(week != NULL)
        delete [] week;
    
    employees = NULL;
    week = NULL;
}


// Accessors
void Restaurant::view_hours() const{
    for (int i = 0; i < 7; i++) {
        cout << week[i].day << ' ' <<  week[i].open_hour  << ' ' << week[i].close_hour << endl;
    }
}

void Restaurant::view_name() const { cout << name << endl;}
void Restaurant::view_address() const { cout << this->address << endl; }
void Restaurant::view_phone() const { cout << phone << endl; }
void Restaurant::view_num_employees() const { cout << this-> num_employees << endl; }
int Restaurant::return_num_employees() const { return this->num_employees;}
void Restaurant::view_employees() const {
    if (!employees) {
        for (int i = 0; i < this->num_employees; i++) {
            cout << employees[i].id << employees[i].first_name << employees[i].last_name << employees[i].password << endl;
        }
    }
}

void Restaurant::view_menu() const{
    menu.view_menu();
}


void Restaurant::search_by_cost(){
    string input ="", size = "";
    int price = 0;
    while(true){
        printf("What size are you looking for? (small, medium, large) \n");
        getline(cin, size);
        if(size == "small" || size == "medium" || size == "large")
            break;

        printf("Invalid input, lower case only\n");
    }
    while(true){
        printf("What is the max price you're looking for? \n");
        getline(cin, input);
        if(is_int(input)){
            price = get_int(input);
            break;
        }
    }

    Menu results = menu.search_pizza_by_cost(price, size);
    cout << "I'm here! " << endl;
    results.view_menu();
    // menu.view_menu();
}

bool Restaurant::validate_login(Restaurant &r) const{
    string input = "";
    bool valid = false;
    do{
        printf("Username: \n");
        getline(cin, input);
        if(input == "Q" || input == "q")
            return false;
        for(int i =0; i < r.return_num_employees(); i++){
            if(employees[i].id == input){
                valid = true;
                break;
            }
        }
        
        printf("Please input a valid username. Q to quit\n");

    } while(!valid);
    valid = false;
    do{
        system("clear");
        printf("Password: \n");
        getline(cin, input);
        for(int i =0; i < r.return_num_employees(); i++){
            if(employees[i].password == input){
                valid = true;
                break;
            }

            printf("Please input a valid password\n");
        }
    } while(!valid);

    return true;
}


//Mutators
void Restaurant::set_name(string new_name) {name = new_name;}
void Restaurant::set_phone(string new_phone)  {phone = new_phone;}
void Restaurant::set_address(string new_add) {address = new_add;}
void Restaurant::set_num_days(int num) { num_days = num;}

void Restaurant::load_data() {
    int num_days;
    fstream f;
    verify_file_open(f, REST_NAME); //opens and checks, re-prompts too
    getline(f, this->name);
    getline(f, this->phone);
    getline(f, this->address);

    f >> this->num_days;

    this->week = new hours[num_days];
    for (int i = 0; i < num_days; i++) {
        f >> week[i].day >> week[i].open_hour >> week[i].close_hour;
    }

    f.close();

    verify_file_open(f, EMP_NAME);
    this->num_employees = get_num_lines(f);
    employees = new employee [num_employees];
    get_employees(f);

    f.close();
    verify_file_open(f, ORD_NAME);
    this->num_orders = get_num_lines(f);
    this->orders = new order [this->num_orders*100];
    get_orders(f);
    f.close();

    menu.load_data(); 
}


void Restaurant::change_hours(){
    string input = "";
    int index = 0;
    this->view_hours();
    printf("What day would you like to change? ");
    cin >> input;
    index = verify_week_day(input);

    do{
    printf("What opening time would you like? ");
    cin >> input;
    }while(!is_int(input));
    week[index].open_hour = input;

    do{
    printf("What closing time would you like? ");
    cin >> input;
    }while(!is_int(input));
    week[index].close_hour = input;
}

void Restaurant::place_order(){
   order temp;
   menu.place_order(temp);
   this->num_orders++;
   temp.order_num = num_orders;
   orders[num_orders - 1] = temp;
}

int Restaurant::verify_week_day(string input){
    while(true){
        for(int i =0; i < this->num_days; i++){
            if(this->week[i].day == input)
                return i;
        }
        printf("That is not a valid day of the week! Please re-enter it! ");
        cin >> input;
    }
}

/*********************************************************************
 ** Function: get_employees
 ** Description: Pulls employee data from file into struct
 ** Parameters: Requires already open file object
 ** Pre-Conditions: Requires already open file object
 ** Post-Conditions: Fills already created employee array;
 *********************************************************************/
void Restaurant::get_employees(fstream &f) {
    for (int i = 0; i < num_employees; i++)
        f >> employees[i].id >> employees[i].first_name >> employees[i].last_name >> employees[i].password;
}

void Restaurant::view_orders(){
    for(int i =0; i < this->num_orders; i++){
        cout << orders[i].order_num << " " << orders[i].customer_first << " " << orders[i].customer_last << " ";
        cout << orders[i].credit_card << " " << orders[i].address << " " << orders[i].pizza << " " << orders[i].size;
        cout << " " << orders[i].quantity;
        putchar('\n');
    }    
}

void Restaurant::get_orders(fstream &f){
    for(int i =0; i < this-> num_employees; i++){
        f >> orders[i].order_num >> orders[i].customer_first >> orders[i].customer_last;
        f >> orders[i].credit_card >> orders[i].address >> orders[i].phone;
        f >> orders[i].pizza >> orders[i].size >> orders[i].quantity;
    }
}

void Restaurant::add_item_to_menu(){
    menu.add_item_to_menu();

}

void Restaurant::remove_iterm_from_menu(){
    menu.remove_iterm_from_menu();
}