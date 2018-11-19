/*
File Name : NormalAccount.h
Author : Luke
Update Information : File Ver.0.82
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "String.h"

class NormalAccount : public Account {
private:
	const int interestRate;
public:
	NormalAccount(int _accID, String _cusName, int _balance, int intRate);
	int getInterestRate();
	int getInterest(int money);
	void deposit(int money);
	void showAccInfo() const;
};

NormalAccount::NormalAccount(int _accID, String _cusName, int _balance, int intRate)
	:Account(_accID, _cusName, _balance), interestRate(intRate) {};

int NormalAccount::getInterestRate() { return interestRate; }

int NormalAccount::getInterest(int money) {
	return (int)(money * (interestRate * 0.01));
}

void NormalAccount::deposit(int money) {
	Account::deposit(money + getInterest(money));
}

void NormalAccount::showAccInfo() const {
	Account::showAccInfo();
	cout << "ÀÌÀÚÀ² : " << interestRate << "%" << endl;
}


#endif // !__NORMAL_ACCOUNT_H__