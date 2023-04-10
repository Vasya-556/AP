// Labs-8.1.4.cpp
// Кобрин Василь
// Лабораторна робота No 8.1.4
// Пошук та заміна символів у літерному рядку
// Варіант 3

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

char* Change(char* dest, const char* str, char* t, int i)
{
	if (str[i ] != 0)
	{
		if (str[i] == ',')
		{
			strcat(t, "**");
			return Change(dest, str, t + 2, i + 1);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	char* dest1 = new char[151];
	dest1[0] = '\0';
	char* dest2;
	dest2 = Change(dest1, str, dest1, 0);
	cout << "Modified string (param) : " << dest1 << endl;
	return 0;
}