#include<iostream>
#include<string>

using namespace std;

#define MAX_ARR_SIZE 10
class Vector{
	int * arr;
	int length;
public:
	void * operator new(size_t size);
	void operator delete(void *);
	void show();
	void set();
};

void * Vector::operator new(size_t size){
	cout<<"New operator called\n";
	Vector *temp = ::new Vector;
	temp->arr = new int[MAX_ARR_SIZE];
	temp->length = MAX_ARR_SIZE;
	for (int i = 0; i < MAX_ARR_SIZE; ++i)
	{
		temp->arr[i] = 0;
	}
	return temp;
}
void Vector::operator delete(void * v){
	cout<<"Delete operator called\n";
	Vector* temp = (Vector*)v;
	delete[] temp->arr;
	::delete temp;
}

void Vector::show(){
	for (int i = 0; i < length; ++i)
	{
		cout<<"v["<<i<<"] = "<<arr[i]<<endl;
	}
}

void Vector::set(){
	cout<<"Length : "<<length<<endl;
	for (int i = 0; i < length; ++i)
	{
		arr[i] = i;
	}
}

int main(){
	Vector *v = new Vector;
	v->show();
	cout<<"Setting vector : \n";
	v->set();
	v->show();
	delete v;
	return 0;
}