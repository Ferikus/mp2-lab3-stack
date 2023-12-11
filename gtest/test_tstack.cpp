#include "pch.h"
#include "../Stack/Stack.h"

TEST(TStack, CAN_CREATE_STACK_WITH_POSITIVE_SIZE) {
	EXPECT_NO_THROW(TStack<int> s(3));
}

TEST(TStack, CANT_CREATE_STACK_WTIH_NEGATIVE_SIZE) {
	EXPECT_ANY_THROW(TStack<int> s(-1));
	EXPECT_ANY_THROW(TStack<int> s(0));
}

TEST(TStack, CAN_GET_MAXSIZE) {
	TStack<int> s(3);

	EXPECT_NO_THROW(s.getMaxSize());
	EXPECT_EQ(3, s.getMaxSize());
}

TEST(TStack, CAN_GET_LENGTH) {
	TStack<int> s(3);
	s.push(1);
	s.push(1);

	EXPECT_NO_THROW(s.getLength());
	EXPECT_EQ(2, s.getLength());
}

TEST(TStack, NEW_STACK_IS_EMPTY) {
	TStack<int> s(3);

	ASSERT_TRUE(s.empty());
}

TEST(TStack, CAN_PUSH) {
	TStack<int> s(3);

	EXPECT_NO_THROW(s.push(1));
}

TEST(TStack, CAN_POP) {
	TStack<int> s(3);

	EXPECT_NO_THROW(s.pop(1));
}

TEST(TStack, FULL_STACK_IS_FULL) {
	TStack<int> s1(3);
	TStack<int> s2(3);
	s1.push(1);
	s1.push(1);
	s1.push(1);
	
	EXPECT_TRUE(s1.full());
	EXPECT_FALSE(s2.full());
}

TEST(TStack, EMPTY_STACK_IS_EMPTY) {
	TStack<int> s1(3);
	TStack<int> s2(3);
	s1.push(1);
	s1.push(1);
	s1.push(1);

	EXPECT_TRUE(s2.empty());
	EXPECT_FALSE(s1.empty());
}

TEST(TStack, EMPTY_STACK_POP_THROWS_EXCEPTION) {
	TStack<int> s(3);

	EXPECT_ANY_THROW(s.pop());
}

TEST(TStack, EMPTY_STACK_TOP_THROWS_EXCEPTION) {
	TStack<int> s(3);

	EXPECT_ANY_THROW(s.top());
}

TEST(TStack, FULL_STACK_PUSH_THROWS_EXCEPTION) {
	TStack<int> s(3);
	s.push(1);
	s.push(1);
	s.push(1);

	EXPECT_ANY_THROW(s.push(1));
}