#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;



// template <class T> 
class car{
private:
	int price;
	int num_wheels;

public:
	int get_price() const {return price;}
	int get_num_wheels() const {return num_wheels;}

	void set_price(int p) {price = p;}
	void set_num_wheels(int w) {num_wheels = w;}
};

int main(){
	// srand(time(NULL));
	vector<car> cars (5);
	vector<car>::iterator it;
	for(it = cars.begin(); it!=cars.end(); it++){
		it->set_price(4);
	}

	cout << cars.at(1).get_price() << endl;
	
	// cars[5].set_price(4);
	// cout << cars[5].get_price() << endl;
	// string temp = "";

	// vector<string> testVector;

	// for(int i = 0; i <=5; i++){
	// 	getline(cin, temp);
	// 	testVector.push_back(temp);
	// }

	// for(vector<string>::iterator it = 0; it < 5; it++)
	// 	(*it)->set_price(2);


	// for(vector<string>::iterator it = cars.begin(); it!= cars.end(); it++)
	// 	cout << ' ' << *it;

	// cout << "  DONE!" << endl;
	return 0;
}