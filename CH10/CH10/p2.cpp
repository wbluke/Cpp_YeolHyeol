#include<iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

	void showPosition() const {
		cout << '[' << xpos << ", " << ypos << "]" << endl;
	}

	Point& operator-() {
		xpos = -xpos;
		ypos = -ypos;
		return *this;
	}

	friend Point& operator~(Point &pos);
};

Point& operator~(Point &pos) {
	int temp = pos.xpos;
	pos.xpos = pos.ypos;
	pos.ypos = temp;
	return pos;
}

int main(void) {

	Point pos1(3, 4);
	Point pos2(10, 20);
	
	Point pos3 = -pos1;
	pos3.showPosition();

	Point pos4 = ~pos2;
	pos4.showPosition();


	return 0;
}