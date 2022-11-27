#include <iostream>

using namespace std;

#define EXCHANGE_VALUE 82

class Currency
{
protected:
	float value;

public:
	void setValue()
	{
		cin >> value;
		cin.ignore();
	}
	float getValue()
	{
		return value;
	}
};

class Rupee : public Currency
{
public:
	Rupee(float val = 0)
	{
		value = val;
	}
};

class Dollar : public Currency
{
public:
	Dollar(float val = 0)
	{
		value = val;
	}
	Dollar(Rupee &r)
	{
		value = r.getValue() / EXCHANGE_VALUE;
	}
	operator Rupee()
	{
		return Rupee(value * EXCHANGE_VALUE);
	}
};

int main()
{

	Dollar d1(10);
	Rupee r1(100);

	Dollar d2;
	Rupee r2;

	cout << "Enter the value in Rupees : ";
	r1.setValue();
	d2 = r1;
	cout << "Value in Dollar : " << d2.getValue() << endl;

	cout << "Enter the value in Dollars: ";
	d1.setValue();
	r2 = d1;
	cout << "Value in Rupee: " << r2.getValue() << endl;
	return 0;
}