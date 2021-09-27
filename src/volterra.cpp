#include <Rcpp.h>
#include "volterra.h"
// #include "mod_prey.h"

using namespace Rcpp;

Volterra::Volterra(NumericVector size_p, NumericVector gr_p, NumericVector Kp, NumericVector inter_pP,
                   NumericVector size_P, NumericVector gr_P, NumericVector KP, NumericVector inter_Pp, int N)
{
  NumericVector in_prey (N+1);
  in_prey[0] = size_p[0];
  // Two ways to achieve this, either define intern vector and apply with this
  // or push_back the vector for each iteration (memory heavy process)
  pred.push_back(size_P[0]);
  for(int t = 0; t < N ; t++){
    pred.push_back(0);
    Volterra::Preyb(in_prey, pred, gr_p, Kp, inter_pP, t);
    // Rprintf("Prey %0.f", in_prey[t]);
    Volterra::Pred(pred, in_prey, gr_P, KP, inter_Pp, t);
    // Rprintf("Pred %0.f\n", pred[t]);
  }
  this->prey = in_prey;
}

void Volterra::Pred(SEXP size, SEXP other, SEXP gr, SEXP K, SEXP inter_Pp, int t){
  if(REAL(size)[t] <= 0){
    REAL(size)[t+1] = 0;
  } else {
    // REAL(size)[t+1] = REAL(size)[t] + REAL(size)[t] * REAL(gr)[0] *
    //   (1 - REAL(size)[t] / REAL(K)[0] ) + REAL(other)[t] * REAL(inter_Pp)[0];
    REAL(size)[t+1] = REAL(size)[t] + REAL(size)[t] * REAL(gr)[0] + REAL(size)[t] * REAL(other)[t] * REAL(inter_Pp)[0];
  }
}

void Volterra::Preyb(SEXP size, SEXP other, SEXP gr, SEXP K, SEXP inter_pP, int t){
  if(REAL(size)[t] <= 0){
    REAL(size)[t+1] = 0;
  } else {
    // REAL(size)[t+1] = REAL(size)[t] + REAL(size)[t] * REAL(gr)[0] *
    //   (1 - REAL(size)[t] / REAL(K)[0] ) + REAL(other)[t] * REAL(inter_Pp)[0];
    REAL(size)[t+1] = REAL(size)[t] + REAL(size)[t] * REAL(gr)[0] + REAL(size)[t] * REAL(other)[t] * REAL(inter_pP)[0];
  }
}
