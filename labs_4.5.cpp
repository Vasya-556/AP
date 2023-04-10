// Lab_04_5.cpp
// < Кобрин Василь >
// Лабараторна робота № 4.5 
// «Попадання» у плоску фігуру
// Варіант 3
#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>
using namespace std;
int main ()
{
	double x, y, R;
	srand ((unsigned) time(NULL));
	for (int i=0; i<10; i++){
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	cout << "R = "; cin >> R;
	if(R*R >= pow(x+R,2)+pow(y-R,2) && R*R >= pow(x-R,2)+pow(y+R,2) || 
	y <= R && y >=-R && x>=-R && x<= R )	
	cout << "yes" << endl;
	else
	cout << "no" << endl;}
	cout << endl << fixed;
	for (int i=0; i<10; i++){
	x = 6.*rand()/RAND_MAX - 2*R;
	y = 6.*rand()/RAND_MAX - 2*R;
	if (R*R >= pow(x+R,2)+pow(y-R,2) && R*R >= pow(x-R,2)+pow(y+R,2) || 
	y <= R && y >=-R && x>=-R && x<= R )
	cout << setw(8) << setprecision(4) << x << " " << setw(8) << setprecision(4) << y << " " << "yes" << endl;
	else
	cout << setw(8) << setprecision(4) << x << " " << setw(8) << setprecision(4) << y << " " << "no" << endl;}
	system("pause");
	return 0;
}