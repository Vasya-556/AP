// Labs-10.1.cpp
// Кобрин Василь
// Лабораторна робота No 10.1
// Пошук символів у текстовому файлі
// Варіант 3
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include <string>

using namespace std;

int Count(char* fname)
{
	ifstream fin(fname);
	size_t pos = 0;
	int k = 0;
	char line[100];
	char* t;
	while (fin.getline(line, sizeof(line)))
	{
		while (t = strchr(line + pos, ','))
		{
			pos = t - line + 1;
				k++;
				if (k == 3)
				{
					return pos;
				}
		}
		pos = 0;
	}
	fin.close();
	
	return 0;
}

int main()
{
	char fname[] = "t.txt";
	cout << "third coma at posion " << Count(fname) <<  endl;
	return 0;
}