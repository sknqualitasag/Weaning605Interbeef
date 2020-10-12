//
//
//   Header for global constants
//

#ifndef Const_h
#define Const_h


class CONSTANTS {
public:
  //' ebv label for interbeef evaluation
  static const char EBV_LABEL[];
  //' number of columns of rrtdm-pedigree
  static const unsigned NUM_COL_RRTDM;
  //' number of columns of rrtdm-pedigree by missing informations
  static const unsigned NUM_COL_RRTDM_WITH_MISSING;
  // string corresponding to missing value code
  static const char STRING_NA[];
  //' missing value code as integer
  static const int INT_NA;
  // length of TVD-Nr in number of characters
  static const unsigned TVD_NR_LENGTH;
  //' length of ITB-Nr in number of characters
  static const unsigned ITB_NR_LENGTH;
  //' length of breed,country and sex code in ITB-NR
  static const unsigned BREED_COUNTRY_SEX_CODE_LENGTH;
  // number of characters that correspond to the country code
  static const unsigned COUNTRY_CODE_LENGTH;
  // string that corresponds to all letters
  static const char LETTERS[];





};

#endif
