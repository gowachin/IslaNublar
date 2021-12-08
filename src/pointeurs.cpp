#include <Rcpp.h>
#include "pointeurs.h"

  using namespace Rcpp;

Pointeurs::Pointeurs(NumericVector size_p, NumericVector gr_p, NumericVector Kp, NumericVector inter_pP,
                   NumericVector size_P, NumericVector gr_P, NumericVector KP, NumericVector inter_Pp,
                   int N, int verbose = 0)
{
  nbT = N+1;
  // Two ways to achieve this, either define intern vector and apply with this
  // or push_back the vector for each iteration (memory heavy process)
  pred.push_back(size_P[0]);
  for(int t = 0; t < N ; t++){
    if(verbose){
      Rprintf("t = %i\n", t);
    }
    pred.push_back(0);
    Pointeurs::Preyb(size_p, pred, gr_p, Kp, inter_pP, t);
    Rprintf("Prey %0.f", in_prey[t]);
    Pointeurs::Pred(pred, in_prey, gr_P, KP, inter_Pp, t);
    // Rprintf("Pred %0.f\n", pred[t]);
  }
  this->prey = in_prey;
}

void Pointeurs::Pred(NumericVector size, NumericVector other, NumericVector gr,
                    NumericVector K, NumericVector inter_Pp, int t){
  if(size[t] <= 0){
    size[t+1] = 0;
  } else {
    // REAL(size)[t+1] = REAL(size)[t] + REAL(size)[t] * REAL(gr)[0] *
      //   (1 - REAL(size)[t] / REAL(K)[0] ) + REAL(other)[t] * REAL(inter_Pp)[0];
    size[t+1] = size[t] +size[t] * gr[0] + size[t] * other[t] * inter_Pp[0];
    // modified to use Rcpp format, this is easier to read.
  }
}


void Pointeurs::Preyb(SEXP size_p, SEXP other, SEXP gr, SEXP K, SEXP inter_pP, int t){

  SEXP ans;
  int nbT = 5;
  // double *pres;

  // if(t == 0){
  // PROTECT(ans = allocVector(REALSXP, nbT));
  // PROTECT(ans = NEW_NUMERIC(nbT));
  //   //   // Rprintf("what is it ? %d", LENGTH(ans));
  //   //   // setAttrib(ans, R_NamesSymbol, times);
  //   //   // SET_VECTOR_ELT(in_prey, e, ans);
  // }
  //   // // pres = REAL(in_prey);
  //   // // Rprintf(" - point %d - val : %d %d\n", pres, pres[t], &pres[t]);
  //   // //
  //   // // if(pres[t] <= 0){
  //   // //   pres[t+1] = 0;
  //   // // } else {
  //   // //   pres[t+1] = pres[t] + pres[t] * REAL(gr)[0] + pres[t] * REAL(other)[t] * REAL(inter_pP)[0];
  //   // // }
  //   //
  // if (t==0) UNPROTECT(1);
}
