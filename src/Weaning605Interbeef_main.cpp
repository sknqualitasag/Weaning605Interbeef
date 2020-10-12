#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <Rcpp.h>
#include <plog/Log.h>
#include "parmMap.h"
#include "animalMap.h"
#include "bloodMap.h"
#include "constant.h"



using namespace Rcpp;


enum{
SecondLog = 1,
};


// [[Rcpp::export]]
int Weaning605Interbeef_main(std::string paramFileName) {

  //Time tracking
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  time_t start_time = std::chrono::system_clock::to_time_t(start);



  std::cout<<"-----------------------------------------------------------------"<< std::endl;
  std::cout << "START Weaning605Interbeef_main() at " << std::ctime(&start_time) << std::endl;
  std::cout<<"-----------------------------------------------------------------"<< std::endl;

  std::cout<<"ParameterFile = "<<paramFileName<<std::endl;
  ParmMap parmMap;
  parmMap.fileName = paramFileName;
  parmMap.inputParms();

  std::string dataFile  							        = parmMap.getString("dataFileName");
  std::string bloodFile							          = parmMap.getString("bloodFileName");
  std::string bloodFileReformattted	          = bloodFile+".reformatted";
  std::string pedigreeFile							      = parmMap.getString("pedigreeFileName");
  std::string pedigreeFileReformatted     	  = pedigreeFile+".reformatted";
  std::string parRunMode                      = parmMap.getString("DEBUG");
  std::string parRunModeFile                  = parmMap.getString("DEBUGFile");



  animalMap aMap;
  animalMap pMap;

  //Read blood composite file
  bloodMap bMap;
  bMap.setRunningMode(CONSTANTS::RUNNING_DEBUGALL);
  bMap.makeReadableBloodComposite(bloodFile, bloodFileReformattted);
  aMap.BreedComposite = bMap;

  //Sophie: Falls Fehler auftretten oder als Hilfe für die Entwicklung
  if (parRunMode == CONSTANTS::DEBUG){
    plog::init(plog::debug, "DEBUG_Weaning605Interbeef_Output.txt"); //Sophie
    aMap.setRunningMode(CONSTANTS::RUNNING_DEBUG);
    aMap.inputDebug(parRunModeFile);
  }
  else if(parRunMode == CONSTANTS::DEBUGALL){
    plog::init(plog::debug, "DEBUG_Weaning605Interbeef_Output.txt"); //Sophie
    aMap.setRunningMode(CONSTANTS::RUNNING_DEBUGALL);
  }
  else {
    aMap.setRunningMode(CONSTANTS::RUNNING_ROUTINE);
  }

  //Read data file
  aMap.inputData(dataFile);

//Read pedigree file
  pMap.makeReadableRRTDMPedigree(pedigreeFile,pedigreeFileReformatted);
  pMap.readRRTDMPedigree(pedigreeFileReformatted);


  //Create a sire map

  //Prepare 605 Interbeef file

  //Time tracking
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout<<"\n-----------------------------------------------------------------"<< std::endl;
  std::cout << "END Weaning605Interbeef_main() at " << std::ctime(&end_time)
            << "elapsed time: " << elapsed_seconds.count() << " s"<<std::endl;
  std::cout<<"-----------------------------------------------------------------"<< std::endl;


  return 0;
}

//With RConsole ausführen
/*** R
Weaning605Interbeef_main()
  */
