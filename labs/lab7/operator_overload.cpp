#include <iostream>
#include <string>

using namespace std;
class Property{
private:
	int size;

public:
	int get_size() const {return this->size;}
	void set_size(int size){this->size = size;}
};


bool operator>(const Property& p1, const Property& p2){
	if(p1.get_size() > p2.get_size())
		return true;
	return false;
}

bool operator<(const Property& p1, const Property& p2){
	if(p1.get_size() < p2.get_size())
		return true;
	return false;
}

int main(){
	Property p1;
	Property p2;

	p1.set_size(5);
	p2.set_size(7);
	bool comp = p1>p2;
	cout << "P1>P2 " << comp << endl;
	comp = p1<p2;
	cout << "P1<P2 " << comp << endl;
}


