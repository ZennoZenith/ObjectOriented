#include<iostream>

using namespace std;

#define EXCHANGE_VALUE 82

class Currency{
protected:
	float value;
public:
	float getValue(){
		return value;
	}
};



class Dollar : public Currency{
public:
	Dollar(float val = 0){
		value = val;
	}
	
};


class Rupee : public Currency{
public:
	Rupee(float val = 0){
		value = val;
	}

	Rupee(Dollar &r){
		value = r.getValue() * EXCHANGE_VALUE; 
	}
	operator Dollar(){
		return Dollar(value / EXCHANGE_VALUE);
	}
};

int main(){

	Dollar d1(10);
	Rupee r1(100);

	Dollar d2;
	Rupee r2;

	cout<<"Value of d1 : "<<d1.getValue()<<endl;
	cout<<"Value of r1 : "<<r1.getValue()<<endl;
	cout<<"Value of d2 : "<<d2.getValue()<<endl;
	cout<<"Value of r2 : "<<r2.getValue()<<endl;
	
	d2 = r1;
	r2 = d1;
	
	cout<<"Value of d2 : "<<d2.getValue()<<endl;
	cout<<"Value of r2 : "<<r2.getValue()<<endl;
	return 0;
}