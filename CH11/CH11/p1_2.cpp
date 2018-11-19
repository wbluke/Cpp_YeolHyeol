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
		cout << "제목 : " << title << endl;
		cout << "ISBN : " << isbn << endl;
		cout << "가격 : " << price << endl;
	}

	Book(const Book &book)
		:price(book.price)
	{
		title = new char[strlen(book.title) + 1];
		strcpy_s(title, strlen(book.title) + 1, book.title);
		isbn = new char[strlen(book.isbn) + 1];
		strcpy_s(isbn, strlen(book.isbn) + 1, book.isbn);
	}

	Book& operator=(const Book book) {
		delete []title;
		delete []isbn;
		title = new char[strlen(book.title) + 1];
		strcpy_s(title, strlen(book.title) + 1, book.title);
		isbn = new char[strlen(book.isbn) + 1];
		strcpy_s(isbn, strlen(book.isbn) + 1, book.isbn);
		price = book.price;
		return *this;
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
		cout << "인증키 : " << DRMKey << endl;
	}

	EBook(const EBook &ebook)
		:Book(ebook) {
		DRMKey = new char[strlen(ebook.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(ebook.DRMKey) + 1, ebook.DRMKey);
	}

	EBook& operator=(const EBook ebook) {
		delete []DRMKey;
		Book::operator=(ebook);
		DRMKey = new char[strlen(ebook.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(ebook.DRMKey) + 1, ebook.DRMKey);
		return *this;
	}

};

int main(void) {

	Book book1("좋은 C++", "555-12345-890-0", 20000);
	Book book2 = book1;	//복사생성자 호출
	book2.showBookInfo();
	Book book3("좋은 C", "123123-12345-890-0", 50000);
	book3 = book1;	//대입연산자 호출
	book3.showBookInfo();
	cout << endl;

	EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2 = ebook1;	//복사생성자 호출
	ebook2.showEBookInfo();
	EBook ebook3("좋은 C ebook", "123123-12345-890-1", 30000, "f124214w0i8kiw");
	ebook3 = ebook1;	//대입연산자 호출
	ebook3.showEBookInfo();
	return 0;
}