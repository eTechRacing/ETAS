/*
 * polyfit_qSahpz3o.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control".
 *
 * Model version              : 10.1
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Fri Nov 17 17:17:31 2023
 * Created for block: Torque_Control
 */

#include "rtwtypes.h"
#include "polyfit_qSahpz3o.h"
#include "qrpf_X6HM2OpU.h"

/* Function for MATLAB Function: '<S152>/Kamm_Circle LatD' */
void polyfit_qSahpz3o(const real_T x[2], const real_T y[2], real_T p[2])
{
  real_T V[4];
  real_T B[2];
  real_T tau[2];
  real_T wj;
  int32_T jpvt[2];
  int32_T assumedRank;
  int32_T c_k;
  V[2] = 1.0;
  V[0] = x[0];
  B[0] = y[0];
  jpvt[0] = 1;
  tau[0] = 0.0;
  V[3] = 1.0;
  V[1] = x[1];
  B[1] = y[1];
  jpvt[1] = 2;
  tau[1] = 0.0;
  qrpf_X6HM2OpU(V, 1, 2, 2, tau, jpvt);
  assumedRank = -1;
  if (V[0] != 0.0) {
    assumedRank = 0;
  }

  if (V[3] != 0.0) {
    assumedRank++;
  }

  p[0] = 0.0;
  if (tau[0] != 0.0) {
    wj = (V[1] * y[1] + y[0]) * tau[0];
    if (wj != 0.0) {
      B[0] = y[0] - wj;
      B[1] = y[1] - V[1] * wj;
    }
  }

  p[1] = 0.0;
  if (tau[1] != 0.0) {
    wj = tau[1] * B[1];
    if (wj != 0.0) {
      B[1] -= wj;
    }
  }

  for (c_k = 0; c_k <= assumedRank; c_k++) {
    p[jpvt[c_k] - 1] = B[c_k];
  }

  while (assumedRank + 1 > 0) {
    int32_T p_tmp;
    p_tmp = assumedRank << 1;
    p[jpvt[assumedRank] - 1] /= V[p_tmp + assumedRank];
    for (c_k = 0; c_k < assumedRank; c_k++) {
      p[jpvt[c_k] - 1] -= V[p_tmp + c_k] * p[jpvt[assumedRank] - 1];
    }

    assumedRank--;
  }
}
