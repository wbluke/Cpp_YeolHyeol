#include<iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x, int y)
		:xpos(x), ypos(y) {};	//Member Initializer
	/*void init(int x, int y) {
		xpos = x;
		ypos = y;
	}*/
	void showPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle {
private:
	Point center;
	int rad;
public:
	Circle(int x, int y, int radius)
		:center(x, y), rad(radius) {};	//Member Initializer
	/*void init(int x, int y, int radius) {
		center.init(x, y);
		rad = radius;
	}*/
	void showCircleInfo() const {
		cout << "radius : " << rad << endl;
		center.showPointInfo();
	}
};

class Ring {
private:
	Circle inner, outer;
public:
	Ring(int inX, int inY, int inRad, int outX, int outY, int outRad)
		:inner(inX, inY, inRad), outer(outX, outY, outRad) {};	//Member Initializer
	/*void init(int inX, int inY, int inRad, int outX, int outY, int outRad) {
		inner.init(inX, inY, inRad);
		outer.init(outX, outY, outRad);
	}*/
	void showRingInfo() const {
		cout << "Inner Circle Info" << endl;
		inner.showCircleInfo();
		cout << "outer Circle Info" << endl;
		outer.showCircleInfo();
	}
};

int main(void) {

	Ring ring(1, 1, 4, 2, 2, 9);
	ring.showRingInfo();

	return 0;
}