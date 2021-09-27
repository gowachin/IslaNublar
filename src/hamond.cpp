#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <R.h>
#include <Rdefines.h>
#include <Rmath.h>
#include "hamond.h"

using namespace std;

SEXP Profit(SEXP dino)
{
  SEXP p = PROTECT(allocVector(REALSXP, 1));
  REAL(p)[0] = INTEGER(dino)[0] * 0.42;
  Rprintf("Picsou!\n");
  UNPROTECT(1);
  return(p);
}

