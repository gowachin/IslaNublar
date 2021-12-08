#include <R.h>
#include <Rdefines.h>
#include <Rmath.h>
#include "hamond.h"

SEXP Profit(SEXP dino)
{
  SEXP p = PROTECT(allocVector(REALSXP, 1));
  REAL(p)[0] = INTEGER(dino)[0] * 0.42;
  Rprintf("Picsou!\n");
  UNPROTECT(1);
  return(p);
}

