#include<iostream>
#include<string>

using namespace std;

#define EXCHANGE_VALUE 82

class String{
private:
	char *str;
public:
	String(){
		str = NULL;
	}
	String(const char *s){
		str = new char[strlen(s)];
		// str = new char[strlen(s) + 1];
		strcpy(str,s);
	}
	String(const string &s){
		// if(str != NULL)
			// delete[] str;
		// cout<<"\nAssigning string to Stirng\n";
		str = new char[s.length()+1];
		strcpy(str,s.c_str());
		// cout<<" -- "<<str<<" -- "<<endl;
	}
	operator string(){
		// cout<<"\nAssigning String to stirng\n";
		return string(str);
	}
	const char* getStr(){
		return str;
	}

	friend ostream & operator << (ostream &out, String &s){
		// cout<<"\nostream called\n";
		// cout<<" ??? "<<s.str<<" ??? "<<endl;
		out<<s.str;
		return out;
	}
	~String(){
		// delete[] str;
	}
};

int main(){
	string str1 = "Hello World" ;
	string str2;
	String Str1("New Hello World!");
	String Str2;
	cout<<"str 1 : "<<str1<<endl;
	cout<<"Str 1 : "<<Str1.getStr()<<endl;


	Str2 = str1;
	// cout<<"Str 1 : "<<Str1.getStr()<<endl;

	str2 = Str1;

	cout<<"Str 2 : "<<Str2.getStr()<<endl;

	cout<<"str 2 : "<<str2<<endl;
 	
	return 0;
}