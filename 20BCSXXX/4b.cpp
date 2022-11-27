#include<iostream>
#include<math.h>

using namespace std;


class Distance;
class Point{
	int x;
	int y;
public:
	void setXY(int a, int b){
		x=a,y=b;
	}
	friend class Distance;	
	// friend float Distance::printDistance(Point a, Point b);
};

class Distance{
public:
	float printDistance(Point a, Point b){
		return sqrt(pow(a.x - b.x, 2) + pow((a.y - b.y), 2));
	}
};

int main(){
	Distance d;
	Point a,b;
	a.setXY(0,0);
	b.setXY(3,4);
	cout<<"Distance : "<<d.printDistance(a,b)<<endl;
	return 0;
}