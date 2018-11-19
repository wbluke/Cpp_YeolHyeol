/*
File Name : AccountHandler.h
Author : Luke
Update Information : File Ver.0.82
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler {
private:
	BoundCheckArray<Account*> accArr;	//������ ������ ���� �迭
	int accNum;				//���� ��
public:
	AccountHandler();
	void printDisplay(void) const;	//�޴� ���
	void makeAccount(void);		//���� ����
	int choiceAccount(void);	//���� ���� ����
	void makeNormalAccount(void);
	void makeHighCreditAccount(void);
	void depositMoney(void);	//�Ա�
	void withdrawMoney(void);	//���
	void showAllAccInfo(void) const;		//��� �������� ���
	~AccountHandler();
};

#endif // !__ACCOUNT_HANDLER_H__
