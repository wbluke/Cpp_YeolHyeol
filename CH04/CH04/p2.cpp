#include<iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	void init(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void showPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle {
private:
	Point center;
	int rad;
public:
	void init(int x, int y, int radius) {
		center.init(x, y);
		rad = radius;
	}
	void showCircleInfo() const {
		cout << "radius : " << rad << endl;
		center.showPointInfo();
	}
};

class Ring {
private:
	Circle inner, outer;
public:
	void init(int inX, int inY, int inRad, int outX, int outY, int outRad) {
		inner.init(inX, inY, inRad);
		outer.init(outX, outY, outRad);
	}
	void showRingInfo() const {
		cout << "Inner Circle Info" << endl;
		inner.showCircleInfo();
		cout << "outer Circle Info" << endl;
		outer.showCircleInfo();
	}
};

int main(void) {

	Ring ring;
	ring.init(1, 1, 4, 2, 2, 9);
	ring.showRingInfo();

	return 0;
}