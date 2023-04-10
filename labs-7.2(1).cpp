// Labs-7.2(1).cpp
// Кобрин Василь
// Лабораторна робота No 7.2.(1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 3

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** matrix, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** matrix, const int rowCount, const int colCount);
bool SearchSumMin(int** matrix, const int n, const int k, int& SumMin);

int main()
{
	srand((unsigned)time(NULL));
	int Low = 1;
	int High = 3;
	int n;
	int k;
	cout << "rowscount = "; cin >> n;
	cout << "collumcount = "; cin >> k;
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];

	Create(matrix, n, k, Low, High);
	Print(matrix, n, k);

	int SumMin;

	if (SearchSumMin(matrix, n, k, SumMin))
		cout << "SumMin = " << SumMin << endl;
	else
		cout << "None " << endl;
	cout << endl;

	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}

void Create(int** matrix, const int n, const int k, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j< k; j++)
			matrix[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** matrix, const int n, const int k)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			cout << setw(4) << matrix[i][j];
		cout << endl;
	}
	cout << endl;
}

bool SearchSumMin(int** matrix, const int n, const int k, int& SumMin)
{
	int min;
	SumMin = 0;
	for (int i = 0; i < n; i++) {
		min = matrix[i][0];
		for (int j = 0; j < k; j++)
			if (matrix[i][j] < min)
				min = matrix[i][j];
		SumMin += min;
	}
	return true;
}