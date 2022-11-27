#include <iostream>

using namespace std;

void Read(char *ch)
{
	int i = 0;
	char c;
	while (1)
	{
		scanf("%c", &c);
		if (c == '\n' || c == '\r')
		{
			*(ch + i) = '\0';
			break;
		}
		else
		{
			*(ch + i) = c;
		}
		i++;
	}
}

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
	int getID()
	{
		return id;
	};
	char *getName()
	{
		return name;
	};
};

class Teacher
{
	Student students[100];
	int numberOfStudents;

public:
	Teacher()
	{
		numberOfStudents = 0;
	}
	void getStudentData();
	void getStudentData(int);
	void displayStudentData();
	void displayStudentData(int);
	void setNumberOfStudents(int n)
	{
		numberOfStudents = n;
	}
	int getNumberOfStudents()
	{
		return numberOfStudents;
	}
	void searchStudentById();
	void searchStudentByName();
};

int main()
{
	Teacher t;
	t.getStudentData(3);
	return 0;
}

void Student::getData()
{
	cout << "Enter student id : ";
	// cin>>id;
	id = rand() % 1000;
	cout << id << endl;

	cout << "Enter student name : ";
	Read(name);
	// gets(name);
	cout << "Enter age : ";
	// cin>>age;
	age = (rand() % 10) + 10;
	cout << age << endl;

	cout << "Enter standard : ";
	//	cin>>standard;
	standard = (rand() % 10) + 5;
	cout << standard << endl;

	cout << "Enter marks (out of 100) : ";
	//	cin>>marks;
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

void Teacher::getStudentData()
{
	students[numberOfStudents].getData();
	numberOfStudents++;
}
void Teacher::getStudentData(int n)
{
	for (int i = 0; i < n; ++i)
	{
		students[numberOfStudents].getData();
		numberOfStudents++;
	}
}
void Teacher::displayStudentData()
{
	for (int i = 0; i < numberOfStudents; ++i)
	{
		students[i].showData();
	}
}
void Teacher::displayStudentData(int n)
{
	for (int i = 0; i < n; ++i)
	{
		students[i].showData();
	}
}
void Teacher::searchStudentById()
{
	int id;
	cout << "Enter id to be searched : ";
	cin >> id;
	int flag = 0;
	for (int i = 0; i < numberOfStudents; ++i)
	{
		if (id == students[i].getID())
		{
			if (flag == 0)
				cout << "Student found!!!\n";
			flag = 1;
			students[i].showData();
		}
	}
	if (flag == 0)
		cout << "Student not found!!!\n";
}
void Teacher::searchStudentByName()
{
	int id;
	cout << "Enter id to be searched : ";
	cin >> id;
	int flag = 0;
	for (int i = 0; i < numberOfStudents; ++i)
	{
		if (id == students[i].getID())
		{
			if (flag == 0)
				cout << "Student found!!!\n";
			flag = 1;
			students[i].showData();
		}
	}
	if (flag == 0)
		cout << "Student not found!!!\n";
}
