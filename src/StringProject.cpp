//============================================================================
// Name        : StringProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstring>
#include "MyString.h"
#include "gtest/gtest.h"



int main(int argc, char **argv)
{
/*    std::cout << "###############" << std::endl << std::endl;

    Home::String str1("Hello i am string 1");

    for (Home::String::Iterator it = str1.begin(); it != str1.end(); ++it)
    {
        std::cout << *it;
    }

    std::cout << std::endl << std::endl << "1###############1" << std::endl;

    str1.insert(6, Home::String("I"));


    for (Home::String::Iterator it = str1.begin(); it != str1.end(); ++it)
    {
        std::cout << *it;
    }

    std::cout << std::endl << std::endl << "2###############2" << std::endl;


    str1.insert(6, Home::String("I######################################################################"));


    for (Home::String::Iterator it = str1.begin(); it != str1.end(); ++it)
    {
        std::cout << *it;
    }

    std::cout << std::endl << std::endl << "3###############3" << std::endl;*/

    //std::cout <<  __cplusplus << std::endl;

/*    std::string str;

    std::string str2(str, 5, 5);

    std::cout << str2 << std::endl;*/

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
