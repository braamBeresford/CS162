#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

using namespace std;

class Rectangle:public Shape {
private:
	int length;
	int width;

public:
	void set_length(int a);
	void set_width(int a);

	int get_length();
	int get_width();

	int get_area();

	Rectangle();
};

#endif