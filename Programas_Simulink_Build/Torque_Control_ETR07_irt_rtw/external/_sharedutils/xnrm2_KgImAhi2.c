/*
 * C:\Users\Adrian Newey\Documents\ETAS\ETR07\Modelos Matlab\slprj\irt\_sharedutils\xnrm2_KgImAhi2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control_ETR07".
 *
 * Model version              : 1.3
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Tue Apr 12 15:34:12 2022
 * Created for block: Torque_Control_ETR07
 */

#include "rtwtypes.h"
#include <math.h>
#include "xnrm2_KgImAhi2.h"

/* Function for MATLAB Function: '<S123>/Kamm_Circle LatD' */
real_T xnrm2_KgImAhi2(const real_T x[12], int32_T ix0)
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = ix0; k <= ix0 + 3; k++) {
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

  return scale * sqrt(y);
}
