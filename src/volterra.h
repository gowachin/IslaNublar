#ifndef __VOLTERRA_H__
#define __VOLTERRA_H__

#include <Rcpp.h>
using namespace Rcpp;

class Volterra
{
  public:
    // List prey, pred;
    // SEXP prey, pred;
    NumericVector prey, pred;
    //constructor
    Volterra(NumericVector size_p, NumericVector gr_p, NumericVector Kp, NumericVector inter_pP,
             NumericVector size_P, NumericVector gr_P, NumericVector KP, NumericVector inter_Pp, int N);
    //destructor
    ~Volterra();

    void Preyb(SEXP size, SEXP other, SEXP gr, SEXP K, SEXP inter_pP, int t);
    // module pred
    void Pred(SEXP size, SEXP other, SEXP gr, SEXP K, SEXP inter_Pp, int t);
};

#endif