/*
File Name : BankingCommonDecl.h
Author : Luke
Update Information : File Ver.0.72
*/

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };	//select 번호 열거형으로 지정
enum { GRADE_A = 7, GRADE_B = 4, GRADE_C = 2 };

#endif // !__BANKING_COMMON_H__
