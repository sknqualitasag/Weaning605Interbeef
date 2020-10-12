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
#include <vector>
#include <functional>
#include <sstream>
#include <set>
#include <sstream>
#include <vector>
#include <map>
#include "date.h"
//#include "constants.h"



using namespace std;

class animal {
public:

  string indStr, traitStr, damStr, sireStr, indBreedStr, sexBirthStr, indDbIdStr, damDbIdStr, sireDbIdStr;
  double accDbl;
  string itbidStr, indactivStr, indhbStr, inditbbreedStr, itbDamStr, itbSireStr;
  date birthdate;

  animal(string indstr, string traitname, double acc, string psRunningMode);
  animal(string indstr, string indbreedstr, date indbirthdate, string itbidstr, string sexstr, string indactivstr, string indhbstr, string inditbbreedstr, long int indDbId, long int damDbId, long int sireDbId, string psRunningMode);

  void constructorDebug(string message, string tvdid, string psRunningMode);


};
