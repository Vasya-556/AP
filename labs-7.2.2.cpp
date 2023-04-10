// Labs-7.2.2.cpp
// Кобрин Василь
// Лабораторна робота No 7.2.2
// Опрацювання багатовимірних масивів ітераційним і рекурсивним способами
// Варіант 3
#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int high, const int low, int rowNo);
void Create2(int** a, const int rowNo, const int colCount, const int high, const int low, int colNo);
void Show(int** a, const int rowCount, const int colCount, int rowNo);
void Show2(int** a, const int rowNo, const int colCount, int colNo);
void Calc(int** a, int& S, const int rowCount, const int colCount, int rowNo);
void Calc2(int** a, int& S, const int rowNo, const int colCount, int rowCount, int colNo, int& min);


int main()
{
	srand((unsigned)time(NULL));

	int high = 20;
	int low = 0;
	int S = 0;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;


	int** a = new  int* [rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		a[i] = new int[colCount];
	}

	Create(a, rowCount, colCount, high, low, 0);
	Show(a, rowCount, colCount, 0);
	Calc(a, S, rowCount, colCount, 1);

	cout << "S = " << S << endl;

	for (int i = 0; i < rowCount; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int high, const int low, int rowNo)
{
	Create2(a, rowNo, colCount, high, low, 0);
	if (rowNo < rowCount - 1)
	{
		Create(a, rowCount, colCount, high, low, rowNo + 1);
	}
	else
	{
		return;
	}
}

void Create2(int** a, const int rowNo, const int colCount, const int high, const int low, int colNo)
{
	a[rowNo][colNo] = low + rand() % (high - low + 1);
	if (colNo < colCount - 1)
	{
		Create2(a, rowNo, colCount, high, low, colNo + 1);
	}
	else
	{
		return;
	}
}

void Show(int** a, const int rowCount, const int colCount, int rowNo)
{
	Show2(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
	{
		Show(a, rowCount, colCount, rowNo + 1);
	}
	else
	{
		cout << endl;
	}

}

void Show2(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
	{
		Show2(a, rowNo, colCount, colNo + 1);
	}
	else
	{
		cout << endl;
	}

}


void Calc(int** a, int& S, const int rowCount, const int colCount, int rowNo)
{

	if (rowNo >= rowCount)
	{
		return;
	}
	int min = a[rowNo][0];
	Calc2(a, S, rowNo, colCount, rowCount, 0, min);
	if (rowNo < rowCount - 1)
	{
		Calc(a, S, rowCount, colCount, rowNo + 1);
	}
	else
	{
		return;
	}
}

void Calc2(int** a, int& S, const int rowNo, const int colCount, int rowCount, int colNo, int& min)
{
	if (a[rowNo][colNo] < min)
	{
		min = a[rowNo][colNo];
	}
	if (colNo == colCount - 1)
	{
		S += min;
	}
	if (colNo < colCount - 1)
	{
		Calc2(a, S, rowNo, colCount, rowCount, colNo + 1, min);
	}
	else
	{
		return;
	}
}