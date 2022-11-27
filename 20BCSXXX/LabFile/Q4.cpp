#include <iostream>
using namespace std;
class Media
{
public:
  string title;
  string publication;
  virtual void read();
  virtual void display();
};
void Media::read()
{
  cout << "Enter title : ";
  getline(cin, title, '\n');
  cout << "Enter publication : ";
  getline(cin, publication, '\n');
}
void Media::display()
{
  cout << "Title: " << title << endl;
  cout << "Publication: " << publication << endl;
}

class Book : public Media
{
public:
  int pages;
  void read();
  void display();
};
void Book::read()
{
  Media::read();
  cout << "Enter number of pages : ";
  cin >> pages;
  cin.ignore();
}
void Book::display()
{
  Media::display();
  cout << "Pages : " << pages << endl;
}

class Tape : public Media
{
public:
  int time;
  void read();
  void display();
};
void Tape::read()
{
  Media::read();
  cout << "Enter time : ";
  cin >> time;
  cin.ignore();
}
void Tape::display()
{
  Media::display();
  cout << "Time : " << time << endl;
}

int main()
{
  Media *book = new Book();
  Media *tape = new Tape();
  cout << "Enter details of book...\n";
  book->read();
  cout << "Enter details of tape...\n";
  tape->read();
  cout << "\nDetails of book..." << endl;
  book->display();
  cout << "\nDetails of tape" << endl;
  tape->display();
  return 0;
}