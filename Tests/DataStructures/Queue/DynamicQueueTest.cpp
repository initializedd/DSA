#include <catch2/catch_test_macros.hpp>
#include "../../../DataStructures/Queue/DynamicQueue.hpp"

TEST_CASE("DynamicQueue {}")
{
	DynamicQueue<int> queue { -2113, 8228, -1312 };

	REQUIRE(queue.front().value() == -2113);

	queue.pop();

	REQUIRE(queue.front().value() == 8228);

	queue.pop();

	REQUIRE(queue.front().value() == -1312);
}

TEST_CASE("DynamicQueue .push()")
{
	DynamicQueue<int> queue;

	CHECK_FALSE(queue.back().has_value());
	CHECK(queue.empty());

	queue.push(214);

	REQUIRE(queue.back().value() == 214);
	REQUIRE(queue.size() == 1);

	queue.push(-3213);

	REQUIRE(queue.back().value() == -3213);
	REQUIRE(queue.size() == 2);

	queue.push(-25516);

	REQUIRE(queue.back().value() == -25516);
	REQUIRE(queue.size() == 3);
}

TEST_CASE("DynamicQueue .pop()")
{
	DynamicQueue<int> queue {4213, -2151, 221544};

	REQUIRE(queue.front().value() == 4213);
	REQUIRE(queue.size() == 3);

	queue.pop();

	REQUIRE(queue.front().value() == -2151);
	REQUIRE(queue.size() == 2);

	queue.pop();

	REQUIRE(queue.front().value() == 221544);
	REQUIRE(queue.size() == 1);

	queue.pop();

	CHECK(queue.empty());
	REQUIRE(queue.size() == 0);

	queue.pop(); // queue is already empty, nothing happens

	CHECK(queue.empty());
	REQUIRE(queue.size() == 0);
}

TEST_CASE("DynamicQueue .empty()")
{
	DynamicQueue<int> queue;

	CHECK(queue.empty());

	queue.push(1414);

	CHECK_FALSE(queue.empty());

	queue.pop();

	CHECK(queue.empty());
}

TEST_CASE("DynamicQueue .front()")
{
	DynamicQueue<int> queue;

	CHECK_FALSE(queue.front().has_value());

	queue.push(-211);

	REQUIRE(queue.front().value() == -211);

	queue.push(1935);

	REQUIRE(queue.front().value() == -211);

	queue.pop();

	REQUIRE(queue.front().value() == 1935);

	queue.pop();

	CHECK_FALSE(queue.front().has_value());
}

TEST_CASE("DynamicQueue .back()")
{
	DynamicQueue<int> queue;

	CHECK_FALSE(queue.back().has_value());

	queue.push(-66123);

	REQUIRE(queue.back().value() == -66123);

	queue.push(841);

	REQUIRE(queue.back().value() == 841);

	queue.pop();

	REQUIRE(queue.back().value() == 841);

	queue.pop();

	CHECK_FALSE(queue.back().has_value());
}

TEST_CASE("DynamicQueue .clear()")
{
	DynamicQueue<int> queue { -221, 551, 514 };

	CHECK_FALSE(queue.empty());

	queue.clear();

	CHECK(queue.empty());

	queue.push(666);

	CHECK_FALSE(queue.empty());
}

TEST_CASE("DynamicQueue .size()")
{
	DynamicQueue<int> queue;

	REQUIRE(queue.size() == 0);

	queue.pop();

	REQUIRE(queue.size() == 0);

	queue.push(213);
	queue.push(-441);

	REQUIRE(queue.size() == 2);

	queue.push(21317);

	REQUIRE(queue.size() == 3);

	queue.pop();

	REQUIRE(queue.size() == 2);
}