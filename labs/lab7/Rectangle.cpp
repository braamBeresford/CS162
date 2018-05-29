#include "Rectangle.hpp"

using namespace std;

void Rectangle::set_length(int a) {length = a;}
void Rectangle::set_width(int a) {width = a;}

int Rectangle::get_length() {return length;}
int Rectangle::get_width() {return width;}
int Rectangle::get_area() {return area;}

Rectangle::Rectangle() {
	this->name = "Rectangle";
	this->color = "Orange";
	this->area = 2*8;
}