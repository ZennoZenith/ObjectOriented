
#include<iostream>

using namespace std;

class PackageDetails{
public:
	string name;
	string address;
	string city;
	string state;
	int zipCode;
	void setDetails();
	void showDetails();
};

void PackageDetails::setDetails(){
	cout<<"Enter name : ";
	getline(cin, name, '\n');
	cout<<"Enter city : ";
	getline(cin, city, '\n');
	cout<<"Enter address : ";
	getline(cin, address, '\n');
	cout<<"Enter state : ";
	getline(cin, state, '\n');
	cout<<"Enter zip code : ";
	cin>>zipCode;
	cin.ignore();
	cout<<endl;
}
void PackageDetails::showDetails(){
	cout<<"Name : "<<name<<endl;
	cout<<"City : "<<city<<endl;
	cout<<"Address : "<<address<<endl;
	cout<<"State : "<<state<<endl;
	cout<<"Zip code : "<<zipCode<<endl<<endl;
}

class Package{
protected:
	PackageDetails from;
	PackageDetails to;
	double costPerWeight;
	double weight;
public:
	Package(){
		weight = 0.5;
		costPerWeight = 10;
		cout<<"Package constructor called\n";
	}
	void setWeight();
	void setFromDetails();
	void setToDetails();
	void showDetails();
	double calculateCost();
};

void Package::setWeight(){
	do{
		cout<<"Enter weight : ";
		cin>>weight;
		cin.ignore();
		if(weight<=0)
			cout<<"Weight should be greater than 0 \n";
	}while(weight<=0);
}

double Package::calculateCost(){
	return weight*costPerWeight;
}

void Package::setFromDetails(){
	cout<<"Enter sender's details :\n\n";
	from.setDetails();
}
void Package::setToDetails(){
	cout<<"Enter reciever's details :\n\n";
	to.setDetails();
}
void Package::showDetails(){
	cout<<"\nSender details :\n";
	from.showDetails();
	cout<<"\nReciever details :\n";
	to.showDetails();
}


class TwoDayPackage: public Package{
	double flatFee;
public:
	TwoDayPackage(int fee = 25.5){
		flatFee = fee;
		cout<<"TwoDayPackage constructor called\n";
	}
	double calculateCost();
};

double TwoDayPackage::calculateCost(){
	if(from.zipCode == to.zipCode)
		flatFee = 30;
	else if(from.city == to.city)
		flatFee = 40;
	else if(from.state == to.state)
		flatFee = 50;
	else if(from.address == to.address)
		flatFee = 10;
	else
		flatFee = 90;
	return (weight*costPerWeight) + flatFee;
}

class OvernightPackage: public Package{
	double additionalFeePerKg;
public:
	OvernightPackage(int fee = 25.5){
		additionalFeePerKg = fee;
		cout<<"OvernightPackage constructor called\n";
	}
	double calculateCost();
};

double OvernightPackage::calculateCost(){
	if(from.zipCode == to.zipCode)
		additionalFeePerKg = 30;
	else if(from.city == to.city)
		additionalFeePerKg = 40;
	else if(from.state == to.state)
		additionalFeePerKg = 50;
	else if(from.address == to.address)
		additionalFeePerKg = 10;
	else
		additionalFeePerKg = 90;
	return weight*(costPerWeight + additionalFeePerKg);
}

int main(){
	Package p;
	TwoDayPackage pt;
	OvernightPackage po;
	// cout<<p.calculateCost()<<endl;
	// cout<<pt.calculateCost()<<endl;
	// cout<<po.calculateCost()<<endl;

	int choice = 1;
	do{
		cout<<"\n1. Normal package\n";
		cout<<"2. Two day shipping package\n";
		cout<<"3. Overnight Shipping package\n";
		cout<<"4. Exit\n";
		cout<<"   Enter your choice : ";
		cin>>choice;
	 	cin.ignore();
		switch(choice){
			case 1:
				p.setFromDetails();
				p.setToDetails();
				p.setWeight();
				cout<<"Shipping cost : "<<p.calculateCost()<<endl;
				break;
			case 2:
				pt.setFromDetails();
				pt.setToDetails();
				pt.setWeight();
				pt.showDetails();
				cout<<"Shipping cost : "<<pt.calculateCost()<<endl;
				break;
			case 3:
				po.setFromDetails();
				po.setToDetails();
				po.setWeight();
				po.showDetails();
				cout<<"Shipping cost : "<<po.calculateCost()<<endl;
				break;
			case 4:
				cout<<"Exiting...\n";
				break;
			default:
				cout<<"Wrong choice! Try again.\n";		
		}
	}while(choice != 4);
	return 0;
}