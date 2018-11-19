#include<iostream>
using namespace std;

class Rectangle {
private:
	int width;
	int height;
public:
	Rectangle(int _width, int _height)
		:width(_width), height(_height) {};

	void showAreaInfo() {
		cout << "¸éÀû : " << width * height << endl;
	}
};

class Square : public Rectangle {
public:
	Square(int width)
		:Rectangle(width, width) {};
};

int main(void) {

	Rectangle rec(4, 3);
	rec.showAreaInfo();

	Square sqr(7);
	sqr.showAreaInfo();

	return 0;
}