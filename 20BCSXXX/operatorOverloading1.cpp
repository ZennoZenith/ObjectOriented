#include<iostream>

using namespace std;

class Bool{
	bool number;
public:
	Bool(bool t = false){
		number = t;
	}
	bool operator&&(bool);
	bool operator||(bool);
	bool operator&&(const Bool &);
	bool operator||(const Bool &);
	bool operator!(void);
};
bool Bool::operator&&(bool num){
	return number && num;
}
bool Bool::operator||(bool num){
	return number || num;
}
bool Bool::operator&&(const Bool &num){
	return number && num.number;
}
bool Bool::operator||(const Bool &num){
	return number || num.number;
}
bool Bool::operator!(void){
	return !number;
}

int main(){
	Bool i(false),j(false),k(true);
	cout<<" i || j ? "<<(i || j )<< endl;
	cout<<" i && j ? "<<(i && j )<< endl;
	cout<<" i || k ? "<<(i || k )<< endl;
	cout<<" i && k ? "<<(i && k )<< endl;
	cout<<" i || true ? "<<(i || true )<< endl;
	cout<<" i && false ? "<<(i || false )<< endl;
	cout<<" j || false ? "<<(j || false )<< endl;
	cout<<" j && false ? "<<(j || false )<< endl;
	cout<<" !i ? "<<(!i)<< endl;
	cout<<" !k ? "<<(!k)<< endl;

	return 0;
}