#include "pch.h"
#include "../Stack/Stack.h"

TEST(TStack, CAN_CREATE_STACK_WITH_POSITIVE_SIZE) {
	EXPECT_NO_THROW(TStack<int> s);
}

TEST(TStack, CAN_GET_LENGTH) {
	TStack<int> s;
	s.push(1);
	s.push(1);

	EXPECT_NO_THROW(s.getLength());
	EXPECT_EQ(2, s.getLength());
}

TEST(TStack, NEW_STACK_IS_EMPTY) {
	TStack<int> s;

	ASSERT_TRUE(s.empty());
}

TEST(TStack, CAN_PUSH) {
	TStack<int> s;

	EXPECT_NO_THROW(s.push(1));
}

TEST(TStack, CAN_POP) {
	TStack<int> s;
	s.push(1);
	s.push(1);

	EXPECT_NO_THROW(s.pop());
	EXPECT_EQ(1, s.pop());
}

TEST(TStack, EMPTY_STACK_IS_EMPTY) {
	TStack<int> s1;
	TStack<int> s2;
	s1.push(1);
	s1.push(1);
	s1.push(1);

	EXPECT_TRUE(s2.empty());
	EXPECT_FALSE(s1.empty());
}

TEST(TStack, EMPTY_STACK_POP_THROWS_EXCEPTION) {
	TStack<int> s;

	EXPECT_ANY_THROW(s.pop());
}

TEST(TStack, EMPTY_STACK_TOP_THROWS_EXCEPTION) {
	TStack<int> s;

	EXPECT_ANY_THROW(s.top());
}