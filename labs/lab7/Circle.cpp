#include "Circle.hpp"

using namespace std;

void Circle::set_radius(int a) {radius = a;}
int Circle::get_radius() {return radius;}

int Circle::get_area() {return area;}

Circle::Circle() {
	this->name = "Circle";
	this->color = "Green";
	this->area = 3.14*2*2;
}