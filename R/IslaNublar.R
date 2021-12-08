#' Malcom
#'
#' just a citation to test package
#' @export
Malcom <- function() {
  cat("Life finds a way\n")
}


#' Park
#'
#' function calling a C++ function
#'
#' @param people int default = 0
#' @param dino int default = 0
#' @importFrom Rcpp evalCpp
#' @useDynLib IslaNublar, .registration = TRUE
#'
#' @export
Park <- function(people = 0, dino = 0){
  res <- .Call("Danger", people= as.integer(people), dino = as.integer(dino), PACKAGE = "IslaNublar")
  print(.Call("Profit", dino = as.integer(dino), PACKAGE = "IslaNublar"))
  # res = 42
  print(res)
}


#' Lotka-Voltera
#'
#' @param prey_t number of prey at t0
#' @param pred_t number of predator at t0
#' @param prey_gr prey growth rate
#' @param pred_gr pred growth rate
#' @param prey_K capacity for prey
#' @param pred_K capacity for pred
#' @param int_predprey interaction of pred on prey
#' @param int_preypred interaction of prey on pred
#' @param n number of times
#'
#' @useDynLib IslaNublar, .registration = TRUE
#'
#' @export
lotka <- function(prey_t, pred_t, prey_gr, pred_gr,
                  prey_K, pred_K,
                  int_predprey, int_preypred, n, verbose = FALSE){
  res <- .Call("Isla",
               size_p = as.numeric(prey_t), gr_p = as.numeric(prey_gr),
               Kp = as.numeric(prey_K), inter_pP = as.numeric(int_predprey),

               size_P = pred_t, gr_P = as.numeric(pred_gr),
               KP = as.numeric(pred_K), inter_Pp = as.numeric(int_preypred),
               n = as.integer(n), verbose = as.integer(verbose),
               PACKAGE = "IslaNublar")
  return(res)
}









