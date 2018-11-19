/*
File Name : Account.cpp
Author : Luke
Update Information : File Ver.0.92
*/

#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"

Account::Account(int _accID, String _cusName, int _balance)
	:accID(_accID), balance(_balance)
{
	//cusName = new char[strlen(_cusName) + 1];
	//strcpy_s(cusName, strlen(_cusName) + 1, _cusName);
	cusName = _cusName;
}

/*
Account::Account(const Account &ref)
	:accID(ref.accID), balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy_s(cusName, strlen(ref.cusName) + 1, ref.cusName);
}
*/

/*
Account& Account::operator=(const Account &acc) {
	delete[]cusName;
	accID = acc.accID;
	balance = acc.balance;
	cusName = new char[strlen(acc.cusName) + 1];
	strcpy_s(acc.cusName, strlen(acc.cusName) + 1, acc.cusName);
	return *this;
}
*/

int Account::getAccID() const { return accID; }

int Account::getBalance() const { return balance; }

void Account::deposit(int money) { 
	if (money < 0) {
		throw MoneyIsNegativeException(money);
	}

	balance += money; 
}

void Account::withdraw(int money) { 
	if (money < 0) {
		throw MoneyIsNegativeException(money);
	}

	if (balance < money) {
		throw DepositMoneyIsOverException(money);
	}
	
	balance -= money; 
}

void Account::showAccInfo() const {
	cout << "°èÁÂID : " << accID << endl;
	cout << "ÀÌ  ¸§ : " << cusName << endl;
	cout << "ÀÜ  ¾× : " << balance << endl;
}

//Account::~Account() { delete[] cusName; }
