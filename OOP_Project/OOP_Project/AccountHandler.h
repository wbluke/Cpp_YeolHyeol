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
	BoundCheckArray<Account*> accArr;	//고객정보 저장을 위한 배열
	int accNum;				//고객의 수
public:
	AccountHandler();
	void printDisplay(void) const;	//메뉴 출력
	void makeAccount(void);		//계좌 개설
	int choiceAccount(void);	//계좌 종류 선택
	void makeNormalAccount(void);
	void makeHighCreditAccount(void);
	void depositMoney(void);	//입금
	void withdrawMoney(void);	//출금
	void showAllAccInfo(void) const;		//모든 계좌정보 출력
	~AccountHandler();
};

#endif // !__ACCOUNT_HANDLER_H__
