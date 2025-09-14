#pragma once
#include <iostream>

class MyString
{
private:
    char* data;
    int length;

public:
    MyString(const char* str = "");
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    ~MyString();
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;
    int getLength() const;
    const char* getData() const;
    MyString operator+(const MyString& other) const;
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator>=(const MyString& other) const;
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);
    char& operator[](int index);
    char operator[](int index) const;
    int find(const char* subStr) const;
    void erase(int position, int count);
    void replace(int position, int count, const MyString& str);
    MyString substr(int start, int end) const;
    bool empty() const;
    void insert(int position, const MyString& str);
};