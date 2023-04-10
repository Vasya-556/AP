// Lab_6.1.1.cpp
// < Кобрин Василь >
// Лабараторна робота № 6.1.1
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом 
// Варіант 3

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);
void Calc(int* a, const int size, int& sum, int& r);

int main()
{
  srand((unsigned)time(NULL));
  const int n = 24;
  int a[n];

  int Low = -50;
  int High = 15;
  int sum = 0;
  int r = 0;

  Create(a, n, Low, High);
  cout << "a = "; Print(a, n);

  Calc(a, n, sum, r);
  cout << "b = "; Print(a, n);

  cout << "sum = " << setw(4) << sum << endl
    << "number = " << setw(2) << r << endl;

}
void Create(int* a, const int size, const int Low, const int High)
{
  for (int i = 0; i < size; i++)
    a[i] = Low + rand() % (High - Low + 1);
}
void Print(int* a, const int size)
{
  for (int i = 0; i < size; i++)
    cout << setw(5) << a[i];
  cout << endl;
}

void Calc(int* a, const int size, int& sum, int& r)
{
  for (int i = 0; i < size; i++){
	if (a[i] < 0 || a[i]%2!=0) {
      sum += a[i];
      r++;
      a[i] = 0;
    }
  }
}