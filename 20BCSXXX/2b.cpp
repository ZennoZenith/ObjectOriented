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
	Student s1, s2, s3 ;
	cout<<"Enter details of 3 students : \n\n";
	s1.getData();
	s2.getData();
	s3.getData();
	s1.showData();
	s2.showData();
	s3.showData();
	return 0;
}

void Student::getData(){
	cout<<"Enter student id : ";
	//cin>>id;
	id = rand()%100;
	cout<<id<<endl;

	cout<<"Enter student name : ";
	// while((getchar()) != '\n');
	getchar();
	cin.getline(name,100);
	cout<<"Enter age : ";
	//cin>>age;
	age = (rand()%10) + 10;
	cout<<age<<endl;

	cout<<"Enter standard : ";
//	cin>>standard;
	standard = (rand()%10) + 5;
	cout<<standard<<endl;

	cout<<"Enter marks (out of 100) : ";
//	cin>>marks;
	marks = (rand()%10) + 5;
	cout<<marks<<endl;
}

void Student::showData(){
	cout<<"Student details\n";
	cout<<"Name : "<<name<<endl;
	cout<<"ID : "<<id<<endl;
	cout<<"Age : "<<age<<endl;
	cout<<"Standard : "<<standard<<endl;
	cout<<"Marks : "<<marks<<"\n\n";
}
