#include <iostream>
#include "MyString.h"

using namespace std;
//Òóò ìàéæå âåñü êîä äëÿ êëàñó ñòð³íã 
int main()
{
	MyString str1("Hello");
	MyString str2("World");
	MyString str3 = str1 + "," + str2 + MyString("!");
	cout << "str3: " << str3 << endl;
	cout << "Length of str3: " << str3.getLength() << endl;
	MyString str4;
	cout << "Enter a string: ";
	cin >> str4;
	cout << "You entered: " << str4 << endl;
	if (str1 < str2)
		cout << "\"" << str1 << "\" is less than \"" << str2 << "\"" << endl;
	else
		cout << "\"" << str1 << "\" is not less than \"" << str2 << "\"" << endl;
	MyString str5 = "C++";
	cout << str5 << endl;
	cout << "Length of str5: " << str5.getLength() << endl;
	cout << "Length of str4" << str4.getLength() << endl;
	return 0;
}

