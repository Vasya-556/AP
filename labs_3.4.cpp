// Labs_03_4.cpp
// кобрин Василь
// лабараторна робота №3.4
// розгалуження, задане плосокю фігурою
// варіант 3
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x; // вхідний агрумент
	double y; // вхідний параметр
	double R; // радіус
	double a; // ввів значення a
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	cout << "R = "; cin >> R;
	a=R;
	// розгалуження в повній формі
	if(R*R >= pow(x+R,2)+pow(y-R,2) && R*R >= pow(x-R,2)+pow(y+R,2) || 
	y <= R && y >=-R && a>=-R && a<= R )
	cout << "yes" << endl;
	else
	cout << "no" << endl;
	cin.get();
	system("pause");
	return 0;
}