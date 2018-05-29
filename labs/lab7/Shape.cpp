#include "Shape.hpp"

using namespace std;

void Shape::set_name(string n) {name = n;}
void Shape::set_color(string c) {color = c;}

string Shape::get_name() {return name;}
string Shape::get_color() {return color;}
int Shape::get_area() {return area;}

Shape::Shape (){
	this->color = "";
	this->name = "";
	this->area = 0;
}
