#include <iostream>
#include "Calculation.h"

int main() {
	std::string s;
	double res;

	std::cout << "Enter the expression" << std::endl;
	getline(std::cin, s);
	TCalc expr(s);
	if (expr.checkExpression()) {
		std::cout << "The expression is valid. Calculating...";
		res = expr.calc();
		std::cout << "This expression equals " << res << std::endl;
	}
}