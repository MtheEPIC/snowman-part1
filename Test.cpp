#include "doctest.h"
#include "snowman.hpp"
#include <string>

using namespace ariel;
using namespace std;

TEST_CASE("Good snowman example")
{
    CHECK(snowman(11114411) == string(" _===_ \n (.,.) \n ( : ) \n ( : ) "));
}

TEST_CASE("Bad snowman length")
{
    CHECK_THROWS(snowman(111144114));
    CHECK_THROWS(snowman(1111441));
    CHECK_THROWS(snowman(NULL));
}

TEST_CASE("Bad snowman values")
{
    CHECK_THROWS(snowman(11104411));
    CHECK_THROWS(snowman(11154411));
    CHECK_THROWS(snowman(11114410));
    CHECK_THROWS(snowman(01114411));
    CHECK_THROWS(snowman(-11114411));
    CHECK_THROWS(snowman(11114411.2));
}

TEST_CASE("Bad snowman type")
{
    CHECK_THROWS(snowman(111.4411));
    CHECK_THROWS(snowman(11114411));
}