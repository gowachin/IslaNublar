#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <R.h>
#include <Rdefines.h>
#include <Rmath.h>
#include "lotka.h"
#include "mod_prey.h"

using namespace std;

extern "C"{
  void Lotka::Prey(SEXP size, SEXP other, SEXP gr, SEXP K, SEXP inter_pP, int t){
    if(REAL(size)[t] <= 0){
      REAL(size)[t+1] = 0;
    } else {
      // REAL(size)[t+1] = REAL(size)[t] + REAL(size)[t] * REAL(gr)[0] *
      //   (1 - REAL(size)[t] / REAL(K)[0] ) + REAL(other)[t] * REAL(inter_pP)[0];
      REAL(size)[t+1] = REAL(size)[t] + REAL(size)[t] * REAL(gr)[0] + REAL(size)[t] * REAL(other)[t] * REAL(inter_pP)[0];
    }
  }
}
