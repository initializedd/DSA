#include <catch2/catch_test_macros.hpp>
#include "../../../DataStructures/LinkedList/SingleLinkedList.hpp"

TEST_CASE("SingleLinkedList {}")
{
	SingleLinkedList<int> list{ 595, -41, 662 };

	CHECK(list.front().has_value());
	REQUIRE(list.front().value() == 595);

	list.pop_front();

	REQUIRE(list.front().value() == -41);

	list.pop_front();

	REQUIRE(list.front().value() == 662);

	list.pop_front();

	CHECK_FALSE(list.front().has_value());
	REQUIRE(list.size() == 0);
}

TEST_CASE("SingleLinkedList .push_front()")
{
	SingleLinkedList<int> list;

	CHECK(list.empty());
	REQUIRE(list.size() == 0);

	list.push_front(-616);

	REQUIRE(list.front().value() == -616);
	REQUIRE(list.size() == 1);

	list.push_front(99999);

	REQUIRE(list.front().value() == 99999);
	REQUIRE(list.size() == 2);

	list.push_front(4414);

	REQUIRE(list.front().value() == 4414);
	REQUIRE(list.size() == 3);
}

TEST_CASE("SingleLinkedList .push_back()")
{
	SingleLinkedList<int> list;

	CHECK(list.empty());
	REQUIRE(list.size() == 0);

	list.push_back(441);

	REQUIRE(list.front().value() == 441);
	REQUIRE(list.size() == 1);

	list.push_back(-51);

	REQUIRE(list.front().value() == 441);
	REQUIRE(list.size() == 2);

	list.pop_front();

	REQUIRE(list.front().value() == -51);
	REQUIRE(list.size() == 1);
}

TEST_CASE("SingleLinkedList .pop_front()")
{
	SingleLinkedList<int> list{ 8004, -414, 404 };

	CHECK_FALSE(list.empty());
	REQUIRE(list.front().value() == 8004);

	list.pop_front();

	REQUIRE(list.front().value() == -414);
	REQUIRE(list.size() == 2);

	list.pop_front();

	REQUIRE(list.front().value() == 404);
	REQUIRE(list.size() == 1);

	list.pop_front();

	CHECK_FALSE(list.front().has_value());
	CHECK(list.empty());

	list.pop_front(); // list is already empty, nothing happens

	CHECK_FALSE(list.front().has_value());
	CHECK(list.empty());
}

TEST_CASE("SingleLinkedList .pop_back()")
{
	SingleLinkedList<int> list;

	CHECK(list.empty());
	CHECK_FALSE(list.front().has_value());

	list.push_back(5514);
	list.push_back(214);

	CHECK_FALSE(list.empty());
	REQUIRE(list.front().value() == 5514);

	list.pop_back();

	REQUIRE(list.front().value() == 5514);
	REQUIRE(list.size() == 1);

	list.pop_back();

	CHECK(list.empty());
	CHECK_FALSE(list.front().has_value());

	list.pop_back(); // list is already empty, nothing happens

	CHECK(list.empty());
	CHECK_FALSE(list.front().has_value());
}

TEST_CASE("SingleLinkedList .empty()")
{
	SingleLinkedList<int> list;

	CHECK(list.empty());

	list.push_front(551);

	CHECK_FALSE(list.empty());

	list.pop_back();

	CHECK(list.empty());
}

TEST_CASE("SingleLinkedList .front()")
{
	SingleLinkedList<int> list{ 999, 444, 666 };

	CHECK(list.front().has_value());
	REQUIRE(list.front().value() == 999);

	list.pop_front();

	CHECK(list.front().has_value());
	REQUIRE(list.front().value() == 444);

	list.pop_front();

	CHECK(list.front().has_value());
	REQUIRE(list.front().value() == 666);

	list.pop_front();

	CHECK_FALSE(list.front().has_value());

	list.insert(5551, 0);

	CHECK(list.front().has_value());
	REQUIRE(list.front().value() == 5551);
}

TEST_CASE("SingleLinkedList .insert()")
{
	SingleLinkedList<int> list;

	REQUIRE(list.size() == 0);

	list.insert(-151, 0);

	REQUIRE(list.front().value() == -151);
	REQUIRE(list.size() == 1);

	list.insert(44, -1); // invalid index, nothing happens

	REQUIRE(list.front().value() == -151);
	REQUIRE(list.size() == 1);

	list.insert(65, 1);

	REQUIRE(list.front().value() == -151);
	REQUIRE(list.size() == 2);

	list.pop_front();

	REQUIRE(list.front().value() == 65);
	REQUIRE(list.size() == 1);
}

TEST_CASE("SingleLinkedList .clear()")
{
	SingleLinkedList<int> list { 0, 1, -1 };

	CHECK_FALSE(list.empty());

	list.clear();

	CHECK(list.empty());

	list.clear();

	CHECK(list.empty());

	list.push_front(333);

	CHECK_FALSE(list.empty());

	list.clear();

	CHECK(list.empty());
}

TEST_CASE("SingleLinkedList .size()")
{
	SingleLinkedList<int> list;

	REQUIRE(list.size() == 0);

	list.pop_front(); // list is already empty, nothing happens

	REQUIRE(list.size() == 0);

	list.push_front(19533);
	list.push_back(-421);

	REQUIRE(list.size() == 2);

	list.push_front(7);

	REQUIRE(list.size() == 3);

	list.pop_back();

	REQUIRE(list.size() == 2);

	list.clear();

	REQUIRE(list.size() == 0);
}