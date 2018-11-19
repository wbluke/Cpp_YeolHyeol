#include<iostream>
#include<cstring>
using namespace std;

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void showPositionInfo(int pos) {
		switch (pos) {
		case CLERK:
			cout << "사원" << endl;
			return;
		case SENIOR:
			cout << "주임" << endl;
			return;
		case ASSIST:
			cout << "대리" << endl;
			return;
		case MANAGER:
			cout << "과장" << endl;
			return;
		}
	}
}

class nameCard {
private:
	char * name;
	char * company;
	char * phoneNum;
	int position;
public:
	nameCard(const char *_name, const char * _company, const char * _phoneNum, int pos)
		:position(pos) {
		name = new char[strlen(_name) + 1];
		company = new char[strlen(_company) + 1];
		phoneNum = new char[strlen(_phoneNum) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
		strcpy_s(company, strlen(_company) + 1, _company);
		strcpy_s(phoneNum, strlen(_phoneNum) + 1, _phoneNum);

	}

	nameCard(const nameCard &copy)
		:position(copy.position)
	{
		name = new char[strlen(copy.name) + 1];
		company = new char[strlen(copy.company) + 1];
		phoneNum = new char[strlen(copy.phoneNum) + 1];
		strcpy_s(name, strlen(copy.name) + 1, copy.name);
		strcpy_s(company, strlen(copy.company) + 1, copy.company);
		strcpy_s(phoneNum, strlen(copy.phoneNum) + 1, copy.phoneNum);
	}

	void showNameCardInfo() {
		cout << "이름 : " << name << endl;
		cout << "회사 : " << company << endl;
		cout << "전화번호 : " << phoneNum << endl;
		cout << "직급 : "; COMP_POS::showPositionInfo(position);
		cout << endl;

	}
	~nameCard() {
		delete[]name;
		delete[]company;
		delete[]phoneNum;
	}
};

int main(void) {

	nameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	nameCard copy1 = manClerk;
	nameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	nameCard copy2 = manSenior;
	copy1.showNameCardInfo();
	copy2.showNameCardInfo();

	return 0;
}