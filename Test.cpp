#include "doctest.h"
#include "snowman.hpp"
#include <string.h>

using namespace ariel;
using namespace std;

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

TEST_CASE("Good snowman example")
{
    /*
    as stated on the site: (Notice that spaces are put on otherwise empty lines so the section shape is always correct.)
    */
    CHECK(snowman(11114411) == string("       \n _===_ \n (.,.) \n ( : ) \n ( : ) "));
}

TEST_CASE("Good snowman input length")
{
    CHECK_THROWS(snowman(111144114));
    CHECK_THROWS(snowman(1111441));
    //CHECK_THROWS(snowman(NULL));
}

TEST_CASE("Good snowman output length")
{
    CHECK(snowman(11114411).length() == 39);
}

TEST_CASE("Good snowman values")
{
    CHECK_THROWS(snowman(11104411));
    CHECK_THROWS(snowman(11154411));
    CHECK_THROWS(snowman(11114410));
    CHECK_THROWS(snowman(01114411));
    CHECK_THROWS(snowman(-11114411));
}

TEST_CASE("Good snowman hat")
{
    CHECK(snowman(11114411).substr(0, 16) == string("       \n _===_ \n"));
    CHECK(snowman(21114411).substr(0, 16) == string("  ___  \n ..... \n"));
    CHECK(snowman(31114411).substr(0, 16) == string("   _   \n  /_\\  \n"));
    CHECK(snowman(41114411).substr(0, 16) == string("  ___  \n (_*_) \n"));
}

TEST_CASE("Good snowman nose")
{
    CHECK(snowman(11114411)[19] == ',');
    CHECK(snowman(12114411)[19] == '.');
    CHECK(snowman(13114411)[19] == '_');
    CHECK(snowman(14114411)[19] == ' ');
}

TEST_CASE("Good snowman left eye")
{
    CHECK(snowman(11114411)[18] == '.');
    CHECK(snowman(11214411)[18] == 'o');
    CHECK(snowman(11314411)[18] == 'O');
    CHECK(snowman(11414411)[18] == '-');
}

TEST_CASE("Good snowman right eye")
{
    CHECK(snowman(11114411)[20] == '.');
    CHECK(snowman(11124411)[20] == 'o');
    CHECK(snowman(11134411)[20] == 'O');
    CHECK(snowman(11144411)[20] == '-');
}

TEST_CASE("Good snowman left arm")
{
    CHECK((snowman(11111411)[16] == ' ' && snowman(11111411)[24] == '<'));
    CHECK((snowman(11112411)[16] == '\\' && snowman(11112411)[24] == ' '));
    CHECK((snowman(11113411)[16] == ' ' && snowman(11113411)[24] == '/'));
    CHECK((snowman(11114411)[16] == ' ' && snowman(11114411)[24] == ' '));
}

TEST_CASE("Good snowman right arm")
{
    CHECK((snowman(11114111)[22] == ' ' && snowman(11114111)[30] == '>'));
    CHECK((snowman(11114211)[22] == '/' && snowman(11114211)[30] == ' '));
    CHECK((snowman(11114311)[22] == ' ' && snowman(11114311)[30] == '\\'));
    CHECK((snowman(11114411)[22] == ' ' && snowman(11114411)[30] == ' '));
}

TEST_CASE("Good snowman torso")
{
    CHECK(snowman(11114411).substr(26, 3) == string(" : "));
    CHECK(snowman(11114421).substr(26, 3) == string("] ["));
    CHECK(snowman(11114431).substr(26, 3) == string("> <"));
    CHECK(snowman(11114441).substr(26, 3) == string("   "));
}

TEST_CASE("Good snowman base")
{
    CHECK(snowman(11114411).substr(34, 3) == string(" : "));
    CHECK(snowman(11114412).substr(34, 3) == string("\" \""));
    CHECK(snowman(11114413).substr(34, 3) == string("___"));
    CHECK(snowman(11114414).substr(34, 3) == string("   "));
}