#include "Calculation.h";

bool TCalculation::CheckExpression() {
	int res = true;
	for (int i = 0; i < expr.size(); i++) {
		if (expr[i] == '(') st.stackPush('(');
		if (expr[i] == ')') {
			if (!st.stackEmpty()) st.stackPop();
			else res = false;
		}
	}
	if (!st.stackEmpty()) res = false;
	return res;
}