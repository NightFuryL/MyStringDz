#include "MyString.h"
#include <cstring>

MyString::MyString(const char* str)
{
    if (str)
    {
        this->length = strlen(str);
        this->data = new char[length + 1];
        strcpy_s(data, length + 1, str);
    }
    else
    {
        this->length = 0;
        this->data = new char[1];
        this->data[0] = '\0';
    }
}
MyString::MyString(const MyString& other)
{
    this->length = other.length;
    this->data = new char[length + 1];
    strcpy_s(data, (length + 1), other.data);
}
MyString::MyString(MyString&& other) noexcept
{
    this->length = other.length;
    this->data = other.data;
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
        this->length = other.length;
        this->data = new char[length + 1];
        strcpy_s(data, length + 1, other.data);
    }
    return *this;
}
MyString& MyString::operator=(MyString&& other) noexcept
{
    if (this != &other)
    {
        delete[] data;
        this->length = other.length;
        this->data = other.data;
        other.length = 0;
        other.data = new char[1];
        other.data[0] = '\0';
    }
    return *this;
}
int MyString::getLength() const
{
    return this->length;
}
const char* MyString::getData() const
{
    return this->data;
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
    return strcmp(this->data, other.data);
}
bool MyString::operator!=(const MyString& other) const
{
    return !(*this == other);
}
bool MyString::operator<(const MyString& other) const
{
    return strcmp(this->data, other.data) < 0;
}
bool MyString::operator<=(const MyString& other) const
{
    return strcmp(this->data, other.data) <= 0;
}
bool MyString::operator>(const MyString& other) const
{
    return strcmp(this->data, other.data) > 0;
}
bool MyString::operator>=(const MyString& other) const
{
    return strcmp(this->data, other.data) >= 0;
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
char& MyString::operator[](int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
char MyString::operator[](int index) const {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
int MyString::find(const char* subStr) const {
    if (!subStr || subStr[0] == '\0') return -1;
    int subLength = strlen(subStr);
    for (int i = 0; i <= length - subLength; i++) {
        int j = 0;
        while (j < subLength && data[i + j] == subStr[j]) {
            j++;
        }
        if (j == subLength) {
            return i;
        }
    }
    return -1;
}
void MyString::erase(int position, int count) {
    if (position < 0 || position >= length || count <= 0) return;
    if (position + count > length) {
        count = length - position;
    }
    for (int i = position; i + count <= length; i++) {
        data[i] = data[i + count];
    }
    this->length -= count;
}
void MyString::replace(int position, int count, const MyString& str) {
    if (position < 0 || position >= length || count < 0) return;
    if (position + count > length) count = length - position;
    int newLength = length - count + str.length;
    char* newData = new char[newLength + 1];
    strncpy_s(newData, newLength + 1, data, position);
    strcpy_s(newData + position, newLength + 1 - position, str.data); 
    strcpy_s(newData + position + str.length, newLength + 1 - position - str.length, data + position + count);
    delete[] data;
    data = newData;
    length = newLength;
}
MyString MyString::substr(int start, int end) const {
    if (start < 0 || end > length || start >= end) return MyString("");
    int subLength = end - start;
    char* subData = new char[subLength + 1];
	strncpy_s(subData, subLength + 1, data + start, subLength); // Ця функція також копіює рядок,але вона більш безпечна
    subData[subLength] = '\0';
    MyString result(subData);
    delete[] subData;
    return result;
}
bool MyString::empty() const {
    return length == 0;
}
void MyString::insert(int position, const MyString& str) {
    if (position < 0 || position > length) return;
    int newLength = length + str.length;
    char* newData = new char[newLength + 1];
    strncpy_s(newData, newLength + 1, data, position);
    strcpy_s(newData + position, newLength + 1 - position, str.data);
    strcpy_s(newData + position + str.length, newLength + 1 - position - str.length, data + position);
    delete[] data;
    data = newData;
    length = newLength;
}