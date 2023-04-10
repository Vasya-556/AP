// Lab_05.5.cpp
// < Кобрин Василь >
// Лабараторна робота № 5.5
// Рекурсивні функції
// Варіант 3
#include<iostream>
#include<cmath>
using namespace std;
int depth = 0;
int f(int b);
double C(int n, int k);
int main()
{
//	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	cout << "C = " << C(n,k) << endl;
	cout<<"depth = "<< depth <<endl;
	system("pause");
	return 0;
}
int f(int b)
{
	depth++;
	if (b > 1)
		return b * f(b -1);
	else
		return 1;
}
double C(int n, int k)
{
	if(n>0)
		return ((f(n-1))/(f(k-1)*f(n-1-k+1))+(f(n-1))/(f(k)*f(n-1-k)));
	else
		return 1;
	if (k==n || k==0)
		return 1;
}