#include<iostream>
using namespace std;

class Book {
private:
	char * title;
	char * isbn;
	int price;
public:
	Book(const char * _title, const char * _isbn, int _price)
		:price(_price)
	{
		title = new char[strlen(_title) + 1];
		strcpy_s(title, strlen(_title) + 1, _title);
		isbn = new char[strlen(_isbn) + 1];
		strcpy_s(isbn, strlen(_isbn) + 1, _isbn);
	}

	void showBookInfo() {
		cout << "���� : " << title << endl;
		cout << "ISBN : " << isbn << endl;
		cout << "���� : " << price << endl;
	}
};

class EBook : public Book {
private:
	char * DRMKey;
public:
	EBook(const char * _title, const char * _isbn, int _price, const char * _DRMKey)
		:Book(_title, _isbn, _price)
	{
		DRMKey = new char[strlen(_DRMKey) + 1];
		strcpy_s(DRMKey, strlen(_DRMKey) + 1, _DRMKey);
	}

	void showEBookInfo() {
		showBookInfo();
		cout << "����Ű : " << DRMKey << endl;
	}
};

int main(void) {

	Book book("���� C++", "555-12345-890-0", 20000);
	book.showBookInfo();
	cout << endl;
	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.showEBookInfo();

	return 0;
}