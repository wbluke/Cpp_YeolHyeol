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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "���� : ";
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
		cout << "[������������]" << endl;
		cout << "1. ���뿹�ݰ���  2. �ſ�ŷڰ���" << endl;
		cout << "���� : ";
		cin >> sel;
		if (sel == 1 || sel == 2) {
			return sel;
		}
		else {
			cout << "�߸� �����ϼ̽��ϴ�." << endl << endl;
		}
	}
}

void AccountHandler::makeNormalAccount() {
	int id, money, rate;
	String name;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�� �� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> money;
	cout << "������ : "; cin >> rate;
	cout << endl;
	accArr[accNum++] = new NormalAccount(id, name, money, rate);
}

void AccountHandler::makeHighCreditAccount() {
	int id, money, rate, grade;
	String name;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�� �� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> money;
	cout << "������ : "; cin >> rate;
	while (true) {
		cout << "�ſ���(1toA, 2toB, 3toC) : "; cin >> grade;
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
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl << endl;
		}
	}
}

void AccountHandler::depositMoney(void) {
	int id;
	int money;

	cout << "[��   ��]" << endl;
	cout << "����ID : "; cin >> id;
	while (true) {
		cout << "�Աݾ� : "; cin >> money;
		try{
			for (int i = 0; i < accNum; i++) {
				if (accArr[i]->getAccID() == id) {
					accArr[i]->deposit(money);
					cout << "�ԱݿϷ�" << endl << endl;
					return;
				}
				else {
					cout << "��ġ�ϴ� ����ID�� �����ϴ�." << endl << endl;
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

	cout << "[��   ��]" << endl;
	cout << "����ID : "; cin >> id;
	while (true) {
		cout << "��ݾ� : "; cin >> money;
		try {
			for (int i = 0; i < accNum; i++) {
				if (accArr[i]->getAccID() == id) {
					accArr[i]->withdraw(money);
					cout << "��ݿϷ�" << endl << endl;
					return;
				}
				else {
					cout << "��ġ�ϴ� ����ID�� �����ϴ�." << endl << endl;
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
	cout << "========== ��ü ���� ���� ==========" << endl << endl;

	for (int i = 0; i < accNum; i++) {
		cout << "=== ��Ϲ�ȣ " << (i + 1) << "�� ���� ===" << endl;
		accArr[i]->showAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
}