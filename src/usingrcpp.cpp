#include <Rcpp.h>
#include "lotka.h"
using namespace Rcpp;

//[[Rcpp::plugins(cpp11)]]

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
  int N = n[0];

  Lotka * object = new Lotka(size_p, gr_p, Kp, inter_pP,
                             size_P, gr_P, KP, inter_Pp,
                             N);

  return List::create(object->prey, object->pred);
}
