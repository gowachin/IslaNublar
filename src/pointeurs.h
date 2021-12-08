#ifndef __POINTEURS_H__
#define __POINTEURS_H__

#include <Rcpp.h>
using namespace Rcpp;

class Pointeurs
{
  public:
    // List prey, pred;
  // SEXP prey, pred;
  NumericVector prey, pred;
  NumericVector in_prey;
  int nbT;
  //constructor
  Pointeurs(NumericVector size_p, NumericVector gr_p, NumericVector Kp, NumericVector inter_pP,
           NumericVector size_P, NumericVector gr_P, NumericVector KP, NumericVector inter_Pp,
           int N, int verbose);
  //destructor
  ~Pointeurs();

  void Preyb(SEXP size_p, SEXP other, SEXP gr, SEXP K, SEXP inter_Pp, int t);
  // module pred
  void Pred(NumericVector size, NumericVector other, NumericVector gr,
            NumericVector K, NumericVector inter_Pp, int t);
};

#endif
