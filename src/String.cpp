/*
 * String.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: ozerov
 */

#include "MyString.h"

#include <stdexcept>
#include <cstring>

//#include <iostream>

namespace Home
{

String::String() : mString(NULL), mLength(0), mCapacity(0)
{
}

String::String(const String &inputString) : mLength(inputString.mLength), mCapacity(inputString.mCapacity)
{
    mString = new char[mCapacity];

    for (size_t i = 0; i < mLength; ++i)
    {
        mString[i] = inputString.mString[i];
    }
}

String::String(const String &inputString, size_t pos, size_t len)
{
    if (pos >= inputString.mLength )
    {
        throw(std::out_of_range("Home::String(inputString, pos, len) pos out_of_range"));
    }
    else if (len == 0u)
    {
        String();
        return;
    }

    if (len > inputString.mLength - pos)
    {
        len = inputString.mLength - pos;
    }

    mLength = len;
    mCapacity = String::allocationCoefficient * 2;

    mString = new char[mCapacity];

    for (size_t i = 0; i < mLength; ++i, ++pos)
    {
        mString[i] = inputString.mString[pos];
    }
}

String::String(const char* inputString)
{
    if (inputString == NULL || (mLength = strlen(inputString)) == 0)
    {
        String();
    }

    mCapacity = mLength * allocationCoefficient;

    mString = new char[mCapacity];

    for (size_t i = 0; i < mLength; ++i)
    {
        mString[i] = inputString[i];
    }
}

String::String(const char* inputString, size_t n)
{

    size_t inputStringLen = 0;
    if (inputString == NULL || (inputStringLen = strlen(inputString)) == 0)
    {
        //TODO::Throw exception?
        String();
        return;
    }
    if (n > inputStringLen || n == String::npos)
    {
        n = inputStringLen;
    }
    mLength = n;

    mCapacity = mLength * allocationCoefficient;

    mString = new char[mCapacity];

    for (size_t i = 0; i < mLength; ++i)
    {
        mString[i] = inputString[i];
    }
}

String::String(size_t n, char c) : mLength(n)
{
    mCapacity = mLength * allocationCoefficient;

    mString = new char[mCapacity];

    for (size_t i = 0; i < mLength; ++i)
    {
        mString[i] = c;
    }
}

String::String(std::initializer_list<char> il)
{
    mLength = il.size();

    mCapacity = mLength * allocationCoefficient;

    mString = new char[mCapacity];

    size_t i = 0;
    for(auto c : il)
    {
        mString[i] = c;
        ++i;
    }
}

/*template <class InputIterator>
String::String(InputIterator first, InputIterator last)
{
    if (first == last)
    {
        String();
        return;
    }

    size_t length = 0;
    for (auto it = first; first != last; it++)
    {
        ++length;
    }
}*/

String& String::operator=(const String& inputString)
{
    if (mCapacity != 0)
    {
        delete [] mString;
    }

    mLength = inputString.mLength;
    mCapacity = inputString.mCapacity;

    mString = new char[mCapacity];

    for (size_t i = 0; i < mLength; ++i)
    {
        mString[i] = inputString.mString[i];
    }

    return *this;
}

String& String::operator=(const char* inputString)
{
    if (inputString == NULL || (mLength = strlen(inputString)) == 0)
    {
        //TODO::Throw exception?
        String();
    }

    if (mCapacity != 0)
    {
        delete [] mString;
    }

    mCapacity = mLength * allocationCoefficient;

    mString = new char[mCapacity];

    for (size_t i = 0; i < mLength; ++i)
    {
        mString[i] = inputString[i];
    }

    return *this;
}

String& String::operator=(char c)
{
    if (mCapacity != 0)
    {
        delete [] mString;
    }

    mLength = 1;
    mCapacity = mLength * allocationCoefficient;

    mString = new char[mCapacity];

    mString[0] = c;
    return *this;
}

String::~String()
{
    delete [] mString;
}


char& String::at(size_t pos)
{
    if(pos < 0 || pos > mLength -1)
    {
        throw(std::out_of_range("out of range"));
    }
    else
    {
        return mString[pos];
    }
}

const char& String::at(size_t pos) const
{
    if(pos < 0 || pos > mLength -1)
    {
        throw(std::out_of_range("out of range"));
    }
    else
    {
        return mString[pos];
    }
}

void String::resize(size_t newLength)
{
/*    if (newLength <= mCapacity)
    {
        mLength = newLength;
    }
    else if (newLength > mCapacity && newLength < max_size())
    {
        size_t newCapacity = newLength * allocationCoefficient;
        char * newString = new char[newCapacity];
        for (size_t i = 0; i < mLength; ++i)
        {
            newString[i] = mString[i];
        }

        mLength = newLength;
        mCapacity = newCapacity;
        delete mString;
        mString = newString;
    }*/
    resize(newLength, '\0');

}

void String::resize(size_t newLength, char c)
{
    if (newLength < mLength)
    {
        mLength = newLength;
    }
    else if (newLength > mLength && newLength < max_size())
    {
        if (newLength <= mCapacity)
        {
            for (size_t i = mLength; i < newLength - mLength; ++i)
            {
                mString[i] = c;
            }
            mLength = newLength;
        }
        else
        {
            size_t newCapacity = newLength * allocationCoefficient;
            char * newString = new char[newCapacity];
            for (size_t i = 0; i < mLength; ++i)
            {
                newString[i] = mString[i];
            }
            for (size_t i = mLength; i < newLength; ++i)
            {
                newString[i] = c;
            }

            mLength = newLength;
            mCapacity = newCapacity;
            delete mString;
            mString = newString;
        }
    }
}

void String::reserve(size_t newCapacity)
{
    if (newCapacity > 0 && newCapacity < max_size())
    {
        if (newCapacity < mLength)
        {
            newCapacity = mLength;
        }

        char * newString = new char[newCapacity];
        for (size_t i = 0; i < mLength; ++i)
        {
            newString[i] = mString[i];
        }

        mCapacity = newCapacity;
        delete mString;
        mString = newString;
    }
}

void String::clear()
{
    if (mLength > 0)
    {
        mLength = 0;
    }
}

//Modifiers
String& String::operator+=(const String& str)
{
    unsigned long newLength = mLength + str.mLength;

    if (newLength > max_size())
    {
        return *this;
    }

    if (newLength <= mCapacity)
    {
        for (size_t i = mLength; i < newLength; ++i)
        {
            mString[i] = str.mString[i - mLength];
        }
        mLength = newLength;
        return *this;
    }
    else
    {
        size_t priviousLength = mLength;

        resize(newLength);

        for (size_t i = priviousLength; i < newLength; ++i)
        {
            mString[i] = str.mString[i - priviousLength];
        }

        return *this;
    }
}

String& String::operator+=(const char* str)
{
    size_t strLength = strlen(str);

    unsigned long newLength = mLength + strLength;

    if (newLength > max_size())
    {
        return *this;
    }

    if (newLength <= mCapacity)
    {
        for (size_t i = mLength; i < newLength; ++i)
        {
            mString[i] = str[i - mLength];
        }
        mLength = newLength;
    }
    else
    {
        size_t priviousLength = mLength;
        resize(newLength);

        for (size_t i = priviousLength; i < newLength; ++i)
        {
            mString[i] = str[i - priviousLength];
        }
    }
    return *this;
}



String& String::operator+=(char c)
{

    int i {};
    if (mLength + 1 <= mCapacity)
    {
        mString[mLength] = c;
        mLength++;
    }
    else
    {
        size_t priviousLength = mLength;
        resize(mLength + 1);

        mString[priviousLength] = c;
    }
    return *this;
}

String& String::insert(size_t pos, const String& str)
{
    if(pos >= mLength)
    {
        throw(std::out_of_range("pos > str.length()"));
    }

    size_t newLength = mLength + str.mLength;

    String endStringPart(*this, pos, mLength - pos);

    resize(newLength);

    for (size_t i = pos; i < str.mLength + pos; ++i)
    {
        mString[i] = str.mString[i - pos];
    }

    for (size_t i = str.mLength + pos; i < str.mLength + pos + endStringPart.mLength; ++i)
    {
        mString[i] = endStringPart.mString[i - pos - str.mLength];
    }

    return *this;
}

String& String::insert(size_t pos, const String& str, size_t subpos, size_t sublen)
{
    return insert(pos, String(str, subpos, sublen));
}

String& String::insert(size_t pos, const char* str)
{
    return insert(pos, String(str));
}

String& String::insert(size_t pos, const char* str, size_t n)
{
    return insert(pos, String(str, n));
}

String& String::insert(size_t pos, size_t n, char c)
{
    return insert(pos, String(n, c));
}

void String::swap(String& str)
{
    String tmp(str);
    str = *this;
    *this = tmp;
}

int String::compare(const String& str) const noexcept
{
    if (mLength == str.mLength)
    {
        if (mLength == 0)
        {
            return 0;
        }
        for (size_t i = 0; i < mLength; ++i)
        {
            if (mString[i] != str.mString[i])
            {
                if (mString[i] < str.mString[i])
                {
                    return -1;
                }
                else
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    else if(mLength > str.mLength)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
} /* namespace Home */
