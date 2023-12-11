#include "pch.h"
#include "../Stack/Stack.h"

TEST(TStack, CAN_CREATE_STACK_WITH_POSITIVE_SIZE) {

}

TEST(TStack, CANT_CREATE_STACK_WTIH_NEGATIVE_SIZE) {
	EXPECT_ANY_THROW(TStack<int> s(-1));
	EXPECT_ANY_THROW(TStack<int> s(0));
}

TEST(TStack, FULL_STACK_PUSH_THROWS_EXCEPTION) {
	TStack<int> s(3);
	s.push(1);
	s.push(1);
	s.push(1);

	EXPECT_ANY_THROW(s.push(1));
}

TEST(TStack, EMPTY_STACK_POP_THROWS_EXCEPTION) {
	TStack<int> s(3);

	EXPECT_ANY_THROW(s.pop());
}

TEST(TStack, EMPTY_STACK_TOP_THROWS_EXCEPTION) {
	TStack<int> s(3);

	EXPECT_ANY_THROW(s.top());
}

//can_create_stack_with_positive_size
//can_get_length
//new_stack_is_empty
//can_push_and_pop
//throws_when_use_pop_on_empty_stack
//throws_when_use_push_on_overflow_stack
//throws_when_use_TOP_on_empty_stack
//return_true_when_use_Full_on_full_stack
//return_false_when_use_Full_on_not_full_stack
//return_true_when_use_Empty_on_empty_stack
//return_false_when_use_Empty_on_not_empty_stack