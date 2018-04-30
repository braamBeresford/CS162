#include "student_db.h"

using namespace std;

int main() {
	char file_name [256] = "tes.txt";
	fstream f;
	while (1) {
		f.open(file_name);
		if (!f.is_open()) {
			cout << "I cannot find that file! Please input another" << endl;
			cin >> file_name;
		}
		else {
			break;
		}
	}
	int num_student;
	f >> num_student;

	student * students = create_student_db(num_student);
	get_student_db_info(students, num_student, f);
	chooser(students, num_student);
	delete_student_db_info(&students, num_student);


	return 0;
}