#include<iostream>
using namespace std;

int main(void) {

	const int num = 12;

	const int * ptr = &num;

	const int * (&ptRef) = ptr;

	cout << "포인터를 이용한 출력 : " << *ptr << endl;
	cout << "포인터의 참조자를 이용한 출력 : " << *ptRef << endl;

	return 0;
}