#include "Students.hpp"
#include "SList.hpp"
#include <iostream>
using namespace std;

int main()
{
	SList	slist;

	//* Test Insertion
	slist.addStudent(Students("Alice", 1, {100, 90, 80}));
	slist.addStudent(Students("Bob", 2, {90, 80, 70}));
	slist.addStudent(Students("Charlie", 3, {80, 70, 60}));
	slist.addStudent(Students("David", 4, {70, 60, 50}));
	slist.addStudent(Students("Eve", 5, {90, 80, 90}));

	slist.printStudents();

	//* Test operator[]
	cout << "Printing students using operator[]:" << endl;
	for (int i = 0; i < slist.size(); i++) {
		cout << slist[i] << endl;
	}

	//* Test delete
	cout << "Test delete" << endl;
	slist.deleteStudent(2);
	slist.printStudents();

}
