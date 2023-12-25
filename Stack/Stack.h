#pragma once
#include <iostream>

template <class T>
struct TNode
{
	T val;
	TNode<T>* pNext;
};

template <class T>
class TStack
{
	TNode<T>* pFirst;
public:
	TStack() { pFirst = nullptr; }

	TStack(const TStack<T>& s) {
		TNode<T>* tmp = new TNode<T>;
		tmp = s.pFirst;
		while (tmp != nullptr)
		{
			pFirst = tmp;
			tmp = tmp->pNext;
		}
	}

	TStack<T>& operator=(const TStack & s) {
		TNode<T>* tmp = new TNode<T>;
		tmp = s.pFirst;
		while (tmp != nullptr) {
			pFirst = tmp;
			tmp = tmp->pNext;
		}
		return *this;
	}

	~TStack() {
		TNode <T>* tmp = pFirst;
		while (pFirst != nullptr) {
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}

	bool empty() { return pFirst == nullptr; }

	bool full() {
		TNode<T>* p = new TNode<T>;
		if (p)
		{
			delete p;
			return true;
		}
		else return false;
	}

	void push(T el) {
		TNode <T>* tmp;
		tmp = new TNode<T>;
		tmp->pNext = pFirst;
		tmp->val = el;
		pFirst = tmp;
	}

	T pop() {
		if (empty()) throw "The stack is empty";
		T res = pFirst->val;
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		return res;
	}

	T top() {
		if (empty()) throw "The stack is empty";
		return pFirst->val;
	}

	void clear() {
		TNode <T>* tmp = pFirst;
		while (pFirst != nullptr) {
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}

	int getLength() {
		TNode<T>* p = pFirst;
		int i = 0;
		while (p != nullptr) {
			i++;
			p = (*p).pNext;
		}
		return i;
	}
};