#ifndef SireMap_h
#define SireMap_h
#include <set>
#include <sstream>
#include <vector>
#include <map>
#include "sire.h"
#include "animalMap.h"

using namespace std;

class sireMap : public map<string,sire*>{
private:

  string runningMode;

public:

  sireMap(void);
  void mergeAllInputs(animalMap &aMap, animalMap &pMap);

  void setRunningMode(string psRunningMode);
  string getRunningMode();
  void simpleDebug(string message, string tvdid);


};

#endif
