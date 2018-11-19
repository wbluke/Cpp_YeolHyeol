/*
File Name : AccountException.h
Author : Luke
Update Information : File Ver.0.82
*/

#include "Account.h"

#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

class AccountException {
public:
	virtual void showExceptionReason() = 0;
};

class MoneyIsNegativeException : public AccountException {
private:
	int money;
public:
	MoneyIsNegativeException(int money) : money(money) {};
	void showExceptionReason() {
		cout << "[ERROR] �߸��� �ݾ� �Է�!" << endl;
	}
};

class DepositMoneyIsOverException : public AccountException {
private:
	int money;
public:
	DepositMoneyIsOverException(int money) : money(money) {};
	void showExceptionReason() {
		cout << "[ERROR] �ܾ� ����!" << endl;
	}
};


#endif // !__ACCOUNT_EXCEPTION_H__

