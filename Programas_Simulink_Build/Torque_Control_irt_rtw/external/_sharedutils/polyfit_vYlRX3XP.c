/*
 * C:\Users\dwegg\Desktop\ETAS-main\ETAS\Programas_Simulink_Build\slprj\irt\_sharedutils\polyfit_vYlRX3XP.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control".
 *
 * Model version              : 1.181
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Mar 29 13:03:35 2023
 * Created for block: Torque_Control
 */

#include "rtwtypes.h"
#include "xgeqp3_wlXEYd7k.h"
#include "polyfit_vYlRX3XP.h"

/* Function for MATLAB Function: '<S147>/Kamm_Circle LatD' */
void polyfit_vYlRX3XP(const real_T x[2], const real_T y[2], real_T p[2])
{
  real_T V[4];
  real_T tau[2];
  int32_T jpvt[2];
  real_T wj;
  int32_T c_i;
  real_T B_idx_0;
  real_T B_idx_1;
  V[2] = 1.0;
  V[0] = x[0];
  V[3] = 1.0;
  V[1] = x[1];
  xgeqp3_wlXEYd7k(V, tau, jpvt);
  p[0] = 0.0;
  B_idx_0 = y[0];
  p[1] = 0.0;
  B_idx_1 = y[1];
  if (tau[0] != 0.0) {
    wj = y[0];
    c_i = 2;
    while (c_i < 3) {
      wj += V[1] * B_idx_1;
      c_i = 3;
    }

    wj *= tau[0];
    if (wj != 0.0) {
      B_idx_0 = y[0] - wj;
      c_i = 2;
      while (c_i < 3) {
        B_idx_1 -= V[1] * wj;
        c_i = 3;
      }
    }
  }

  p[jpvt[0] - 1] = B_idx_0;
  if (tau[1] != 0.0) {
    wj = tau[1] * B_idx_1;
    if (wj != 0.0) {
      B_idx_1 -= wj;
    }
  }

  p[jpvt[1] - 1] = B_idx_1;
  p[jpvt[1] - 1] /= V[3];
  c_i = 1;
  while (c_i <= 1) {
    p[jpvt[0] - 1] -= p[jpvt[1] - 1] * V[2];
    c_i = 2;
  }

  p[jpvt[0] - 1] /= V[0];
}
