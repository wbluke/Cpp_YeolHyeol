#include<iostream>

int main(void) {

	int num;

	std::cout << "구구단을 츨력할 단 입력 : ";
	std::cin >> num;

	std::cout << "========================" << std::endl;
	std::cout << "< " << num << "단 >" << std::endl;
	for (int i = 1; i < 10; i++) {
		std::cout << num << " x " << i << " = " << num * i << std::endl;
	}



	return 0;
}