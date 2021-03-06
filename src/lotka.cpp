#include <Rdefines.h>
#include <Rmath.h>
#include "hamond.h"
#include "lotka.h"
#include "mod_prey.h"

Lotka::Lotka(SEXP size_p, SEXP gr_p, SEXP Kp, SEXP inter_pP,
             SEXP size_P, SEXP gr_P, SEXP KP, SEXP inter_Pp, int N, int verbose){

  PROTECT(prey = allocVector(REALSXP, N +1));
  PROTECT(pred = allocVector(REALSXP, N +1));
  REAL(prey)[0] = REAL(size_p)[0];
  REAL(pred)[0] = REAL(size_P)[0];

  for(int t = 0; t < N ; t++){
    if(verbose && (t % 10) == 0) Rprintf("t = %i\n", t);
    Lotka::Prey(prey, pred, gr_p, Kp, inter_pP, t);
    Lotka::Pred(pred, prey, gr_P, KP, inter_Pp, t);
  }

  UNPROTECT(2);
}

void Lotka::Pred(SEXP size, SEXP other, SEXP gr, SEXP K, SEXP inter_Pp, int t){
  if(REAL(size)[t] <= 0){
    REAL(size)[t+1] = 0;
  } else {
    // REAL(size)[t+1] = REAL(size)[t] + REAL(size)[t] * REAL(gr)[0] *
    //   (1 - REAL(size)[t] / REAL(K)[0] ) + REAL(other)[t] * REAL(inter_Pp)[0];
    REAL(size)[t+1] = REAL(size)[t] + REAL(size)[t] * REAL(gr)[0] + REAL(size)[t] * REAL(other)[t] * REAL(inter_Pp)[0];
  }
}

extern "C" {
  SEXP Isla(SEXP size_p, SEXP gr_p, SEXP Kp, SEXP inter_pP,
            SEXP size_P, SEXP gr_P, SEXP KP, SEXP inter_Pp, SEXP n, SEXP verbose)
  {
    int N = INTEGER(n)[0];
    int VERBOSE = INTEGER(verbose)[0];
    SEXP output;

    Lotka * object = new Lotka(size_p, gr_p, Kp, inter_pP,
                               size_P, gr_P, KP, inter_Pp,
                               N, VERBOSE);

    PROTECT(output = allocVector(VECSXP, 2));
    SET_VECTOR_ELT(output, 0, object->prey);
    SET_VECTOR_ELT(output, 1, object->pred);

    UNPROTECT(1);
    return(output);
    delete object;
  }
}


extern "C" {
  SEXP Danger(SEXP people, SEXP dino)
  {
    SEXP s = PROTECT(allocVector(REALSXP, 1));
    REAL(s)[0] =  INTEGER(people)[0] * 6.6;
    REAL(s)[0] -= REAL(Profit(dino))[0];
    Rprintf("GrrrR\n");
    UNPROTECT(1);
    return(s);
  }
}

int main(){
  return 0;
}
