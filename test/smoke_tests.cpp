#include <gtest/gtest.h>
#include <vector>

// Include the header file containing the SearchAlgos::binarySearch function
#include "../include/search_algos.h"

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