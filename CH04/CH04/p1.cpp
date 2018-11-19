#include<iostream>
using namespace std;

namespace FruitSellBuy {
	bool checkMoneyToBuyApples(int money) {
		if (money < 0) {
			cout << "����� ���Ÿ� �������� 0���� ���� ���� ������ �� �����ϴ�." << endl;
			return false;
		}
		else {
			return true;
		}
	}
}

class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void initMembers(int price, int num, int money) {
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int saleApples(int money) {
		if (FruitSellBuy::checkMoneyToBuyApples(money)) {
			int num = money / APPLE_PRICE;
			numOfApples -= num;
			myMoney += money;
			return num;
		}
		return 0;
	}
	void showSalesResult() const {
		cout << "���� ��� : " << numOfApples << endl;
		cout << "�Ǹ� ���� : " << myMoney << endl << endl;
	}
};

class FruitBuyer {
	int myMoney;
	int numOfApples;

public:
	void initMembers(int money) {
		myMoney = money;
		numOfApples = 0;
	}
	void buyApples(FruitSeller &seller, int money) {
		if (FruitSellBuy::checkMoneyToBuyApples(money)) {
			numOfApples += seller.saleApples(money);
			myMoney -= money;
		}
	}
	void showBuyResult() const {
		cout << "���� �ܾ� : " << myMoney << endl;
		cout << "��� ���� : " << numOfApples << endl << endl;
	}
	
};

int main(void) {

	FruitSeller seller;
	seller.initMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.initMembers(5000);
	buyer.buyApples(seller, 2000);	//Buy Apples

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.showSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.showBuyResult();


	return 0;
}