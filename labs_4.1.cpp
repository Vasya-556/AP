// Lab_04_1.cpp
// < Кобрин Василь >
// Лабараторна робота № 4.1 
// цикли
// варіант 3
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	// 1
	int i; 
	int N; 
	double S;
	cout << "N = "; cin >> N;
	S=0;
	i=1;
	while(i<=N){
		S+= 1/i + sqrt(1+pow(sin(i),2));
		i++;
	}
	cout << S << endl;
	// 2
	S=0;
	i=1;
	do {
		S+= 1/i + sqrt(1+pow(sin(i),2));
		i++;
	} while (i<=N);
	cout << S << endl;
	// 3 
	S=0;
	i=1;
	for (i=1; i<= N; i++)
	{
		S+= 1/i + sqrt(1+pow(sin(i),2));
	}
	cout << S << endl;
	// 4
	S=0;
	i=1;
	for (i=N; i>= 1; i--)
	{
		S+= 1/i + sqrt(1+pow(sin(i),2));
	}
	cout << S << endl;
	system("pause");
	return 0;
}