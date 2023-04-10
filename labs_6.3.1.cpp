// Lab_6.3.1.cpp
// < Кобрин Василь >
// Лабараторна робота № 6.3.1
// Опрацювання одновимірних масивів ітераційними та рекурсивними способами
// Варіант 24

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);
void Calc(int* a, const int size, int& max);

int main()
{
	srand((unsigned)time(NULL));
	const int n = 10;
	int a[n];
	int max = 0;
	
	int Low = -10;
	int High = 10;

	Create(a, n, Low, High);
	cout << "a = "; Print(a, n);

	Calc(a, n, max);
	cout << "max = " << max << endl;

}

void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
    	a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}

void Calc(int* a, const int size, int& max){
	for (int i = 0; i < size; i++){
		if(a[i]%2==0){
			if(a[i]>max)
				max = a[i];
		}	
	}
}