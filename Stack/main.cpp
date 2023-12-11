#include <iostream>
#include "Calculation.h"

int main() {
	TCalc expr;
	std::string s;
	double res = 0;

	std::cout << "Enter the expression" << std::endl;
	getline(std::cin, s);
	if (expr.checkExpression()) {
		std::cout << "The expression is valid. Calculating...";
		res = s.calc();
		std::cout << "This expression equals " << res << std::endl;
	}
}