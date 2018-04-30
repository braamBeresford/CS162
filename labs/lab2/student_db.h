#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <fstream>

using namespace std;

struct student {
	int ID;
	string first_name;
	string last_name;
	string major;
};


student * create_student_db(int num);
void get_student_db_info(student * students, int num, fstream &f);
void delete_student_db_info(student ** students, int num);
bool ID_sorter(student s1, student s2);
void sort_by_ID(student * students, int num);
void print_students(student * students, int num_student);
void sort_by_name(student * students, int num);
bool name_sorter(student s1, student s2);
int major_counter(student * students, int num);
void chooser(student * students, int num_students) ;