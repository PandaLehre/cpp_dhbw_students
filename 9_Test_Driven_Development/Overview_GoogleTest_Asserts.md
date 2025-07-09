# Googletest Asserts Overview

This document provides an overview of the various asserts available in GoogleTest, a popular C++ testing framework.

# GoogleTest Asserts Overview

GoogleTest provides a rich set of assertions to facilitate writing tests. These assertions can be categorized into several types based on their functionality.

## Basic Assertions

- `ASSERT_TRUE(condition)`: Fails the test if the condition is false.
- `ASSERT_FALSE(condition)`: Fails the test if the condition is true.
- `ASSERT_EQ(expected, actual)`: Fails the test if `expected` is not equal to `actual`.
- `ASSERT_NE(val1, val2)`: Fails the test if `val1` is equal to `val2`.
- `ASSERT_LT(val1, val2)`: Fails the test if `val1` is not less than `val2`.
- `ASSERT_LE(val1, val2)`: Fails the test if `val1` is not less than or equal to `val2`.
- `ASSERT_GT(val1, val2)`: Fails the test if `val1` is not greater than `val2`.
- `ASSERT_GE(val1, val2)`: Fails the test if `val1` is not greater than or equal to `val2`.
## String Assertions
- `ASSERT_STREQ(expected, actual)`: Fails the test if the C-style strings `expected` and `actual` are not equal.
- `ASSERT_STRNE(str1, str2)`: Fails the test if the C-style strings `str1` and `str2` are equal.
- `ASSERT_STRCASEEQ(expected, actual)`: Fails the test if the C-style strings `expected` and `actual` are not equal, ignoring case.
- `ASSERT_STRCASENE(str1, str2)`: Fails the test if the C-style strings `str1` and `str2` are equal, ignoring case.
## Pointer Assertions
- `ASSERT_NULL(pointer)`: Fails the test if `pointer` is not null.
- `ASSERT_NOTNULL(pointer)`: Fails the test if `pointer` is null.   
- `ASSERT_EQ(expected, actual)`: Can also be used for pointer comparisons.
## Floating Point Assertions
- `ASSERT_FLOAT_EQ(expected, actual)`: Fails the test if the two floating-point numbers are not equal within a small margin of error.
- `ASSERT_DOUBLE_EQ(expected, actual)`: Similar to `ASSERT_FLOAT_EQ`, but for double precision floating-point numbers.
- `ASSERT_NEAR(val1, val2, abs_error)`: Fails the test if `val1` and `val2` are not within `abs_error` of each other.

## Expectations

Similar to assertions, but they do not abort the test immediately. Instead, they log the failure and continue executing the test. 
Use `EXPECT_*` instead of `ASSERT_*` for these cases.

Best Practices:
- Use `ASSERT_*` when the failure should stop the test immediately.
- Use `EXPECT_*` when you want to log the failure but continue testing.