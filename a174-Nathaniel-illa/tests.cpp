#define CATCH_CONFIG_MAIN // defines main() automatically
#include "catch.hpp"
#include "SList.hpp"
// tests for exercise 1

TEST_CASE("Ex1 ", "[Test 1]")
{
	SList	slist;

	slist.addStudent(Students("Alice", 1, {100, 90, 80}));
	slist.addStudent(Students("Bob", 2, {90, 80, 70}));
	slist.addStudent(Students("Charlie", 3, {80, 70, 60}));
	slist.addStudent(Students("David", 4, {70, 60, 50}));
	slist.addStudent(Students("Eve", 5, {90, 80, 90}));

	REQUIRE(slist.size() == 5);
	REQUIRE(slist[0].getName() == "David");
	REQUIRE(slist[1].getName() == "Charlie");
	REQUIRE(slist[2].getName() == "Bob");
	REQUIRE(slist[3].getName() == "Eve");
	REQUIRE(slist[4].getName() == "Alice");
}

TEST_CASE("Ex2 ", "[Delete Test 1]")
{
	SList	slist;

	slist.addStudent(Students("Alice", 1, {100, 90, 80}));
	slist.addStudent(Students("Bob", 2, {90, 80, 70}));
	slist.addStudent(Students("Charlie", 3, {80, 70, 60}));
	slist.addStudent(Students("David", 4, {70, 60, 50}));
	slist.addStudent(Students("Eve", 5, {90, 80, 90}));

	REQUIRE(slist.size() == 5);
	slist.deleteStudent(2);
	REQUIRE(slist.size() == 4);
	REQUIRE(slist[0].getName() == "David");
	REQUIRE(slist[1].getName() == "Charlie");
	REQUIRE(slist[2].getName() == "Eve");
	REQUIRE(slist[3].getName() == "Alice");
}
TEST_CASE("Ex3 ", "[Insert Head and Tail Test 1]")
{
	SList	slist;
	slist.addStudent(Students("Alice", 1, {100, 90, 80}));
	slist.addStudent(Students("Bob", 2, {100, 100, 100}));
	REQUIRE(slist.size() == 2);
	REQUIRE(slist[0].getName() == "Alice");
	REQUIRE(slist[1].getName() == "Bob");
	slist.addStudent(Students("Charlie", 3, {0, 0, 0}));
	REQUIRE(slist.size() == 3);
	REQUIRE(slist[0].getName() == "Charlie");
	REQUIRE(slist[1].getName() == "Alice");
	REQUIRE(slist[2].getName() == "Bob");
}
