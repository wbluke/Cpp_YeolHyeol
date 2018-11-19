#include<iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) {}

	void showPosition() const {
		cout << '[' << xpos << ", " << ypos << "]" << endl;
	}

	friend Point operator- (const Point &pos1, const Point &pos2);
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);

	Point& operator+=(const Point &pos) {
		xpos += pos.xpos;
		ypos += pos.ypos;
		return *this;
	}

	Point& operator-=(const Point &pos) {
		xpos -= pos.xpos;
		ypos -= pos.ypos;
		return *this;
	}
};

Point operator- (const Point &pos1, const Point &pos2) {
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

bool operator==(const Point &pos1, const Point &pos2) {
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos) {
		return true;
	}
	else return false;
}

bool operator!=(const Point &pos1, const Point &pos2) {
	return !(pos1 == pos2);
}

int main(void) {

	Point pos1(3, 4);
	Point pos2(10, 20);
	(pos1 - pos2).showPosition();

	pos1 += pos2;
	pos1.showPosition();

	pos1 -= pos2;
	pos1.showPosition();

	Point pos4(3, 4);
	Point pos5(3, 5);
	Point pos6(40, 60);

	cout << (pos1 == pos4) << endl;
	cout << (pos1 == pos5) << endl;
	cout << (pos1 != pos4) << endl;
	cout << (pos1 != pos5) << endl;
	cout << (pos4 != pos6) << endl;

	return 0;
}