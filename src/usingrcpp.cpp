#include <Rcpp.h>
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

