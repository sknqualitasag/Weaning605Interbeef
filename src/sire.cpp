#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <sstream>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <cstring>
#include <plog/Log.h>
#include "constants.h"
#include "sire.h"
#include "date.h"




using namespace std;


sire::sire(string indstr, string traitname, double acc, string indbreedstr, date indbirthdate, string itbidstr, string sexstr, string inditbbreedstr, long int indDbId, long int damDbId, long int sireDbId){

  indStr = indstr;
  traitStr = traitname;
  accDbl = acc;
  indBreedStr = indbreedstr;
  birthdate = indbirthdate;
  itbidStr = itbidstr;
  sexBirthStr = sexstr;
  inditbbreedStr = inditbbreedstr;
  indDbIdLi = indDbId;
  damDbIdLi = damDbId;
  sireDbIdLi = sireDbId;

}
