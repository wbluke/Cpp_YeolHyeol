#include<iostream>

int main(void) {

	char name[50], phone[100];

	std::cout << "�̸� �Է� : ";
	std::cin >> name;
	std::cout << "��ȭ��ȣ �Է� : ";
	std::cin >> phone;

	std::cout << "====================================" << std::endl;
	std::cout << "�̸� : " << name << std::endl;
	std::cout << "��ȭ��ȣ : " << phone << std::endl;


	return 0;
}