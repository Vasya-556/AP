// Lab_04_2.cpp
// < Кобрин Василь >
// Лабараторна робота № 4.2 
// Табуляція функції, заданої формулою: функція однієї змінної
// Варіант 3
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double x, y, xp, xk, dx, A, B;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << fixed;
	cout <<"----------------------" << endl;
	cout <<"|" << setw(5) << "x" << "   |" 
	<<setw(7 ) <<"y" <<"    |"<< endl;
	cout <<"----------------------" << endl;	
	x=xp;
	while(x<=xk)
	{
	A=2/x+abs(x);
	if(x<0)
	B=1+4*x*x;
	else 
	if(x>2)
	B=5*sin(x*x+1);
	else
	B= pow(exp(x)+abs(x),2);
	y=A+B;
	cout << "|" << setw(7) << setprecision(2) << x
	<< " |" << setw(10) << setprecision(3) << y
	<< " |" << endl;
	x += dx;	
	}
	cout <<"---------------------------" << endl;
	system("pause");
	return 0;
}