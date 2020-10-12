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

  string indStr, traitStr, damStr, sireStr, indBreedStr, sexBirthStr;
  double accDbl;
  string itbidStr, indactivStr, indhbStr, inditbbreedStr, itbDamStr, itbSireStr;
  long int indDbIdLi;   //technical ID from DB for animal
  long int damDbIdLi;   //technical ID from DB for dam
  long int sireDbIdLi;  //technical ID from DB for sire
  string dataSourceStr;
  date birthdate;

  animal(string indstr, string traitname, double acc, string psRunningMode);
  animal(string indstr, string indbreedstr, date indbirthdate, string itbidstr, string damstr, string sirestr, string sexstr, string indactivstr, string indhbstr, string inditbbreedstr, long int indDbId, long int damDbId, long int sireDbId, string itbdamstr, string itbsirestr);

  void constructorDebug(string message, string tvdid, string psRunningMode);


};
