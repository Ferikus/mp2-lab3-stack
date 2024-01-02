#include "pch.h"
#include "../Stack/Calculation.h"

TEST(TCalc, CAN_CREATE_CALCULATION_WITH_STR) {

	std::string s = "(2 + 2)";
	ASSERT_NO_THROW(TCalc expr(s));
}

TEST(TCalc, CAN_GET_INFIX) {
	std::string s = "(2 + 2)";
	std::string a;
	TCalc expr(s);
	ASSERT_NO_THROW(a = expr.getInfix());
	EXPECT_EQ(a, expr.getInfix());
}

TEST(TCalc, CAN_SET_INFIX) {
    std::string a = "2 + (3 * 5)";
    std::string b;
    TCalc calc(a);

    ASSERT_NO_THROW(calc.setInfix(b));
    EXPECT_EQ(calc.getInfix(), b);
}

TEST(TCalc, CAN_CHECK_IF_THE_EXPRESSION_IS_CORRECT) {
    std::string a = "2 + (3 * 5)";
    TCalc calc(a);
    bool check;

    ASSERT_NO_THROW(check = calc.checkExpression());
    EXPECT_EQ(1, check);
}

TEST(TCalc, CAN_CREATE_CORRECT_POSTFIX) {
    std::string a = "2 + (3 * 5)";
    std::string b = "235*+";
    std::string c;
    TCalc expr(a);
    c = expr.getPostfix();

    EXPECT_EQ(c, b);
}

TEST(TCalc, CAN_CALCULATE) {
    std::string a = "2.2 + (3 * 5)";
    TCalc expr(a);
    double check;

    ASSERT_NO_THROW(check = expr.calc());
    EXPECT_EQ(17.2, check);
}

TEST(TCalc, PROCCESSES_ALL_OPERANDS) {
    std::string a = "((2 + 2) * 2 / 2)^2";
    TCalc expr(a);

    ASSERT_NO_THROW(expr.calc());
    EXPECT_EQ(16, expr.calc());
}