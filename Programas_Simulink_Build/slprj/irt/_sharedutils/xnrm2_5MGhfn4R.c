/*
 * C:\Users\joser\OneDrive\Documentos\GitHub\ETAS\Programas_Simulink_Build\slprj\irt\_sharedutils\xnrm2_5MGhfn4R.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control".
 *
 * Model version              : 1.182
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Nov 10 03:01:16 2023
 * Created for block: Torque_Control
 */

#include "rtwtypes.h"
#include <math.h>
#include "xnrm2_5MGhfn4R.h"

/* Function for MATLAB Function: '<S147>/Kamm_Circle LatD' */
real_T xnrm2_5MGhfn4R(int32_T n, const real_T x[4], int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (!(n < 1)) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}
