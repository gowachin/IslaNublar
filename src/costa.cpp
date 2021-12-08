#include <Rcpp.h>
#include "lotka.h"
#include "mod_prey.h"
#include "volterra.h"

using namespace Rcpp;

//' Costa
//'
//' Using the Volterra class with Rcpp
//'
//' @param size_p number of prey at t0
//' @param gr_p prey growth rate
//' @param Kp capacity for prey
//' @param inter_pP interaction of pred on prey
//' @param size_P number of predator at t0
//' @param gr_P pred growth rate
//' @param KP capacity for pred
//' @param inter_Pp interaction of prey on pred
//' @param n number of times
//' @export
// [[Rcpp::export]]
List Costa(NumericVector size_p, NumericVector gr_p,
          NumericVector Kp, NumericVector inter_pP,
          NumericVector size_P, NumericVector gr_P,
          NumericVector KP, NumericVector inter_Pp,
          NumericVector n, bool verbose)
{
  // List l (2);
  int N = n[0];
  // Rprintf("in Cost \n");
  Volterra * object = new Volterra(size_p, gr_p, Kp, inter_pP,
                                   size_P, gr_P, KP, inter_Pp,
                                   N, verbose);
  // l[0] = object->prey;
  // l[1] = object->pred;
  return Rcpp::List::create(Rcpp::Named("prey") = object->prey,
                      Rcpp::Named("pred") = object->pred);
  // return l;
}
