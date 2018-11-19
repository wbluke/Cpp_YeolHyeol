#include<iostream>
using namespace std;

void swapPointer(int * (&pt1), int * (&pt2)) {
	int * temp;
	temp = pt1;
	pt1 = pt2;
	pt2 = temp;
}

int main(void) {

	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;

	swapPointer(ptr1, ptr2);

	cout << "ptr1이 가리키는 값 : " << *ptr1 << endl;
	cout << "ptr2이 가리키는 값 : " << *ptr2 << endl;

	return 0;
}