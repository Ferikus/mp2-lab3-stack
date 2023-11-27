#pragma once
#include <iostream>

template <class T>
class TStack
{
	T* pMem;
	int MaxSize;
	int CurrInd;
public:
	TStack(int _MaxSize = 10) {
		MaxSize = _MaxSize;
		pMem = new T[MaxSize];
		CurrInd = -1;
	}
	TStack(const TStack& s) {
		MaxSize = s.MaxSize;
		pMem = new T[MaxSize];
		CurrInd = s.CurrInd;
		for (int i = 0; i < CurrInd + 1; i++) {
			pMem[i] = s.pMem[i];
		}
	}
	TStack& operator= (const TStack& s) {
		if (MaxSize != s.MaxSize) {
			delete[] pMem;
			MaxSize = s.MaxSize;
			pMem = new T[MaxSize];
		}
		CurrInd = s.CurrInd;
		for (int i = 0; i < CurrInd + 1; i++) {
			pMem[i] = s.pMem[i];
		}
	}
	friend std::ostream& operator<< (std::ostream& os, const TStack& s) {
		for (int i = 0; i < s.CurrInd; i++) {
			os << s.pMem[i] << " ";
		}
		return os;
	}
	bool empty() { return CurrInd == -1; }
	bool full() { return CurrInd == (MaxSize - 1); }
	void push(const T& el) {
		CurrInd++;
		pMem[CurrInd] = el;
		if (CurrInd >= MaxSize) throw "Stack overflow";
	}
	T pop() {
		if (empty()) throw "Stack is empty";
		CurrInd--;
		return pMem[CurrInd + 1];
	}
	T top() {
		if (empty()) throw "Stack is empty";
		return pMem[CurrInd + 1];
	}
	void clear() {
		CurrInd = -1;
	}
};