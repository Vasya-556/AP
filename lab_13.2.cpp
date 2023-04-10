#include <iostream>

using namespace std;

#define MAX(x,y)  ((x)>(y))?(x):(y)
#define MIN(x,y)  ((x)<(y))?(x):(y)
#define MODUL(x) ((x)>(0))?(x):(-x)
#define SQR(x) (x)*(x)
#define CUBE(x) (x)*(x)*(x)

#define VIVID(w) cout<<w;
#define VVID(w)	cin>>w;

int main()
{
	double w;
	int x, y, z;
	VIVID("x = "); VVID(x);
	VIVID("y = "); VVID(y);
	VIVID("z = "); VVID(z);
	#if (1<z && z < 3)
	w = MAX(MODUL(x) + MODUL(y) + MODUL(z), CUBE(z));
	#else if z>3
	w = MIN(2 * x + y, SQR(2*y-z));
	#endif
	VIVID("w = "); VIVID(w);
	VIVID(endl);
	return 0;
}