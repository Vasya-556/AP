// lab_03_3.cpp
// Кобрин Василь
// Лабараторна робота №3.3
// Розгалуження, задане графіком функції
// варіант 3

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x; // вхідний аргумент
	double R; // вхідний параметр
	double y; // результат обчислення виразу
	double Pi; // ввід числа пі
	cout << "R = "; cin >> R;
	cout << "x = "; cin >> x;
	Pi = 4* atan(1);
	// розгалуження в повній формі
	if (x<=-7-R)
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
	cout << endl;
	cout << "y = " << y << endl;
	cin.get();
	system("pause");
	return 0;
}