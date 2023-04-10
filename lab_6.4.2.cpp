// Lab_6.4.2.cpp
// < Кобрин Василь >
// Лабараторна робота № 6.4.2
// Опрацювання та впорядкування одновимірних динамічних масивів
// Варіант 3


#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i);
void Print(int* a, const int size, int i);
void Calc(int* a, const int size, int& m, int& x, int i);
void Sort(int* a, const int size, int i);
void Min(int* a, const int size, int &y, int &iy, int j);

int main()
{
	srand((unsigned)time(NULL));
	int n;
	cout << "n = "; cin >> n;
	int a[n];
	
	int Low = -10;
	int High = 10;
	int m = 1;
	int x = 0;
	
	Create(a, n, Low, High, 0);
	cout << "a = "; Print(a, n, 0);
	
	Calc(a, n, m, x, 0);
	cout << "dob = " << m << endl;
	cout << "sum = " << x << endl;
	
	Sort(a, n, 0);
	cout << "a1 = "; Print(a, n, 0);
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

void Calc(int* a, const int size, int& m, int& x, int i){
		if (i%2 ==0)
			m *= a[i];
		if (i!=0 && i!=size-1)
			x += a[i];
		if (i<size-1)
			return Calc(a, size, m, x, i+1);
}

void Sort(int* a, const int size, int i){
	int y=a[i];
	int iy=i;
	Min(a, size, y, iy, i+1);
	a[iy] = a[i];
	a[i] =y;
	if (i<size-2)
		Sort(a, size, i+1);
}
void Min(int* a, const int size, int &y, int &iy, int j){
	if (y<0){
		y = a[j];
		iy = j;
	}
	if (j<size-1)
	Min(a, size, y, iy, j+1);
}