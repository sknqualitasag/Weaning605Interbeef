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
#include "date.h"



using namespace std;

void animalMap::inputData(string dataFile){

  ifstream datafile(dataFile.c_str());

  if(!datafile){
    cout<< "inputData(): Cannot open file "<<dataFile<<endl;
    exit(8);
  }

  cout<<"\ninputData(): Reading file "<<dataFile<<endl;
  cout<<"*****************************************************************"<< endl;

    std::string sep(" ");
    std::string subStr;
    Tokenizer colData;
    string inputStr;
    int rec=0, numCol, numFound=0, numSkipped=0, numSkipped1=0;
    while (getline(datafile,inputStr)) 	{
      cout<<"inputStr: "<<inputStr<<endl;
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

        if(rec%100000==0){
          cout<<rec<<" records processed \r";
          cout.flush();
        }

        map<string,animal*>::iterator ait = this->find(aPtr->indStr);
        if(ait == this->end()){
          (*this)[aPtr->indStr] = aPtr;

        }

      }

    }

    cout<<"\nTotal number of animals in the input-file: "<<rec<<endl;

}


//' Make readable RRTDM-Pedigree from file pedfile
void animalMap::makeReadableRRTDMPedigree(string ipedfile, string opedfile){

  cout<<"\nmakeReadableRRTDMPedigree(): Reformatting the file "<<ipedfile<<" writing "<<opedfile<<endl;
  cout<<"*****************************************************************"<< endl;

  ifstream datafile(ipedfile.c_str());
  if(!datafile){
    cout<< "Cannot open file "<< ipedfile<<" in makeReadableRRTDMPedigree()! \n";
    exit(1);
  }

  ofstream outputfile(opedfile.c_str());
  if(!outputfile){
    cout<< "Cannot open output file! \n";
    exit(1);
  }


  datafile.setf(ios::skipws);
  string sep(" ");
  string indnumstr, sirenumstr, damnumstr, birthyearstr, itbidstr, inputStr, indstr, indbreedstr, indbirthdatestr, indactivstr, indhbstr, inditbbreedstr, damstr, sirestr;
  Tokenizer colData;
  unsigned lineNumber=0, numCols, sireCounter=0, damCounter=0, indBreedCounter=0, birthYearIntCounter=0, birthYearStrCounter=0, birthMonthIntCounter=0, birthMonthStrCounter=0, birthDayIntCounter=0, birthDayStrCounter=0, newAnimalsCounter=0;

  // reading RRTDM-pedigree file line by line
  while(getline(datafile,inputStr)){
    colData.getTokens(inputStr,sep);
    lineNumber++;
    numCols = colData.size();
    if(numCols == CONSTANTS::NUM_COL_RRTDM){
      //      LOGD<<"\n*";
      //      LOGD<<"Read RRTDM-Ped for animal: "<<colData[5];
      //      LOGD<<" colData[0] = indnumstr: "<<colData[0];
      //      LOGD<<" colData[1] = sirenumstr: "<<colData[1];
      //      LOGD<<" colData[2] = damnumstr: "<<colData[2];
      //      LOGD<<" colData[3] = birthdate.YearStr: "<<colData[3];
      //      LOGD<<" colData[4] = itbidstr: "<<colData[4];
      //      LOGD<<" colData[5] = indstr: "<<colData[5];
      //      LOGD<<" colData[6] = indbirthdatestr: "<<colData[6];
      //      LOGD<<" colData[7] = indbreedstr: "<<colData[7];
      //      LOGD<<" colData[8] = indactivstr: "<<colData[8];
      //      LOGD<<" colData[9] = indhbstr: "<<colData[9];
      //      LOGD<<" colData[10] = inditbbreedstr: "<<colData[10];

      indnumstr = colData[0];
      sirenumstr = colData[1];
      damnumstr = colData[2];
      birthyearstr = colData[3];
      itbidstr = colData[4];
      indstr = colData[5];
      indbirthdatestr = colData[6];
      indbreedstr = colData[7];
      indactivstr = colData[8];
      indhbstr = colData[9];
      inditbbreedstr = colData[10];

      outputfile<<indnumstr<<" "<<sirenumstr<<" "<<damnumstr<<" "<<birthyearstr<<" "<<itbidstr<<" "<<indstr<<" "<<indbirthdatestr<<" "<<indbreedstr<<" "
                <<indactivstr<<" "<<indhbstr<<" "<<inditbbreedstr<<endl;
    } else if(numCols == CONSTANTS::NUM_COL_RRTDM_WITH_MISSING){
      //      LOGD<<"\n*";
      //      LOGD<<"Read RRTDM-Ped for animal: "<<colData[4];
      //      LOGD<<" colData[0] = indnumstr: "<<colData[0];
      //      LOGD<<" colData[1] = sirenumstr: "<<colData[1];
      //      LOGD<<" colData[2] = damnumstr: "<<colData[2];
      //      LOGD<<" birthdate.YearStr: 0000";
      //      LOGD<<" colData[3] = itbidstr: "<<colData[3];
      //      LOGD<<" colData[4] = indstr: "<<colData[4];
      //      LOGD<<" indbirthdatestr: 00000000";
      //      LOGD<<" colData[5] = indbreedstr: "<<colData[5];
      //      LOGD<<" colData[6] = indactivstr: "<<colData[6];
      //      LOGD<<" colData[7] = indhbstr: "<<colData[7];
      //      LOGD<<" colData[8] = inditbbreedstr: "<<colData[8];

      indnumstr = colData[0];
      sirenumstr = colData[1];
      damnumstr = colData[2];
      birthyearstr = "0000";
      itbidstr = colData[3];
      indstr = colData[4];
      indbirthdatestr = "00000000";
      indbreedstr = colData[5];
      indactivstr = colData[6];
      indhbstr = colData[7];
      inditbbreedstr = colData[8];

      outputfile<<indnumstr<<" "<<sirenumstr<<" "<<damnumstr<<" "<<birthyearstr<<" "<<itbidstr<<" "<<indstr<<" "<<indbirthdatestr<<" "<<indbreedstr<<" "
                <<indactivstr<<" "<<indhbstr<<" "<<inditbbreedstr<<endl;

    } else {
      cout << " *** ERROR: Read RRTDM-Ped for record: " << inputStr << " has the wrong number of columns"<<endl;
      cout << " ***        Observed number of columns: " << colData.size()<<endl;
      cout << " ***        Required number of columns for record with known birthdate: " << CONSTANTS::NUM_COL_RRTDM<<endl;
      cout << " ***        Required number of columns for record with missing birthdate: " << CONSTANTS::NUM_COL_RRTDM_WITH_MISSING<<endl;
      cout << " ***        Record ignored in outputfile: " << opedfile<<endl;
    }
  }

  datafile.close();
  outputfile.close();

}


void animalMap::readRRTDMPedigree(string pedfileName){

  cout<<"\nreadRRTDMPedigree(): Reading RRTDM-pedigree from "<<pedfileName<<endl;
  cout<<"*****************************************************************"<< endl;

  ifstream datafile(pedfileName.c_str());
  if(!datafile){
    cout<< "Cannot open file "<< pedfileName<<" in readRRTDMPedigree()! \n";
    exit(1);
  }

  datafile.setf(ios::skipws);
  string sep(" ");
  string indnumstr, sirenumstr, damnumstr, birthyearstr, itbidstr, inputStr, indstr, indbreedstr, indactivstr, indhbstr, inditbbreedstr, damstr, sirestr, sexstr;
  Tokenizer colData;
  unsigned lineNumber=0, numCols, newAnimalsCounter=0, rec = 0, replaceAnimalsCounter = 0;

  // reading RRTDM-pedigree file line by line
  while(getline(datafile,inputStr)){
    colData.getTokens(inputStr,sep);
    lineNumber++;
    if (lineNumber==1){
      numCols = colData.size();
      cout<<"Number of columns: "<<numCols<<endl;
    }
    else if(colData.size() != numCols){
      cout<<"readRRTDMPedigree() Line "<<lineNumber<<" has "<<colData.size()<<" columns, "<<numCols<<" expected!"<<endl;
      cerr<<"record is: "<<inputStr<<endl;
      exit(8);
    }

    indnumstr = colData[0];
    sirenumstr = colData[1];
    damnumstr = colData[2];
    birthyearstr = colData[3];
    itbidstr = colData[4];
    indstr = colData[5];
    date indbirthdate = date(colData[6]);
    indbreedstr = verifyBreed(colData[7],indstr);
    indactivstr = colData[8];
    indhbstr = colData[9];
    inditbbreedstr = colData[10];

    sexstr=getSexWithITBid(itbidstr);

    if(indbreedstr == CONSTANTS::STRING_NA){
      continue;
    }
    if(sexstr == CONSTANTS::STRING_NA){
      continue;
    }

    // find maximum animal id
    if(atoi(indnumstr.c_str()) > maxid){
      maxid = atoi(indnumstr.c_str());
    }

    rec++;
    if(rec%100000==0){
      cout<<rec<<" records processed \r";
      cout.flush();
    }

    //new animal record
    animal *aPtr = new animal(indstr, indbreedstr, indbirthdate, itbidstr, CONSTANTS::STRING_NA, CONSTANTS::STRING_NA, sexstr, indactivstr, indhbstr, inditbbreedstr, atoi(indnumstr.c_str()), atoi(damnumstr.c_str()), atoi(sirenumstr.c_str()), CONSTANTS::STRING_NA, CONSTANTS::STRING_NA);

    map<string,animal*>::iterator ait = this->find(indnumstr);
    if(ait == this->end()){
      (*this)[indnumstr] = aPtr;
    }
    else {
      cout<<"Numeric ID of animal "<<indnumstr<<" is already in the map with rrtdm-input. Something is wrong!";
      exit(1);
    }
  }


  datafile.close();

  cout<<"\nnumber of records on pedigree file: "<<rec<<endl;
  cout<<this->size()<<" total number of records stored in map."<<endl;

}


string animalMap::verifyBreed(string breedstr, string indstr){

  if(breedstr == "AN") {
    return "AN";
  }
  else if(breedstr =="SI") {
    return "SI";
  }
  else if(breedstr =="CH") {
    return "CH";
  }
  else if(breedstr =="LM") {
    return "LM";
  }
  else if(breedstr == "HH") {
    return "HH";
  }
  else{
    return CONSTANTS::STRING_NA;
  }

}


string animalMap::getSexWithITBid(string itbidstr){

  string sexstr;

  if(itbidstr != CONSTANTS::STRING_NA){
    sexstr = itbidstr.substr(5,1);
  }

  if(sexstr != "M" || sexstr != "F"){
    sexstr = CONSTANTS::STRING_NA;
  }

  return sexstr;

}


void animalMap::mergeInfoMaps(animalMap &aMap){

  cout<<"\nmergeInfoMaps()"<<endl;
  cout<<"*****************************************************************"<< endl;

  //pMap ist mit numerische Ids vom Vater und Mutter aufgebaut, der Rest sind Infos zu dem Tier.
  for(map<string,animal*>::iterator it = this->begin(); it != this->end();  it++){

    //outputDebug("mergeInfoMaps()_animal numeric id is  " + to_string(it->second->indDbIdLi) + " and animal TVD is" + it->second->indStr, it->second->indStr);

    //aMap ist mit den Daten von Tier aufgebaut. Numerische Ids sind auf missing gesetzt.
    map<string, animal*>::iterator itTVD = aMap.find(it->second->indStr);
    if(itTVD == aMap.end()){
      //outputDebug("mergeInfoMaps()_animal not found in aMap: " + it->second->indStr, it->second->indStr);
    }else{
      //Wenn ein Tier gefunden wird, werden die numerische Ids vom Vater und Mutter sowie interbullID des Tieres in aMap gespeichert.
      //outputDebug("mergeInfoMaps()_animal found in aMap, numeric id in pMap is it->second->indDbIdLi " + to_string(it->second->indDbIdLi) + " and numeric id in aMap is itTVD->second->indDbIdLi " + to_string(itTVD->second->indDbIdLi) + " of animal " + it->second->indStr, it->second->indStr);
      //outputDebug("mergeInfoMaps()_sire numeric id in pMap is it->second->sireDbIdLi " + to_string(it->second->sireDbIdLi) + " and sire id in aMap is itTVD->second->sireDbIdLi " + to_string(itTVD->second->sireDbIdLi) + " of animal " + it->second->indStr, it->second->indStr);
      //outputDebug("mergeInfoMaps()_dam numeric id in pMap is it->second->damDbIdLi " + to_string(it->second->damDbIdLi) + " and dam id in aMap is itTVD->second->damDbIdLi " + to_string(itTVD->second->damDbIdLi) + " of animal " + it->second->indStr, it->second->indStr);
      //outputDebug("mergeInfoMaps()_animal found in aMap, interbullID in pMap is it->second->itbidStr " + it->second->itbidStr + " and interbullID in aMap is itTVD->second->itbidStr " + itTVD->second->itbidStr + " of animal " + it->second->indStr, it->second->indStr);
      itTVD->second->indDbIdLi = it->second->indDbIdLi;
      itTVD->second->sireDbIdLi = it->second->sireDbIdLi;
      itTVD->second->damDbIdLi = it->second->damDbIdLi;
      itTVD->second->itbidStr = it->second->itbidStr;
      //outputDebug("mergeInfoMaps()_animal found in aMap, numeric id in pMap is it->second->indDbIdLi " + to_string(it->second->indDbIdLi) + " and setting numeric id in aMap is itTVD->second->indDbIdLi " + to_string(itTVD->second->indDbIdLi) + " of animal " + it->second->indStr, it->second->indStr);
      //outputDebug("mergeInfoMaps()_sire numeric id in pMap is it->second->sireDbIdLi " + to_string(it->second->sireDbIdLi) + " and setting sire id in aMap is itTVD->second->sireDbIdLi " + to_string(itTVD->second->sireDbIdLi) + " of animal " + it->second->indStr, it->second->indStr);
      //outputDebug("mergeInfoMaps()_dam numeric id in pMap is it->second->damDbIdLi " + to_string(it->second->damDbIdLi) + " and setting dam id in aMap is itTVD->second->damDbIdLi " + to_string(itTVD->second->damDbIdLi) + " of animal " + it->second->indStr, it->second->indStr);
      //outputDebug("mergeInfoMaps()_animal found in aMap, interbullID in pMap is it->second->itbidStr " + it->second->itbidStr + " and setting interbullID in aMap is itTVD->second->itbidStr " + itTVD->second->itbidStr + " of animal " + it->second->indStr, it->second->indStr);

      //Sobald, dass die numerische Id vom Vater in aMap gespeichert ist, wird in pMap TVDid und interbullID vom Vater gesucht und in aMap gespeichert.
      if(it->second->sireDbIdLi){
        map<string,animal*>::iterator sit = this->find(to_string(it->second->sireDbIdLi));
        if(sit == this->end()){
          //outputDebug("mergeInfoMaps()_sire numeric id not in pMap " + to_string(it->second->sireDbIdLi) + " of animal " + it->second->indStr, it->second->indStr);
          itTVD->second->sireStr = CONSTANTS::STRING_NA;
          itTVD->second->itbSireStr = CONSTANTS::STRING_NA;
          //outputDebug("mergeInfoMaps()_sire tvd is set in aMap to missing " + itTVD->second->sireStr + " , because sire numeric id is not in pMap" + " of animal " + it->second->indStr, it->second->indStr);
          //outputDebug("mergeInfoMaps()_sire itbid is set in aMap to missing " + itTVD->second->itbSireStr + " , because sire numeric id is not in pMap" + " of animal " + it->second->indStr, it->second->indStr);
        }else{
          //outputDebug("mergeInfoMaps()_sire numeric id in pMap is " + to_string(it->second->sireDbIdLi) + " and this TVD id in pMap is " + sit->second->indStr + " and in aMap is " + itTVD->second->sireStr + " of animal " + it->second->indStr, it->second->indStr);
          //outputDebug("mergeInfoMaps()_sire numeric id in pMap is " + to_string(it->second->sireDbIdLi) + " and this itb id in pMap is " + sit->second->itbidStr + " and in aMap is set to" + itTVD->second->itbSireStr + " of animal " + it->second->indStr, it->second->indStr);
          itTVD->second->sireStr = sit->second->indStr;
          itTVD->second->itbSireStr = sit->second->itbidStr;
          //outputDebug("mergeInfoMaps()_sire numeric id in pMap is " + to_string(it->second->sireDbIdLi) + " and this TVD id in pMap is " + sit->second->indStr + " and in aMap is set to" + itTVD->second->sireStr + " of animal " + it->second->indStr, it->second->indStr);
          //outputDebug("mergeInfoMaps()_sire numeric id in pMap is " + to_string(it->second->sireDbIdLi) + " and this itb id in pMap is " + sit->second->itbidStr + " and in aMap is set to" + itTVD->second->itbSireStr + " of animal " + it->second->indStr, it->second->indStr);
        }
      }else{
        itTVD->second->sireStr = CONSTANTS::STRING_NA;
        itTVD->second->itbSireStr = CONSTANTS::STRING_NA;
        //outputDebug("mergeInfoMaps()_sire numeric id not in pMap " + to_string(it->second->sireDbIdLi) + " therefore set the sire tvd to missing " + itTVD->second->sireStr + " of animal " + it->second->indStr, it->second->indStr);
        //outputDebug("mergeInfoMaps()_sire numeric id not in pMap " + to_string(it->second->sireDbIdLi) + " therefore set the sire itb to missing " + itTVD->second->itbSireStr + " of animal " + it->second->indStr, it->second->indStr);
      }

      if(it->second->damDbIdLi){
        map<string,animal*>::iterator dit = this->find(to_string(it->second->damDbIdLi));
        if(dit == this->end()){
          //outputDebug("mergeInfoMaps()_dam numeric id not in pMap " + to_string(it->second->damDbIdLi) + " of animal " + it->second->indStr, it->second->indStr);
          itTVD->second->damStr = CONSTANTS::STRING_NA;
          itTVD->second->itbDamStr = CONSTANTS::STRING_NA;
          //outputDebug("mergeInfoMaps()_dam tvd is set in aMap to missing " + itTVD->second->damStr + " , because dam numeric id is not in pMap" + " of animal " + it->second->indStr, it->second->indStr);
          //outputDebug("mergeInfoMaps()_dam itb is set in aMap to missing " + itTVD->second->itbDamStr + " , because dam numeric id is not in pMap" + " of animal " + it->second->indStr, it->second->indStr);
        }else{
          //outputDebug("mergeInfoMaps()_dam numeric id in pMap is " + to_string(it->second->damDbIdLi) + " and this TVD id in pMap is " + dit->second->indStr + " and in aMap is " + itTVD->second->damStr + " of animal " + it->second->indStr, it->second->indStr);
          //outputDebug("mergeInfoMaps()_dam numeric id in pMap is " + to_string(it->second->damDbIdLi) + " and this itb id in pMap is " + dit->second->itbidStr + " and in aMap is " + itTVD->second->itbDamStr + " of animal " + it->second->indStr, it->second->indStr);
          itTVD->second->damStr = dit->second->indStr;
          itTVD->second->itbDamStr = dit->second->itbidStr;
          //outputDebug("mergeInfoMaps()_dam numeric id in pMap is " + to_string(it->second->damDbIdLi) + " and this TVD id in pMap is " + dit->second->indStr + " and in aMap is set to" + itTVD->second->damStr + " of animal " + it->second->indStr, it->second->indStr);
          //outputDebug("mergeInfoMaps()_dam numeric id in pMap is " + to_string(it->second->damDbIdLi) + " and this itb id in pMap is " + dit->second->itbidStr + " and in aMap is " + itTVD->second->itbDamStr + " of animal " + it->second->indStr, it->second->indStr);
        }
      }else{
        itTVD->second->damStr = CONSTANTS::STRING_NA;
        itTVD->second->itbDamStr = CONSTANTS::STRING_NA;
        //outputDebug("mergeInfoMaps()_dam numeric id not in pMap " + to_string(it->second->damDbIdLi) + " therefore set the dam tvd to missing " + itTVD->second->damStr + " of animal " + it->second->indStr, it->second->indStr);
        //outputDebug("mergeInfoMaps()_dam numeric id not in pMap " + to_string(it->second->damDbIdLi) + " therefore set the dam itb to missing " + itTVD->second->itbDamStr + " of animal " + it->second->indStr, it->second->indStr);
      }

      if(itTVD->second->damStr ==""){
        itTVD->second->damStr = CONSTANTS::STRING_NA;
        itTVD->second->itbDamStr = CONSTANTS::STRING_NA;
      }

      if(itTVD->second->sireStr == ""){
        itTVD->second->sireStr = CONSTANTS::STRING_NA;
        itTVD->second->itbSireStr = CONSTANTS::STRING_NA;
      }

    }

  }

}


void animalMap::outputInterbeef605(string psBreed, string psTrait, animalMap &pMap){

  string itbBreed=convertBreed2InterbullBreed(psBreed);

  cout<<"\noutputInterbeef605(): WRITING 605-FILE FOR "<<itbBreed<<" AND "<<psTrait<<endl;
  cout<<"*****************************************************************"<< endl;


  ofstream datafile605("datafile605_"+itbBreed+"_"+psTrait);


}

