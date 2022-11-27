#include<iostream>

using namespace std;

class Integer{
	int number;
public:
	Integer(int num = 0){
		number = num;
	}
	int operator<<(int);
	int operator>>(int);
	int operator<<(Integer);
	int operator>>(Integer);
};
int Integer::operator<<(int shift){
	return number<<shift;
}
int Integer::operator>>(int shift){
	return number>>shift;
}
int Integer::operator<<(Integer shift){
	return number<<shift.number;
}
int Integer::operator>>(Integer shift){
	return number>>shift.number;
}


int main(){
	Integer i(10),j(20),k(100),shift(2);
	cout<<"i << 1 : "<<(i << 1)<<endl;
	cout<<"j >> 2 : "<<(i >> 2)<<endl;
	cout<<"k << shift : "<<(k << shift)<<endl;
	cout<<"k >> shift : "<<(k >> shift)<<endl;

	return 0;
}