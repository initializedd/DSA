#include <catch2/catch_test_macros.hpp>
#include "../../../DataStructures/Stack/DynamicStack.hpp"

TEST_CASE("DynamicStack {}")
{
	DynamicStack<int> stack { -43, 88, 22 };

	REQUIRE(stack.top().value() == 22);

	stack.pop();

	REQUIRE(stack.top().value() == 88);

	stack.pop();

	REQUIRE(stack.top().value() == -43);
}

TEST_CASE("DynamicStack .push()")
{
	DynamicStack<int> stack;

	CHECK_FALSE(stack.top().has_value());
	CHECK(stack.empty());

	stack.push(44);

	REQUIRE(stack.top().value() == 44);
	REQUIRE(stack.size() == 1);

	stack.push(-33);

	REQUIRE(stack.top().value() == -33);
	REQUIRE(stack.size() == 2);

	stack.push(66236);

	REQUIRE(stack.top().value() == 66236);
	REQUIRE(stack.size() == 3);
}

TEST_CASE("DynamicStack .pop()")
{
	DynamicStack<int> stack {446, -4151, 4};

	REQUIRE(stack.top().value() == 4);
	REQUIRE(stack.size() == 3);

	stack.pop();

	REQUIRE(stack.top().value() == -4151);
	REQUIRE(stack.size() == 2);

	stack.pop();

	REQUIRE(stack.top().value() == 446);
	REQUIRE(stack.size() == 1);

	stack.pop();

	CHECK(stack.empty());
	REQUIRE(stack.size() == 0);

	stack.pop(); // stack is already empty, nothing happens

	CHECK(stack.empty());
	REQUIRE(stack.size() == 0);
}

TEST_CASE("DynamicStack .empty()")
{
	DynamicStack<int> stack;

	CHECK(stack.empty());

	stack.push(44);

	CHECK_FALSE(stack.empty());

	stack.pop();

	CHECK(stack.empty());
}

TEST_CASE("DynamicStack .top()")
{
	DynamicStack<int> stack;

	CHECK_FALSE(stack.top().has_value());

	stack.push(-844);

	REQUIRE(stack.top().value() == -844);

	stack.push(0);

	REQUIRE(stack.top().value() == 0);

	stack.pop();

	REQUIRE(stack.top().value() == -844);

	stack.pop();

	CHECK_FALSE(stack.top().has_value());
}

TEST_CASE("DynamicStack .clear()")
{
	DynamicStack<int> stack { -98, 73, 44 };

	CHECK_FALSE(stack.empty());

	stack.clear();

	CHECK(stack.empty());

	stack.push(77);

	CHECK_FALSE(stack.empty());
}

TEST_CASE("DynamicStack .size()")
{
	DynamicStack<int> stack;

	REQUIRE(stack.size() == 0);

	stack.pop();

	REQUIRE(stack.size() == 0);

	stack.push(3);
	stack.push(4);

	REQUIRE(stack.size() == 2);

	stack.push(7);

	REQUIRE(stack.size() == 3);

	stack.pop();

	REQUIRE(stack.size() == 2);
}