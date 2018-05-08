#include "driver.hpp"

using namespace std;

void print_properties(const Property* props, const int num){
    for(int i = 0; i < num; i++){
        cout << props[i].get_type() << endl;
    }
}