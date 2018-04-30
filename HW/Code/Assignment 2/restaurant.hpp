#ifndef RESTAURANT
#define RESTAURANT

#include "driver.hpp"
#include "menu.hpp"
// #include "pizza.hpp"

class Restaurant {
private:
    Menu menu;
    int num_employees;
    employee * employees;
    int num_days;
    hours * week;
    string name;
    string phone;
    string address;
    

public:
    //Constructors
    Restaurant();
    ~Restaurant();

    //Accessors
    void view_name() const;
    void view_hours() const;
    void view_address()const;
    void view_phone() const;
    void view_num_employees() const;
    int return_num_employees() const;
    void view_employees() const;
    void view_menu() const;
    bool validate_login(Restaurant &r) const;



    //Mutators
    void set_name(string name) ;
    void set_phone(string phone);
    void set_address(string addr);
    void get_employees(fstream &f);
    void load_data();
    void set_num_days(int num);
    void change_hours();
    int verify_week_day(string input);
    void add_item_to_menu();
    void remove_iterm_from_menu();

    // To Do
    bool login(string id, string password);
    void search_menu_by_price();
    void search_by_ingredients();
    // void place_order(Pizza* selection);
    void add_to_menu();
    void remove_from_menu();
    void view_orders();
    void remove_orders();
};

#endif