// verylong_test.cpp
#include <gtest/gtest.h>
#include <sstream>
#include "verylong.h"

TEST(VeryLongBasics, DefaultConstructor)
{
    verylong vl1;
    EXPECT_EQ(static_cast<int>(vl1), 0);
}

TEST(VeryLongBasics, StringConstructorPositive)
{
    verylong vl1 = "150000";
    EXPECT_EQ(static_cast<int>(vl1), 150000);
}

TEST(VeryLongBasics, StringConstructorNegative)
{
    verylong vl1 = "-250000";
    EXPECT_EQ(static_cast<int>(vl1), -250000);
}

TEST(VeryLongBasics, StringConstructorZero)
{
    verylong vl1 = "0";
    EXPECT_EQ(static_cast<int>(vl1), 0);
}

TEST(VeryLongEquality, EqualityAndInequalityVeryLong)
{
    verylong vl1 = "500000";
    verylong vl2 = "500000";
    verylong vl3 = "-500000";
    verylong vl4 = "500001";

    EXPECT_TRUE(vl1 == vl2);
    EXPECT_FALSE(vl1 == vl3);
    EXPECT_FALSE(vl1 == vl4);
    EXPECT_TRUE(vl1 != vl3);
    EXPECT_TRUE(vl1 != vl4);
    EXPECT_FALSE(vl1 != vl2);
}

TEST(VeryLongEquality, EqualityAndInequalityInt)
{
    verylong vl1 = "25000";
    verylong vl2 = "-25000";

    EXPECT_TRUE(vl1 == 25000);
    EXPECT_FALSE(vl1 == 123);
    EXPECT_FALSE(vl2 == 25000);
    EXPECT_TRUE(vl1 != 123);
    EXPECT_TRUE(vl2 != 25000);
    EXPECT_FALSE(vl1 != 25000);
}

TEST(VeryLongStreams, StreamOutput)
{
    verylong vl1 = "1234567";
    verylong vl2 = "-99999";

    EXPECT_TRUE(cout << vl1);
    EXPECT_TRUE(cout << vl2);
}

TEST(VeryLongStreams, StreamInputPositive)
{
    std::stringstream ss("123456");
    verylong vl;
    ss >> vl;

    EXPECT_EQ(static_cast<int>(vl), 123456);
}

TEST(VeryLongStreams, StreamInputNegative)
{
    std::stringstream ss("-654321");
    verylong vl;
    ss >> vl;

    EXPECT_EQ(static_cast<int>(vl), -654321);
}

TEST(VeryLongStreams, StreamChaining)
{
    std::stringstream ss("100 -200");
    verylong vl1, vl2;
    ss >> vl1 >> vl2;

    EXPECT_EQ(static_cast<int>(vl1), 100);
    EXPECT_EQ(static_cast<int>(vl2), -200);
}

TEST(VeryLongComparison, GreaterThanVeryLong)
{
    verylong vl1 = "100000";
    verylong vl2 = "100005";
    EXPECT_TRUE(vl2 > vl1);
    EXPECT_FALSE(vl1 > vl2);
}

TEST(VeryLongComparison, GreaterOrEqualVeryLong)
{
    verylong vl1 = "300000";
    verylong vl2 = "300005";
    verylong vl3 = "300000";
    EXPECT_TRUE(vl2 >= vl1);
    EXPECT_TRUE(vl1 >= vl3);
}

TEST(VeryLongComparison, LessThanVeryLong)
{
    verylong vl1 = "-450000";
    verylong vl2 = "-400000";
    EXPECT_TRUE(vl1 < vl2);
    EXPECT_FALSE(vl2 < vl1);
}

TEST(VeryLongComparison, LessOrEqualVeryLong)
{
    verylong vl1 = "480000";
    verylong vl2 = "480005";
    verylong vl3 = "480000";
    EXPECT_TRUE(vl3 <= vl2);
    EXPECT_TRUE(vl1 <= vl3);
}

TEST(VeryLongComparison, EqualNumbers)
{
    verylong vl1 = "500000";
    verylong vl2 = "500000";
    EXPECT_TRUE(vl1 >= vl2);
    EXPECT_TRUE(vl1 <= vl2);
}

TEST(VeryLongComparison, SignComparisons)
{
    verylong vl1 = "-250000";
    verylong vl2 = "250000";
    EXPECT_FALSE(vl1 > vl2);
    EXPECT_TRUE(vl1 < vl2);
}

TEST(VeryLongIntComparison, GreaterThanInt)
{
    verylong vl1 = "15000";
    EXPECT_TRUE(vl1 > 14999);
    EXPECT_FALSE(vl1 > 15001);
}

TEST(VeryLongIntComparison, GreaterOrEqualInt)
{
    verylong vl1 = "25000";
    EXPECT_TRUE(vl1 >= 25000);
    EXPECT_TRUE(vl1 >= 20000);
}

TEST(VeryLongIntComparison, LessThanInt)
{
    verylong vl1 = "10000";
    EXPECT_TRUE(vl1 < 10001);
    EXPECT_FALSE(vl1 < 9999);
}

TEST(VeryLongIntComparison, LessOrEqualInt)
{
    verylong vl1 = "500";
    EXPECT_TRUE(vl1 <= 500);
    EXPECT_TRUE(vl1 <= 600);
}

TEST(VeryLongIntComparison, NegativeIntComparison)
{
    verylong vl1 = "-12000";
    EXPECT_TRUE(vl1 < -5000);
    EXPECT_TRUE(vl1 > -20000);
}

TEST(VeryLongArithmetic, AdditionVeryLong)
{
    verylong vl1 = "300000";
    verylong vl2 = "150000";
    verylong vl3 = "200000";
    vl3 += vl2;

    EXPECT_EQ(static_cast<int>(vl1 + vl2), 450000);
    EXPECT_EQ(static_cast<int>(vl3), 350000);
}

TEST(VeryLongArithmetic, SubtractionVeryLong)
{
    verylong vl1 = "400000";
    verylong vl2 = "350000";
    verylong vl3 = "110000";
    vl3 -= vl2;

    EXPECT_EQ(static_cast<int>(vl1 - vl2), 50000);
    EXPECT_EQ(static_cast<int>(vl3), -240000);
}

TEST(VeryLongArithmetic, MultiplicationVeryLong)
{
    verylong vl1 = "20000";
    verylong vl2 = "15";
    verylong vl3 = "10000";
    vl3 *= vl2;

    EXPECT_EQ(static_cast<int>(vl1 * vl2), 300000);
    EXPECT_EQ(static_cast<int>(vl3), 150000);
}

TEST(VeryLongArithmetic, DivisionVeryLong)
{
    verylong vl1 = "500000";
    verylong vl2 = "25000";
    verylong vl3 = "200000";
    vl3 /= vl2;

    EXPECT_EQ(static_cast<int>(vl1 / vl2), 20);
    EXPECT_EQ(static_cast<int>(vl3), 8);
}

TEST(VeryLongArithmetic, ArithmeticWithNegativeVeryLong)
{
    verylong vl1 = "-150000";
    verylong vl2 = "250000";

    EXPECT_EQ(static_cast<int>(vl1 + vl2), 100000);
    EXPECT_EQ(static_cast<int>(vl1 - vl2), -400000);
}

TEST(VeryLongArithmetic, ZeroArithmeticVeryLong)
{
    verylong vl1 = "350000";
    verylong vl2 = "0";
    EXPECT_EQ(static_cast<int>(vl1 * vl2), 0);
    EXPECT_EQ(static_cast<int>(vl1 + vl2), 350000);
}

TEST(VeryLongIntArithmetic, AdditionInt)
{
    verylong vl1 = "15000";
    EXPECT_EQ(static_cast<int>(vl1 + 5000), 20000);
    vl1 += 5000;
    EXPECT_EQ(static_cast<int>(vl1), 20000);
}

TEST(VeryLongIntArithmetic, SubtractionInt)
{
    verylong vl1 = "25000";
    EXPECT_EQ(static_cast<int>(vl1 - 15000), 10000);
    vl1 -= 15000;
    EXPECT_EQ(static_cast<int>(vl1), 10000);
}

TEST(VeryLongIntArithmetic, MultiplicationInt)
{
    verylong vl1 = "4000";
    EXPECT_EQ(static_cast<int>(vl1 * 5), 20000);
    vl1 *= 5;
    EXPECT_EQ(static_cast<int>(vl1), 20000);
}

TEST(VeryLongIntArithmetic, DivisionInt)
{
    verylong vl1 = "24000";
    verylong vl2 = vl1;
    EXPECT_EQ(vl1 / 60, 400);
    vl2 /= 800;
    EXPECT_EQ(static_cast<int>(vl2), 30);
}

TEST(VeryLongIncrementDecrement, PrefixIncrement)
{
    verylong vl1 = "12500";
    verylong vl2 = ++vl1;
    EXPECT_EQ(static_cast<int>(vl1), 12501);
    EXPECT_EQ(static_cast<int>(vl2), 12501);
}

TEST(VeryLongIncrementDecrement, PostfixIncrement)
{
    verylong vl1 = "24999";
    verylong vl2 = vl1++;
    EXPECT_EQ(static_cast<int>(vl1), 25000);
    EXPECT_EQ(static_cast<int>(vl2), 24999);
}

TEST(VeryLongIncrementDecrement, PrefixDecrement)
{
    verylong vl1 = "501";
    verylong vl2 = --vl1;
    EXPECT_EQ(static_cast<int>(vl1), 500);
    EXPECT_EQ(static_cast<int>(vl2), 500);
}

TEST(VeryLongIncrementDecrement, PostfixDecrement)
{
    verylong vl1 = "10000";
    verylong vl2 = vl1--;
    EXPECT_EQ(static_cast<int>(vl1), 9999);
    EXPECT_EQ(static_cast<int>(vl2), 10000);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
