/*
File Name : HighCreditAccount.h
Author : Luke
Update Information : File Ver.0.82
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public NormalAccount {
private:
	int creditGrade;
public:
	HighCreditAccount(int _accID, String _cusName, int _balance, int intRate, int creditGrade);
	int getCreditGradeRate();
	int getInterest(int money);
	void deposit(int money);
	void showAccInfo() const;
};

HighCreditAccount::HighCreditAccount(int _accID, String _cusName, int _balance, int intRate, int creditGrade)
	:NormalAccount(_accID, _cusName, _balance, intRate), creditGrade(creditGrade) {};

int HighCreditAccount::getCreditGradeRate() {
	return getInterestRate() + creditGrade;
}

int HighCreditAccount::getInterest(int money) {
	return (int)(money * (getCreditGradeRate() * 0.01));
}

void HighCreditAccount::deposit(int money) {
	Account::deposit(money + getInterest(money));
}

void HighCreditAccount::showAccInfo() const {
	NormalAccount::showAccInfo();
	cout << "신용등급 이자율 : " << creditGrade << "%" << endl;
}

#endif // !__HIGHCREDIT_ACCOUNT_H__

