/*
 * C:\Users\GERARD\Desktop\e-Tech\ETAS\Intecrio\slprj\irt\_sharedutils\mldivide_u4svSR16.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control_ETR07".
 *
 * Model version              : 1.16
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Jun 17 19:17:38 2022
 * Created for block: Torque_Control_ETR07
 */

#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "xgeqp3_BPnHOoPT.h"
#include "mldivide_u4svSR16.h"

/* Function for MATLAB Function: '<S135>/Kamm_Circle LatD' */
void mldivide_u4svSR16(const real_T A[12], const real_T B[4], real_T Y[3])
{
  real_T b_A[12];
  real_T tau[3];
  int32_T jpvt[3];
  int32_T rankR;
  real_T tol;
  real_T b_B[4];
  int32_T c_i;
  memcpy(&b_A[0], &A[0], 12U * sizeof(real_T));
  xgeqp3_BPnHOoPT(b_A, tau, jpvt);
  rankR = 0;
  tol = 4.0 * fabs(b_A[0]) * 2.2204460492503131E-16;
  while ((rankR < 3) && (!(fabs(b_A[(rankR << 2) + rankR]) <= tol))) {
    rankR++;
  }

  Y[0] = 0.0;
  Y[1] = 0.0;
  Y[2] = 0.0;
  b_B[0] = B[0];
  b_B[1] = B[1];
  b_B[2] = B[2];
  b_B[3] = B[3];
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

  for (c_i = 0; c_i + 1 <= rankR; c_i++) {
    Y[jpvt[c_i] - 1] = b_B[c_i];
  }

  for (rankR--; rankR + 1 > 0; rankR--) {
    Y[jpvt[rankR] - 1] /= b_A[(rankR << 2) + rankR];
    for (c_i = 0; c_i + 1 <= rankR; c_i++) {
      Y[jpvt[c_i] - 1] -= b_A[(rankR << 2) + c_i] * Y[jpvt[rankR] - 1];
    }
  }
}
