// Lab_6.2.2.cpp
// < Кобрин Василь >
// Лабараторна робота № 6.2.2
// Опрацювання одновимірних масивів ітераційними та рекурсивними способами
// Варіант 3

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i);
void Print(int* a, const int size, int i);
void Calc(int* a, const int size, int& r, int i);

int main()
{
	srand((unsigned)time(NULL));
	const int n = 10;
	int a[n];

	int Low = -10;
	int High = 10;
	int r = 0;

	Create(a, n, Low, High, 0);
	cout << "a = "; Print(a, n, 0);

	Calc(a, n, r, 0);
	cout << "number = " << setw(2) << r << endl;
}

void Create(int* a, const int size, const int Low, const int High, int i){
	a[i] = Low + rand() % (High - Low + 1);
	if (i<size-1)
		Create(a, size, Low, High, i+1);
}

void Print(int* a, const int size, int i)
{
	cout << setw(5) << a[i];
	if (i<size-1)
		Print(a, size, i+1);
	else
	cout << endl;
}

void Calc(int* a, const int size, int& r, int i){
	if(a[i]%2!=0)
		r++;
	if (i<size-1)
		return Calc(a, size, r, i+1);
}