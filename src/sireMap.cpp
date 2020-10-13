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

  cout<<"\nmergeAllInputs(): mergeAllInputs in sireMap "<<endl;
  cout<<"*****************************************************************"<< endl;

  //pMap ist mit numerischeID Tier.
  for(map<string,animal*>::iterator pit = pMap.begin(); pit != pMap.end();  pit++){
    //aMap ist mit den TVD-ID von Tier aufgebaut.
    map<string, animal*>::iterator itTVD = aMap.find(pit->second->indStr);
    // itTVD found in aMap
    if(itTVD != aMap.end()){

      // new sire record
      sire *sPtr = new sire(itTVD->second->indStr, itTVD->second->traitStr, itTVD->second->accDbl, pit->second->indBreedStr, pit->second->birthdate, pit->second->itbidStr, pit->second->sexBirthStr, pit->second->inditbbreedStr, pit->second->indDbIdStr, pit->second->damDbIdStr, pit->second->sireDbIdStr);

      (*this)[itTVD->second->indDbIdStr] = sPtr;

      simpleDebug("mergeAllInputs()_Insert sireMap ", itTVD->second->indDbIdStr);


    }

  }

}


void sireMap::outputInterbeef605(string psBreed, string psTrait){

  string itbBreed=convertBreed2InterbullBreed(psBreed);


  cout<<"\noutputInterbeef602(): WRITING INTERBEEF DATA-FILE FOR "<<itbBreed<<" AND "<<psTrait<<endl;
  cout<<"*****************************************************************"<< endl;

  ofstream datafile605("datafile605_"+itbBreed+"_"+psTrait);

  for(map<string,sire*>::iterator it = this->begin();it != this->end(); it++){
    sire *sPtr =(*it).second;

    if(sPtr->indBreedStr == psBreed){
      if(purgeBloodcomposite(sPtr->indDbIdStr, psBreed)){

        cout<<"sPtr->indStr "<<sPtr->indStr<<endl;
        cout<<"sPtr->sPtr->inditbbreedStr<<sPtr->itbidStr.substr(3,16) "<<sPtr->inditbbreedStr<<sPtr->itbidStr.substr(3,16)<<endl;
        cout<<"sPtr->accDbl*100 "<<sPtr->accDbl*100<<endl;

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


// setter for running mode
void sireMap::setRunningMode(string psRunningMode){
  runningMode = psRunningMode;

}


// getter for running mode
string sireMap::getRunningMode(){
  return runningMode;
}


// simple debug File
void sireMap::simpleDebug(string message, string tvdid){
  string localRunningMode = getRunningMode();
  if(localRunningMode == CONSTANTS::RUNNING_DEBUGALL){
    //here Develop-Output-Logfile
    LOGD <<"Message "<<message<<" of animal "<<tvdid;
  }
}
