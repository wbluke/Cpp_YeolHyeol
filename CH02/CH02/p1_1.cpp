#include<iostream>
using namespace std;

void addOneFunc(int &num);
void changeSign(int &num);

int main(void) {

	int number;

	cout << "정수 입력 : ";
	cin >> number;

	addOneFunc(number);
	cout << "1 더한 수 : " << number << endl;

	changeSign(number);
	cout << "부호를 바꾼 수 : " << number << endl;


	return 0;
}

void addOneFunc(int &num) {
	num++;
}

void changeSign(int &num) {
	num *= -1;
}