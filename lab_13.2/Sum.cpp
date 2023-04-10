#include <math.h>
#include "Dod.h"
#include "Sum.h"
#include "Var.h"

using namespace nsDod;
using namespace nsVar;

void nsSum::sum(){
    n = 0;
    a = 1;
    S = a;
    do
    {
        n++;
        dod();
        S += a;
    } while (fabs(a) > eps);
    
}