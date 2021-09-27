#include <Rcpp.h>
#include "lotka.h"
#include "mod_prey.h"
#include "volterra.h"

using namespace Rcpp;

//' Double a value
//'
//' This will fucking work at least u motherf*cker
//'
//' @param x An integer vector
//' @export
// [[Rcpp::export]]
NumericVector timesTwo(NumericVector x) {
  return x * 2;
}

//' Costa
//'
//' Using the Lotka class with Rcpp
//'
//' @param x An integer vector
//' @export
// [[Rcpp::export]]
List Costa(NumericVector size_p, NumericVector gr_p,
          NumericVector Kp, NumericVector inter_pP,
          NumericVector size_P, NumericVector gr_P,
          NumericVector KP, NumericVector inter_Pp,
          NumericVector n)
{
  // List l (2);
  int N = n[0];
  // Rprintf("in Cost \n");
  Volterra * object = new Volterra(size_p, gr_p, Kp, inter_pP,
                                   size_P, gr_P, KP, inter_Pp,
                                   N);
  // l[0] = object->prey;
  // l[1] = object->pred;
  return Rcpp::List::create(Rcpp::Named("prey") = object->prey,
                      Rcpp::Named("pred") = object->pred);
  // return l;
}
