#include<iostream>
#include<cstring>
using namespace std;


int main(void) {

	char str1[] = "�ȳ��ϼ���~ ";
	char str2[] = "�ݰ����ϴ�!";
	char str3[50];

	cout << strlen(str1) << endl;
	cout << strlen(str2) << endl;
	strcpy_s(str3, str1);
	strcat_s(str3, str2);
	cout << str3 << endl;

	if (strcmp(str1, str2) == 0) {
		cout << "���ڿ��� ����." << endl;
	}
	else {
		cout << "���ڿ��� ���� �ʴ�." << endl;
	}


	return 0;
}