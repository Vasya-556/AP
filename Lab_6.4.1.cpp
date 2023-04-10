// Lab_6.4.1.cpp
// < Кобрин Василь >
// Лабараторна робота № 6.4.1
// Опрацювання та впорядкування одновимірних динамічних масивів
// Варіант 3

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);
void Calc(int* a, const int size, int& m, int& x);
void Sort(int* a, const int size);

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
	
	Create(a, n, Low, High);
	cout << "a = "; Print(a, n);
	
	Calc(a, n, m, x);
	cout << "dob = " << m << endl;
	cout << "sum = " << x << endl;
	
	Sort(a, n);
	cout << "a1 = "; Print(a, n);
}

void Create(int* a, const int size, const int Low, const int High){
	for (int i = 0; i < size; i++)
    	a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size){
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}

void Calc(int* a, const int size, int& m, int& x){
	for (int i = 0; i < size; i++){
		if (i%2 ==0)
			m *= a[i];
		if (i!=0 && i!=size-1)
			x += a[i];	
	}
}

void Sort(int* a, const int size){
	for (int i=0; i<size-1; i++){
		int y=a[i];
		int iy=i; 
		for (int j=i+1; j<size; j++){
			if (y<0){
				y = a[j];
				iy = j;
			}
		}
		a[iy] = a[i];
		a[i] = y;
	}
}