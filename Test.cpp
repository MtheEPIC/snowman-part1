#include "doctest.h"
#include "snowman.hpp"
#include <string.h>

using namespace ariel;
using namespace std;

TEST_CASE("Good snowman example")
{
    CHECK(snowman(11114411) == string("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(snowman(11113411) == string(" _===_\n (.,.)\n/( : )\n ( : )"));
    CHECK(snowman(11114311) == string("_===_ \n(.,.) \n( : )\\\n( : ) "));
    CHECK(snowman(11113311) == string(" _===_ \n (.,.) \n/( : )\\\n ( : ) "));

    CHECK(snowman(41114411) == string(" ___ \n(_*_)\n(.,.)\n( : )\n( : )"));
    CHECK(snowman(41113411) == string("  ___ \n (_*_)\n (.,.)\n/( : )\n ( : )"));
    CHECK(snowman(41114311) == string(" ___  \n(_*_) \n(.,.) \n( : )\\\n( : ) "));
    CHECK(snowman(41113311) == string("  ___  \n (_*_) \n (.,.) \n/( : )\\\n ( : ) "));
}

TEST_CASE("Bad snowman input length")
{
    CHECK_THROWS(snowman(111144114));
    CHECK_THROWS(snowman(1111441));
    //CHECK_THROWS(snowman(NULL));
}

TEST_CASE("Good snowman output length")
{
    // small hat
    CHECK(snowman(11114411).length() == 24); // no arms
    CHECK(snowman(11113411).length() == 28); // one arm
    CHECK(snowman(11114311).length() == 28); // one arm
    CHECK(snowman(11113311).length() == 32); // two arm
    // big hat
    CHECK(snowman(21114411).length() == 30); // no arms
    CHECK(snowman(21113411).length() == 35); // one arm
    CHECK(snowman(21114311).length() == 35); // one arm
    CHECK(snowman(21113311).length() == 40); // two arm
}

TEST_CASE("Bad snowman values")
{
    CHECK_THROWS(snowman(11104411));
    CHECK_THROWS(snowman(11154411));
    CHECK_THROWS(snowman(11114410));
    CHECK_THROWS(snowman(01114411));
    CHECK_THROWS(snowman(-11114411));
}

TEST_CASE("Good snowman hat")
{
    CHECK(snowman(11114411).substr(0, 5) == string("_===_"));
    CHECK(snowman(21114411).substr(0, 11) == string(" ___ \n....."));
    CHECK(snowman(31114411).substr(0, 11) == string("  _   \n /_\\ "));
    CHECK(snowman(41114411).substr(0, 11) == string(" ___ \n(_*_)"));
}

TEST_CASE("Good snowman nose")
{
    // no hands
    CHECK(snowman(11114411)[15] == ',');
    CHECK(snowman(12114411)[15] == '.');
    CHECK(snowman(13114411)[15] == '_');
    CHECK(snowman(14114411)[15] == ' ');
    // left hand
    CHECK(snowman(11113411)[18] == ',');
    CHECK(snowman(12113411)[18] == '.');
    CHECK(snowman(13113411)[18] == '_');
    CHECK(snowman(14113411)[18] == ' ');
    // right hand
    CHECK(snowman(11113411)[17] == ',');
    CHECK(snowman(12113411)[17] == '.');
    CHECK(snowman(13113411)[17] == '_');
    CHECK(snowman(14113411)[17] == ' ');
    // two hands
    CHECK(snowman(11113411)[20] == ',');
    CHECK(snowman(12113411)[20] == '.');
    CHECK(snowman(13113411)[20] == '_');
    CHECK(snowman(14113411)[20] == ' ');
}

TEST_CASE("Good snowman left eye")
{
    // no hands
    CHECK(snowman(11114411)[14] == '.');
    CHECK(snowman(11214411)[14] == 'o');
    CHECK(snowman(11314411)[14] == 'O');
    CHECK(snowman(11414411)[14] == '-');
    // left hand
    CHECK(snowman(11113411)[17] == ',');
    CHECK(snowman(12113411)[17] == '.');
    CHECK(snowman(13113411)[17] == '_');
    CHECK(snowman(14113411)[17] == ' ');
    // right hand
    CHECK(snowman(11113411)[16] == ',');
    CHECK(snowman(12113411)[16] == '.');
    CHECK(snowman(13113411)[16] == '_');
    CHECK(snowman(14113411)[16] == ' ');
    // two hands
    CHECK(snowman(11113411)[19] == ',');
    CHECK(snowman(12113411)[19] == '.');
    CHECK(snowman(13113411)[19] == '_');
    CHECK(snowman(14113411)[19] == ' ');
}

TEST_CASE("Good snowman right eye")
{
    // no hands
    CHECK(snowman(11114411)[16] == '.');
    CHECK(snowman(11214411)[16] == 'o');
    CHECK(snowman(11314411)[16] == 'O');
    CHECK(snowman(11414411)[16] == '-');
    // left hand
    CHECK(snowman(11113411)[19] == ',');
    CHECK(snowman(12113411)[19] == '.');
    CHECK(snowman(13113411)[19] == '_');
    CHECK(snowman(14113411)[19] == ' ');
    // right hand
    CHECK(snowman(11113411)[18] == ',');
    CHECK(snowman(12113411)[18] == '.');
    CHECK(snowman(13113411)[18] == '_');
    CHECK(snowman(14113411)[18] == ' ');
    // two hands
    CHECK(snowman(11113411)[21] == ',');
    CHECK(snowman(12113411)[21] == '.');
    CHECK(snowman(13113411)[21] == '_');
    CHECK(snowman(14113411)[21] == ' ');
}

TEST_CASE("Good snowman left arm")
{
    CHECK((snowman(11111411)[12] == ' ' && snowman(11111411)[20] == '<' && snowman(11111411).length() == 28));
    CHECK((snowman(11112411)[12] == '\\' && snowman(11112411)[20] == ' ' && snowman(11112411).length() == 28));
    CHECK((snowman(11113411)[12] == ' ' && snowman(11113411)[20] == '/' && snowman(11113411).length() == 28));
    CHECK(snowman(11114411).length() == 24);

    CHECK((snowman(21111411)[14] == ' ' && snowman(21111411)[22] == '<' && snowman(21111411).length() == 35));
    CHECK((snowman(21112411)[14] == '\\' && snowman(21112411)[22] == ' ' && snowman(21112411).length() == 35));
    CHECK((snowman(21113411)[14] == ' ' && snowman(21113411)[22] == '/' && snowman(21113411).length() == 35));
    CHECK(snowman(21114411).length() == 30);
}

TEST_CASE("Good snowman right arm")
{
    CHECK((snowman(11114111)[18] == ' ' && snowman(11114111)[26] == '>' && snowman(11114111).length() == 28));
    CHECK((snowman(11114211)[18] == '/' && snowman(11114211)[26] == ' ' && snowman(11114211).length() == 28));
    CHECK((snowman(11114311)[18] == ' ' && snowman(11114311)[26] == '\\' && snowman(11114311).length() == 28));
    CHECK(snowman(11114411).length() == 24);

    CHECK((snowman(21114111)[20] == ' ' && snowman(21114111)[28] == '>' && snowman(21114111).length() == 35));
    CHECK((snowman(21114211)[20] == '/' && snowman(21114211)[28] == ' ' && snowman(21114211).length() == 35));
    CHECK((snowman(21114311)[20] == ' ' && snowman(21114311)[28] == '\\' && snowman(21114311).length() == 35));
    CHECK(snowman(21114411).length() == 30);
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
    CHECK(snowman(11114411).substr(19, 3) == string(" : "));
    CHECK(snowman(11114412).substr(19, 3) == string("\" \""));
    CHECK(snowman(11114413).substr(19, 3) == string("___"));
    CHECK(snowman(11114414).substr(19, 3) == string("   "));
}