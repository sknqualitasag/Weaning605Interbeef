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
#include <plog/Log.h>
#include <chrono>
#include <ctime>
#include "sireMap.h"
#include "date.h"
#include "constant.h"

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
      sire *sPtr = new sire(itTVD->second->indStr, itTVD->second->traitStr, itTVD->second->accDbl, itTVD->second->indBreedStr, itTVD->second->birthdate, itTVD->second->itbidStr, itTVD->second->sexBirthStr, itTVD->second->inditbbreedStr, itTVD->second->indDbIdStr, itTVD->second->damDbIdStr, itTVD->second->sireDbIdStr);

      (*this)[itTVD->second->indDbIdStr] = sPtr;

    }

  }

}


void sireMap::outputInterbeef605(string psBreed, string psTrait){

  string itbBreed=convertBreed2InterbullBreed(psBreed);


  cout<<"\noutputInterbeef602(): WRITING INTERBEEF DATA-FILE FOR "<<itbBreed<<" AND "<<psTrait<<endl;
  cout<<"*****************************************************************"<< endl;

  ofstream datafile605("datafile605_"+itbBreed+"_"+psTrait);

  //https://wiki.interbull.org/public/beef_guidelines#A4.2.2.4_OFCL_file_.28605.29

  for(map<string,sire*>::iterator it = this->begin();it != this->end(); it++){
    sire *sPtr =(*it).second;

    if(sPtr->indBreedStr == psBreed){
      if(purgeBloodcomposite(sPtr->indDbIdStr, psBreed)){
        datafile605 <<setw(3)<<"605"
                    <<setw(20)<<sPtr->inditbbreedStr<<sPtr->itbidStr.substr(3,16)
                    <<setw(3)<<sPtr->accDbl*100
                    <<setw(3)<<"00"
                    <<setw(4)<<"CHE";

      }

    }

  }


}


string sireMap::convertBreed2InterbullBreed(string psBreed){

  if(psBreed == "AN") return("AAN");
  else if(psBreed == "CH") return("CHA");
  else if(psBreed == "HH") return("HER");
  else if(psBreed == "LM") return("LIM");
  else if(psBreed == "SI") return("SIM");
  else return("XXX");

}


bool sireMap::purgeBloodcomposite(string indDbIdStr, string parBreedName){

  map<string, blood*>::iterator bit=BreedComposite.find(indDbIdStr);
  if(bit != BreedComposite.end()){
    if(bit->second->BloodComposite[parBreedName] < CONSTANTS::MIN_BLOOD_CONTENT){
      return false;
    }else{
      return true;
    }
  }else{
    return false;
  }

}
