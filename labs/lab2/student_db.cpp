#include "student_db.h"

using namespace std;


student * create_student_db(int num) {
	student * temp = new student[num];
	return temp;
}


void get_student_db_info(student * students, int num, fstream &f) {
	string last, first, major;
	int ID;
	for (int i = 0; i < num; i++) {
		f >> ID >> first >> last >> major;

		students[i].ID = ID;
		students[i].first_name = first;
		students[i].last_name = last;
		students[i].major = major;
	}
}


void delete_student_db_info(student ** students, int num) {
	delete [] *students;

	students = NULL;
}

void sort_by_ID(student * students, int num) {
	sort(students, students + num, ID_sorter);
}

bool ID_sorter(student s1, student s2) {
	return (s1.ID > s2.ID);
}

void print_students(student * students, int num_student) {
	for (int i = 0; i < num_student; i++) {
		cout << students[i].ID <<  " " << students[i].last_name << endl;
	}
}

bool name_sorter(student s1, student s2) {
	return (s1.last_name < s2.last_name);
}

void sort_by_name(student * students, int num) {
	sort(students, students + num, name_sorter);
}

int major_counter(student * students, int num) {
	string temp[num];
	int counter = 0;
	bool found = false;
	int countr = 6;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (students[i].major == temp[j]) {
				found = true;
				break;
			}
		}

		if (!found) {
			counter++;
			// temp.apend(students[i].major);

		}
	}

	return countr;
}


void chooser(student * students, int num_student) {
	string input = "";

	while (1) {
		cout << "Choose what you would like to do" << endl;
		cout << "1. For sort by student names" << endl;
		cout << "2. For sort by student ID" << endl;
		cout << "3. For number of majors" << endl;
		cout << "Antyhing else to quit." << endl;

		cin >> input;

		if (input == "1") {
			sort_by_name(students, num_student);
			print_students(students, num_student);

		}

		else if (input == "2") {
			sort_by_ID(students, num_student);
			print_students(students, num_student);

		}
		else if (input == "3"){
			cout << "Unique majors: " <<  major_counter( students, num_student) << endl;
		}
		else
			break;
	}
}