#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* str)
{
	if (strlen(str) < 3)
		return 0;

	int j = 0;
	int l = 0;
	int k = 0;
	for (int i = 1; str[i + 1] != 0; i++) {
		l++;
		if (str[i] == ',') {
			k++;
			if (k == 3)
				j = l;
		}
	}
	return j;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "third coma: " << Count(str) << endl;
	return 0;
}