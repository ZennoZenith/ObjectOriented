#include<iostream>
#include<string>

using namespace std;

class Class{
	struct Student{
		int rollNumber;
		char name[50];
	}students[50];
	int numberOfStudents;
public:
	Class(){
		numberOfStudents = 0;
	}
	const char * operator[](int);
	int operator[](const char * );
	void addStudent(int , const char *);
};
const char* Class::operator[](int rollNumber){
	for(int i=0; i < numberOfStudents; i++){
		if(students[i].rollNumber == rollNumber)
			return students[i].name;
	}
	return "Not-found";
}
int Class::operator[](const char* name){
	for(int i=0; i < numberOfStudents; i++){
		if(strcmp(students[i].name, name) == 0)
			return students[i].rollNumber;
	}
	return -1;	
}
void Class::addStudent(int rollNumber,const char *name){
	students[numberOfStudents].rollNumber = rollNumber;
	strcat(students[numberOfStudents].name, name);
	numberOfStudents++;
}


int main(){
	Class c;
	c.addStudent(1, "Name 1");
	c.addStudent(2, "Name 2");
	c.addStudent(3, "Name 3");
	c.addStudent(4, "Name 4");
	c.addStudent(5, "Name 5");
	cout<<"c[3] ? " << c[3]<<endl;
	cout<<"c[7] ? " << c[7]<<endl;
	cout<<"c[\"Name 5\"] ? " << c["Name 5"]<<endl;
	cout<<"c[\"Name 7\"] ? " << c["Name 7"]<<endl;
	return 0;
}