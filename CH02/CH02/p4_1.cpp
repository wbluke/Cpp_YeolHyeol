#include<iostream>
#include<cstring>
using namespace std;


int main(void) {

	char str1[] = "안녕하세요~ ";
	char str2[] = "반갑습니다!";
	char str3[50];

	cout << strlen(str1) << endl;
	cout << strlen(str2) << endl;
	strcpy_s(str3, str1);
	strcat_s(str3, str2);
	cout << str3 << endl;

	if (strcmp(str1, str2) == 0) {
		cout << "문자열이 같다." << endl;
	}
	else {
		cout << "문자열이 같지 않다." << endl;
	}


	return 0;
}