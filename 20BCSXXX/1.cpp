#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

using namespace std;

struct student
{
	int roll_no;
	char name[20];
	int semester;
	int marks;
};

int main()
{
	student s[100];
	int n;
	string temp2;
	int max = s[0].marks;
	cout << "Enter number of Students: ";
	cin >> n;
	cin.ignore();

	int choice;
	cout << "1.Enter Student Details: " << endl;
	cout << "2.Display Student Details: " << endl;
	cout << "3.Search Student using Roll No.: " << endl;
	cout << "4.Search Student using by Name: " << endl;
	cout << "5.Display Topper Student" << endl;
	cout << "6.Exit: " << endl;
	cout << "Enter choice : ";
	cin >> choice;
	while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6)
	{
		switch (choice)
		{
		case 1:
			for (int i = 0; i < n; i++)
			{
				cout << "Roll No.: ";
				cin >> s[i].roll_no;
				cin.ignore();
				cout << "Name: ";
				cin.getline(s[i].name, 20);
				cout << "Semester: ";
				cin >> s[i].semester;
				cin.ignore();
				cout << "Marks: ";
				cin >> s[i].marks;
				cin.ignore();
			}
			cout << "Enter choice : ";
			cin >> choice;
			cin.ignore();

			break;
		case 2:
			for (int i = 0; i < n; i++)
			{
				printf("%3d\t%20s\t%d\t%3d\n", s[i].roll_no, s[i].name, s[i].semester, s[i].marks);
			}
			cout << "Enter choice";
			cin >> choice;
			cin.ignore();

			break;
		case 3:
			int temp;
			cout << "Enter Roll No. to search: ";
			cin >> temp;
			cin.ignore();

			for (int i = 0; i < n; i++)
			{
				if (s[i].roll_no == temp)
					printf("%3d\t%20s\t%d\t%3d\n", s[i].roll_no, s[i].name, s[i].semester, s[i].marks);
			}
			cout << "Enter choice";
			cin >> choice;
			cin.ignore();

			break;
		case 4:
			cout << "Enter Name to search: ";
			cin >> temp2;

			for (int i = 0; i < n; i++)
			{
				if (temp2.find(s[i].name) >= 0 && temp2.find(s[i].name) <= 20)

					printf("%3d\t%20s\t%d\t%3d\n", s[i].roll_no, s[i].name, s[i].semester, s[i].marks);
			}
			cout << "Enter choice : " << endl;
			cin >> choice;
			cin.ignore();

			break;
		case 5:
			for (int i = 0; i < n; i++)
			{
				if (max < s[i].marks)
					printf("%3d\t%20s\t%d\t%3d\n", s[i].roll_no, s[i].name, s[i].semester, s[i].marks);
				;
			}

			cout << "Enter choice : " << endl;
			cin >> choice;
			cin.ignore();

			break;
		case 6:
			return 0;
		}
	}

	return 0;
}