#pragma once

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
	ostream& operator<< (ostream& os, const TStack& s) {
		for (int i = 0; i < CurrInd; i++) {
			os << pMem[i] << " ";
		}
		os << pMem[i];
		return os;
	}
	bool stackEmpty() { return CurrInd == -1 }
	bool stackFull() { return CurrInd == (MaxSize - 1) }
	void stackPush(const T& el) {
		CurrInd++;
		if (CurrInd >= MaxSize) throw "Stack overflow";
	}
	T stackPop() {
		if (stackEmpty()) throw "Stack is empty";
		CurrInd--;
		return pMeme[CurrInd + 1];
	}
	T stackTop() {
		if (stackEmpty()) throw "Stack is empty";
		return pMeme[CurrInd + 1];
	}
	void stackClear() {
		CurrInd = -1;
	}
};