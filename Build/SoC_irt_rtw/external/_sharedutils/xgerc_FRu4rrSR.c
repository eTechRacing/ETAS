/*
 * xgerc_FRu4rrSR.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SoC".
 *
 * Model version              : 13.3
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Apr 22 17:11:45 2024
 * Created for block: SoC
 */

#include "rtwtypes.h"
#include "xgerc_FRu4rrSR.h"

/* Function for MATLAB Function: '<S14>/updatePx' */
void xgerc_FRu4rrSR(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
                    real_T y[2], real_T A[12], int32_T ia0)
{
  int32_T ijA;
  int32_T j;
  if (!(alpha1 == 0.0)) {
    int32_T jA;
    jA = ia0;
    for (j = 0; j < n; j++) {
      real_T temp;
      temp = y[j];
      if (temp != 0.0) {
        int32_T b;
        temp *= alpha1;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA - 1] += A[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += 6;
    }
  }
}
