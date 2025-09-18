#include "decimal.h"
#include <gtest/gtest.h>

TEST(DecimalConstructorTest, UnsignedIntConstructor) {
  Decimal d(123ull);
  EXPECT_TRUE(d == Decimal({1, 2, 3}));
}

TEST(DecimalConstructorTest, InitializerListConstructor) {
    Decimal d({9, 9, 9, 9});
    EXPECT_TRUE(d == Decimal(9999ull));
}

TEST(DecimalArithmeticTest, SubtractionNegativeResult) {
    Decimal d1(5ull);
    Decimal d2(10ull);
    Decimal res = d1 - d2;
    EXPECT_TRUE(res == Decimal(0ull));
}

TEST(DecimalArithmeticTest, SubtractionPositiveResult) {
    Decimal d1(10ull);
    Decimal d2(5ull);
    Decimal res = d1 - d2;
    EXPECT_TRUE(res == Decimal(5ull));
}

TEST(DecimalArithmeticTest, AdditionCheck) {
    Decimal d1(1000ull);
    Decimal d2(123ull);
    Decimal res = d1 + d2;
    EXPECT_TRUE(res == Decimal(1123ull));
}

TEST(DecimalComparisonTest, Comparisons) {
    Decimal zero(0ull);
    Decimal one(1ull);
    
    EXPECT_TRUE(zero == zero);
    EXPECT_TRUE(zero < one);
    EXPECT_TRUE(one > zero);
    EXPECT_TRUE(zero <= one);
    EXPECT_TRUE(one >= zero);
}