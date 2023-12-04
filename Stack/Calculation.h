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
	bool checkExpression();
	void toPostfix();
	double calc();
};