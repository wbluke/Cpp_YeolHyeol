#include<iostream>

int salary(int money) {
	return (int)(50 + money * 0.12);
}

int main(void) {

	int sellMoney;

	while (1) {
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end) : ";
		std::cin >> sellMoney;
		if (sellMoney == -1) {
			break;
		}
		else {
			std::cout << "이번 달 급여 : " << salary(sellMoney) << "만원" << std::endl;
		}
	}


	return 0;
}