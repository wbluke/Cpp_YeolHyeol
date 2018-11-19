/*
File Name : Account.h
Author : Luke
Update Information : File Ver.0.92
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account {
private:
	int accID;				//계좌번호
	String cusName;			//고객이름
	int balance;			//잔액

public:
	Account(int _accID, String _cusName, int _balance);
	//Account(const Account &ref);	//복사생성자_깊은복사
	//Account& operator=(const Account &acc);
	int getAccID() const;
	int getBalance() const;
	virtual void deposit(int money);
	void withdraw(int money);
	virtual void showAccInfo() const;
	//~Account();
};


#endif // !__ACCOUNT_H__

