#include <Rcpp.h>
#include "lotka.h"
#include "mod_prey.h"
#include "pointeurs.h"

using namespace Rcpp;

//' Costa
//'
//' Using the Volterra class with Rcpp
//'
//' @param prey list of initial size, gr, K and interactivity
//' @param pred list of initial size, gr, K and interactivity
//' @param n number of times
//' @export
// [[Rcpp::export]]
List Sorna(List prey, List pred,
           NumericVector n, bool verbose)
{
  // List l (2);
  int N = n[0];
  NumericVector size_p = prey[0];
  NumericVector gr_p = prey[1];
  NumericVector Kp = prey[2];
  NumericVector inter_pP = prey[3];

  NumericVector size_P = pred[0];
  NumericVector gr_P = pred[1];
  NumericVector KP = pred[2];
  NumericVector inter_Pp = pred[3];
  // Rprintf("in Cost \n");
  Pointeurs * object = new Pointeurs(size_p, gr_p, Kp, inter_pP,
                                   size_P, gr_P, KP, inter_Pp,
                                   N, verbose);
  // l[0] = object->prey;
  // l[1] = object->pred;
  return Rcpp::List::create(Rcpp::Named("prey") = object->prey,
                            Rcpp::Named("pred") = object->pred);
  // return l;
}

