#include<iostream>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
}Point;

Point& pntAdder(const Point &p1, const Point &p2) {
	Point * p3 = new Point;
	p3->xpos = p1.xpos + p2.xpos;
	p3->ypos = p1.ypos + p2.ypos;
	return *p3;
}

int main(void) {

	Point * A = new Point;
	Point * B = new Point;

	A->xpos = 3;
	A->ypos = 5;
	B->xpos = 12;
	B->ypos = 13;

	Point &C = pntAdder(*A, *B);

	cout << "x : " << C.xpos << endl;
	cout << "y : " << C.ypos << endl;

	delete A;
	delete B;
	delete &C;

	return 0;
}