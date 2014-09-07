
#include "gtest/gtest.h"
#include "MyString.h"

#include <cstring>
#include <utility>

TEST(StringConstructorTest, NullaryConstructor)
{
    Home::String str;
    EXPECT_EQ(0, str.size());
    EXPECT_EQ(0, str.capacity());
    EXPECT_EQ(0, str.length());
    EXPECT_TRUE(str.empty());
}

TEST(StringConstructorTest, CopyConstructor)
{
    Home::String str1("Hello world");
    Home::String str2(str1);
    std::string str3("Hello world");

    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.capacity(), str2.capacity());
    EXPECT_EQ(str1.length(), str2.length());
    EXPECT_EQ(0, str1.compare(str2));

    for (size_t i = 0; i < str3.length(); ++i)
    {
        if (str2[i] != str3[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringConstructorTest, SubStringConstructor)
{
    Home::String str3("Hello world");
    Home::String str1("world");
    Home::String str2(str3, 6, 5);
    std::string st4("world");

    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());
    EXPECT_EQ(0, str1.compare(str2));

    for (size_t i = 0; i < st4.length(); ++i)
    {
        if (str2[i] != st4[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringConstructorTest, CStringConstructor)
{
    const char * str1 = "Hello world";
    Home::String str2(str1);

    for (size_t i = 0; i < 11; ++i)
    {
        EXPECT_TRUE(str1[i] == str2[i]);
    }
    EXPECT_EQ(str2.size(), 11);
}

TEST(StringConstructorTest, SubCStringConstructor)
{
    const char * str3 = "C++ programming language";
    Home::String str2(str3, 3);
    const char * str1 = "C++";

    for (size_t i = 0; i < 3u; ++i)
    {
        EXPECT_TRUE(str1[i] == str2[i]);
    }
}

TEST(StringConstructorTest, CharConstructor)
{
    Home::String str1(5, 'a');

    for (size_t i = 0; i < 5u; ++i)
    {
        EXPECT_TRUE(str1[i] == 'a');
    }
}

TEST(StringConstructorTest, InitializerList)
{
    Home::String str1{'H','e','l','l','o',' ','w','o','r','l','d'};
    Home::String str2("Hello world");
    std::string str3{'H','e','l','l','o',' ','w','o','r','l','d'};

    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.capacity(), str2.capacity());
    EXPECT_EQ(str1.length(), str2.length());
    EXPECT_EQ(0, str1.compare(str2));

    for (size_t i = 0; i < str3.length(); ++i)
    {
        if (str1[i] != str3[i])
        {
            ADD_FAILURE();
        }
    }
}

/*TEST(StringConstructorTest, RangeConstructor)
{
    Home::String str1{'H','e','l','l','o',' ','w','o','r','l','d'};
    Home::String str2(str1.begin(), str1.end());
    std::string str3{'H','e','l','l','o',' ','w','o','r','l','d'};
    std::string str4(str3.begin(), str3.end());

    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.capacity(), str2.capacity());
    EXPECT_EQ(str1.length(), str2.length());
    EXPECT_EQ(0, str1.compare(str2));

    for (size_t i = 0; i < str3.length(); ++i)
    {
        if (str1[i] != str3[i])
        {
            ADD_FAILURE();
        }
    }
}*/

TEST(StringConstructorTest, MoveConstructor)
{
    Home::String str4{'H','e','l','l','o',' ','w','o','r','l','d'};
    Home::String str1{'H','e','l','l','o',' ','w','o','r','l','d'};
    Home::String str2(std::move(str4));
    std::string str3{'H','e','l','l','o',' ','w','o','r','l','d'};

    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.capacity(), str2.capacity());
    EXPECT_EQ(str1.length(), str2.length());
    EXPECT_EQ(0, str1.compare(str2));

    EXPECT_TRUE(str4.empty());

    for (size_t i = 0; i < str3.length(); ++i)
    {
        if (str1[i] != str3[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringAssignOperatorTest, AssignStringOperator)
{
    Home::String str2("Hello world");
    Home::String str1("world");
    str1 = str2;

    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());
    EXPECT_EQ(0, str1.compare(str2));

    std::string str3("Hello world");
    for (size_t i = 0; i < str3.length(); ++i)
    {
        if (str1[i] != str3[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringAssignOperatorTest, AssignCStringOperator)
{
    Home::String str1("world");
    const char * str2 = "C++ programming language";
    str1 = str2;
    size_t length = strlen(str2);
    for (size_t i = 0; i < length; ++i)
    {
        EXPECT_TRUE(str1[i] == str2[i]);
    }
}

TEST(StringAssignOperatorTest, AssignCharOperator)
{
    Home::String str1("world");
    str1 = 'a';

    EXPECT_TRUE(str1[0] == 'a');
}

TEST(StringAssignOperatorTest, InitializerList)
{
    Home::String etalonString("Hello world");
    Home::String testString("test");

    testString = {'H','e','l','l','o',' ','w','o','r','l','d'};

    std::string realString("hi");

    realString = {'H','e','l','l','o',' ','w','o','r','l','d'};

    EXPECT_EQ(testString.size(), etalonString.size());
    EXPECT_EQ(testString.capacity(), testString.capacity());
    EXPECT_EQ(testString.length(), testString.length());
    EXPECT_EQ(0, testString.compare(etalonString));

    for (size_t i = 0; i < realString.length(); ++i)
    {
        if (testString[i] != realString[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringAssignOperatorTest, MoveSemantic)
{
    Home::String testString("test");
    Home::String tempString("Hello world");
    Home::String etalonString("Hello world");

    testString = std::move(tempString);

    std::string realString("hi");
    std::string tempString2("Hello world");

    realString = std::move(tempString2);

    EXPECT_EQ(testString.size(), etalonString.size());
    EXPECT_EQ(testString.capacity(), testString.capacity());
    EXPECT_EQ(testString.length(), testString.length());
    EXPECT_EQ(0, testString.compare(etalonString));

    for (size_t i = 0; i < realString.length(); ++i)
    {
        if (testString[i] != realString[i])
        {
            ADD_FAILURE();
        }
    }
}


TEST(StringIteratorTest, Begin)
{
    Home::String str1("Earth");
    Home::String::Iterator it = str1.begin();

    EXPECT_EQ(&str1[0], &*it);
    EXPECT_EQ('E', *it);
}

TEST(StringIteratorTest, BeginConst)
{
    Home::String str1("Earth");
    const Home::String & str2 = str1;
    Home::String::constIterator it = str2.begin();

    EXPECT_EQ(&str1[0], &*it);
    EXPECT_EQ('E', *it);
}

TEST(StringIteratorTest, End)
{
    Home::String str1("Earth");
    Home::String::Iterator it = str1.end();

    EXPECT_EQ(&str1[str1.length()], &*it);
    EXPECT_EQ('h', *(--it));
}

TEST(StringIteratorTest, EndConst)
{
    Home::String str1("Earth");
    const Home::String & str2 = str1;

    Home::String::constIterator it = str2.end();
    EXPECT_EQ(&str1[str1.length()], &*it);
    EXPECT_EQ('h', *(--it));
}

TEST(StringIteratorTest, RBegin)
{
    Home::String str1("Earth");
    Home::String::reverseIterator it = str1.rbegin();

    EXPECT_EQ(&str1[str1.length() - 1], &*it);
    EXPECT_EQ('h', *(it));
}

TEST(StringIteratorTest, REnd)
{
    Home::String str1("Earth");
    Home::String::reverseIterator it = str1.rend();

    EXPECT_EQ(&str1[0 - 1], &*it);
}

TEST(StringElementAccessTest, AcessOperator)
{
    Home::String str1("Earth");

    EXPECT_EQ(str1[0], 'E');
    EXPECT_EQ(str1[1], 'a');
    EXPECT_EQ(str1[2], 'r');
    EXPECT_EQ(str1[3], 't');
    EXPECT_EQ(str1[4], 'h');
}

TEST(StringElementAccessTest, ConstAcessOperator)
{
    const Home::String str1("Earth");

    EXPECT_EQ(str1[0], 'E');
    EXPECT_EQ(str1[1], 'a');
    EXPECT_EQ(str1[2], 'r');
    EXPECT_EQ(str1[3], 't');
    EXPECT_EQ(str1[4], 'h');
}

TEST(StringElementAccessTest, At)
{
    Home::String str1("Earth");

    EXPECT_EQ(str1.at(0), 'E');
    EXPECT_EQ(str1.at(1), 'a');
    EXPECT_EQ(str1.at(2), 'r');
    EXPECT_EQ(str1.at(3), 't');
    EXPECT_EQ(str1.at(4), 'h');

    ASSERT_THROW(str1.at(-1), std::out_of_range);
    ASSERT_THROW(str1.at(10), std::out_of_range);
}

TEST(StringElementAccessTest, ConstAt)
{
    const Home::String str1("Earth");

    EXPECT_EQ(str1.at(0), 'E');
    EXPECT_EQ(str1.at(1), 'a');
    EXPECT_EQ(str1.at(2), 'r');
    EXPECT_EQ(str1.at(3), 't');
    EXPECT_EQ(str1.at(4), 'h');

    ASSERT_THROW(str1.at(-1), std::out_of_range);
    ASSERT_THROW(str1.at(10), std::out_of_range);
}

TEST(StringCapacityTest, Size)
{
    Home::String str1("C++ programming language");

    EXPECT_EQ(str1.size(), strlen("C++ programming language"));
    EXPECT_EQ(str1.size(), 24);
    EXPECT_NE(str1.size(), 10);
}

TEST(StringCapacityTest, Length)
{
    Home::String str1("Dinamo Kiev");

    EXPECT_EQ(str1.length(), strlen("Dinamo Kiev"));
    EXPECT_EQ(str1.length(), 11);
    EXPECT_NE(str1.length(), 5);
}

TEST(StringCapacityTest, MaxSize)
{
    Home::String str1;
    std::string str2;

    EXPECT_EQ(str1.max_size(), str2.max_size());
}

TEST(StringCapacityTest, Npos)
{
    size_t i = Home::String::npos;

    EXPECT_EQ(i, std::string::npos);
}

TEST(StringCapacityTest, Resize)
{
    Home::String str1("Hello");
    std::string str2("Hello");

    str1.resize(10);
    str2.resize(10);

    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.capacity(), str2.capacity());
    EXPECT_EQ(str1.length(), str2.length());

    str1.resize(2);
    str2.resize(2);

    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.capacity(), str2.capacity());
    EXPECT_EQ(str1.length(), str2.length());
}

TEST(StringCapacityTest, Capacity)
{
    Home::String str1("Hello");

    EXPECT_EQ(10, str1.capacity());
}

TEST(StringCapacityTest, Reserve)
{
    Home::String str1("Hello");
    std::string str2("Hello");

    str1.reserve(10);
    str2.reserve(10);

    EXPECT_EQ(str1.capacity(), str2.capacity());

    str1.reserve(2);
    str2.reserve(2);

    EXPECT_EQ(str1.capacity(), str2.capacity());
}

TEST(StringCapacityTest, Clear)
{
    Home::String str1("Hello world");
    std::string str2("Hello world");

    str1.clear();
    str2.clear();

    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());
    EXPECT_EQ(str1.empty(), str2.empty());
}

TEST(StringCapacityTest, Empty)
{
    Home::String str1;
    std::string str2;

    EXPECT_EQ(str1.empty(), str2.empty());

    str1 = "fafsd";
    str2 = "fafsd";

    EXPECT_EQ(str1.empty(), str2.empty());
}

TEST(StringModifiersTest, StringAppendOperator)
{
    Home::String str1("Hello ");
    std::string str2("Hello ");

    Home::String str3("world");
    std::string str4("world");

    str1 += str3;
    str2 += str4;

    Home::String str5("Hello world");

    EXPECT_EQ(0, str1.compare(str5));
    EXPECT_EQ(str1.size(), str5.size());
    EXPECT_EQ(str1.length(), str5.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringModifiersTest, CStringAppendOperator)
{
    Home::String str1("Hello ");
    std::string str2("Hello ");

    str1 += "world";
    str2 += "world";

    Home::String str3("Hello world");

    EXPECT_EQ(0, str1.compare(str3));
    EXPECT_EQ(str1.size(), str3.size());
    EXPECT_EQ(str1.length(), str3.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringModifiersTest, CharAppendOperator)
{
    Home::String str1("Hello ");
    std::string str2("Hello ");

    str1 += 'w';
    str1 += 'o';
    str1 += 'r';
    str1 += 'l';
    str1 += 'd';

    str2 += "world";

    Home::String str3("Hello world");

    EXPECT_EQ(0, str1.compare(str3));
    EXPECT_EQ(str1.size(), str3.size());
    EXPECT_EQ(str1.length(), str3.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringModifiersTest, InitializerListAppendOperator)
{
    Home::String testString("Hello ");
    std::string realString("Hello ");

    testString += {'w', 'o', 'r', 'l', 'd'};
    realString += {'w', 'o', 'r', 'l', 'd'};

    Home::String etalonString("Hello world");

    EXPECT_EQ(0, testString.compare(etalonString));
    EXPECT_EQ(testString.size(), etalonString.size());
    EXPECT_EQ(testString.length(), etalonString.length());
    EXPECT_EQ(testString.size(), realString.size());
    EXPECT_EQ(testString.length(), realString.length());

    for (size_t i = 0; i < realString.length(); ++i)
    {
        if (testString[i] != realString[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringModifiersTest, StringAppendMetod)
{
    Home::String str1("Hello ");
    std::string str2("Hello ");

    Home::String str3("world");
    std::string str4("world");

    str1.append(str3);
    str2.append(str4);

    Home::String str5("Hello world");

    EXPECT_EQ(0, str1.compare(str5));
    EXPECT_EQ(str1.size(), str5.size());
    EXPECT_EQ(str1.length(), str5.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringModifiersTest, SubStringAppendMetod)
{
    Home::String str1("Hello ");
    std::string str2("Hello ");

    Home::String str3("world war");
    std::string str4("world war");

    str1.append(str3, 6, 3);
    str2.append(str4, 6, 3);

    Home::String str5("Hello war");

    EXPECT_EQ(0, str1.compare(str5));
    EXPECT_EQ(str1.size(), str5.size());
    EXPECT_EQ(str1.length(), str5.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringModifiersTest, CStringAppendMetod)
{
    Home::String str1("Hello ");
    std::string str2("Hello ");

    str1.append("world");
    str2.append("world");

    Home::String str3("Hello world");

    EXPECT_EQ(0, str1.compare(str3));
    EXPECT_EQ(str1.size(), str3.size());
    EXPECT_EQ(str1.length(), str3.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringModifiersTest, SubCStringAppendMetod)
{
    Home::String str1("Hello ");
    std::string str2("Hello ");

    const char* str4 = "world war";

    str1.append(str4, 5);
    str2.append(str4, 5);

    Home::String str3("Hello world");

    EXPECT_EQ(0, str1.compare(str3));
    EXPECT_EQ(str1.size(), str3.size());
    EXPECT_EQ(str1.length(), str3.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringModifiersTest, CharSequenceAppendMetod)
{
    Home::String str1("Hello ");
    std::string str2("Hello ");

    str1.append(5, 'w');

    str2.append(5, 'w');

    Home::String str3("Hello wwwww");

    EXPECT_EQ(0, str1.compare(str3));
    EXPECT_EQ(str1.size(), str3.size());
    EXPECT_EQ(str1.length(), str3.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringModifiersTest, PushBack)
{
    Home::String str1("World ");
    std::string str2("World ");

    str1.push_back('W');
    str1.push_back('a');
    str1.push_back('r');
    str1.push_back(' ');
    str1.push_back('I');
    str1.push_back('I');

    str2.push_back('W');
    str2.push_back('a');
    str2.push_back('r');
    str2.push_back(' ');
    str2.push_back('I');
    str2.push_back('I');

    Home::String str3("World War II");

    EXPECT_EQ(0, str1.compare(str3));
    EXPECT_EQ(str1.size(), str3.size());
    EXPECT_EQ(str1.length(), str3.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringAssignOperatorTest, AssignStringMetod)
{
    Home::String str1("world");
    Home::String str2("Hello world");
    str1.assign(str2);

    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());
    EXPECT_EQ(0, str1.compare(str2));

    std::string str3("Hello world");
    for (size_t i = 0; i < str3.length(); ++i)
    {
        if (str1[i] != str3[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringAssignOperatorTest, AssignSubStringMetod)
{
    Home::String str1("world");
    Home::String str2("my");
    Home::String str3("Hello my world");
    str1.assign(str3, 6, 2);

    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());
    EXPECT_EQ(0, str1.compare(str2));

    std::string str4("my");
    for (size_t i = 0; i < str4.length(); ++i)
    {
        if (str1[i] != str4[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringAssignOperatorTest, AssignCStringMetod)
{
    Home::String str1("world");
    const char * str2 = "C++ programming language";
    str1.assign(str2);
    size_t length = strlen(str2);
    for (size_t i = 0; i < length; ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringAssignOperatorTest, AssignSubCStringMetod)
{
    Home::String str1("world");
    const char * str2 = "C++ programming language";
    const char * str3 = "C++ programming";
    str1.assign(str2, 15);
    size_t length = strlen(str3);
    for (size_t i = 0; i < length; ++i)
    {
        if (str1[i] != str3[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringAssignOperatorTest, AssignCharSequenceMetod)
{
    Home::String str1("world");
    str1.assign(5, 'a');
    EXPECT_EQ(str1[0], 'a');
    EXPECT_EQ(str1[1], 'a');
    EXPECT_EQ(str1[2], 'a');
    EXPECT_EQ(str1[3], 'a');
    EXPECT_EQ(str1[4], 'a');
}

TEST(StringModifiersTest, StringInsert)
{
    Home::String str1("Hello ! Today is good day.");
    std::string str2("Hello ! Today is good day.");

    Home::String str3("world");
    std::string str4("world");

    str1.insert(6, str3);
    str2.insert(6, str4);

    Home::String str5("Hello world! Today is good day.");

    EXPECT_EQ(0, str1.compare(str5));
    EXPECT_EQ(str1.size(), str5.size());
    EXPECT_EQ(str1.length(), str5.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringModifiersTest, SubStringInsert)
{
    Home::String str1("Hello world! Today good day.");
    std::string str2("Hello world! Today good day.");

    Home::String str3("world is great");
    std::string str4("world is great");

    str1.insert(19, str3, 6, 3);
    str2.insert(19, str4, 6, 3);

    Home::String str5("Hello world! Today is good day.");

    EXPECT_EQ(0, str1.compare(str5));
    EXPECT_EQ(str1.size(), str5.size());
    EXPECT_EQ(str1.length(), str5.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringModifiersTest, CStringInsert)
{
    Home::String str1("Hello ! Today is good day.");
    std::string str2("Hello ! Today is good day.");

    str1.insert(6, "world");
    str2.insert(6, "world");

    Home::String str5("Hello world! Today is good day.");

    EXPECT_EQ(0, str1.compare(str5));
    EXPECT_EQ(str1.size(), str5.size());
    EXPECT_EQ(str1.length(), str5.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringModifiersTest, SubCStringInsert)
{
    Home::String str1("Hello ! Today is good day.");
    std::string str2("Hello ! Today is good day.");

    const char* str3 = "world i mine";

    str1.insert(6, str3, 5);
    str2.insert(6, str3, 5);

    Home::String str5("Hello world! Today is good day.");

    EXPECT_EQ(0, str1.compare(str5));
    EXPECT_EQ(str1.size(), str5.size());
    EXPECT_EQ(str1.length(), str5.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}


TEST(StringModifiersTest, CharSequenceInsert)
{
    Home::String str1("Hello world! Today is  day.");
    std::string str2("Hello world! Today is  day.");

    str1.insert(22, 3, 'x');
    str2.insert(22, 3, 'x');

    Home::String str5("Hello world! Today is xxx day.");

    EXPECT_EQ(0, str1.compare(str5));
    EXPECT_EQ(str1.size(), str5.size());
    EXPECT_EQ(str1.length(), str5.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}

TEST(StringModifiersTest, Swap)
{
    Home::String str1("Hello world! Today good day.");
    std::string str2("Hello world! Today good day.");

    Home::String str3("world is great");
    std::string str4("world is great");

    str1.swap(str3);
    str2.swap(str4);

    Home::String str5("world is great");

    EXPECT_EQ(0, str1.compare(str5));
    EXPECT_EQ(str1.size(), str5.size());
    EXPECT_EQ(str1.length(), str5.length());
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ADD_FAILURE();
        }
    }
}


TEST(StringModifiersTest, Compare)
{
    Home::String str1("Hello world! Today good day.");

    Home::String str2("Hello world! Today good day.");

    int compare = str1.compare(str2);

    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1.length(), str2.length());

    for (size_t i = 0; i < str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            if (compare == 0)
            {
                ADD_FAILURE();
            }
        }
    }
}

