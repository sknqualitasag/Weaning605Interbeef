#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <Rcpp.h>
#include <plog/Log.h>


using namespace Rcpp;


enum{
SecondLog = 1,
};


// [[Rcpp::export]]
int Weaning605Interbeef_main(std::string paramFileName) {

  std::cout<<"Start Weaning605Interbeef_main"<<std::endl;

//  //Time tracking
//  std::chrono::time_point<std::chrono::system_clock> start, end;
//  start = std::chrono::system_clock::now();
//  time_t start_time = std::chrono::system_clock::to_time_t(start);
//
//
//
//  std::cout<<"-----------------------------------------------------------------"<< std::endl;
//  std::cout << "START Weaning605Interbeef_main() at " << std::ctime(&start_time) << std::endl;
//  std::cout<<"-----------------------------------------------------------------"<< std::endl;
//
//
//  //Time tracking
//  end = std::chrono::system_clock::now();
//  std::chrono::duration<double> elapsed_seconds = end-start;
//  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
//  std::cout<<"\n-----------------------------------------------------------------"<< std::endl;
//  std::cout << "END Weaning605Interbeef_main() at " << std::ctime(&end_time)
//            << "elapsed time: " << elapsed_seconds.count() << " s"<<std::endl;
//  std::cout<<"-----------------------------------------------------------------"<< std::endl;


  return 0;
}

//With RConsole ausführen
/*** R
Weaning605Interbeef_main()
  */
