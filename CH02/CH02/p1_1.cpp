#include<iostream>
using namespace std;

void addOneFunc(int &num);
void changeSign(int &num);

int main(void) {

	int number;

	cout << "���� �Է� : ";
	cin >> number;

	addOneFunc(number);
	cout << "1 ���� �� : " << number << endl;

	changeSign(number);
	cout << "��ȣ�� �ٲ� �� : " << number << endl;


	return 0;
}

void addOneFunc(int &num) {
	num++;
}

void changeSign(int &num) {
	num *= -1;
}