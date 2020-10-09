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

}

//animal::  animal(string myId, string birthDateYYYYMMDD, int numDescendants, int numObs, int numDaughter, int numProgrenies, double sol, double acc, double matSol, double matAcc, int numProgreniesCH, int numHerdsCH, double itbPubld, double itbPublm){ //Sophie
//
//
//  indITBStr = getVerifiedITBNr(myId);
//  indITBBreedStr = verifyBreed(myId);
//  sexITBStr = verifySex(myId);
//
//
//  if(birthDateYYYYMMDD.size() == 8){
//    birthYearStr = birthDateYYYYMMDD.substr(0,4).c_str();
//    birthYearInt = atoi(birthYearStr.c_str());
//    if(birthYearInt < 1950) {
//      birthYearInt = -9999;
//      birthYearStr = "-9999";
//    }
//    birthMonthStr = birthDateYYYYMMDD.substr(4,2).c_str();
//    birthMonthInt=atoi(birthMonthStr.c_str());
//    if(birthMonthInt<1 || birthMonthInt>12) {
//      birthMonthInt = -9999;
//      birthMonthStr = "-9999";
//    }
//
//    birthDayStr = birthDateYYYYMMDD.substr(6,2).c_str();
//    birthDayInt=atoi(birthDayStr.c_str());
//    if(birthDayInt<1 || birthDayInt>31) {
//      birthDayInt = -9999;
//      birthDayStr = "-9999";
//    }
//  }
//  else {
//    birthYearInt = -9999;
//    birthYearStr = "-9999";
//    birthMonthInt = -9999;
//    birthMonthStr = "-9999";
//    birthDayInt = -9999;
//    birthDayStr = "-9999";
//  }
//
//  numDescendantsWWITB = numDescendants;
//  numObsWWITB = numObs;
//  numDaughterWWITB = numDaughter;
//  numProgreniesWWITB = numProgrenies;
//  solWWITB = sol;
//  accWWITB = acc;
//  solMatWWITB = matSol;
//  matAccWWITB = matAcc;
//  numProgreniesCHWWITB = numProgreniesCH;
//  numHerdsCHWWITB = numHerdsCH;
//  itbPubldWWITB = itbPubld;
//  itbPublmWWITB = itbPublm;
//
//
//  scaledSolWWITB = -9999.0;
//  scaledSolMatWWITB = -9999.0;
//  base = false;
//  meanWW = 0.0;
//  meanMatWW = 0.0;
//
//}
