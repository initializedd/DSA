#include <catch2/catch_test_macros.hpp>
#include "../../../DataStructures/Array/FixedArray.hpp"

TEST_CASE(".insert()")
{
	FixedArray<int, 5> arr;
	arr.insert(22, 0);
	arr.insert(326, 1);
	arr.insert(-85325, 2);
	arr.insert(11916062, 3);
	arr.insert(-7685151, 4);

	REQUIRE(arr[0] == 22);
	REQUIRE(arr[1] == 326);
	REQUIRE(arr[2] == -85325);
	REQUIRE(arr[3] == 11916062);
	REQUIRE(arr[4] == -7685151);
}

TEST_CASE("[] insertion")
{
	FixedArray<int, 5> arr;
	arr[0] = -4;
	arr[1] = 23;
	arr[2] = 5151;
	arr[3] = -77353; 
	arr[4] = 0;

	REQUIRE(arr[0] == -4);
	REQUIRE(arr[1] == 23);
	REQUIRE(arr[2] == 5151);
	REQUIRE(arr[3] == -77353);
	REQUIRE(arr[4] == 0);
}

TEST_CASE(".front()")
{
	FixedArray<int, 5> arr{-50, 20, 1415, -3151, 2};
	
	REQUIRE(arr.front() == -50);
}

TEST_CASE(".back()")
{
	FixedArray<int, 5> arr{404, 4141, -737, 6452, 0};

	REQUIRE(arr.back() == 0);
}

TEST_CASE(".size()")
{
	FixedArray<int, 5> arr;

	REQUIRE(arr.size() == 5);

	SECTION("Size does not change when using .insert()")
	{
		arr.insert(32, 0);

		REQUIRE(arr.size() == 5);
	}

	SECTION("Size does not change when using [] overload")
	{
		arr[3] = 20;

		REQUIRE(arr.size() == 5);
	}
}