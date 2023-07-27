#include <catch2/catch_test_macros.hpp>
#include "../../../DataStructures/HashTable/HashTable.hpp"

TEST_CASE("HashTable {}")
{
	HashTable<std::string, int> ht{{ "Hello!", 3113 }, { "NOTHING", 0 }, { "embed", -431 }};

	CHECK(ht.contains("Hello!"));
	CHECK(ht.contains("NOTHING"));
	CHECK(ht.contains("embed"));
}

TEST_CASE("HashTable .insert()")
{
	HashTable<std::string, int> ht{};
	ht.insert({ "xyz", 2 });
	ht.insert({ "execute", 1515 });
	ht.insert({ "._|rand-", -421 });

	CHECK(ht.contains("xyz"));
	CHECK(ht.contains("execute"));
	CHECK(ht.contains("._|rand-"));
}

TEST_CASE("HashTable .remove()")
{
	HashTable<std::string, int> ht{{ "Server", 200 }, { "ERROR", 404 }, { "Ok", -32 }};
	ht.remove("Server");
	ht.remove("ERROR");
	ht.remove("Ok");

	CHECK_FALSE(ht.contains("Server"));
	CHECK_FALSE(ht.contains("ERROR"));
	CHECK_FALSE(ht.contains("Ok"));
}

TEST_CASE("HashTable .find()")
{
	HashTable<std::string, int> ht{{ "()", 0 }, { "duck", 21 }, { "PEPE", -11 }};

	REQUIRE(ht.find("()") == 0);
	REQUIRE(ht.find("duck") == 21);
	REQUIRE(ht.find("PEPE") == -11);
}

TEST_CASE("HashTable .empty()")
{
	HashTable<std::string, int> ht{};

	CHECK(ht.empty());

	ht.insert({ "Zebra", 444 });

	CHECK_FALSE(ht.empty());
}

TEST_CASE("HashTable .clear()")
{
	HashTable<std::string, int> ht{};

	ht.clear();

	CHECK(ht.empty());

	ht.insert({ "eee", 3 });
	ht.insert({ "9313ha", 9 });

	ht.clear();

	CHECK(ht.empty());
}

TEST_CASE("HashTable .size()")
{
	HashTable<std::string, int> ht{};

	REQUIRE(ht.size() == 0);

	ht.insert({ "X", 313 });
	ht.insert({ "X", 44 }); // overwritten previous value
	ht.insert({ "yyyuada", -311 });

	REQUIRE(ht.size() == 2);

	ht.clear();
	ht.remove("Oda");

	REQUIRE(ht.size() == 0);
}

TEST_CASE("HashTable .max_size()")
{
	SECTION("Default max_size")
	{
		HashTable<std::string, int> ht{};

		REQUIRE(ht.max_size() == 13);
	}

	HashTable<std::string, int> ht{{ "C", 1972 }, { "C++", 1985 }, { "C#", 2002 }};

	REQUIRE(ht.max_size() == 6);

	ht.insert({ "Rust", 2015 });
	ht.insert({ "COBOL", 1959 });
	ht.insert({ "Swift", 2014 });

	REQUIRE(ht.max_size() == 10);
}