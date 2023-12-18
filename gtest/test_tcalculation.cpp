#include "pch.h"
#include "../Stack/Calculation.h"

TEST(TCalc, CAN_CREATE_CALCULATION_WITH_STR) {

	std::string s = "(2 + 2)";
	ASSERT_NO_THROW(TCalc expr(s));
}

//TEST(TCalc, CAN_GET_INFIX) {
//	std::string s = "(2 + 2)";
//	std::string a;
//	TCalc expr(s);
//	ASSERT_NO_THROW(a = expr.getInfix());
//	EXPECT_EQ(a, expr.getInfix());
//}

TEST(TCalc, CAN_SET_INFIX) {
	ADD_FAILURE();
}

TEST(TCalc, CAN_CHECK_IF_THE_EXPRESSION_IS_CORRECT) {
	ADD_FAILURE();
}

TEST(TCalc, CAN_CREATE_CORRECT_POSTFIX) {
	ADD_FAILURE();
}

TEST(TCalc, CAN_CALCULATE) {
	ADD_FAILURE();
}


//TEST(TCalc, CAN_SET_INFIX)
//{
//    std::string a = "2+(3*5)";
//    std::string b;
//    TCalculator calc(a);
//    ASSERT_NO_THROW(calc.set_infix(b));
//    EXPECT_EQ(calc.get_infix(), b);
//}
//TEST(TCalc, CAN_CREATE_CORRECT_POSTFIX)
//{
//    std::string a = "2+(3*5)";
//    std::string b = "235*+";
//    std::string c;
//    TCalculator calc(a);
//    ASSERT_NO_THROW(c = calc.get_postfix());
//    EXPECT_EQ(c, b);
//}
//TEST(TCalc, CAN_CHECK_IF_THE_EXPRESSION_IS_CORRECT)
//{
//    std::string a = "2+(3*5)";
//
//
//    TCalculator calc(a);
//    bool check;
//    ASSERT_NO_THROW(check = calc.CheckExpression());
//    EXPECT_EQ(1, check);
//}
//TEST(TCalc, CAN_CALCULATE)
//{
//    std::string a = "2+(3*5)";
//
//
//    TCalculator calc(a);
//    double check;
//    ASSERT_NO_THROW(check = calc.CalcPostfix());
//    EXPECT_EQ(17, check);
//}
//