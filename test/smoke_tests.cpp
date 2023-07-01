#include <gtest/gtest.h>
#include <vector>

#include "../include/search_algos.h"
#include "../include/sort_algos.h"

TEST(BinarySearchTest, EmptyArray) {
    SearchAlgos TestAlgos;
    std::vector<int> emptyArray;
    int target = 42;

    ASSERT_EQ(TestAlgos.binarySearch(emptyArray, target), -1);
}

TEST(BinarySearchTest, SingleElementArray_TargetFound) {
    SearchAlgos TestAlgos;
    std::vector<int> singleElementArray = {10};
    int target = 10;

    ASSERT_EQ(TestAlgos.binarySearch(singleElementArray, target), 0);
}

TEST(BinarySearchTest, SingleElementArray_TargetNotFound) {
    SearchAlgos TestAlgos;
    std::vector<int> singleElementArray = {10};
    int target = 5;

    ASSERT_EQ(TestAlgos.binarySearch(singleElementArray, target), -1);
}

TEST(BinarySearchTest, ArrayWithEvenElements_TargetFound) {
    SearchAlgos TestAlgos;
    std::vector<int> array = {1, 3, 5, 7};
    int target = 3;

    ASSERT_EQ(TestAlgos.binarySearch(array, target), 1);
}

TEST(BinarySearchTest, ArrayWithEvenElements_TargetNotFound) {
    SearchAlgos TestAlgos;
    std::vector<int> array = {1, 3, 5, 7};
    int target = 2;

    ASSERT_EQ(TestAlgos.binarySearch(array, target), -1);
}

TEST(BinarySearchTest, ArrayWithOddElements_TargetFound) {
    SearchAlgos TestAlgos;
    std::vector<int> array = {1, 3, 5, 7, 9};
    int target = 5;

    ASSERT_EQ(TestAlgos.binarySearch(array, target), 2);
}

TEST(BinarySearchTest, ArrayWithOddElements_TargetNotFound) {
    SearchAlgos TestAlgos;
    std::vector<int> array = {1, 3, 5, 7, 9};
    int target = 6;

    ASSERT_EQ(TestAlgos.binarySearch(array, target), -1);
}

TEST(BinarySearchTest, ArrayWithDuplicateElements_TargetFound) {
    SearchAlgos TestAlgos;
    std::vector<int> array = {1, 3, 5, 5, 7, 9};
    int target = 5;

    ASSERT_GE(TestAlgos.binarySearch(array, target), 2);
}

TEST(BinarySearchTest, ArrayWithDuplicateElements_TargetNotFound) {
    SearchAlgos TestAlgos;
    std::vector<int> array = {1, 3, 5, 5, 7, 9};
    int target = 6;

    ASSERT_EQ(TestAlgos.binarySearch(array, target), -1);
}

TEST(BinarySearchTest, ArrayWithTargetUpperBound_TargetFound) {
    SearchAlgos TestAlgos;
    std::vector<int> array = {1, 3, 5, 7, 9, 11, 23, 27, 32, 68};
    int target = 32;

    ASSERT_GE(TestAlgos.binarySearch(array, target), 8);
}

TEST(BinarySearchTest, ArrayWithTargetLowerBound_TargetFound) {
    SearchAlgos TestAlgos;
    std::vector<int> array = {1, 3, 5, 7, 9, 11, 23, 27, 32, 68};
    int target = 3;

    ASSERT_GE(TestAlgos.binarySearch(array, target), 1);
}

TEST(BinarySearchTest, ArraySearchMidPlusOneEven_TargetFound) {
    SearchAlgos TestAlgos;
    std::vector<int> array = {1, 3, 5, 7, 9, 11, 23, 27, 32, 68};
    int target = 7;

    ASSERT_GE(TestAlgos.binarySearch(array, target), 3);
}

TEST(BinarySearchTest, ArraySearchMidMinusOneEven_TargetFound) {
    SearchAlgos TestAlgos;
    std::vector<int> array = {1, 3, 5, 7, 9, 11, 23, 27, 32, 68};
    int target = 11;

    ASSERT_GE(TestAlgos.binarySearch(array, target), 5);
}

TEST(BinarySearchTest, ArraySearchMidPlusOneOdd_TargetFound) {
    SearchAlgos TestAlgos;
    std::vector<int> array = {1, 3, 5, 7, 9, 11, 23, 27, 32};
    int target = 7;

    ASSERT_GE(TestAlgos.binarySearch(array, target), 3);
}

TEST(BinarySearchTest, ArraySearchMidMinusOneOdd_TargetFound) {
    SearchAlgos TestAlgos;
    std::vector<int> array = {1, 3, 5, 7, 9, 11, 23, 27, 32};
    int target = 11;

    ASSERT_GE(TestAlgos.binarySearch(array, target), 5);
}

// 1. The vector is empty - Expected: -1
TEST(TernarySearchTest, EmptyVector) {
    SearchAlgos searchAlgos;
    std::vector<int> v;
    int target = 5;
    int result = searchAlgos.ternarySearch(v, target);
    EXPECT_EQ(-1, result);
}

// 2. The target is not present in the vector - Expected: -1
TEST(TernarySearchTest, TargetNotPresent) {
    SearchAlgos searchAlgos;
    std::vector<int> v = {1, 3, 5, 7, 9};
    int target = 6;
    int result = searchAlgos.ternarySearch(v, target);
    EXPECT_EQ(-1, result);
}

// 3. The target is the first element of the vector - Expected: 0
TEST(TernarySearchTest, TargetIsFirstElement) {
    SearchAlgos searchAlgos;
    std::vector<int> v = {5, 10, 15, 20, 25};
    int target = 5;
    int result = searchAlgos.ternarySearch(v, target);
    EXPECT_EQ(0, result);
}

// 4. The target is the last element of the vector - Expected: 4
TEST(TernarySearchTest, TargetIsLastElement) {
    SearchAlgos searchAlgos;
    std::vector<int> v = {5, 10, 15, 20, 25};
    int target = 25;
    int result = searchAlgos.ternarySearch(v, target);
    EXPECT_EQ(4, result);
}

// 5. The target is in the middle of the vector - Expected: 2
TEST(TernarySearchTest, TargetInMiddle) {
    SearchAlgos searchAlgos;
    std::vector<int> v = {5, 10, 15, 20, 25};
    int target = 15;
    int result = searchAlgos.ternarySearch(v, target);
    EXPECT_EQ(2, result);
}

// 6. The target is in the first third of the vector - Expected: 0
TEST(TernarySearchTest, TargetInFirstThird) {
    SearchAlgos searchAlgos;
    std::vector<int> v = {5, 10, 15, 20, 25};
    int target = 10;
    int result = searchAlgos.ternarySearch(v, target);
    EXPECT_EQ(1, result);
}

// 7. The target is in the last third of the vector - Expected: 4
TEST(TernarySearchTest, TargetInLastThird) {
    SearchAlgos searchAlgos;
    std::vector<int> v = {5, 10, 15, 20, 25};
    int target = 20;
    int result = searchAlgos.ternarySearch(v, target);
    EXPECT_EQ(3, result);
}

// Invalid partition - Test Case:

// 8. The vector is not sorted in ascending order - Expected: -1
TEST(TernarySearchTest, VectorNotSorted) {
    SearchAlgos searchAlgos;
    std::vector<int> v = {10, 5, 15, 20, 25};
    int target = 10;
    int result = searchAlgos.ternarySearch(v, target);
    EXPECT_EQ(-1, result);
}

// Additional Test Cases:

// Test an edge case with a vector containing a single element
TEST(TernarySearchTest, SingleElementVector) {
    SearchAlgos searchAlgos;
    std::vector<int> v = {5};
    int target = 5;
    int result = searchAlgos.ternarySearch(v, target);
    EXPECT_EQ(0, result);
}

// Test a large vector to check performance
TEST(TernarySearchTest, LargeVector) {
    SearchAlgos searchAlgos;
    std::vector<int> v;
    for (int i = 0; i < 1000000; ++i) {
        v.push_back(i);
    }
    int target = 999999;
    int result = searchAlgos.ternarySearch(v, target);
    EXPECT_EQ(999999, result);
}

// Test case for an empty vector
TEST(BubbleSortTest, EmptyVector) {
    SortAlgos sorter;
    std::vector<int> input;
    std::vector<int> expected;

    std::vector<int> result = sorter.bubbleSort(input);

    EXPECT_EQ(result, expected);
}

// Test case for a vector with one element
TEST(BubbleSortTest, SingleElementVector) {
    SortAlgos sorter;
    std::vector<int> input = {5};
    std::vector<int> expected = {5};

    std::vector<int> result = sorter.bubbleSort(input);

    EXPECT_EQ(result, expected);
}

// Test case for a vector with sorted elements
TEST(BubbleSortTest, SortedVector) {
    SortAlgos sorter;
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    std::vector<int> result = sorter.bubbleSort(input);

    EXPECT_EQ(result, expected);
}

// Test case for a vector with reverse sorted elements
TEST(BubbleSortTest, ReverseSortedVector) {
    SortAlgos sorter;
    std::vector<int> input = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    std::vector<int> result = sorter.bubbleSort(input);

    EXPECT_EQ(result, expected);
}

// Test case for a vector with duplicate elements
TEST(BubbleSortTest, VectorWithDuplicates) {
    SortAlgos sorter;
    std::vector<int> input = {3, 2, 1, 2, 3};
    std::vector<int> expected = {1, 2, 2, 3, 3};

    std::vector<int> result = sorter.bubbleSort(input);

    EXPECT_EQ(result, expected);
}

// Test case for a vector with negative elements
TEST(BubbleSortTest, VectorWithNegatives) {
    SortAlgos sorter;
    std::vector<int> input = {-5, -3, -1, -4, -2};
    std::vector<int> expected = {-5, -4, -3, -2, -1};

    std::vector<int> result = sorter.bubbleSort(input);

    EXPECT_EQ(result, expected);
}