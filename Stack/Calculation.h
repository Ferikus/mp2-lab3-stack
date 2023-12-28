#pragma once
#include <string>
#include <cmath>
#include "Stack.h";

class TCalc
{
	std::string infix, postfix;
	TStack<double> D;
	TStack<char> C;
	int prior(char c) {
		switch (c) {
		case '(': return 0;
		case ')': return 0;
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '^': return 3;
		}
	};
public:
	TCalc() {}

	TCalc(std::string s):infix(s) {
		toPostfix();
	}

	void setInfix(std::string s) { infix = s; }

	std::string getInfix() { return infix; }

	std::string getPostfix() { return postfix; }

	void toPostfix() {
		C.clear();
		std::string str = '(' + infix + ')';
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') C.push('(');
			if (isdigit(str[i])) postfix += str[i];
			if (str[i] == ')') {
				char el = C.pop();
				while (el != '(') {
					postfix += el;
					el = C.pop();
				}
			}
			if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^')) {
				char el = C.pop();
				while (prior(el) >= prior(str[i])) {
					postfix += el;
					el = C.pop();
				}
				C.push(el);
				C.push(str[i]);
			}
		}
	}

	bool checkExpression() {
		int res = true;
		for (int i = 0; i < infix.size(); i++) {
			if (infix[i] == '(') C.push('(');
			if (infix[i] == ')') {
				if (!C.empty()) C.pop();
				else res = false;
			}
		}
		if (!C.empty()) res = false;
		return res;
	}

	double calc() {
		D.clear();
		for (int i = 0; i < postfix.length(); i++) {
			if (isdigit(postfix[i])) D.push(postfix[i] - '0');
			if ((postfix[i] == '+') || (postfix[i] == '-') || (postfix[i] == '*') || (postfix[i] == '/') || (postfix[i] == '^')) {
				double x1 = 0, x2 = 0, y = 0;
				if (D.empty() == false) x2 = D.pop();
				if (D.empty() == false) x1 = D.pop();
				switch (postfix[i]) {
				case '+': y = x1 + x2; break;
				case '-': y = x1 - x2; break;
				case '*': y = x1 * x2; break;
				case '/': {
					if (x2 == 0) throw "Division by 0";
					y = x1 / x2;
				} break;
				case '^': y = pow(x1, x2); break;
				}
				D.push(y);
			}
		}
		double res = D.pop();
		//if (D.empty() == false) res = D.pop();
		//else throw "Stack is empty";
		return res;
	}
};