// Lab_6.1.2.cpp
// < Кобрин Василь >
// Лабараторна робота № 6.1.2
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом 
// Варіант 3

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i);
void Print(int* a, const int size, int i);
void Calc(int* a, const int size, int& sum, int& r, int i);

int main()
{
  srand((unsigned)time(NULL));
  const int n = 24;
  int a[n];

  int Low = -50;
  int High = 15;
  int sum = 0;
  int r = 0;

  Create(a, n, Low, High, 0);
  cout << "a = "; Print(a, n, 0);

  Calc(a, n, sum, r, 0);
  cout << "b = "; Print(a, n, 0);

  cout << "sum = " << setw(4) << sum << endl
    << "number = " << setw(2) << r << endl;
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

void Calc(int* a, const int size, int& sum, int& r, int i)
{
	if (a[i] < 0 || a[i]%2!=0){
		sum += a[i];
		r++;
		a[i] = 0;
	}
	if (i<size-1)
		return Calc(a, size, sum, r, i+1);
}