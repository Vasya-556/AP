// Lab_05.3.cpp
// < Кобрин Василь >
// Лабараторна робота № 5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями
// Варіант 3
#include <iostream>
#include <cmath>
using namespace std;
double h(const double x);
int main()
{
double qp, qk, z;
int n;
cout << "qp = "; cin >> qp;
cout << "qk = "; cin >> qk;
cout << "n = "; cin >> n;
double dq = (qk-qp)/n;
double q = qp;
while (q <= qk)
{
z = h(q+1)+h(q*q+1)+pow(h(q*q),2);
cout << q << " " << z << endl;
q += dq;
}
return 0;
}


double h(const double x)
{
if (abs(x) >= 1)
return ((cos(x)+1)/(sin(x)*sin(x)+1));
else
{
double S=0;
int i=0;
double a=1;
S = a;
do
{
i++;
double R = pow(x, 2*i)/((2*i-5)*(2*i-4)*(2*i-3)*(2*i-2)*(2*i-1)*2*i );
a *= 1/cos(x)*R;
S += a;
} while(i<6);
return S;
}
}