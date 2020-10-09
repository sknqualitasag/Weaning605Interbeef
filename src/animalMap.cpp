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



using namespace std;

//void animalMap::inputSolITB(char* fname1, string startYear, string endYear){
//
//
//  ifstream solfile(fname1);
//  if(!solfile){
//    cout<< "Cannot open file "<<fname1<<endl;
//    exit(1);
//  }
//  cout<<"\ninputSolITB(): Reading file "<<fname1<<endl;
//  cout<<"*****************************************************************"<< endl;
//
//  std::string sep(";");
//  std::string subStr;
//  Tokenizer colData;
//  string inputStr, myId, birthDateYYYYMMDD, country;
//  int numDescendants,numObs, rec=0, numCol, numFound=0, numSkipped=0, numSkipped1=0;
//  double sol, acc, matSol, matAcc;
//  while (getline(solfile,inputStr)) 	{
//    // remove Mac carriage return from argument...
//    size_t foundloc = inputStr.find('\r');
//    if ( foundloc != string::npos ) {
//      subStr = inputStr.substr(0,foundloc);
//      inputStr = subStr;
//    }
//    colData.getTokens(inputStr,sep);
//    if(rec==0){
//      numCol = colData.size();
//    }
//    myId  = colData[0];
//    birthDateYYYYMMDD = colData[1];
//    numDescendants  = atoi(colData[2].c_str());
//    numObs  = atoi(colData[3].c_str());
//    sol  = atof(colData[4].c_str());
//    acc = atof(colData[5].c_str());
//    matSol  = atof(colData[6].c_str());
//    matAcc = atof(colData[7].c_str());
//    country = colData[8];
//    rec++;
//    if(country == "che") {
//      animal *aPtr = new animal(myId, birthDateYYYYMMDD, numDescendants, numObs, -9999, -9999 , sol, acc, matSol, matAcc, -9999, -9999, false, false); //Sophie
//
//      if(rec%100000==0){
//        cout<<rec<<" records processed \r";
//        cout.flush();
//      }
//
//      map<string,animal*>::iterator ait = this->find(aPtr->indITBStr);
//      if(ait == this->end()){
//        (*this)[aPtr->indITBStr] = aPtr;
//
//        LOGD<<"aPtr->indITBStr "<<aPtr->indITBStr<<" , aPtr->birthYearStr "<<aPtr->birthYearStr<<" ,aPtr->birthMonthSt "<<aPtr->birthMonthStr<<" ,aPtr->birthDayStr "<<aPtr->birthDayStr
//            <<" ,aPtr->numDescendantsWWITB "<<aPtr->numDescendantsWWITB<<" ,aPtr->numObsWWITB "<<aPtr->numObsWWITB<<" ,aPtr->solWWITB "<<aPtr->solWWITB<<" ,aPtr->solMatWWITB "<<aPtr->solMatWWITB
//            <<" ,aPtr->accWWITB "<<aPtr->accWWITB<<" , aPtr->matAccWWITB "<<aPtr->matAccWWITB;
//
//      }
//
//      //Sophie: Basis festlegen
//      if(aPtr->birthYearStr >= startYear && aPtr->birthYearStr <= endYear){
//        if(aPtr->sexITBStr == "M"){
//          aPtr->base = true;
//          LOGD<<"aPtr->indITBStr "<<aPtr->indITBStr<<" is flagged as basis animal";
//        }
//      }
//
//    }
//
//  }
//
//  cout<<"\nTotal number of interbeef animals: "<<rec<<endl;
//
//};
