#include "pch.h"
#include "../Stack/Stack.h"

TEST(TStack, SIZE_IS_POSITIVE) {
	EXPECT_ANY_THROW(TStack s(-1));
	EXPECT_ANY_THROW(TStack s(0));
}

TEST(TStack, FULL_STACK_PUSH_THROWS_EXCEPTION) {
	TStack s(3);
	TStack.push(1);
	TStack.push(1);
	TStack.push(1);

	EXPECT_ANY_THROW(TStack.push(1));
}

TEST(TStack, EMPTY_STACK_POP_THROWS_EXCEPTION) {
	TStack s(3);

	EXPECT_ANY_THROW(TStack.pop());
}

TEST(TStack, EMPTY_STACK_TOP_THROWS_EXCEPTION) {
	TStack s(3);

	EXPECT_ANY_THROW(TStack.top());
}