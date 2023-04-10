// Labs-8.1.6.cpp
// Кобрин Василь
// Лабораторна робота No 8.1.6
// Пошук та заміна символів у літерному рядку 
// Варіант 3
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


char* Change(char* s)
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0, pos2 = 0;
	*t = 0;
	while (p = strstr(s + pos1, ","))
	{
		pos2 = p - s + 1;
		strncat(t, s + pos1, pos2 - pos1 - 1);
		strcat(t, "*");
		pos1 = pos2;
	}
	strcat(t, s + pos1);
	strcpy(s, t);
	return t;
}

int main()
{
	char s[101];
	cout << "Enter string:" << endl;
	cin.getline(s, 100);
	char* dest = new char[151];
	cout << "Modified string (param) : " << s << endl;
	dest = Change(s);
	cout << "Modified string (result): " << dest << endl;
	return 0;
}