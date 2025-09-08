#include "MyString.h"
#include <cstring> // Äëÿ strcpy_s, strcat_s

MyString::MyString(const char* str)
{
	if (str)
	{
		length = strlen(str);
		data = new char[length + 1];
		strcpy_s(data, length + 1, str);
	}
	else
	{
		length = 0;
		data = new char[1];
		data[0] = '\0';
	}
}
MyString::MyString(const MyString& other)
{
	length = other.length;
	data = new char[length + 1];
	strcpy_s(data, (length + 1), other.data);
}
MyString::MyString(MyString&& other) noexcept
{
	length = other.length;
	data = other.data;
	other.length = 0;
	other.data = new char[1];
	other.data[0] = '\0';
}
MyString::~MyString()
{
	delete[] data;
}
MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		delete[] data;
		length = other.length;
		data = new char[length + 1];
		strcpy_s(data, length + 1, other.data);
	}
	return *this;
}
MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		delete[] data;
		length = other.length;
		data = other.data;
		other.length = 0;
		other.data = new char[1];
		other.data[0] = '\0';
	}
	return *this;
}
int MyString::getLength() const
{
	return length;
}
const char* MyString::getData() const
{
	return data;
}
MyString MyString::operator+(const MyString& other) const
{
	MyString result;
	delete[] result.data;
	result.length = length + other.length;
	result.data = new char[result.length + 1];
	strcpy_s(result.data, length + 1, data);
	strcat_s(result.data, result.length + 1, other.data);
	return result;
}
bool MyString::operator==(const MyString& other) const
{
	return strcmp(data, other.data) == 0;
}
bool MyString::operator!=(const MyString& other) const
{
	return !(*this == other);
}
bool MyString::operator<(const MyString& other) const
{
	return strcmp(data, other.data) < 0;
}
bool MyString::operator<=(const MyString& other) const
{
	return strcmp(data, other.data) <= 0;
}
bool MyString::operator>(const MyString& other) const
{
	return strcmp(data, other.data) > 0;
}
bool MyString::operator>=(const MyString& other) const
{
	return strcmp(data, other.data) >= 0;
}
std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	os << str.data;
	return os;
}
std::istream& operator>>(std::istream& is, MyString& str)
{
	char buffer[1024];
	is >> buffer;
	str = MyString(buffer);
	return is;
}