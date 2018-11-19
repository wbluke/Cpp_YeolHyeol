#include<iostream>
using namespace std;

namespace FruitSellBuy {
	bool checkMoneyToBuyApples(int money) {
		if (money < 0) {
			cout << "사과의 구매를 목적으로 0보다 작은 돈을 지불할 수 없습니다." << endl;
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
		cout << "남은 사과 : " << numOfApples << endl;
		cout << "판매 수익 : " << myMoney << endl << endl;
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
		cout << "현재 잔액 : " << myMoney << endl;
		cout << "사과 개수 : " << numOfApples << endl << endl;
	}
	
};

int main(void) {

	FruitSeller seller;
	seller.initMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.initMembers(5000);
	buyer.buyApples(seller, 2000);	//Buy Apples

	cout << "과일 판매자의 현황" << endl;
	seller.showSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.showBuyResult();


	return 0;
}