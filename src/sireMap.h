#ifndef SireMap_h
#define SireMap_h
#include <set>
#include <sstream>
#include <vector>
#include <map>
#include "sire.h"

using namespace std;

class sireMap : public map<string,sire*>{

public:

  sireMap(void);

};

#endif
