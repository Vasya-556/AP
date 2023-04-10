// Lab_6.3.2.cpp
// < Кобрин Василь >
// Лабараторна робота № 6.3.2
// Опрацювання одновимірних масивів ітераційними та рекурсивними способами
// Варіант 24

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i);
void Print(int* a, const int size, int i);
void Calc(int* a, const int size, int& max, int i);

int main()
{
	srand((unsigned)time(NULL));
	const int n = 10;
	int a[n];
	int max = -10;

	int Low = -10;
	int High = 10;
	int r = 0;

	Create(a, n, Low, High, 0);
	cout << "a = "; Print(a, n, 0);

	Calc(a, n, max, 0);
	cout << "max = " << max << endl;
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

void Calc(int* a, const int size, int& max, int i){
	if(a[i]%2==0){
			if(a[i]>max)
				max = a[i];
	}
	if (i<size-1)
		return Calc(a, size, max, i+1);
}