#include<iostream>

using namespace std;

class test{
public:
	int a;
	test(){
		a=1;
	}
};
int main(){
	int i=0;

	while(i<5){
		test *t = new test;
		int *abc = new int(10);
		cout<<"Address of t : "<<t<<endl;
		cout<<"Address of abc : "<<abc<<endl;
		i++;
		// delete t;
	}