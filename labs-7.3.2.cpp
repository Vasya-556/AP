// Lab_7_3.cpp
// Кобрин Василь
// Лабораторна робота No 7.3.1
// Опрацювання динамічних багатовимірних масивів. Рекурсивний спосіб.
// Варіант 3

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** matrix, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** matrix, const int rowCount, const int colCount);
void Part2(int** matrix, const int rowCount, const int colCount, int& sum);

int main() {
	srand((unsigned)time(NULL));
	int Low = 0;
	int High = 3;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** matrix = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		matrix[i] = new int[colCount];

	Create(matrix, rowCount, colCount, Low, High);
	Print(matrix, rowCount, colCount);

	int sum = 0;

	Part2(matrix, rowCount, colCount, sum);
	cout << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}

void Create(int** matrix, const int rowCount, const int colCount, const int Low, const int High) {
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			matrix[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** matrix, const int rowCount, const int colCount) {
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << matrix[i][j];
		cout << endl;
	}
	cout << endl;
}

void Part2(int** matrix, int rowCount, const int colCount, int& sum) {
	int count;
	int n;
	count = matrix[0][0];
	for (int i = 0; i < rowCount; i++) {
		sum = 0;
		n = 1;
		for (int j = 0; j < colCount; j++)
			if (count == matrix[i][j])
				sum++;
			else {
				count = matrix[i][j];
				if (sum <= n)
					sum = n;
				else
					n = sum;
			}
			cout << "row = " << i << setw(9) << "sum = " << sum << endl;
	}
}