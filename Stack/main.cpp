#include <iostream>
#include "Calculation.h"

int main() {
	try {
		std::string s;
		double res;
	
		std::cout << "Enter the expression" << std::endl;
		std::cout << "To end the execution enter 'STOP'" << std::endl;
		getline(std::cin, s);

		while (s != "STOP") {
			TCalc expr(s);
			if (expr.checkExpression()) {
				std::cout << "The expression is valid. Calculating..." << std::endl;
				res = expr.calc();
				std::cout << "This expression equals " << res << std::endl << std::endl;
			}
			std::cout << "Enter the expression" << std::endl;
			std::cout << "To end the execution enter 'STOP'" << std::endl;
			getline(std::cin, s);
		}
	}
	catch (const char* ex) {
		std::cout << ex;
	}
}