#include <catch2/catch_test_macros.hpp>
#include "../../../DataStructures/Tree/BinarySearchTree.hpp"

TEST_CASE("BinarySearchTree {}")
{
	BinarySearchTree<int> bst{ 1, 2, 3 };
	
	CHECK(bst.find(1));
	CHECK(bst.find(2));
	CHECK(bst.find(3));
}

TEST_CASE("BinarySearchTree .insert()")
{
	BinarySearchTree<int> bst;

	CHECK(bst.empty());
	REQUIRE(bst.size() == 0);

	bst.insert(51);

	CHECK(bst.find(51));
	REQUIRE(bst.size() == 1);

	bst.insert(-532525);

	CHECK(bst.find(-532525));
	REQUIRE(bst.size() == 2);

	bst.insert(9962);
	
	CHECK(bst.find(9962));
	REQUIRE(bst.size() == 3);
}

TEST_CASE("BinarySearchTree .remove()")
{
	BinarySearchTree<int> bst{ 200, 404, 420 };

	CHECK_FALSE(bst.empty());
	REQUIRE(bst.size() == 3);

	bst.remove(404);

	CHECK_FALSE(bst.find(404));
	REQUIRE(bst.size() == 2);

	bst.remove(200);

	CHECK_FALSE(bst.find(200));
	REQUIRE(bst.size() == 1);

	bst.remove(420);

	CHECK_FALSE(bst.find(420));
	REQUIRE(bst.size() == 0);

	bst.remove(-31); // data does not exist, nothing is removed

	CHECK_FALSE(bst.find(-31));
	REQUIRE(bst.size() == 0);
}

TEST_CASE("BinarySearchTree .empty()")
{
	BinarySearchTree<int> bst;

	CHECK(bst.empty());

	bst.remove(54); // data does not exist, nothing is removed

	CHECK(bst.empty());

	bst.insert(9951);

	CHECK_FALSE(bst.empty());

	bst.remove(9951);

	CHECK(bst.empty());
}

TEST_CASE("BinarySearchTree .find()")
{
	BinarySearchTree<int> bst;

	CHECK_FALSE(bst.find(1));
	REQUIRE(bst.size() == 0);

	bst.insert(1);

	CHECK(bst.find(1));
	REQUIRE(bst.size() == 1);

	bst.insert(51);

	CHECK(bst.find(51));
	REQUIRE(bst.size() == 2);

	bst.remove(51);

	CHECK_FALSE(bst.find(51));
	CHECK(bst.find(1));
	REQUIRE(bst.size() == 1);
}

TEST_CASE("BinarySearchTree .min()")
{
	BinarySearchTree<int> bst;

	CHECK_FALSE(bst.min().has_value());

	bst.insert(41);

	REQUIRE(bst.min().value() == 41);

	bst.insert(61);

	REQUIRE(bst.min().value() == 41);

	bst.insert(-313);

	REQUIRE(bst.min().value() == -313);

	bst.remove(-313);

	REQUIRE(bst.min().value() == 41);

	bst.clear();

	CHECK_FALSE(bst.min().has_value());
}

TEST_CASE("BinarySearchTree .max()")
{
	BinarySearchTree<int> bst;

	CHECK_FALSE(bst.max().has_value());

	bst.insert(-41551);

	REQUIRE(bst.max().value() == -41551);

	bst.insert(61);

	REQUIRE(bst.max().value() == 61);

	bst.insert(0);

	REQUIRE(bst.max().value() == 61);

	bst.remove(61);

	REQUIRE(bst.max().value() == 0);

	bst.clear();

	CHECK_FALSE(bst.max().has_value());
}

TEST_CASE("BinarySearchTree .clear()")
{
	BinarySearchTree<int> bst { -11, 444, 0 };

	CHECK_FALSE(bst.empty());

	bst.clear();

	CHECK(bst.empty());

	bst.clear();

	CHECK(bst.empty());

	bst.insert(222);

	CHECK_FALSE(bst.empty());

	bst.clear();

	CHECK(bst.empty());
}

TEST_CASE("BinarySearchTree .size()")
{
	BinarySearchTree<int> bst;

	REQUIRE(bst.size() == 0);

	bst.remove(51);

	REQUIRE(bst.size() == 0);

	bst.insert(32113);
	bst.insert(-741);

	REQUIRE(bst.size() == 2);

	bst.insert(21317);

	REQUIRE(bst.size() == 3);

	bst.remove(-741);

	REQUIRE(bst.size() == 2);

	bst.clear();

	REQUIRE(bst.size() == 0);
}