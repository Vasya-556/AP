// Lab_04_3.cpp
// < Кобрин Василь >
// Лабараторна робота № 4.3 
// Табуляція функції, заданої формулою: функція з параметрами
// Варіант 3
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double a, b, c, xp, xk, dx, x, y;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;
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
	if(a<0 && c!=0)
	y=a*x*x+b*x+c;
	else
	if(a>0 && c==0)
	y=-a/(x-c);
	else
	y=a*(x+c);
	cout << "|" << setw(7) << setprecision(2) << x
	<< " |" << setw(10) << setprecision(3) << y
	<< " |" << endl;
	x += dx;
	}
	cout <<"---------------------------" << endl;
system("pause");
return 0;
}