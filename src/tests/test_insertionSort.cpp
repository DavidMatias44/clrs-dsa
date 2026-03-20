#include <catch2/catch_test_macros.hpp>
#include "../../include/sorting/insertionSort.h"

#include <limits>

TEST_CASE("Insertion sort works for an integer vector", "[insertionSort]")
{
    std::vector<int> actual = { 60, -243, -475, -490, -101, 378, -127, -65, 31, -317 };
    std::vector<int> expected = { -490, -475, -317, -243, -127, -101, -65, 31, 60, 378 };

    insertionSort(actual);

    REQUIRE(actual.size() == 10);
    REQUIRE(actual == expected);
}

TEST_CASE("Insertion sort works for a float vector", "[insertionSort]")
{
    std::vector<float> actual = { 6.0, -24.3, -47.5, -49.0, -10.1, 37.8, -12.7, -6.5, 3.1, -31.7 };
    std::vector<float> expected = { -49.0, -47.5, -31.7, -24.3, -12.7, -10.1, -6.5, 3.1, 6.0, 37.8 };

    insertionSort(actual);

    REQUIRE(actual.size() == 10);
    REQUIRE(actual == expected);
}

TEST_CASE("Insertion sort works for an empty vector", "[insertionSort]")
{
    std::vector<float> actual = {};
    std::vector<float> expected = {};

    insertionSort(actual);

    REQUIRE(actual.size() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("Insertion sort works for single element vector", "[insertionSort]")
{
    std::vector<float> actual = { 8.5 };
    std::vector<float> expected = { 8.5 };

    insertionSort(actual);

    REQUIRE(actual.size() == 1);
    REQUIRE(actual == expected);
}

TEST_CASE("Insertion sort works for vector with minimum and maximum elements", "[insertionSort]")
{
    std::vector<float> actual = { std::numeric_limits<float>::max(), 0, std::numeric_limits<float>::lowest() };
    std::vector<float> expected = { std::numeric_limits<float>::lowest(), 0, std::numeric_limits<float>::max() };

    insertionSort(actual);

    REQUIRE(actual.size() == 3);
    REQUIRE(actual == expected);
}
