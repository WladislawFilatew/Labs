#include <gtest.h>
#include "..\lib\queue_lib.h"



TEST(Queue, you_can_create_an_object)
{
	ASSERT_NO_THROW(MyQueue<int> a);
}

TEST(Queue, can_check_for_emptiness)
{
	MyQueue<int> temp;
	EXPECT_EQ(true, temp.empty());
}

TEST(Queue, the_stac_is_not_empty)
{
	MyQueue<int> temp;
	for (int i = 0; i < 10; i++) {
		temp.push(i);
	}
	EXPECT_EQ(false, temp.empty());
}

TEST(Queue, can_add_objects_1_object)
{
	MyQueue<int> temp;
	temp.push(1);
	EXPECT_EQ(1, temp.size());
}

TEST(Queue, can_add_objects_multiple_objects)
{
	MyQueue<int> temp;
	for (int i = 0; i < 10; i++) {
		temp.push(i);
	}
	EXPECT_EQ(10, temp.size());
}

TEST(Queue, error_clearing_an_empty_stack)
{
	MyQueue<int> a;
	ASSERT_ANY_THROW(a.pop());
}

TEST(Queue, there_is_no_error_when_deleting_an_element_from_an_object)
{
	MyQueue<int> a;
	a.push(1);
	ASSERT_NO_THROW(a.pop());
}

TEST(Queue, can_clear_the_stack)
{
	MyQueue<int> temp;
	for (int i = 0; i < 10; i++) {
		temp.push(i);
	}
	for (int i = 0; i < 10; i++) {
		temp.pop();
	}
	EXPECT_EQ(0, temp.size());
}

TEST(Queue, can_get_an_element_from_the_stack)
{
	MyQueue<int> temp;
	for (int i = 0; i < 10; i++) {
		temp.push(i + 1);
	}
	for (int i = 0; i < 3; i++) {
		temp.pop();
	}
	EXPECT_EQ(4, temp.top());
}

TEST(Queue, error_when_getting_an_element_from_an_empty_stack)
{
	MyQueue<int> a;
	ASSERT_ANY_THROW(a.top());
}

TEST(Queue, can_get_an_object_without_an_error)
{
	MyQueue<int> a;
	a.push(1);
	ASSERT_NO_THROW(a.top());
}

TEST(Queue, can_bypass_the_object)
{
	MyQueue<int> temp;
	for (int i = 0; i < 4; i++) {
		temp.push(i + 1);
	}
	int sum = 0;
	while (!temp.empty()) {
		sum += temp.top();
		temp.pop();
	}
	EXPECT_EQ(10, sum);
}