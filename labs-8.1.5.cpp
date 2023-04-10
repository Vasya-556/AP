#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* str)
{
	int k = 0, pos = 0, i=0, j = 0;
	char* t;
	for (int l = 0; str[i] != 0; l++)
		while (t = strchr(str + pos, ','))
		{
			i++;
			pos = t - str + 1;
			if (i == 3)
				j = pos;
		}
	return j;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "position ',' = " << Count(str) << endl;
	return 0;
}