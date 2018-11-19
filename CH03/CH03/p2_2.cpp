#include<iostream>
using namespace std;

class Printer {
private:
	char str[100];

public:
	void setString(const char * words);
	void showString(void);

};

void Printer::setString(const char * words) {
	strcpy_s(str, words);
}

void Printer::showString(void) {
	cout << str << endl;
}


int main(void) {

	Printer pnt;
	pnt.setString("Hello World!");
	pnt.showString();

	pnt.setString("I love C++!");
	pnt.showString();

	return 0;
}