#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** matrix, const int rowCount, const int colCount, int rowNo);
void Create2(int** matrix, const int rowNo, const int colCount, int colNo);
void Print(int** matrix, const int rowCount, const int colCount, int rowNo);
void Print2(int** matrix, const int rowNo, const int colCount, int colNo);
int Part1_CountCol(int** matrix, const int rowCount, int& count, int colNo, int rowNo);
int Part1_CountCols(int** matrix, const int rowCount, const int colCount, int& count, int colNo, int rowNo);
int Part1_Count(int** matrix, const int colCount, int colNo, int rowNo);

int main()
{
	srand((unsigned)time(NULL));
	int Low = 0;
	int High = 10;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** matrix = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		matrix[i] = new int[colCount];
	Create(matrix, rowCount, colCount, 0);
	Print(matrix, rowCount, colCount, 0);
	int count = 0;
	bool result = false;
	Part1_CountCols(matrix, rowCount, colCount, count, 0, 0);
	if (result)
		cout << "count = " << count << endl;
	else
		cout << "count = 0" << endl;
	cout << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] matrix[i];
	delete[] matrix;
	return 0;
}

void Create(int** matrix, const int rowCount, const int colCount, int rowNo)
{
	Create2(matrix, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
	{
		Create(matrix, rowCount, colCount, rowNo + 1);
	}
	else
	{
		cout << endl;
	}
}

void Create2(int** matrix, const int rowNo, const int colCount, int colNo)
{
	cout << "matrix[" << rowNo << "][" << colNo << "] = ";
	cin >> matrix[rowNo][colNo];
	if (colNo < colCount - 1)
	{
		Create2(matrix, rowNo, colCount, colNo + 1);
	}
	else
	{
		cout << endl;
	}
}

void Print(int** matrix, const int rowCount, const int colCount, int rowNo)
{
	Print2(matrix, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
	{
		Print(matrix, rowCount, colCount, rowNo + 1);
	}
	else
	{
		cout << endl;
	}

}

void Print2(int** matrix, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << matrix[rowNo][colNo];
	if (colNo < colCount - 1)
	{
		Print2(matrix, rowNo, colCount, colNo + 1);
	}
	else
	{
		cout << endl;
	}
}


int Part1_CountCol(int** matrix, const int rowCount, int& count, int colNo, int rowNo)
{
	count = 0;
	if (rowNo < rowCount - 1)
		return Part1_CountCols(matrix, rowCount, 0, count, 0, 0);
}

int Part1_CountCols(int** matrix, const int rowCount, const int colCount, int& count, int colNo, int rowNo)
{
	if (colNo < colCount - 1)
		if (matrix[colNo][rowNo] == 0) {
			Part1_CountCols(matrix, rowCount, colCount, count, colNo + 1, rowNo);
			count++;
		}
		else
			return Part1_CountCols(matrix, rowCount, colCount, count, colNo +1, rowNo);
	else
		return count;
}