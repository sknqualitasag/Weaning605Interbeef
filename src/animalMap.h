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
#include "animal.h"
#include "bloodMap.h"
#include "date.h"

using namespace std;


class animalMap : public map<string,animal*> {

public:

  void setRunningMode(string psRunningMode);
  string getRunningMode();
  void inputDebug(string psRunModeFile);
  void outputDebug(string message, string tvdid);
  string runningMode;
  void simpleDebug(string message, string tvdid);
  // list of TVD-Ids for which we want to output debugging information
  vector <string> debugTvdIds;

  bloodMap BreedComposite;

  void makeReadableRRTDMPedigree(string ipedfile, string opedfile);
  void readRRTDMPedigree(string pedfileName);
  unsigned maxid=0;//the maximum id found in pedigree
  string verifyBreed(string breedstr, string indstr);
  string getSexWithITBid(string itbidstr);

  void inputData(string dataFile);




};
