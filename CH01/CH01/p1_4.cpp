#include<iostream>

int salary(int money) {
	return (int)(50 + money * 0.12);
}

int main(void) {

	int sellMoney;

	while (1) {
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end) : ";
		std::cin >> sellMoney;
		if (sellMoney == -1) {
			break;
		}
		else {
			std::cout << "�̹� �� �޿� : " << salary(sellMoney) << "����" << std::endl;
		}
	}


	return 0;
}