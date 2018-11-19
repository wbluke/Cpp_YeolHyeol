#include<iostream>
using namespace std;

template <class T>
class SmartPtr {
private:
	T * ptr;
public:
	SmartPtr(T * ptr) :ptr(ptr) {}
	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }
	~SmartPtr() { delete ptr; }
};

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void setPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void showPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

int main(void) {

	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(3, 4));
	sptr1->showPosition();
	sptr2->showPosition();
	sptr1->setPos(10, 20);
	sptr2->setPos(30, 40);
	sptr1->showPosition();
	sptr2->showPosition();

	return 0;
}