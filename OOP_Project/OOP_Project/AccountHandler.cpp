/*
File Name : AccountHandler.cpp
Author : Luke
Update Information : File Ver.0.72
*/

#include "Account.h"
#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"
#include "AccountException.h"

AccountHandler::AccountHandler()
	:accNum(0) {};

void AccountHandler::printDisplay(void) const {
	cout << "========== MENU ==========" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 : ";
}

void AccountHandler::makeAccount(void) {
	int sel;

	sel = choiceAccount();
	if (sel == 1) {
		makeNormalAccount();
	}
	else if (sel == 2) {
		makeHighCreditAccount();
	}
}

int AccountHandler::choiceAccount(void) {
	int sel;
	while (true) {
		cout << "[계좌종류선택]" << endl;
		cout << "1. 보통예금계좌  2. 신용신뢰계좌" << endl;
		cout << "선택 : ";
		cin >> sel;
		if (sel == 1 || sel == 2) {
			return sel;
		}
		else {
			cout << "잘못 선택하셨습니다." << endl << endl;
		}
	}
}

void AccountHandler::makeNormalAccount() {
	int id, money, rate;
	String name;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이 름 : "; cin >> name;
	cout << "입금액 : "; cin >> money;
	cout << "이자율 : "; cin >> rate;
	cout << endl;
	accArr[accNum++] = new NormalAccount(id, name, money, rate);
}

void AccountHandler::makeHighCreditAccount() {
	int id, money, rate, grade;
	String name;

	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이 름 : "; cin >> name;
	cout << "입금액 : "; cin >> money;
	cout << "이자율 : "; cin >> rate;
	while (true) {
		cout << "신용등급(1toA, 2toB, 3toC) : "; cin >> grade;
		if (grade >= 1 && grade <= 3) {
			switch (grade) {
			case 1:
				grade = GRADE_A;
				break;
			case 2:
				grade = GRADE_B;
				break;
			case 3:
				grade = GRADE_C;
				break;
			}
			cout << endl;
			accArr[accNum++] = new HighCreditAccount(id, name, money, rate, grade);
			return;
		}
		else {
			cout << "잘못 입력하셨습니다." << endl << endl;
		}
	}
}

void AccountHandler::depositMoney(void) {
	int id;
	int money;

	cout << "[입   금]" << endl;
	cout << "계좌ID : "; cin >> id;
	while (true) {
		cout << "입금액 : "; cin >> money;
		try{
			for (int i = 0; i < accNum; i++) {
				if (accArr[i]->getAccID() == id) {
					accArr[i]->deposit(money);
					cout << "입금완료" << endl << endl;
					return;
				}
				else {
					cout << "일치하는 계좌ID가 없습니다." << endl << endl;
					return;
				}
			}
		}
		catch (AccountException &e) {
			e.showExceptionReason();
		}
	}
}

void AccountHandler::withdrawMoney(void) {
	int id;
	int money;

	cout << "[출   금]" << endl;
	cout << "계좌ID : "; cin >> id;
	while (true) {
		cout << "출금액 : "; cin >> money;
		try {
			for (int i = 0; i < accNum; i++) {
				if (accArr[i]->getAccID() == id) {
					accArr[i]->withdraw(money);
					cout << "출금완료" << endl << endl;
					return;
				}
				else {
					cout << "일치하는 계좌ID가 없습니다." << endl << endl;
					return;
				}
			}
		}
		catch (AccountException &e) {
			e.showExceptionReason();
		}
	}
}

void AccountHandler::showAllAccInfo(void) const {
	cout << "========== 전체 계좌 정보 ==========" << endl << endl;

	for (int i = 0; i < accNum; i++) {
		cout << "=== 등록번호 " << (i + 1) << "번 계좌 ===" << endl;
		accArr[i]->showAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
}