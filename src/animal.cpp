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
#include "constant.h"
#include "date.h"
#include <plog/Log.h>



using namespace std;

animal::animal(string indstr, string traitname, double acc, string psRunningMode){

  indDbIdStr = CONSTANTS::INT_NA;
  damDbIdStr = CONSTANTS::INT_NA;
  sireDbIdStr = CONSTANTS::INT_NA;
  itbidStr = CONSTANTS::STRING_NA;

  indStr = indstr;
  constructorDebug("constructor animal()_Constructor called with indStr", indStr, psRunningMode);
  traitStr = traitname;
  constructorDebug("constructor animal()_Constructor called with traitStr "+traitStr, indStr, psRunningMode);
  accDbl = acc;
  constructorDebug("constructor animal()_Constructor called with accDbl "+to_string(accDbl), indStr, psRunningMode);

}


// Constructor using DB-Ids of animal, sire and dam as additional arguments
animal::animal(string indstr, string indbreedstr, date indbirthdate, string itbidstr, string sexstr, string indactivstr, string indhbstr, string inditbbreedstr, string indDbIdstr, string damDbIdstr, string sireDbIdstr, string psRunningMode){

  indStr = indstr;
  indactivStr = indactivstr;
  indhbStr = indhbstr;
  inditbbreedStr = inditbbreedstr;
  indDbIdStr = indDbIdstr;
  damDbIdStr = damDbIdstr;
  sireDbIdStr = sireDbIdstr;
  indBreedStr = indbreedstr;
  sexBirthStr = sexstr;
  itbidStr = itbidstr;
  birthdate = indbirthdate;

}


// simple debug File
void animal::constructorDebug(string message, string tvdid, string psRunningMode){
  string localRunningMode = psRunningMode;
  if(localRunningMode == CONSTANTS::RUNNING_DEBUGALL){
    //here Develop-Output-Logfile
    LOGD <<"Message "<<message<<" of animal "<<tvdid;
  }
}
