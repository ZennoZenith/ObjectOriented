#include<iostream>

using namespace std;

class Student{
	int id;
	char name[100];
	int marks;
	int age;
	int standard;

public:
	void getData();
	void showData();
};


int main(){
	Student s;
	s.getData();
	s.showData();
	return 0;
}

void Student::getData(){
	cout<<"Enter student id : ";
	cin>>id;
	cout<<"Enter student name : ";
	// while((getchar()) != '\n');
	getchar();
	cin.getline(name,100);
	cout<<"Enter age : ";
	cin>>age;
	cout<<"Enter standard : ";
	cin>>standard;
	cout<<"Enter marks (out of 100) : ";
	cin>>marks;
}

void Student::showData(){
	cout<<"Student details\n";
	cout<<"Name : "<<name<<endl;
	cout<<"ID : "<<id<<endl;
	cout<<"Age : "<<age<<endl;
	cout<<"Standard : "<<standard<<endl;
	cout<<"Marks : "<<marks<<endl;
}	

