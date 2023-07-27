#include <catch2/catch_test_macros.hpp>
#include "../../../DataStructures/Array/FixedArray.hpp"

TEST_CASE("FixedArray {}")
{
	FixedArray<int, 3> arr { -1, 893, 12345 };

	REQUIRE(arr[0] == -1);
	REQUIRE(arr[1] == 893);
	REQUIRE(arr[2] == 12345);
}

TEST_CASE("FixedArray .insert()")
{
	FixedArray<int, 3> arr;
	arr.insert(22, 0);
	arr.insert(326, 1);
	arr.insert(-85325, 2);

	REQUIRE(arr[0] == 22);
	REQUIRE(arr[1] == 326);
	REQUIRE(arr[2] == -85325);
}

TEST_CASE("FixedArray .front()")
{
	FixedArray<int, 3> arr{ -50, 20, 1415 };

	REQUIRE(arr.front() == -50);
}

TEST_CASE("FixedArray .back()")
{
	FixedArray<int, 3> arr{ 404, 4141, -737 };

	REQUIRE(arr.back() == -737);
}

TEST_CASE("FixedArray .size()")
{
	FixedArray<int, 3> arr;

	REQUIRE(arr.size() == 3);

	SECTION("Size does not change when using .insert()")
	{
		arr.insert(32, 0);

		REQUIRE(arr.size() == 3);
	}

	SECTION("Size does not change when using [] overload")
	{
		arr[2] = 20;

		REQUIRE(arr.size() == 3);
	}
}

TEST_CASE("FixedArray [] Insertion")
{
	FixedArray<int, 3> arr;
	arr[0] = -4;
	arr[1] = 23;
	arr[2] = 5151;

	REQUIRE(arr[0] == -4);
	REQUIRE(arr[1] == 23);
	REQUIRE(arr[2] == 5151);
}