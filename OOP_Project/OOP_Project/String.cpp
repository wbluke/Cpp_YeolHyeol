/*
File Name : String.cpp
Author : Luke
Update Information : File Ver.0.12
*/

#include "String.h"

String::String() {
	len = 0;
	str = NULL;
}

String::String(const char * _str) {
	len = strlen(_str) + 1;
	str = new char[len];
	strcpy_s(str, len, _str);
}

String::String(const String& strClass) {
	len = strClass.len;
	str = new char[len];
	strcpy_s(str, len, strClass.str);
}

String& String::operator=(const String& strClass) {
	if(str!=NULL)
		delete[]str;
	len = strClass.len;
	str = new char[len];
	strcpy_s(str, len, strClass.str);
	return *this;
}

String String::operator+(const String& strClass) {
	char * tempStr = new char[len + strClass.len - 1];
	strcpy_s(tempStr, len + strClass.len - 1, str);
	strcat_s(tempStr, len + strClass.len - 1, strClass.str);

	String temp(tempStr);
	delete[]tempStr;
	return temp;
}

String& String::operator+=(const String& strClass) {
	len += (strClass.len - 1);
	char * tempStr = new char[len];
	strcpy_s(tempStr, len, str);
	strcat_s(tempStr, len, strClass.str);

	if (str != NULL)
		delete[]str;
	str = tempStr;
	return *this;
}

bool String::operator==(const String& strClass) {
	return strcmp(str, strClass.str) ? false : true;
}

String::~String() {
	if (str != NULL)
		delete[] str;
}

ostream& operator<< (ostream& os, const String& strClass) {
	os << strClass.str;
	return os;
}

istream& operator>> (istream& is, String& strClass) {
	char str[100];
	is >> str;
	strClass = String(str);
	return is;
}
