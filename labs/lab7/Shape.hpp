#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <cstdlib>
using namespace std;

class Shape {
protected:
	string name;
	string color;
	int area;

public:
	void set_name(string n);
	void set_color(string c);

	string get_name();
	string get_color();
	int get_area();

	Shape();
	virtual int calc_area(){};

};

#endif 