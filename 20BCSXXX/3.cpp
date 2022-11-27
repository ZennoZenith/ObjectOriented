#include <iostream>

using namespace std;

class Author{
	int authorID;
	char authorName[100];
public:
	void setAuthor();
	void getID();
	char* getName();
};

class Book{
	int id;
	char name[100];
	int authorID;
	float price;
	int pages;
public:
	void setBook();
	void createRandomBook(int);
	void printBook();
	char getName();
	int getID();
	int getAuthorId();
};

class Library{
	int numberOfBooks;
	int numberOfAuthors;
	Author a[100];
	Book b[1000];
public:
	// void getAuthorByName();
	Library(){
		numberOfAuthors = 10;
	}
	void createRandomBooks(int );
	void getBooksByAuthorID(int );
};

void Book::setBook(){
	cout<<"Enter book id : ";
	cin>>id; 
	getchar();
	cout<<"Enter book name : ";
	cin.getline(name,100);
	cout<<name<<endl;
	cout<<"Enter author name : ";
	authorID = (rand()%10) + 10;
	cout<<authorID<<endl;
}
int Book::getAuthorId(){
	return authorID;
}
void Book::createRandomBook(int numberOfAuthors){
	id = rand();
	authorID = rand()%numberOfAuthors;
	printf("Id: %d, Name: %s, authorID: %d\n",id,name,authorID );	
}
void Book::printBook(){
	printf("Id: %d, Name: %s, authorID: %d\n",id,name,authorID );	
}

void Library::createRandomBooks(int numberOfRandomBooks){
	while(numberOfRandomBooks > 0){
		b[numberOfBooks].createRandomBook(numberOfAuthors);
		numberOfBooks++;
		numberOfRandomBooks--;
	}
}
void Library::getBooksByAuthorID(int authorID){
	int numberOfBooksFound = 0;
	for (int i = 0; i < numberOfBooks; ++i)
	{
		if(authorID == b[i].getAuthorId()){
			b[i].printBook();
			numberOfBooksFound++;
		}
	}
	if(numberOfBooksFound == 0)
	{
		cout<<"No books found with given author id."<<endl;
		return;
	}
	printf("%d book(s) found.\n", numberOfBooksFound);

}

int main(){
	Library l;
	l.createRandomBooks(100);

	cout<<"\n\nCreated Random books\n\n";
	l.getBooksByAuthorID(5);
	return 0;
}