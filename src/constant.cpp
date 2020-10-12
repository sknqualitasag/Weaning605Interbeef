#include <Rcpp.h>
#include "constant.h"

using namespace Rcpp;

//' ebv label for interbeef evaluation
const char CONSTANTS::EBV_LABEL[] = "CH";
// number of columns of rrtdm-pedigree
const unsigned CONSTANTS::NUM_COL_RRTDM = 11;
// number of columns of rrtdm-pedigree by missing informations
const unsigned CONSTANTS::NUM_COL_RRTDM_WITH_MISSING = 9;
//' missing value code as string
const char CONSTANTS::STRING_NA[] = "-9999";
//' missing value code as integer
const int CONSTANTS::INT_NA = -9999;
//' length of TVD-Nr in number of characters
const unsigned CONSTANTS::TVD_NR_LENGTH = 14;
//' length of ITB-Nr in number of characters
const unsigned CONSTANTS::ITB_NR_LENGTH = 19;
//' length of breed,country and sex code in ITB-NR
const unsigned CONSTANTS::BREED_COUNTRY_SEX_CODE_LENGTH = 7;
//' length of country code in TVD-NR
const unsigned CONSTANTS::COUNTRY_CODE_LENGTH = 2;
//' all letters in a string
const char CONSTANTS::LETTERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


