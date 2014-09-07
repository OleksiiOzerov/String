/*
 * MyString.h
 *
 *  Created on: Aug 12, 2014
 *      Author: ozerov
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_

#include <cstddef>
#include <iterator>
#include <initializer_list>

namespace Home
{

class String
{
public:

    class Iterator : public std::iterator<std::random_access_iterator_tag, char>
    {
        char* p;
    public:
        Iterator(char* x) :p(x) {}
        Iterator(const Iterator& it) : p(it.p) {}
        Iterator& operator++() {++p; return *this;}
        Iterator operator++(int) {Iterator tmp(*this); operator++(); return tmp;}
        Iterator& operator--() {--p; return *this;}
        Iterator operator--(int) {Iterator tmp(*this); operator--(); return tmp;}
        bool operator==(const Iterator& rhs) {return p == rhs.p;}
        bool operator!=(const Iterator& rhs) {return p != rhs.p;}
        char& operator*() {return *p;}
        const char& operator*() const {return *p;}
    };

    class reverseIterator : public Iterator
    {
    public:
        reverseIterator(char* x) :Iterator(x) {}
        reverseIterator(const reverseIterator& it) : Iterator((char*)(&(*it))){}
        Iterator& operator++() {Iterator::operator--(); return *this;}
        Iterator operator++(int) {reverseIterator tmp(*this); Iterator::operator--(); return tmp;}
        Iterator& operator--() {Iterator::operator++(); return *this;}
        Iterator operator--(int) {reverseIterator tmp(*this); operator++(); return tmp;}
        bool operator==(const reverseIterator& rhs) {return Iterator::operator*() == *rhs;}
        bool operator!=(const reverseIterator& rhs) {return Iterator::operator*() != *rhs;}
        char& operator*() {return Iterator::operator*();}
        const char& operator*() const {return Iterator::operator*();}

    };


    class constIterator : public std::iterator<std::random_access_iterator_tag, char>
    {
        const char* p;
    public:
        constIterator(char* x) :p(x) {}
        constIterator(const constIterator& it) : p(it.p) {}
        constIterator& operator++() {++p; return *this;}
        constIterator operator++(int) {constIterator tmp(*this); operator++(); return tmp;}
        constIterator& operator--() {--p; return *this;}
        constIterator operator--(int) {constIterator tmp(*this); operator--(); return tmp;}
        bool operator==(const constIterator& rhs) {return p==rhs.p;}
        bool operator!=(const constIterator& rhs) {return p!=rhs.p;}
        const char& operator*() {return *p;}
    };

public:

    static const size_t npos = static_cast<size_t>(-1);

    //Constructors
    String();

    String(const String &inputString);

    String(const String &inputString, size_t pos, size_t len = npos);

    String(const char* inputString);

    String(const char* s, size_t n);

    String(size_t n, char c);

    String(std::initializer_list<char> il);

    template <class InputIterator>
    String(InputIterator first, InputIterator last);

    String(String&& str) noexcept;

    virtual ~String();

    //Assign Operators
    String& operator=(const String& inputString);

    String& operator=(const char* inputString);

    String& operator=(char c);

    String& operator=(std::initializer_list<char> inputList);

    String& operator=(String&& str) noexcept;

    Iterator begin() noexcept
    {
        return Iterator(&mString[0]);
    }

    constIterator begin() const noexcept
    {
        return constIterator(&mString[0]);
    }

    Iterator end() noexcept
    {
        return Iterator(&mString[mLength]);
    }

    constIterator end() const noexcept
    {
        return constIterator(&mString[mLength]);
    }

    reverseIterator rbegin() noexcept
    {
        return reverseIterator(&mString[mLength - 1]);
    }

    //TODO
    //const_reverse_iterator rbegin() const noexcept;

    reverseIterator rend() noexcept
    {
        return reverseIterator(&mString[0 - 1]);
    }

    //TODO
    //const_reverse_iterator rend() const noexcept;

    //Element access
    char& operator[] (size_t pos)
    {
        return mString[pos];
    }

    const char& operator[] (size_t pos) const
    {
        return mString[pos];
    }

    char& at(size_t pos);

    const char& at(size_t pos) const;

    //Capacity
    size_t size() const noexcept
    {
        return mLength;
    }

    size_t length() const noexcept
    {
        return mLength;
    }

    size_t max_size() const noexcept
    {
        return (((npos - (sizeof(size_t) + sizeof(size_t) + sizeof(int)))/sizeof(char)) - 1) / 4 - 1;
    }

    void resize(size_t n);

    void resize(size_t newLength, char c);

    size_t capacity() const noexcept
    {
        return mCapacity;
    }

    void reserve(size_t newCapacity);

    void clear();

    bool empty() const
    {
        return mLength == 0;
    }

    //Modifiers
    String& operator+=(const String& str);

    String& operator+=(const char* s);

    String& operator+=(char c);

    String& operator+=(std::initializer_list<char> initList);

    String& append(const String& str)
    {
        return *this += str;
    }

    String& append(const String& str, size_t subpos, size_t sublen)
    {
        return *this += String(str, subpos, sublen);
    }

    String& append(const char* str)
    {
        return *this += str;
    }

    String& append(const char* str, size_t n)
    {
        return *this += String(str, n);
    }

    String& append(size_t n, char c)
    {
        return *this += String(n, c);
    }

    String& append(std::initializer_list<char> initList)
    {
        return *this += initList;
    }

/*    template <class InputIterator>
       string& append (InputIterator first, InputIterator last);

    */

    void push_back(char c)
    {
        *this += c;
    }

    String& assign(const String& str)
    {
        return *this = str;
    }

    String& assign(const String& str, size_t subpos, size_t sublen)
    {
        return *this = String(str, subpos, sublen);
    }

    String& assign(const char* str)
    {
        return *this = str;
    }

    String& assign(const char* s, size_t n)
    {
        return *this = String(s, n);
    }

    String& assign(size_t n, char c)
    {
        return *this = String(n, c);
    }

    String& assign (std::initializer_list<char> initList)
    {
        return *this = String(initList);

    }

    String& assign (String&& inputString) noexcept
    {
        return *this = std::move(inputString);
    }

    template <class InputIterator>
    String& assign (InputIterator first, InputIterator last)
    {
        return *this = String(first, last);;
    }

    String& insert(size_t pos, const String& str);

    String& insert(size_t pos, const String& str, size_t subpos, size_t sublen);

    String& insert(size_t pos, const char* s);

    String& insert(size_t pos, const char* s, size_t n);

    String& insert(size_t pos, size_t n, char c);

/*   iterator insert (const_iterator p, size_t n, char c);

   iterator insert (const_iterator p, char c);

   template <class InputIterator>
   iterator insert (iterator p, InputIterator first, InputIterator last);

   String& insert (const_iterator p, initializer_list<char> il);*/


/*    string& erase (size_t pos = 0, size_t len = npos);

   iterator erase (const_iterator p);

   iterator erase (const_iterator first, const_iterator last);


    string& replace (size_t pos,        size_t len,        const string& str);
    string& replace (const_iterator i1, const_iterator i2, const string& str);

    string& replace (size_t pos,        size_t len,        const string& str,
                     size_t subpos, size_t sublen);

    string& replace (size_t pos,        size_t len,        const char* s);
    string& replace (const_iterator i1, const_iterator i2, const char* s);

    string& replace (size_t pos,        size_t len,        const char* s, size_t n);
    string& replace (const_iterator i1, const_iterator i2, const char* s, size_t n);

    string& replace (size_t pos,        size_t len,        size_t n, char c);
    string& replace (const_iterator i1, const_iterator i2, size_t n, char c);

    template <class InputIterator>
      string& replace (const_iterator i1, const_iterator i2,
                       InputIterator first, InputIterator last);

    string& replace (const_iterator i1, const_iterator i2, initializer_list<char> il);
    */

    void swap(String& str);

    int compare(const String& str) const noexcept;

private:

    inline char* AllocateNewString(size_t capacity);

    inline void AllocateString(size_t length);

    inline void DeleteString();

    inline void CopyString(const char* inputString, size_t pos = 0);

    inline void CopyString(char c);

    inline void MoveString(String& inputString);

    char *mString;

    size_t mLength;

    size_t mCapacity;

    static const int allocationCoefficient = 2;
};

} /* namespace Home */

#endif /* MYSTRING_H_ */
