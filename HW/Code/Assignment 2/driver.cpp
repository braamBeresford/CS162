#include "driver.hpp"


int main() {
	Restaurant r;
	// string arr[] = {"hell_my", "sweet_prince", "jake"};
	// remove_underscores(arr,  3);
	// for(int i =0; i < 3; i ++)
	// 	cout << arr[i] << endl;
	// int test[1000000] = {0};
	r.load_data();
	user_choice(r);
}