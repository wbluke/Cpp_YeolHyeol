#include<iostream>

int main(void) {

	int num;

	std::cout << "�������� ������ �� �Է� : ";
	std::cin >> num;

	std::cout << "========================" << std::endl;
	std::cout << "< " << num << "�� >" << std::endl;
	for (int i = 1; i < 10; i++) {
		std::cout << num << " x " << i << " = " << num * i << std::endl;
	}



	return 0;
}