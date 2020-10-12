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

  indDbIdLi = CONSTANTS::INT_NA;
  damDbIdLi = CONSTANTS::INT_NA;
  sireDbIdLi = CONSTANTS::INT_NA;
  itbidStr = CONSTANTS::STRING_NA;

  indStr = indstr;
  constructorDebug("constructor animal()_Constructor called with indStr", indStr, psRunningMode);
  traitStr = traitname;
  constructorDebug("constructor animal()_Constructor called with traitStr "+traitStr, indStr, psRunningMode);
  accDbl = acc;
  constructorDebug("constructor animal()_Constructor called with accDbl"+to_string(accDbl), indStr, psRunningMode);

}


// Constructor using DB-Ids of animal, sire and dam as additional arguments
animal::animal(string indstr, string indbreedstr, date indbirthdate, string itbidstr, string damstr, string sirestr, string sexstr, string indactivstr, string indhbstr, string inditbbreedstr, long int indDbId, long int damDbId, long int sireDbId, string itbdamstr, string itbsirestr){

  indactivStr = indactivstr;
  indhbStr = indhbstr;
  inditbbreedStr = inditbbreedstr;
  // setting DB-ID data fields
  indDbIdLi = indDbId;
  damDbIdLi = damDbId;
  sireDbIdLi = sireDbId;

  indStr = indstr;
  if(damstr != CONSTANTS::STRING_NA){
    damStr = damstr;
  }else {
    damStr = CONSTANTS::STRING_NA;
  }
  if(sirestr != CONSTANTS::STRING_NA){
    sireStr = sirestr;
  }else{
    sireStr = CONSTANTS::STRING_NA;
  }

  indBreedStr = indbreedstr;
  sexBirthStr = sexstr;

  itbidStr = itbidstr;
  itbDamStr = itbdamstr;
  itbSireStr = itbsirestr;

  birthdate = birthdate;


}


// simple debug File
void animal::constructorDebug(string message, string tvdid, string psRunningMode){
  string localRunningMode = psRunningMode;
  if(localRunningMode == CONSTANTS::RUNNING_DEBUGALL){
    //here Develop-Output-Logfile
    LOGD <<"Message "<<message<<" of animal "<<tvdid;
  }
}
