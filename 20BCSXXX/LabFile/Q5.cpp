#include <iostream>

using namespace std;

class AccountBook
{
public:
  string name[5];
  int accountNumber[5];
  int operator[](const string &str)
  {
    for (int i = 0; i < 5; i++)
    {
      if (name[i] == str)
      {
        return accountNumber[i];
      }
    }
    return -1;
  }
  string operator[](int number)
  {
    for (int i = 0; i < 5; i++)
    {
      if (this->accountNumber[i] == number)
      {
        return name[i];
      }
    }
    return "Not Found";
  }
};
int main()
{
  AccountBook accountBook;
  string temp = "Name 1";

  for (int i = 0; i < 5; i++)
  {
    temp[5] = i + '1';
    accountBook.name[i] = temp;
    accountBook.accountNumber[i] = i + 1;
  }

  cout << accountBook["Name 4"] << endl;
  cout << accountBook["Name 7"] << endl;
  cout << accountBook[3] << endl;
  cout << accountBook[10] << endl;
}