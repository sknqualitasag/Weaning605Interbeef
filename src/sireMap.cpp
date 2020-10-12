#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <sstream>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <cstring>
#include "animalMap.h"
#include <plog/Log.h>
#include "constants.h"
#include <chrono>
#include <ctime>
#include "sireMap.h"
#include "date.h"

using namespace std;

sireMap::sireMap(){}


void sireMap::mergeAllInputs(animalMap &aMap, animalMap &pMap){

  cout<<"\nsireMap(): sireMap building "<<endl;
  cout<<"*****************************************************************"<< endl;

  //pMap ist mit numerischeID Tier.
  for(map<string,animal*>::iterator pit = pMap.begin(); pit != pMap.end();  pit++){
    //aMap ist mit den TVD-ID von Tier aufgebaut.
    map<string, animal*>::iterator itTVD = aMap.find(pit->second->indStr);
    // itTVD found in aMap
    if(itTVD != aMap.end()){

      // new sire record
      sire *sPtr = new sire(itTVD->second->indStr, itTVD->second->traitStr, itTVD->second->accDbl, itTVD->second->indBreedStr, itTVD->second->birthdate, itTVD->second->itbidStr, itTVD->second->sexBirthStr, itTVD->second->inditbbreedStr, itTVD->second->indDbIdLi, itTVD->second->damDbIdLi, itTVD->second->sireDbIdLi);

      (*this)[itTVD->second->indDbIdLi] = sPtr;

    }

  }


}
