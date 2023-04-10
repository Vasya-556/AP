#include "Dod.h"
#include "Var.h"
#include <cmath>

using namespace nsVar;

void nsDod::dod(){
    a *= (pow(x,2 * n)*x*x)/(tgamma(x+1));
}
