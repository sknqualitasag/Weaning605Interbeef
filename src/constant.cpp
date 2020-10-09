#include <Rcpp.h>
#include "constant.h"

using namespace Rcpp;

//' ebv label for interbeef evaluation
const char CONSTANTS::EBV_LABEL[] = "CH";
// number of columns of rrtdm-pedigree
const unsigned CONSTANTS::NUM_COL_RRTDM = 11;
// number of columns of rrtdm-pedigree by missing informations
const unsigned CONSTANTS::NUM_COL_RRTDM_WITH_MISSING = 9;

