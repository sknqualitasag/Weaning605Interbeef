#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <strstream>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <functional>
#include <cstring>
#include "animal.h"
#include "rutil.h"



using namespace std;

animal::animal(string indstr, string traitname, double acc){

  indStr = indstr;
  traitStr = traitname;
  accDbl = acc;

}
