// lab_04_4.cpp
// Кобрин Василь
// Лабараторна робота №4.4
// Табуляція функції, заданої графіком
// варіант 3
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	double x;
	double xp;
	double xk;
	double dx;
	double R; 
	double y; 
	double Pi; 
	cout << "R = "; cin >> R;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;cout << fixed;
	cout <<"----------------------" << endl;
	cout <<"|" << setw(5) << "x" << "   |" 
	<<setw(7 ) <<"y" <<"    |"<< endl;
	cout <<"----------------------" << endl;
	x=xp;
	Pi = 4* atan(1);
	while(x<=xk)
	{
	if(x<=-7-R)
	y = R;
	else 
	if(-7-R<x && x<=-7+R)
	y = R - sqrt(pow(R,2) - pow(x+7,2));
	else
	if(-7+R<x && x<=-4)
	y = R;
	else
	if(-4<x && x<=0)	
	y = R+(-R/4)*(x+4);
	else
	if(0<x && x<=Pi)
	y = sin(x);
	else
	y = x-Pi;
	cout << "|" << setw(7) << setprecision(2) << x
	<< " |" << setw(10) << setprecision(3) << y
	<< " |" << endl;
	x += dx;
}
	cout <<"---------------------------" << endl;
	system("pause");
	return 0;
}