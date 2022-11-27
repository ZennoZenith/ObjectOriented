#include <iostream>

using namespace std;

class Time
{
  int hour;
  int minute;

public:
  Time(int h, int m)
  {
    hour = h;
    minute = m;
  }
  Time operator+(const Time &t)
  {
    int tempH = 0, tempM;
    tempM = t.minute + minute;
    if (tempM > 59)
    {
      tempH++;
      tempM -= 60;
    }
    tempH += t.hour + hour;
    return Time(tempH, tempM);
  }
  void show()
  {
    cout << hour << " : " << minute << endl;
  }
};

int main()
{
  Time t1(12, 30);
  Time t2(9, 45);
  Time t3 = t1 + t2;
  cout << "t1 -> ";
  t1.show();
  cout << "t2 -> ";
  t2.show();
  cout << "t3 -> ";
  t3.show();
  return 0;
}