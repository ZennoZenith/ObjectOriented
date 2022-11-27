#include <typeinfo>
#include <iostream>

using namespace std;

class test
{
  int marks;
  char name[100];
  int arr[50];

public:
  int *ptr;
  // https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)
  // constructor
  test()
  {
    cout << "New test object created\n";
    marks = 99;
    for (int i = 0; i < 50; i++)
    {
      name[i] = 'A' + i;
      arr[i] = i * 2;
    }
    name[50] = '\0';
    ptr = new int(786);
  }
  // A type of overlaoded constructor
  test(test *t)
  {
    marks = t->marks;
    cout << "Copy Constructor with pointer variable called\n";
  }
  // Copy constructor
  // using const is optional. It insures that referential object cannot be changed inside copy constrcutor
  test(const test &t)
  {
    marks = t.marks;
    cout << "Copy Constructor witn reference variable called\n";
    int i = 0;
    delete ptr;
    ptr = new int(*t.ptr);
  }
  // copy assignment operator
  // using const is optional. It insures that referential object cannot be changed inside copy assignment operator
  // https://en.wikipedia.org/wiki/Assignment_operator_(C%2B%2B)
  test &operator=(const test &other)
  {
    cout << "Copy assignment operator called\n";
    if (this != &other)
    { // protect against invalid self-assignment
      // 1: allocate new memory and copy the elements
      int *new_ptr = new int(other.marks);
      // copy(other.ptr, other.ptr + other.marks, new_ptr);

      // 2: deallocate old memory
      // delete[] ptr;
      delete ptr;

      // 3: assign the new memory to the object
      ptr = new_ptr;
      marks = other.marks;
    }
    // by convention, always return *this
    return *this;
  }
  void showMarks()
  {
    cout << marks << endl;
  };

  // New object t is created and copy constructor is called
  void showMarks(test t)
  {
    cout << t.marks << endl;

    // for testing purpose
    t.marks += 10;
  };
  void showMarksPtr(test *t)
  {
    cout << t->marks << endl;
    t->marks += 10;
  };
  void setMarks(int m)
  {
    marks = m;
  }
  char *getName()
  {
    return name;
  }
  void setName()
  {
    cin >> name;
  }
  void printArr()
  {
    for (int i = 0; i < 10; i++)
    {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
  void setArr()
  {
    for (int i = 0; i < 5; i++)
    {
      cout << "arr[" << i << "]"
           << " : ";
      cin >> arr[i];
    }
  }
  // Destructor
  ~test()
  {
    delete ptr;
  }
};

int main()
{
  test t1, t2;
  cout << "Address stored in t1.ptr = " << t1.ptr << endl;
  cout << "Address stored in t2.ptr = " << t2.ptr << endl;
  // test t3 = t2;
  test t3;
  t3 = t2;
  cout << "Address stored in t3.ptr = " << t3.ptr << endl;
  // test t1, t2;
  // cout << "t1 : " << t1.getName() << endl;
  // t2.setName();
  // // test t3;
  // // t3 = t2;
  // test t3 = t2;
  // cout << "t2 : " << t2.getName() << endl;
  // cout << "t3 : " << t3.getName() << endl;
  // t3.setName();
  // cout << "t2 : " << t2.getName() << endl;
  // cout << "t3 : " << t3.getName() << endl;

  // t1.printArr();
  // t2.setArr();
  // t2.printArr();
  // test t3 = t2;
  // t3.printArr();

  // t3.setArr();

  // t2.printArr();
  // t3.printArr();
  // test t3(&t1);
  // t1.setMarks(10);
  // t2.showMarks(t1);
  // t2.showMarksPtr(&t1);
  // t1.showMarks();
  // t3.showMarks();
  // test arr[10];

  int a[2][2];
  cout << typeid(a).name() << endl;

  int i = 5;
  // i = (++i) / float(i++);
  // int b = (++i) / (i++);
  // cout << b << endl;
  // cout << i << endl;
  // while (printf("%d", printf("a2")))
  //   printf("by");
  // int **doublePtr = a;

  unsigned int bitWise = 0;
  cout << bitWise << endl;
  cout << ~bitWise << endl;
  return 0;
}