#include<iostream>

using namespace std;

class Pattern{
	char ch;
public:
	Pattern(){
		ch = '*';
	}
	void printPattern(int len = 7){
		if(len%2 == 0){
			cout<<"Length is an even number";
			return;
		}

		int temp = len/2;		
		for (int i = 0; i < (len/2)+1; ++i)
		{
			for (int j = 0; j < temp; ++j)
			{
				cout<<" ";
			}
			cout<<ch;
			for (int j = 1; j < ((len/2) - temp) * 2 ; ++j)
			{
				cout<<" ";
			}
			if(i !=0)
				cout<<ch;
			cout<<endl;

			temp--;
		}
		temp = 1;
		for (int i = 0; i < (len/2); ++i)
		{
			for (int j = 0; j < temp; ++j)
			{
				cout<<" ";
			}
			cout<<ch;
			for (int j = 1; j < ((len/2) - temp) * 2 ; ++j)
			{
				cout<<" ";
			}
			if(i != (len/2) -1)
				cout<<ch;
			cout<<endl;

			temp++;
		}
	}
	void printPattern(char a, int* l);

};
void Pattern::printPattern(char a, int* l){
	int len = *l;
	cout<<"Address stored in l : "<<l<<endl;
	if(len%2 == 0){
		cout<<"Length is an even number";
		return;
	}

	int temp = len/2;		
	for (int i = 0; i < (len/2)+1; ++i)
	{
		for (int j = 0; j < temp; ++j)
		{
			cout<<" ";
		}
		cout<<a;
		for (int j = 1; j < ((len/2) - temp) * 2 ; ++j)
		{
			cout<<" ";
		}
		if(i !=0)
			cout<<a;
		cout<<endl;

		temp--;
	}
	temp = 1;
	for (int i = 0; i < (len/2); ++i)
	{
		for (int j = 0; j < temp; ++j)
		{
			cout<<" ";
		}
		cout<<a;
		for (int j = 1; j < ((len/2) - temp) * 2 ; ++j)
		{
			cout<<" ";
		}
		if(i != (len/2) -1)
			cout<<a;
		cout<<endl;

		temp++;
	}
}

int main(){
	Pattern p;
	int len = 5;
	p.printPattern();
	cout<<"Address of len"<<&len<<endl;
	p.printPattern('#',&len);
	p.printPattern(len-2);
	return 0;
}