// Labs-8.1.3.cpp
// Кобрин Василь
// Лабораторна робота No 8.1.3
// Пошук та заміна символів у літерному рядку
// Варіант 3

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(char* str, int i, int l, int k)
{
	if (strlen(str) < 3)
		return 0;


	int j = 0;

	if (str[i + 1] != 0)
		if (str[i] == ',')
			if (k == 3)
				return l + Count(str, i + 1, l + 1, k+1);
		else
			return Count(str, i + 1, l + 1, k + 1);
		else
			return Count(str, i + 1, l+1, k);
	else
		return 0;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "third coma: " << Count(str, 1, 1, 1) << endl;
	return 0;
}