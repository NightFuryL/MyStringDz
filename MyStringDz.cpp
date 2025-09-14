#include <iostream>
#include "MyString.h"

using namespace std;

int main() {
    MyString str1("Hello");
    MyString str2("World");
    MyString str3("Hello");
    cout << "str1 == str2 ? " << (str1 == str2) << endl;
    cout << "str1 == str3 ? " << (str1 == str3) << endl;
    cout << "str1 != str2 ? " << (str1 != str2) << endl;
    MyString combined = str1 + MyString(" ") + str2;
    cout << "Combined: " << combined << endl;
    cout << "First letter of str1: " << str1[0] << endl;
    str1[0] = 'Y';
    cout << "Modified str1: " << str1 << endl;
    int pos = combined.find("World");
    cout << "Position of 'World' in combined: " << pos << endl;
    int pos2 = combined.find("XYZ");
    cout << "Position of 'XYZ' in combined: " << pos2 << endl;
    cout << "Before erase: " << combined << endl;
    combined.erase(5, 6); 
    cout << "After erase: " << combined << endl;
    MyString replaceStr("abcdefg");
    cout << "================================================================================================" << endl;
    cout << "Before replace: " << replaceStr << endl;
    replaceStr.replace(2, 3, MyString("XYZ"));
    cout << "After replace(2, 3, \"XYZ\"): " << replaceStr << endl;
    cout << "------------------------------------------------------" << endl;
    MyString subStr = replaceStr.substr(2, 5);
    cout << "substr(2, 5): " << subStr << endl;
    cout << "================================================================================================" << endl;
    MyString emptyStr("");
    cout << "emptyStr.empty()? " << (emptyStr.empty() ? "true" : "false") << endl;
    cout << "rep.empty()? " << (replaceStr.empty() ? "true" : "false") << endl;
    cout << "================================================================================================" << endl;
    MyString insertStr("12345");
	cout << "Before insert: " << insertStr << endl;
    insertStr.insert(2, MyString("ABC"));
    cout << "After insert(2, \"ABC\"): " << insertStr << endl;
	cout << "subStr: ABC" << endl;
    cout << "================================================================================================" << endl;

    return 0;
}