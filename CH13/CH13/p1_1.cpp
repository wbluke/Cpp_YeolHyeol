#include<iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y){}
	void showPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

template <class T>
void swapData(T & num1, T & num2) {
	T temp = num1;
	num1 = num2;
	num2 = temp;
}


int main(void) {

	Point p1(1, 2);
	Point p2(3, 4);

	p1.showPosition();
	p2.showPosition();

	swapData<Point>(p1, p2);

	p1.showPosition();
	p2.showPosition();


	return 0;
}