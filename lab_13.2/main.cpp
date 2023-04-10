#include <iostream>
#include<cmath>
#include<iomanip>

#include "Dod.h"
#include "Var.h"
#include "Sum.h"

using namespace std;

using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main(){
    cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << endl;


	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(7) << "x" << " |"
		<< setw(16) << "(x^2n)/x!" << " |"
		<< setw(10) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-------------------------------------------------" << endl;
	
	x = xp;
	while (x <= xk)
	{
		sum();

		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(16) << setprecision(5) << log((1 + x) / (1 - x)) << " |"
			<< setw(10) << setprecision(5) << 2. * S << " |"
			<< setw(5) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "-------------------------------------------------" << endl;
}