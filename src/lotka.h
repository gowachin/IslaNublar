#ifndef __LOTKA_H__
#define __LOTKA_H__

// #include <Rcpp.h>
// using namespace Rcpp;

class Lotka
{
  public:
    SEXP prey, pred;
    //constructeur
    Lotka(SEXP size_p, SEXP gr_p, SEXP Kp, SEXP inter_pP,
         SEXP size_P, SEXP gr_P, SEXP KP, SEXP inter_Pp, int N);

    //destructeur
    ~Lotka();

    // here is 2 module but they are similar in equation here
    // module prey
    void Prey(SEXP size, SEXP other, SEXP gr, SEXP K, SEXP inter_pP, int t);
    // module pred
    void Pred(SEXP size, SEXP other, SEXP gr, SEXP K, SEXP inter_Pp, int t);
};

// class Volterra
// {
//   public:
//     // NumericVector prey, pred;
//     //constructor
//     Volterra(double size_p, double gr_p, double Kp, double inter_pP,
//              double size_P, double gr_P, double KP, double inter_Pp, int N);
//     //destructor
//     ~Volterra();
//
//     void Preyb(SEXP size, SEXP other, SEXP gr, SEXP K, SEXP inter_pP, int t);
//     // module pred
//     void Pred(SEXP size, SEXP other, SEXP gr, SEXP K, SEXP inter_Pp, int t);
// };

#endif
