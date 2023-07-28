#include <catch2/catch_test_macros.hpp>
#include "../../../DataStructures/Stack/StaticStack.hpp"

TEST_CASE("StaticStack {}")
{
	StaticStack<int, 3> stack { 1, 2, 3 };

	REQUIRE(stack[0] == 1);
	REQUIRE(stack[1] == 2);
	REQUIRE(stack[2] == 3);
}

TEST_CASE("StaticStack .push()")
{
	StaticStack<int, 3> stack;

	CHECK_FALSE(stack.top().has_value());
	CHECK(stack.empty());

	stack.push(20);

	REQUIRE(stack.top().value() == 20);
	REQUIRE(stack.size() == 1);

	stack.push(-300);

	REQUIRE(stack.top().value() == -300);
	REQUIRE(stack.size() == 2);

	stack.push(25554);

	REQUIRE(stack.top().value() == 25554);
	REQUIRE(stack.size() == 3);

	stack.push(555); // stack is already full, data is not pushed

	REQUIRE(stack.top().value() == 25554);
	REQUIRE(stack.size() == 3);
}

TEST_CASE("StaticStack .pop()")
{
	StaticStack<int, 3> stack {5, 4, 6 };

	REQUIRE(stack.top().value() == 6);
	REQUIRE(stack.size() == 3);

	stack.pop();

	REQUIRE(stack.top().value() == 4);
	REQUIRE(stack.size() == 2);

	stack.pop();

	REQUIRE(stack.top().value() == 5);
	REQUIRE(stack.size() == 1);

	stack.pop();

	CHECK(stack.empty());
	REQUIRE(stack.size() == 0);

	stack.pop(); // stack is already empty, nothing happens

	CHECK(stack.empty());
	REQUIRE(stack.size() == 0);
}

TEST_CASE("StaticStack .empty()")
{
	StaticStack<int, 3> stack;

	CHECK(stack.empty());

	stack.push(42);

	CHECK_FALSE(stack.empty());

	stack.pop();

	CHECK(stack.empty());
}

TEST_CASE("StaticStack .full()")
{
	StaticStack<int, 3> stack;

	CHECK_FALSE(stack.full());

	stack.pop();

	CHECK_FALSE(stack.full());

	stack = { 1, 4 };

	CHECK_FALSE(stack.full());

	stack.push(41);

	CHECK(stack.full());
}

TEST_CASE("StaticStack .top()")
{
	StaticStack<int, 3> stack;

	CHECK_FALSE(stack.top().has_value());

	stack.push(-441);

	REQUIRE(stack.top().value() == -441);

	stack.push(95);

	REQUIRE(stack.top().value() == 95);

	stack.pop();

	REQUIRE(stack.top().value() == -441);

	stack.pop();

	CHECK_FALSE(stack.top().has_value());
}

TEST_CASE("StaticStack .clear()")
{
	StaticStack<int, 3> stack { 2, 9, 41 };

	CHECK_FALSE(stack.empty());

	stack.clear();

	CHECK(stack.empty());
	
	stack.clear();

	CHECK(stack.empty());

	stack.push(77);

	CHECK_FALSE(stack.empty());

	stack.clear();

	CHECK(stack.empty());
}

TEST_CASE("StaticStack .size()")
{
	StaticStack<int, 3> stack;

	REQUIRE(stack.size() == 0);

	stack.pop();

	REQUIRE(stack.size() == 0);

	stack = { -300, -442 };

	REQUIRE(stack.size() == 2);

	stack.pop();

	REQUIRE(stack.size() == 1);

	stack.push(-999);

	REQUIRE(stack.size() == 2);

	stack.clear();

	REQUIRE(stack.size() == 0);
}

TEST_CASE("StaticStack .capacity()")
{
	StaticStack<int, 3> stack;

	REQUIRE(stack.capacity() == 3);

	stack = { 647, -2 };

	REQUIRE(stack.capacity() == 3);

	stack.push(44);

	REQUIRE(stack.capacity() == 3);

	stack.pop();

	REQUIRE(stack.capacity() == 3);

	stack.clear();

	REQUIRE(stack.capacity() == 3);
}

TEST_CASE("StaticStack []")
{
	StaticStack<int, 3> stack;

	stack.push(5);

	REQUIRE(stack[0] == 5);

	stack.push(-23);

	REQUIRE(stack[1] == -23);

	stack.push(0);

	REQUIRE(stack[2] == 0);
}