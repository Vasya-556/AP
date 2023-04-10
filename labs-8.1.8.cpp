// Labs-8.1.8.cpp
// Кобрин Василь
// Лабораторна робота No 8.1.8
// Пошук та заміна символів у літерному рядку 
// Варіант 3
#include <iostream>
#include <string>
using namespace std;
string Change(string& s)
{
	size_t pos = 0;
	while ((pos = s.find(",", pos)) != -1)
	{
		s.replace(pos, 1, "*");
	}
	return s;
}
int main()
{
	string str;
	cout << "Enter string:" << endl;
	getline(cin, str);
	cout << "Modified string (param) : " << str << endl;
	string dest = Change(str);
	cout << "Modified string (result): " << dest << endl;
	return 0;
}