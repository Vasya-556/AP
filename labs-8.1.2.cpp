// Labs-8.1.1.cpp
// Кобрин Василь
// Лабораторна робота No 8.1.1
// Пошук та заміна символів у літерному рядку
// Варіант 3

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

char* Change(char* str)
{
	size_t len = strlen(str);
	if (len < 3)
		return str;
	char* tmp = new char[len * 4 / 3 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	size_t i = 0;


		while (i < len && str[i + 2] != 0)
		{
			if (str[i] == ',' )
			{
				strcat(t, "**");
				t += 2;
				i += 1;
			}
			else
			{
				*t++ = str[i++];
				*t = '\0';
			}
		}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy(str, tmp);
	return tmp;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (result): " << endl;
	cout << dest << endl;
	return 0;
}