#include "pch.h"
#include <vector>
#include "../student/average.cpp"
#include "../functions/functions.cpp"

TEST(CalculationTest, Average) {
	std::vector<int> v{ 0 };
	EXPECT_EQ(average(v), 0);

	std::vector<int> v1{ 8, 9, 2, 4, 3 };
	EXPECT_EQ(average(v1), 5.2);

	std::vector<int> v2{ };
	EXPECT_EQ(average(v2), 0);
}

TEST(CalculationTest, Median) {
	std::vector<int> v{ 0 };
	EXPECT_EQ(median(v), 0);

	std::vector<int> v1{ 8, 9, 2, 4, 3 };
	EXPECT_EQ(median(v1), 4);

	std::vector<int> v2{ 8, 9, 2, 4, 3, 10 };
	EXPECT_EQ(median(v2), 6);

	std::vector<int> v3{ };
	EXPECT_EQ(median(v3), 0);
}

TEST(ValueVerification, Grade) {
	EXPECT_TRUE(is_grade("0"));
	EXPECT_TRUE(is_grade("10"));
	EXPECT_TRUE(is_grade("5"));
	EXPECT_FALSE(is_grade("-1"));
	EXPECT_FALSE(is_grade("11"));
	EXPECT_FALSE(is_grade("a"));
	EXPECT_FALSE(is_grade("C"));
	EXPECT_FALSE(is_grade("2.6"));
}

TEST(ValueVerification, TwoItemSelection) {
	EXPECT_TRUE(check_select2("1"));
	EXPECT_TRUE(check_select2("2"));
	EXPECT_FALSE(check_select2("0"));
	EXPECT_FALSE(check_select2("3"));
	EXPECT_FALSE(check_select2("1.2"));
	EXPECT_FALSE(check_select2("."));
	EXPECT_FALSE(check_select2("ASD"));
}

TEST(ValueVerification, ThreeItemSelection) {
	EXPECT_TRUE(check_select3("1"));
	EXPECT_TRUE(check_select3("2"));
	EXPECT_TRUE(check_select3("3"));
	EXPECT_FALSE(check_select3("4"));
	EXPECT_FALSE(check_select3("0"));
	EXPECT_FALSE(check_select3("1.2"));
	EXPECT_FALSE(check_select3("."));
	EXPECT_FALSE(check_select3("ASD"));
}