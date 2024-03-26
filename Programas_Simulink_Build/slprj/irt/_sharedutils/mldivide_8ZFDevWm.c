/*
 * mldivide_8ZFDevWm.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control".
 *
 * Model version              : 10.23
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Tue Mar 26 15:41:33 2024
 * Created for block: Torque_Control
 */

#include "rtwtypes.h"
#include "mldivide_8ZFDevWm.h"
#include <string.h>
#include "qrpf_tu7wheJf.h"
#include <math.h>

/* Function for MATLAB Function: '<S137>/Kamm_Circle LatD' */
void mldivide_8ZFDevWm(const real_T A[12], const real_T B[4], real_T Y[3])
{
  real_T b_A[12];
  real_T b_B[4];
  real_T tau[3];
  real_T tol;
  int32_T jpvt[3];
  int32_T c_i;
  int32_T rankA;
  b_B[0] = B[0];
  b_B[1] = B[1];
  b_B[2] = B[2];
  b_B[3] = B[3];
  jpvt[0] = 1;
  jpvt[1] = 2;
  jpvt[2] = 3;
  memcpy(&b_A[0], &A[0], 12U * sizeof(real_T));
  tau[0] = 0.0;
  tau[1] = 0.0;
  tau[2] = 0.0;
  qrpf_tu7wheJf(b_A, 1, 4, 3, tau, jpvt);
  rankA = 0;
  tol = 8.8817841970012523E-15 * fabs(b_A[0]);
  while ((rankA < 3) && (!(fabs(b_A[(rankA << 2) + rankA]) <= tol))) {
    rankA++;
  }

  Y[0] = 0.0;
  if (tau[0] != 0.0) {
    tol = B[0];
    for (c_i = 1; c_i + 1 < 5; c_i++) {
      tol += b_A[c_i] * b_B[c_i];
    }

    tol *= tau[0];
    if (tol != 0.0) {
      b_B[0] = B[0] - tol;
      for (c_i = 1; c_i + 1 < 5; c_i++) {
        b_B[c_i] -= b_A[c_i] * tol;
      }
    }
  }

  Y[1] = 0.0;
  if (tau[1] != 0.0) {
    tol = b_B[1];
    for (c_i = 2; c_i + 1 < 5; c_i++) {
      tol += b_A[c_i + 4] * b_B[c_i];
    }

    tol *= tau[1];
    if (tol != 0.0) {
      b_B[1] -= tol;
      for (c_i = 2; c_i + 1 < 5; c_i++) {
        b_B[c_i] -= b_A[c_i + 4] * tol;
      }
    }
  }

  Y[2] = 0.0;
  if (tau[2] != 0.0) {
    tol = b_B[2];
    for (c_i = 3; c_i + 1 < 5; c_i++) {
      tol += b_A[c_i + 8] * b_B[c_i];
    }

    tol *= tau[2];
    if (tol != 0.0) {
      b_B[2] -= tol;
      for (c_i = 3; c_i + 1 < 5; c_i++) {
        b_B[c_i] -= b_A[c_i + 8] * tol;
      }
    }
  }

  for (c_i = 0; c_i < rankA; c_i++) {
    Y[jpvt[c_i] - 1] = b_B[c_i];
  }

  for (rankA--; rankA + 1 > 0; rankA--) {
    int32_T Y_tmp;
    Y_tmp = rankA << 2;
    Y[jpvt[rankA] - 1] /= b_A[Y_tmp + rankA];
    for (c_i = 0; c_i < rankA; c_i++) {
      Y[jpvt[c_i] - 1] -= b_A[Y_tmp + c_i] * Y[jpvt[rankA] - 1];
    }
  }
}
