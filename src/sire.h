#ifndef Sire_h
#define Sire_h
#include <set>
#include <sstream>
#include <vector>
#include <map>
#include "date.h"

using namespace std;

class sire{
public:

  string indStr, traitStr, indBreedStr, sexBirthStr;
  double accDbl;
  string itbidStr, inditbbreedStr;
  long int indDbIdLi;   //technical ID from DB for animal
  long int damDbIdLi;   //technical ID from DB for dam
  long int sireDbIdLi;  //technical ID from DB for sire
  date birthdate;

  sire(string indstr, string traitname, double acc, string indbreedstr, date indbirthdate, string itbidstr, string sexstr, string inditbbreedstr, long int indDbId, long int damDbId, long int sireDbId);

};


#endif
