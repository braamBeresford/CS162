#include "driver.hpp"
#include "restaurant.hpp"
#include "menu.hpp"

//Constructor
Restaurant::Restaurant() {
    Menu menu;

    employees = NULL;
    num_days = 0;
    week = NULL;
    name = "NA";
    phone = "000-000-0000";
    address = "NA";
    num_employees = 0;

}


Restaurant::~Restaurant(){
    delete [] employees;
    delete [] week;
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
    cout << "IM HERE!" << endl;
    for (int i = 0; i < num_employees; i++)
        f >> employees[i].id >> employees[i].first_name >> employees[i].last_name >> employees[i].password;
}


void Restaurant::add_item_to_menu(){
    menu.add_item_to_menu();

}

void Restaurant::remove_iterm_from_menu(){
    menu.remove_iterm_from_menu();
}