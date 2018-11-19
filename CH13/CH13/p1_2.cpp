#include<iostream>
using namespace std;


template <class T>
T sumArray(T arr[], int len) {
	T sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[i];
	}
	return sum;
}


int main(void) {

	int arr1[] = { 1,2,3 };
	cout << sumArray(arr1, sizeof(arr1)/sizeof(int)) << endl;

	double arr2[] = { 10.3, 12.3, 1.35 };
	cout << sumArray(arr2, sizeof(arr2) / sizeof(double)) << endl;


	return 0;
}