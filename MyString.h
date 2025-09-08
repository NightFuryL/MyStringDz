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
};

