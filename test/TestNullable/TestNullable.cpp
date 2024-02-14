#include "TestNullable.h"

#include <nullable/IStlNullableReference.hpp>
#include <nullable/IStlNullableType.hpp>
#include <iostream>
#include <optional>

struct Test {
	int x = 10;
	int y = 5;
};

static void TestNullableReference() {
	Test test{};

	IStl::NullableReference<Test> nullableRef{ IStl::null };
	IStl::NullableReference<Test> nullableRef2{ test };

	nullableRef2 = test;

	ISTL_ASSERT(nullableRef.IsNull(), "nullableRef should not have a value!");
	ISTL_ASSERT(!nullableRef2.IsNull(), "nullableRef2 should have a value!");
	ISTL_ASSERT(nullableRef2.GetValue().x == 10, "nullableRef2.GetValue().x should have a value of 10!");
	ISTL_ASSERT(nullableRef2.GetValue().y == 5, "nullableRef2.GetValue().y should have a value of 5!");

	ISTL_ASSERT(nullableRef2->x == 10, "nullableRef2->x should have a value of 10!");
	ISTL_ASSERT(nullableRef2->y == 5, "nullableRef2->y should have a value of 5!");

	ISTL_ASSERT((*nullableRef2).x == 10, "(*nullableRef2).x should have a value of 10!");
	ISTL_ASSERT((*nullableRef2).y == 5, "(*nullableRef2).y should have a value of 5!");

	std::clog << "IStl::NullableReference tests succeeded!" << std::endl;
}

static void TestNullableType() {
	IStl::Nullable<Test> nullableType{ IStl::null };
	IStl::Nullable<Test> nullableType2{ {} };

	nullableType2 = Test{};

	ISTL_ASSERT(nullableType.IsNull(), "nullableType should not have a value!");
	ISTL_ASSERT(!nullableType2.IsNull(), "nullableType2 should have a value!");
	ISTL_ASSERT(nullableType2.GetValue().x == 10, "nullableType2.GetValue().x should have a value of 10!");
	ISTL_ASSERT(nullableType2.GetValue().y == 5, "nullableType2.GetValue().y should have a value of 5!");

	ISTL_ASSERT(nullableType2->x == 10, "nullableType2->x should have a value of 10!");
	ISTL_ASSERT(nullableType2->y == 5, "nullableType2->y should have a value of 5!");

	ISTL_ASSERT((*nullableType2).x == 10, "(*nullableType2).x should have a value of 10!");
	ISTL_ASSERT((*nullableType2).y == 5, "(*nullableType2).y should have a value of 5!");

	std::clog << "IStl::Nullable tests succeeded!" << std::endl;
}

void TestNullable() {
	TestNullableReference();
	TestNullableType();
}
