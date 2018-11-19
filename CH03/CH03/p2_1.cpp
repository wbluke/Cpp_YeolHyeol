#include<iostream>
using namespace std;

class Calculator {
private:
	int addCt = 0, minCt = 0, mulCt = 0, divCt = 0;

public: 
	void init(void);
	double add(double num1, double num2);
	double min(double num1, double num2);
	double mul(double num1, double num2);
	double div(double num1, double num2);
	void showOpCount(void);

};

int main(void) {

	Calculator cal;
	cal.init();
	cout << "3.2 + 2.4 = " << cal.add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.div(4.9, 1.2) << endl;
	cal.showOpCount();

	return 0;
}

void Calculator::init(void) {
	addCt = 0, minCt = 0, mulCt = 0, divCt = 0;
}

double Calculator::add(double num1, double num2) {
	addCt++;
	return num1 + num2;
}

double Calculator::min(double num1, double num2) {
	minCt++;
	return num1 - num2;
}

double Calculator::mul(double num1, double num2) {
	mulCt++;
	return num1 * num2;
}

double Calculator::div(double num1, double num2) {
	divCt++;
	return num1 / num2;
}

void Calculator::showOpCount(void) {
	cout << "µ¡¼À : " << addCt << " »¬¼À : " << minCt << " °ö¼À : " << mulCt << " ³ª´°¼À : " << divCt << endl;
}