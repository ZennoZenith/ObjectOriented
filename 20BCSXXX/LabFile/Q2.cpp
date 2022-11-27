#include <iostream>

using namespace std;

class Person
{
  string name;
  string address;

public:
  Person(string n, string a)
  {
    name = n;
    address = a;
  }
  void display()
  {
    cout << "Name : " << name << endl;
    cout << "Address : " << address << endl;
  }
};
class Student : public Person
{
  float percentageMarks;

public:
  Student(string n, string a, float pM) : Person(n, a)
  {
    percentageMarks = pM;
  }
  void display()
  {
    Person::display();
    cout << "Percentage Marks : " << percentageMarks << endl;
  }
};
class Staff : public Person
{
  float salary;

public:
  Staff(string n, string a, float sal) : Person(n, a)
  {
    salary = sal;
  }
  void display()
  {
    Person::display();
    cout << "Salary : " << salary << endl;
  }
};
int main()
{
  string name;
  string address;
  float percentageMarks;
  float salary;
  cout << "Enter details of student" << endl;
  cout << "Enter name: ";
  getline(cin, name, '\n');
  cout << "Enter address: ";
  getline(cin, address, '\n');
  cout << "Enter percentage marks: ";
  cin >> percentageMarks;
  cin.ignore();

  Student s(name, address, percentageMarks);
  cout << endl;

  cout << "Enter details of staff" << endl;
  cout << "Enter name: ";
  getline(cin, name, '\n');
  cout << "Enter address: ";
  getline(cin, address, '\n');
  cout << "Enter salary: ";
  cin >> salary;
  cin.ignore();

  Staff st(name, address, salary);
  cout << endl;
  cout << "Details of student :" << endl;
  s.display();
  cout << endl;
  cout << "Details of staff :" << endl;
  st.display();
  return 0;
}