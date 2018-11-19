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
	int accID;				//���¹�ȣ
	String cusName;			//���̸�
	int balance;			//�ܾ�

public:
	Account(int _accID, String _cusName, int _balance);
	//Account(const Account &ref);	//���������_��������
	//Account& operator=(const Account &acc);
	int getAccID() const;
	int getBalance() const;
	virtual void deposit(int money);
	void withdraw(int money);
	virtual void showAccInfo() const;
	//~Account();
};


#endif // !__ACCOUNT_H__

