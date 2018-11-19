/*
File Name : String.h
Author : Luke
Update Information : File Ver.0.12
*/

#ifndef __STRING_H__
#define __STRING_H__

#include "BankingCommonDecl.h"

class String {
private:
	int len;
	char * str;
public:
	String();
	String(const char * _str);
	String(const String& strClass);
	String& operator=(const String& strClass);
	String operator+(const String& strClass);
	String& operator+=(const String& strClass);
	bool operator==(const String& strClass);
	~String();

	friend ostream& operator<< (ostream& os, const String& strClass);
	friend istream& operator>> (istream& os, String& strClass);
};

#endif // !__STRING_H__
