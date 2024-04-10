/*
 * xgemv_qp73QypX.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SoC".
 *
 * Model version              : 13.0
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Apr 10 15:35:56 2024
 * Created for block: SoC
 */

#include "rtwtypes.h"
#include "xgemv_qp73QypX.h"
#include <string.h>
#include "div_nde_s32_floor.h"

/* Function for MATLAB Function: '<S14>/updatePx' */
void xgemv_qp73QypX(int32_T m, int32_T n, const real_T A[12], int32_T ia0, const
                    real_T x[12], int32_T ix0, real_T y[2])
{
  int32_T b_iy;
  int32_T iyend;
  if ((m != 0) && (n != 0)) {
    int32_T b;
    if (n - 1 >= 0) {
      memset(&y[0], 0, (uint32_T)n * sizeof(real_T));
    }

    b = (n - 1) * 6 + ia0;
    for (b_iy = ia0; b_iy <= b; b_iy += 6) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = (b_iy + m) - 1;
      for (iyend = b_iy; iyend <= d; iyend++) {
        c += x[((ix0 + iyend) - b_iy) - 1] * A[iyend - 1];
      }

      iyend = div_nde_s32_floor(b_iy - ia0, 6);
      y[iyend] += c;
    }
  }
}
