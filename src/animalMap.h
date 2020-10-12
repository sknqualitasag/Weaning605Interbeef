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

  bloodMap BreedComposite;

  void makeReadableRRTDMPedigree(string ipedfile, string opedfile);
  void readRRTDMPedigree(string pedfileName);
  unsigned maxid=0;//the maximum id found in pedigree

  string verifyBreed(string breedstr, string indstr);




  void inputData(string dataFile);


};
