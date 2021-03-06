# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#' Costa
#'
#' Using the Volterra class with Rcpp
#'
#' @param size_p number of prey at t0
#' @param gr_p prey growth rate
#' @param Kp capacity for prey
#' @param inter_pP interaction of pred on prey
#' @param size_P number of predator at t0
#' @param gr_P pred growth rate
#' @param KP capacity for pred
#' @param inter_Pp interaction of prey on pred
#' @param n number of times
#' @export
Costa <- function(size_p, gr_p, Kp, inter_pP, size_P, gr_P, KP, inter_Pp, n, verbose) {
    .Call(`_IslaNublar_Costa`, size_p, gr_p, Kp, inter_pP, size_P, gr_P, KP, inter_Pp, n, verbose)
}

#' Costa
#'
#' Using the Volterra class with Rcpp
#'
#' @param prey list of initial size, gr, K and interactivity
#' @param pred list of initial size, gr, K and interactivity
#' @param n number of times
#' @export
Sorna <- function(prey, pred, n, verbose) {
    .Call(`_IslaNublar_Sorna`, prey, pred, n, verbose)
}

