// rectangle_test.cpp
#include <gtest/gtest.h>
#include "rectangle.h"

TEST(RectangleBasics, DefaultConstructor)
{
    Rectangle rect1;
    EXPECT_NO_THROW(rect1.getcoord());
}

TEST(RectangleBasics, NormalConstructorStandard)
{
    Rectangle rect1(10, 10, 50, 40);
    EXPECT_NO_THROW(rect1.getcoord());
}

TEST(RectangleBasics, NormalConstructorInvertedX)
{
    Rectangle rect1(50, 10, 10, 40);
    EXPECT_NO_THROW(rect1.getcoord());
}

TEST(RectangleBasics, NormalConstructorInvertedY)
{
    Rectangle rect1(10, 40, 50, 10);
    EXPECT_NO_THROW(rect1.getcoord());
}

TEST(RectangleTransform, DragMethod)
{
    Rectangle rect1(10, 10, 30, 30);
    EXPECT_NO_THROW(rect1.drag(5, -5));
}

TEST(RectangleTransform, ScaleOutMethod)
{
    Rectangle rect1(10, 10, 20, 20);
    EXPECT_NO_THROW(rect1.scaleout(2));
}

TEST(RectangleTransform, ScaleInMethodValid)
{
    Rectangle rect1(10, 10, 40, 40);
    EXPECT_NO_THROW(rect1.scalein(2));
}

TEST(RectangleTransform, ScaleInMethodZeroProtection)
{
    Rectangle rect1(10, 10, 40, 40);
    EXPECT_NO_THROW(rect1.scalein(0));
}

TEST(RectangleIncDec, PrefixIncrement)
{
    Rectangle rect1(10, 10, 20, 20);
    Rectangle rect2 = ++rect1;
    EXPECT_NO_THROW(rect2.getcoord());
}

TEST(RectangleIncDec, PostfixIncrement)
{
    Rectangle rect1(10, 10, 20, 20);
    Rectangle rect2 = rect1++;
    EXPECT_NO_THROW(rect2.getcoord());
}

TEST(RectangleIncDec, PrefixDecrement)
{
    Rectangle rect1(10, 10, 20, 20);
    Rectangle rect2 = --rect1;
    EXPECT_NO_THROW(rect2.getcoord());
}

TEST(RectangleIncDec, PostfixDecrement)
{
    Rectangle rect1(10, 10, 20, 20);
    Rectangle rect2 = rect1--;
    EXPECT_NO_THROW(rect2.getcoord());
}

TEST(RectangleAddition, StandardOperatorPlus)
{
    Rectangle rect1(0, 0, 10, 10);
    Rectangle rect2(5, 5, 15, 15);
    Rectangle rect3 = rect1 + rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleAddition, OperatorPlusAssignment)
{
    Rectangle rect1(0, 0, 10, 10);
    Rectangle rect2(5, 5, 15, 15);
    rect1 += rect2;
    EXPECT_NO_THROW(rect1.getcoord());
}

TEST(RectangleAddition, PlusWithCompletelyDisjoint)
{
    Rectangle rect1(0, 0, 5, 5);
    Rectangle rect2(20, 20, 25, 25);
    Rectangle rect3 = rect1 + rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleAddition, PlusWithOneInsideAnother)
{
    Rectangle rect1(0, 0, 20, 20);
    Rectangle rect2(5, 5, 10, 10);
    Rectangle rect3 = rect1 + rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleAddition, PlusWithIdenticalRectangles)
{
    Rectangle rect1(0, 0, 10, 10);
    Rectangle rect2(0, 0, 10, 10);
    Rectangle rect3 = rect1 + rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleAddition, PlusWithNegativeCoordinates)
{
    Rectangle rect1(-20, -20, -10, -10);
    Rectangle rect2(-15, -15, -5, -5);
    Rectangle rect3 = rect1 + rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleAddition, PlusChained)
{
    Rectangle rect1(0, 0, 5, 5);
    Rectangle rect2(2, 2, 7, 7);
    Rectangle rect3(10, 10, 12, 12);
    Rectangle rect4 = rect1 + rect2 + rect3;
    EXPECT_NO_THROW(rect4.getcoord());
}

TEST(RectangleSubtraction, StandardOperatorMinus)
{
    Rectangle rect1(0, 0, 10, 10);
    Rectangle rect2(5, 5, 15, 15);
    Rectangle rect3 = rect1 - rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleSubtraction, OperatorMinusAssignment)
{
    Rectangle rect1(0, 0, 10, 10);
    Rectangle rect2(5, 5, 15, 15);
    rect1 -= rect2;
    EXPECT_NO_THROW(rect1.getcoord());
}

TEST(RectangleSubtraction, MinusWithDisjointX)
{
    Rectangle rect1(0, 0, 5, 5);
    Rectangle rect2(10, 0, 15, 5);
    Rectangle rect3 = rect1 - rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleSubtraction, MinusWithDisjointY)
{
    Rectangle rect1(0, 0, 5, 5);
    Rectangle rect2(0, 10, 5, 15);
    Rectangle rect3 = rect1 - rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleSubtraction, MinusWithCompletelyDisjoint)
{
    Rectangle rect1(0, 0, 5, 5);
    Rectangle rect2(50, 50, 60, 60);
    Rectangle rect3 = rect1 - rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleSubtraction, MinusWithInternalRect)
{
    Rectangle rect1(0, 0, 30, 30);
    Rectangle rect2(10, 10, 20, 20);
    Rectangle rect3 = rect1 - rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleSubtraction, MinusWithIdenticalRectangles)
{
    Rectangle rect1(0, 0, 10, 10);
    Rectangle rect2(0, 0, 10, 10);
    Rectangle rect3 = rect1 - rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleSubtraction, MinusTouchByEdgeX)
{
    Rectangle rect1(0, 0, 10, 10);
    Rectangle rect2(10, 0, 20, 10);
    Rectangle rect3 = rect1 - rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleSubtraction, MinusTouchByEdgeY)
{
    Rectangle rect1(0, 0, 10, 10);
    Rectangle rect2(0, 10, 10, 20);
    Rectangle rect3 = rect1 - rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleSubtraction, MinusTouchByCorner)
{
    Rectangle rect1(0, 0, 10, 10);
    Rectangle rect2(10, 10, 20, 20);
    Rectangle rect3 = rect1 - rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleSubtraction, MinusWithNegativeCoordinates)
{
    Rectangle rect1(-20, -20, -10, -10);
    Rectangle rect2(-15, -15, -5, -5);
    Rectangle rect3 = rect1 - rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleSubtraction, MinusWithZeroRect)
{
    Rectangle rect1(0, 0, 10, 10);
    Rectangle rect2(0, 0, 0, 0);
    Rectangle rect3 = rect1 - rect2;
    EXPECT_NO_THROW(rect3.getcoord());
}

TEST(RectangleSubtraction, MinusChained)
{
    Rectangle rect1(0, 0, 20, 20);
    Rectangle rect2(5, 5, 25, 25);
    Rectangle rect3(10, 10, 30, 30);
    Rectangle rect4 = rect1 - rect2 - rect3;
    EXPECT_NO_THROW(rect4.getcoord());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
