#include <R.h>
#include <Rdefines.h>
#include <Rmath.h>
#include "lotka.h"
#include "mod_prey.h"

void Lotka::Prey(SEXP other, SEXP gr, SEXP K, SEXP inter_pP, int t){

  SEXP ans;
  double *rans;

  if(t == 0){
    PROTECT(ans = NEW_NUMERIC(N));
    prey = ans;
  }

  rans = REAL(prey);

  if(rans[t] <= 0){
    rans[t+1] = 0;
  } else {
    // REAL(size)[t+1] = REAL(size)[t] + REAL(size)[t] * REAL(gr)[0] *
    //   (1 - REAL(size)[t] / REAL(K)[0] ) + REAL(other)[t] * REAL(inter_pP)[0];
    rans[t+1] = rans[t] + rans[t] * REAL(gr)[0] + rans[t] * REAL(other)[t] * REAL(inter_pP)[0];
  }

  if(t == 0){ UNPROTECT(1); }
}

