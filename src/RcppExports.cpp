// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// timesTwo
NumericVector timesTwo(NumericVector x);
RcppExport SEXP _IslaNublar_timesTwo(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(timesTwo(x));
    return rcpp_result_gen;
END_RCPP
}
// Costa
List Costa(NumericVector size_p, NumericVector gr_p, NumericVector Kp, NumericVector inter_pP, NumericVector size_P, NumericVector gr_P, NumericVector KP, NumericVector inter_Pp, NumericVector n, bool verbose);
RcppExport SEXP _IslaNublar_Costa(SEXP size_pSEXP, SEXP gr_pSEXP, SEXP KpSEXP, SEXP inter_pPSEXP, SEXP size_PSEXP, SEXP gr_PSEXP, SEXP KPSEXP, SEXP inter_PpSEXP, SEXP nSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type size_p(size_pSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type gr_p(gr_pSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type Kp(KpSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type inter_pP(inter_pPSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type size_P(size_PSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type gr_P(gr_PSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type KP(KPSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type inter_Pp(inter_PpSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type n(nSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(Costa(size_p, gr_p, Kp, inter_pP, size_P, gr_P, KP, inter_Pp, n, verbose));
    return rcpp_result_gen;
END_RCPP
}

RcppExport SEXP Danger(SEXP, SEXP);
RcppExport SEXP Isla(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
RcppExport SEXP Profit(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_IslaNublar_timesTwo", (DL_FUNC) &_IslaNublar_timesTwo, 1},
    {"_IslaNublar_Costa", (DL_FUNC) &_IslaNublar_Costa, 10},
    {"Danger", (DL_FUNC) &Danger,  2},
    {"Isla",   (DL_FUNC) &Isla,   10},
    {"Profit", (DL_FUNC) &Profit,  1},
    {NULL, NULL, 0}
};

RcppExport void R_init_IslaNublar(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
