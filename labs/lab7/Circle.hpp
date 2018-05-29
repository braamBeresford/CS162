#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

using namespace std;

class Circle:public Shape{
private:
	int radius;

public:
	void set_radius(int r);

	int get_radius();

	int get_area();

	Circle();
};

#endif