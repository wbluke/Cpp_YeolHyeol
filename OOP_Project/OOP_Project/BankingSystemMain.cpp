/*
Software Ver : Banking System 0.82
File Name : BankingSystemMain.cpp
Author : Luke
Update Information : File Ver.0.72
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void) {

	AccountHandler manager;
	int select;

	while (1) {
		manager.printDisplay();
		cin >> select;
		cout << endl;

		switch (select) {
		case MAKE:
			manager.makeAccount();
			break;
		case DEPOSIT:
			manager.depositMoney();
			break;
		case WITHDRAW:
			manager.withdrawMoney();
			break;
		case INQUIRE:
			manager.showAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal Selection..." << endl;
		}
	}
	return 0;
}


