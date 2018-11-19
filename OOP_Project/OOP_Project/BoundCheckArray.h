/*
File Name : BoundCheckArray.h
Author : Luke
Update Information : File Ver.0.12
*/

#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__

#include "Account.h"

template<class T>
class BoundCheckArray {
private:
	T * arr;
	int arrLen;
	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}
public:
	BoundCheckArray(int len = 100);
	T& operator[](int idx);
	T operator[](int idx) const;
	int getArrLen() const;
	~BoundCheckArray();
};

template<class T>
BoundCheckArray<T>::BoundCheckArray(int len)
	:arrLen(len) {
	arr = new T[len];
}

template<class T>
T& BoundCheckArray<T>::operator[](int idx) {
	if (idx < 0 || idx >= arrLen) {
		cout << "Array Index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template<class T>
T BoundCheckArray<T>::operator[](int idx) const {
	if (idx < 0 || idx >= arrLen) {
		cout << "Array Index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template<class T>
int BoundCheckArray<T>::getArrLen() const {
	return arrLen;
}

template<class T>
BoundCheckArray<T>::~BoundCheckArray() {
	delete[]arr;
}


#endif // !__BOUND_CHECK_ARRAY_H__


