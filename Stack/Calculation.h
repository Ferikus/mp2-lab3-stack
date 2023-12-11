#pragma once
#include <string>
#include <cmath>
#include "Stack.h";

class TCalc
{
	std::string infix, postfix;
	TStack<double> D;
	TStack<char> C;
	int prior(char c);
public:
	void toInfix(std::string s);
	void toPostfix();
	bool checkExpression();
	double calc();
};