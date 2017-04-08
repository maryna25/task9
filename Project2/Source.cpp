#define CATCH_CONFIG_RUNNER 
#include "catch.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include "List.h"
#include "Lists.h"

TEST_CASE("List push_back()")
{
	List<int> l1;
	for (int i = 0; i < 5; i++)
		l1.pushBack(i);
	int el = 4;
	for (auto iter = l1.begin(); iter != l1.end(); ++iter)
	{
		REQUIRE(*iter == el);
		el--;
	}
}

TEST_CASE("List pop_back()")
{
	List<int> l1;
	for (int i = 0; i < 5; i++)
		l1.pushBack(i);
	l1.popBack();
	int el = 3;
	for (auto iter = l1.begin(); iter != l1.end(); ++iter)
	{
		REQUIRE(*iter == el);
		el--;
	}
}

TEST_CASE("Cyclic_List push_back()")
{
	CyclicList<int> l1{ 2, 1 };
	for (int i = 3; i < 8; i++)
		l1.pushBack(i);
	int value = 7;
	for (auto iter = l1.begin(); iter != l1.end(); ++iter)
	{
		REQUIRE(*iter == value);
		value--;
		if (value == 0)
		{
			REQUIRE(*(++iter) == 7);
			break;
		}
	}
}

TEST_CASE("Cyclic_List pop_back()")
{
	CyclicList<int> l1{ 2, 1 };
	for (int i = 3; i < 8; i++)
		l1.pushBack(i);
	l1.popBack();
	int value = 6;
	for (auto iter = l1.begin(); iter != l1.end(); ++iter)
	{
		REQUIRE(*iter == value);
		value--;
		if (value == 0)
		{
			REQUIRE(*(++iter) == 6);
			break;
		}
	}
}

TEST_CASE("Double_Sided_List push_back()")
{
	DoubleSidedList<int> l1;
	for (int i = 0; i < 5; i++)
		l1.pushBack(i);
	int el = 4;
	for (auto iter = l1.begin(); iter != l1.end(); ++iter)
	{
		REQUIRE(*iter == el);
		el--;
	}
}

TEST_CASE("Double_Sided_List pop_back()")
{
	DoubleSidedList<int> l1;
	for (int i = 0; i < 5; i++)
		l1.pushBack(i);
	l1.popBack();
	int el = 3;
	for (auto iter = l1.begin(); iter != l1.end(); ++iter)
	{
		REQUIRE(*iter == el);
		el--;
	}
}

TEST_CASE("Double_Sided_List push_front()")
{
	DoubleSidedList<int> l1;
	for (int i = 0; i < 5; i++)
		l1.pushFront(i);
	int el = 0;
	for (auto iter = l1.begin(); iter != l1.end(); ++iter)
	{
		REQUIRE(*iter == el);
		el++;
	}
}

TEST_CASE("Double_Sided_List pop_front()")
{
	DoubleSidedList<int> l1;
	for (int i = 0; i < 5; i++)
		l1.pushBack(i);
	l1.popFront();
	int el = 4;
	for (auto iter = l1.begin(); iter != l1.end(); ++iter)
	{
		REQUIRE(*iter == el);
		el--;
	}
}

TEST_CASE("Cyclic_Double_Sided_List push_back()")
{
	CyclicDoubleSidedList<int> l1{ 2, 1 };
	for (int i = 3; i < 8; i++)
		l1.pushBack(i);
	int value = 7;
	for (auto iter = l1.begin(); iter != l1.end(); ++iter)
	{
		REQUIRE(*iter == value);
		value--;
		if (value == 0)
		{
			REQUIRE(*(++iter) == 7);
			break;
		}
	}
}

TEST_CASE("Cyclic_Double_Sided_List pop_back()")
{
	CyclicDoubleSidedList<int> l1{ 2, 1 };
	for (int i = 3; i < 8; i++)
		l1.pushBack(i);
	l1.popBack();
	int value = 6;
	for (auto iter = l1.begin(); iter != l1.end(); ++iter)
	{
		REQUIRE(*iter == value);
		value--;
		if (value == 0)
		{
			REQUIRE(*(++iter) == 6);
			break;
		}
	}
}

TEST_CASE("Cyclic_Double_Sided_List push_front()")
{
	CyclicDoubleSidedList<int> l1{ 1, 2 };
	for (int i = 3; i < 8; i++)
		l1.pushFront(i);
	int value = 1;
	for (auto iter = l1.begin(); iter != l1.end(); ++iter)
	{
		REQUIRE(*iter == value);
		value++;
		if (value == 8)
		{
			REQUIRE(*(++iter) == 1);
			break;
		}
	}
}

TEST_CASE("Cyclic_Double_Sided_List pop_front()")
{
	CyclicDoubleSidedList<int> l1{ 2, 1 };
	for (int i = 3; i < 8; i++)
		l1.pushBack(i);
	l1.popFront();
	int value = 7;
	for (auto iter = l1.begin(); iter != l1.end(); ++iter)
	{
		REQUIRE(*iter == value);
		value--;
		if (value == 1)
		{
			REQUIRE(*(++iter) == 7);
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	int result = Catch::Session().run(argc, argv);
	getchar();
	return result;
}