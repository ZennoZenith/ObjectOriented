#include<iostream>

using namespace std;

class MatrixElement{
	
public:
	int element;
	static int count;
	static int multiply(int a, int b){
		count++;
		// cout<<a<<" "<<b<<endl;
		return (a) * (b);
	}
	MatrixElement(){
		element = 0;
	}
	MatrixElement(MatrixElement &m){
		element = m.element;
	}
	void setElement(){
		cin>>element;
	}
	void setElement(int a){
		element = a;
	}
	int getElement(){
		return element;
	}
	void addElement(int a){
		element += a;
	}


};
int MatrixElement::count = 0;

int main(){
	int m=2,n=2,p=2,q=2;
	cout<<"Enter m rows and n column for matrix1 : ";
	cin>>m>>n;
	cout<<"\nEnter p row and q column for matrix2 : ";
	cin>>p>>q;
	MatrixElement x;
	MatrixElement matrix1[m][n];
	MatrixElement matrix2[p][q];
	if(n != p){
		cout<<"Column(s) of matrix1 is not equal to row(s) of matrix2.\n Exitting...\n";
		return 1;
	}
	MatrixElement matrix3[m][q];
	cout<<"Enter matrix 1 : \n";
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix1[i][j].setElement();
		}
	}
	cout<<"\nEnter matrix 2 : \n";
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < q; ++j)
		{
			matrix2[i][j].setElement();
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < q; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				matrix3[i][j].addElement(x.multiply(matrix1[i][k].element, matrix2[k][j].element));
			}
			// cout<<matrix3[i][j].element<<endl;
		}
	}
	// for (int i = 0; i < m; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout<<matrix1[i][j].element<<" ";
	// 	}
	// 	cout<<endl;
	// }for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < p; ++j)
	// 	{
	// 		cout<<matrix2[i][j].element<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<"\nAfter multiplying matrix1 and matrix 2 : \n";
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < q; ++j)
		{
			cout<<matrix3[i][j].element<<" ";
		}
		cout<<endl;
	}
	cout<<"Number of multiplication : "<<x.count<<endl;

	MatrixElement copy(matrix3[0][0]);
	MatrixElement *ptr = &copy;
	cout<<"Copy of first element of matrix 1 : "<<copy.element<<endl;
	cout<<"Address of copy object : "<<&copy<<endl;
	cout<<"Address stored in ptr : "<<ptr<<endl;
	cout<<"Pointer to copy object element value : "<<ptr->element<<endl;

	return 0;
}