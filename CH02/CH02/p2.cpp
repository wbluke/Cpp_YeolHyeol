#include<iostream>
using namespace std;

int main(void) {

	const int num = 12;

	const int * ptr = &num;

	const int * (&ptRef) = ptr;

	cout << "�����͸� �̿��� ��� : " << *ptr << endl;
	cout << "�������� �����ڸ� �̿��� ��� : " << *ptRef << endl;

	return 0;
}