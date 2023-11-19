#pragma once
#include <string>
#include "Stack.h";

class TCalculation
{
	std::string expr;
	TStack<char> st;
public:
	bool CheckExpression();
};