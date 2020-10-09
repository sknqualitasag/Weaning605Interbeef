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
#include "animalMap.h"
#include "rutil.h"
#include <plog/Log.h>
#include "constant.h"



using namespace std;

void animalMap::inputData(string dataFile){

  ifstream datafile(dataFile.c_str());

  if(!datafile){
    cout<< "inputData(): Cannot open file "<<dataFile<<endl;
    exit(8);
  }

  cout<<"\ninputData(): Reading file "<<dataFile<<endl;
  cout<<"*****************************************************************"<< endl;

    std::string sep(";");
    std::string subStr;
    Tokenizer colData;
    string inputStr;
    int rec=0, numCol, numFound=0, numSkipped=0, numSkipped1=0;
    while (getline(datafile,inputStr)) 	{
      // remove Mac carriage return from argument...
      size_t foundloc = inputStr.find('\r');
      if ( foundloc != string::npos ) {
        subStr = inputStr.substr(0,foundloc);
        inputStr = subStr;
      }
      colData.getTokens(inputStr,sep);
      if(rec==0){
        numCol = colData.size();
      }
      string indstr  = colData[0];
      string traitname = colData[1];
      int numDescendants  = atoi(colData[2].c_str());
      int numObs  = atoi(colData[3].c_str());
      double sol  = atof(colData[4].c_str());
      double acc = atof(colData[5].c_str());
      string type  = colData[6];
      string label = colData[7];
      string pubcode = colData[8];
      string base = colData[9];
      rec++;
      if(label == CONSTANTS::EBV_LABEL) {

        animal *aPtr = new animal(indstr, traitname, acc); //Sophie

//        if(rec%100000==0){
//          cout<<rec<<" records processed \r";
//          cout.flush();
//        }
//
//        map<string,animal*>::iterator ait = this->find(aPtr->indITBStr);
//        if(ait == this->end()){
//          (*this)[aPtr->indITBStr] = aPtr;
//
//          LOGD<<"aPtr->indITBStr "<<aPtr->indITBStr<<" , aPtr->birthYearStr "<<aPtr->birthYearStr<<" ,aPtr->birthMonthSt "<<aPtr->birthMonthStr<<" ,aPtr->birthDayStr "<<aPtr->birthDayStr
//              <<" ,aPtr->numDescendantsWWITB "<<aPtr->numDescendantsWWITB<<" ,aPtr->numObsWWITB "<<aPtr->numObsWWITB<<" ,aPtr->solWWITB "<<aPtr->solWWITB<<" ,aPtr->solMatWWITB "<<aPtr->solMatWWITB
//              <<" ,aPtr->accWWITB "<<aPtr->accWWITB<<" , aPtr->matAccWWITB "<<aPtr->matAccWWITB;
//
//        }
//
//        //Sophie: Basis festlegen
//        if(aPtr->birthYearStr >= startYear && aPtr->birthYearStr <= endYear){
//          if(aPtr->sexITBStr == "M"){
//            aPtr->base = true;
//            LOGD<<"aPtr->indITBStr "<<aPtr->indITBStr<<" is flagged as basis animal";
//          }
//        }
//
      }

    }

    cout<<"\nTotal number of interbeef animals: "<<rec<<endl;

}

