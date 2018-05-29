#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"

using namespace std;

Shape** create_arr();
void print(Shape** arr);

int main() {
	Shape** arr = new Shape*[2];
	arr = create_arr();
	print(arr);
}



Shape** create_arr() {
	Shape** arr = new Shape*[2];
	for (int i = 0; i < 2; i++) {
		arr[i] = new Rectangle();
		arr[++i] = new Circle();
	}
	return arr;
}

void print(Shape** arr) {
	for (int i = 0; i < 2; i++) {
		cout << "The name is: " << arr[i]->get_name() << endl;
		cout << "The color is: " << arr[i]->get_color() << endl;
		cout << "The area is: " << arr[i]->get_area() << endl;
	}

}