// Lab_05_4.cpp
// < Кобрин Василь >
// Лабараторна робота № 5.4 
// Обчислення сум та добутків задопомогою рекурсії
// Варіант 3
#include <iostream>
#include <cmath>
using namespace std;
double S1(const int K, const int N)
{
	double s=0;
	for (int i=K; i<=N; i++)
		s += 1/i +sqrt(1+pow(sin(i),2));
	return s;
}
double S2(const int K, const int N, const int i)
{
	if (i>N)
		return 0;
	else
		return 1/i +sqrt(1+pow(sin(i),2)) + S2(K, N, i+1);
}
double S3(const int K, const int N, const int i)
{
	if (i<K)
		return 0;
	else
		return 1/i +sqrt(1+pow(sin(i),2)) + S3(K, N, i-1);
}
double S4(const int K, const int N, const int i, double t)
{
	t = t + 1/i +sqrt(1+pow(sin(i),2));
	if (i>=N)
		return t;
	else
		return S4(K, N, i+1, t);
}
double S5(const int K, const int N, const int i, double t)
{
	t = t + 1/i +sqrt(1+pow(sin(i),2));
	if (i<=K)
		return t;
	else
		return S5(K, N, i-1, t);
}
int main()
{
	int K, N;
	K=1;
	cout << "N = "; cin >> N;
	cout << "(iter) S1 = " << S1(K, N) << endl;
	cout << "(rec up ++) S2 = " << S2(K, N, K) << endl;
	cout << "(rec up --) S3 = " << S3(K, N, N) << endl;
	cout << "(rec down ++) S4 = " << S4(K, N, K, 0) << endl;
	cout << "(rec down --) S5 = " << S5(K, N, N, 0) << endl;
	return 0;
}