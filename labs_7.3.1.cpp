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
void Input(int** matrix, const int rowCount, const int colCount);
void Print(int** matrix, const int rowCount, const int colCount);
int Part1(int** matrix, const int rowCount, const int colCount, int& sum);

int main() {
	srand((unsigned)time(NULL));
	int Low = 0;
	int High = 10;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** matrix = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		matrix[i] = new int[colCount];

	Create(matrix, rowCount, colCount, Low, High);
	Print(matrix, rowCount, colCount);

	int sum = 0;

	if (Part1(matrix, rowCount, colCount, sum))
		cout << "sum = " << sum << endl;
	else
		cout << "Nun" << endl;
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

int Part1(int** matrix, int rowCount, const int colCount, int& sum) {
	sum = 0;
	for (int j = 0; j < colCount; j++)
		for (int i = 0; i < rowCount; i++)
			if (matrix[i][j] == 0) {
				sum++;
				break;
			}
	return sum;
}