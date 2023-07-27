#include <catch2/catch_test_macros.hpp>
#include "../../../DataStructures/Queue/StaticQueue.hpp"

TEST_CASE("StaticQueue {}")
{
	StaticQueue<int, 3> queue { 1, 2, 3 };

	REQUIRE(queue[0] == 1);
	REQUIRE(queue[1] == 2);
	REQUIRE(queue[2] == 3);
}

TEST_CASE("StaticQueue .push()")
{
	StaticQueue<int, 3> queue;

	CHECK_FALSE(queue.back().has_value());
	CHECK(queue.empty());

	queue.push(44);

	REQUIRE(queue.back().value() == 44);
	REQUIRE(queue.size() == 1);

	queue.push(-2231);

	REQUIRE(queue.back().value() == -2231);
	REQUIRE(queue.size() == 2);

	queue.push(5441);

	REQUIRE(queue.back().value() == 5441);
	REQUIRE(queue.size() == 3);

	queue.push(555); // queue is already full, data is not pushed

	REQUIRE(queue.back().value() == 5441);
	REQUIRE(queue.size() == 3);
}

TEST_CASE("StaticQueue .pop()")
{
	StaticQueue<int, 3> queue {231, -40, 36 };

	REQUIRE(queue.front().value() == 231);
	REQUIRE(queue.size() == 3);

	queue.pop();

	REQUIRE(queue.front().value() == -40);
	REQUIRE(queue.size() == 2);

	queue.pop();

	REQUIRE(queue.front().value() == 36);
	REQUIRE(queue.size() == 1);

	queue.pop();

	CHECK(queue.empty());
	REQUIRE(queue.size() == 0);

	queue.pop(); // queue is already empty, nothing happens

	CHECK(queue.empty());
	REQUIRE(queue.size() == 0);
}

TEST_CASE("StaticQueue .empty()")
{
	StaticQueue<int, 3> queue;

	CHECK(queue.empty());

	queue.push(420);

	CHECK_FALSE(queue.empty());

	queue.pop();

	CHECK(queue.empty());
}

TEST_CASE("StaticQueue .full()")
{
	StaticQueue<int, 3> queue;

	CHECK_FALSE(queue.full());

	queue.pop();

	CHECK_FALSE(queue.full());

	queue = { -9, 72 };

	CHECK_FALSE(queue.full());

	queue.push(22);

	CHECK(queue.full());
}

TEST_CASE("StaticQueue .front()")
{
	StaticQueue<int, 3> queue;

	CHECK_FALSE(queue.front().has_value());

	queue.push(-241);

	REQUIRE(queue.front().value() == -241);

	queue.push(95);

	REQUIRE(queue.front().value() == -241);

	queue.pop();

	REQUIRE(queue.front().value() == 95);

	queue.pop();

	CHECK_FALSE(queue.front().has_value());
}

TEST_CASE("StaticQueue .back()")
{
	StaticQueue<int, 3> queue;

	CHECK_FALSE(queue.back().has_value());

	queue.push(-23);

	REQUIRE(queue.back().value() == -23);

	queue.push(8);

	REQUIRE(queue.back().value() == 8);

	queue.pop();

	REQUIRE(queue.back().value() == 8);

	queue.pop();

	CHECK_FALSE(queue.back().has_value());
}

TEST_CASE("StaticQueue .clear()")
{
	StaticQueue<int, 3> queue { 9, 2, 11 };

	CHECK_FALSE(queue.empty());

	queue.clear();

	CHECK(queue.empty());

	queue.push(77);

	CHECK_FALSE(queue.empty());
}

TEST_CASE("StaticQueue .size()")
{
	StaticQueue<int, 3> queue;

	REQUIRE(queue.size() == 0);

	queue.pop();

	REQUIRE(queue.size() == 0);

	queue = { -600, 422 };

	REQUIRE(queue.size() == 2);

	queue.pop();

	REQUIRE(queue.size() == 1);

	queue.push(299);

	REQUIRE(queue.size() == 2);
}

TEST_CASE("StaticQueue .capacity()")
{
	StaticQueue<int, 3> queue;

	REQUIRE(queue.capacity() == 3);

	queue = { 55, 0 };

	REQUIRE(queue.capacity() == 3);

	queue.push(-2402);

	REQUIRE(queue.capacity() == 3);

	queue.pop();

	REQUIRE(queue.capacity() == 3);

	queue.clear();

	REQUIRE(queue.capacity() == 3);
}

TEST_CASE("StaticQueue []")
{
	StaticQueue<int, 3> queue;

	queue.push(523);

	REQUIRE(queue[0] == 523);

	queue.push(13);

	REQUIRE(queue[1] == 13);

	queue.push(-23131);

	REQUIRE(queue[2] == -23131);
}