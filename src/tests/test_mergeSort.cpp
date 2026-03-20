#include <catch2/catch_test_macros.hpp>
#include "../../include/sorting/mergeSort.h"

#include <limits>

TEST_CASE("Merge sort works for an integer vector", "[mergeSort]")
{
    std::vector<int> actual = { 60, -243, -475, -490, -101, 378, -127, -65, 31, -317 };
    std::vector<int> expected = { -490, -475, -317, -243, -127, -101, -65, 31, 60, 378 };

    mergeSort(actual, 0, actual.size() - 1);

    REQUIRE(actual.size() == 10);
    REQUIRE(actual == expected);
}

TEST_CASE("Merge sort works for a float vector", "[mergeSort]")
{
    std::vector<float> actual = { 6.0, -24.3, -47.5, -49.0, -10.1, 37.8, -12.7, -6.5, 3.1, -31.7 };
    std::vector<float> expected = { -49.0, -47.5, -31.7, -24.3, -12.7, -10.1, -6.5, 3.1, 6.0, 37.8 };

    mergeSort(actual, 0, actual.size() - 1);

    REQUIRE(actual.size() == 10);
    REQUIRE(actual == expected);
}

TEST_CASE("Merge sort works for an empty vector", "[mergeSort]")
{
    std::vector<float> actual = {};
    std::vector<float> expected = {};

    mergeSort(actual, 0, actual.size() - 1);

    REQUIRE(actual.size() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("Merge sort works for single element vector", "[mergeSort]")
{
    std::vector<float> actual = { 8.5 };
    std::vector<float> expected = { 8.5 };

    mergeSort(actual, 0, actual.size() - 1);

    REQUIRE(actual.size() == 1);
    REQUIRE(actual == expected);
}

TEST_CASE("Merge sort works for vector with minimum and maximum elements", "[mergeSort]")
{
    std::vector<float> actual = { std::numeric_limits<float>::max(), 0, std::numeric_limits<float>::lowest() };
    std::vector<float> expected = { std::numeric_limits<float>::lowest(), 0, std::numeric_limits<float>::max() };

    mergeSort(actual, 0, actual.size() - 1);

    REQUIRE(actual.size() == 3);
    REQUIRE(actual == expected);
}
