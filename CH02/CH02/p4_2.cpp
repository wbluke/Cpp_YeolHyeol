#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(void) {

	srand(time(NULL));

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "��° ���� : " << rand() % 100 << endl;
	}

	return 0;
}