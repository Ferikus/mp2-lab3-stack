#include "Calculation.h";

TCalc::TCalc() {}

TCalc::TCalc(std::string s) {
	infix = s;
	toPostfix();
}

int TCalc::prior(char c) {
	switch (c) {
	case '(': return 0;
	case ')': return 0;
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	case '^': return 3;
	}
}

void TCalc::setInfix(std::string s) { infix = s; }

std::string TCalc::getInfix() { return infix; }

void TCalc::toPostfix() {
	C.clear();
	std::string str = "(" + infix + ")";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') C.push('(');
		else if (isdigit(str[i])) postfix += str[i];
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
		}
	}
}

bool TCalc::checkExpression() {
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

double TCalc::calc() {
	C.clear(); D.clear();
	std::string str = '(' + infix + ')';
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') C.push(str[i]);
		if (str[i] == ')') {
			char el = C.pop();
			while (el != ')') {
				double x2 = D.pop(),
					x1 = D.pop(),
					res;
				switch (el) {
				case '+': res = x1 + x2; break;
				case '-': res = x1 - x2; break;
				case '*': res = x1 * x2; break;
				case '/': res = x1 / x2; break;
				case '^': res = pow(x1, x2); break;
				}
				D.push(res);
				el = C.pop();
			}
		}
		if (isdigit(str[i])) {
			size_t pos;
			double x;
			x = std::stod(&str[i], &pos);
			D.push(x);
			i = i + pos - 1;
		}
		if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^')) {
			char el = C.pop();
			while (prior(el) >= prior(str[i])) {
				double x1, x2, res;
				x2 = D.pop();
				x1 = D.pop();
				switch (str[i]) {
				case '+': res = x1 + x2; break;
				case '-': res = x1 - x2; break;
				case '*': res = x1 * x2; break;
				case '/': res = x1 / x2; break;
				case '^': res = pow(x1, x2); break;
				}
				D.push(res);
				el = C.pop();
			}
			C.push(el);
			C.push(str[i]);
		}
	}
	return D.pop();
}