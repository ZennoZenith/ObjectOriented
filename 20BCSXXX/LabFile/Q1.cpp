#include <iostream>

using namespace std;

class Student
{
	int id;
	char name[100];
	int marks;
	int age;
	int standard;

public:
	void getData();
	void showData();
	void Read(char *ch);
};

void Student::getData()
{
	cout << "Enter student id : ";
	// cin>>id;
	// cin.ignore();
	id = rand() % 100;
	cout << id << endl;

	cout << "Enter student name : ";
	scanf("%[^\n]%*c", name);

	cout << "Enter age : ";
	// cin>>age;
	// cin.ignore();
	age = (rand() % 10) + 10;
	cout << age << endl;

	cout << "Enter standard : ";
	//	cin>>standard;
	// cin.ignore();
	standard = (rand() % 10) + 5;
	cout << standard << endl;

	cout << "Enter marks (out of 100) : ";
	//	cin>>marks;
	// cin.ignore();
	marks = (rand() % 10) + 5;
	cout << marks << endl;
}

void Student::showData()
{
	cout << "Name : " << name << endl;
	cout << "ID : " << id << endl;
	cout << "Age : " << age << endl;
	cout << "Standard : " << standard << endl;
	cout << "Marks : " << marks << "\n\n";
}

int main()
{
	Student s[100];
	int numberOfStudents = 0;
	cout << "Enter number of students : ";
	cin >> numberOfStudents;
	cin.ignore();

	int i = 0;
	for (i = 0; i < numberOfStudents; i++)
	{
		printf("Student %d :\n", i + 1);
		s[i].getData();
	}
	cout << "\n\nStudent Details...\n";
	for (i = 0; i < numberOfStudents; i++)
	{
		printf("Student %d Details\n", i + 1);
		s[i].showData();
	}
	return 0;
}