#include<iostream>
using namespace std;

class MyFriendInfo {
private:
	char * name;
	int age;
public:

	MyFriendInfo(const char * _name, int _age)
		:age(_age)
	{
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
	}

	void showMyFriendInfo() {
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}

	~MyFriendInfo() {
		delete[] name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char * addr;
	char * phone;
public:

	MyFriendDetailInfo(const char * _name, int _age, const char * _addr, const char * _phone)
		:MyFriendInfo(_name, _age)
	{
		addr = new char[strlen(_addr) + 1];
		strcpy_s(addr, strlen(_addr) + 1, _addr);
		phone = new char[strlen(_phone) + 1];
		strcpy_s(phone, strlen(_phone) + 1, _phone);
	}

	void showMyFriendDetailInfo() {
		showMyFriendInfo();
		cout << "주소 : " << addr << endl;
		cout << "전화 : " << phone << endl;
	}

	~MyFriendDetailInfo() {
		delete[] addr;
		delete[] phone;
	}
};

int main(void) {

	MyFriendDetailInfo inform("김현주", 27, "서울시 관악구 봉천동", "010-1234-1234");
	inform.showMyFriendDetailInfo();

	return 0;
}