/*
 * C:\Users\GERARD\Desktop\e-Tech\ETAS\Intecrio\slprj\irt\_sharedutils\xgeqp3_wlXEYd7k.c
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
#include "rt_hypotd_snf.h"
#include "xnrm2_5MGhfn4R.h"
#include "xnrm2_uObmRgAs.h"
#include "xgeqp3_wlXEYd7k.h"

/* Function for MATLAB Function: '<S135>/Kamm_Circle LatD' */
void xgeqp3_wlXEYd7k(real_T A[4], real_T tau[2], int32_T jpvt[2])
{
  real_T work[2];
  real_T vn1[2];
  int32_T pvt;
  real_T b_atmp;
  int32_T ix;
  real_T smax;
  int32_T iy;
  real_T xnorm;
  int32_T c_ix;
  int32_T d_ix;
  int32_T d;
  int32_T ijA;
  int32_T exitg1;
  boolean_T exitg2;
  jpvt[0] = 1;
  work[0] = 0.0;
  vn1[0] = xnrm2_uObmRgAs(A, 1);
  jpvt[1] = 2;
  work[1] = 0.0;
  vn1[1] = xnrm2_uObmRgAs(A, 3);
  pvt = 0;
  ix = 0;
  smax = fabs(vn1[0]);
  iy = 2;
  while (iy <= 2) {
    ix++;
    b_atmp = fabs(vn1[ix]);
    if (b_atmp > smax) {
      pvt = 1;
      smax = b_atmp;
    }

    iy = 3;
  }

  if (pvt + 1 != 1) {
    ix = pvt << 1;
    smax = A[ix];
    A[ix] = A[0];
    A[0] = smax;
    ix++;
    smax = A[ix];
    A[ix] = A[1];
    A[1] = smax;
    ix = jpvt[pvt];
    jpvt[pvt] = 1;
    jpvt[0] = ix;
  }

  b_atmp = A[0];
  smax = 0.0;
  xnorm = xnrm2_5MGhfn4R(1, A, 2);
  if (xnorm != 0.0) {
    xnorm = rt_hypotd_snf(A[0], xnorm);
    if (A[0] >= 0.0) {
      xnorm = -xnorm;
    }

    if (fabs(xnorm) < 1.0020841800044864E-292) {
      pvt = 0;
      do {
        pvt++;
        for (ix = 1; ix + 1 < 3; ix++) {
          A[ix] *= 9.9792015476736E+291;
        }

        xnorm *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

      xnorm = rt_hypotd_snf(b_atmp, xnrm2_5MGhfn4R(1, A, 2));
      if (b_atmp >= 0.0) {
        xnorm = -xnorm;
      }

      smax = (xnorm - b_atmp) / xnorm;
      b_atmp = 1.0 / (b_atmp - xnorm);
      for (ix = 1; ix + 1 < 3; ix++) {
        A[ix] *= b_atmp;
      }

      for (ix = 1; ix <= pvt; ix++) {
        xnorm *= 1.0020841800044864E-292;
      }

      b_atmp = xnorm;
    } else {
      smax = (xnorm - A[0]) / xnorm;
      b_atmp = 1.0 / (A[0] - xnorm);
      for (pvt = 1; pvt + 1 < 3; pvt++) {
        A[pvt] *= b_atmp;
      }

      b_atmp = xnorm;
    }
  }

  tau[0] = smax;
  A[0] = b_atmp;
  b_atmp = A[0];
  A[0] = 1.0;
  if (smax != 0.0) {
    pvt = 4;
    ix = 1;
    while ((pvt - 2 > 0) && (A[ix] == 0.0)) {
      pvt--;
      ix--;
    }

    ix = 1;
    exitg2 = false;
    while ((!exitg2) && (ix > 0)) {
      iy = 3;
      do {
        exitg1 = 0;
        if (iy <= pvt) {
          if (A[iy - 1] != 0.0) {
            exitg1 = 1;
          } else {
            iy++;
          }
        } else {
          ix = 0;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    pvt = 2;
    ix = 0;
  }

  if (pvt - 2 > 0) {
    if (ix != 0) {
      work[0] = 0.0;
      iy = 0;
      c_ix = 3;
      while (c_ix <= 3) {
        c_ix = 0;
        xnorm = 0.0;
        for (d_ix = 3; d_ix <= pvt; d_ix++) {
          xnorm += A[d_ix - 1] * A[c_ix];
          c_ix++;
        }

        work[iy] += xnorm;
        iy++;
        c_ix = 5;
      }
    }

    if (!(-smax == 0.0)) {
      iy = 0;
      c_ix = 0;
      d_ix = 1;
      while (d_ix <= ix) {
        if (work[c_ix] != 0.0) {
          xnorm = work[c_ix] * -smax;
          d_ix = 0;
          d = pvt + iy;
          for (ijA = iy + 2; ijA + 1 <= d; ijA++) {
            A[ijA] += A[d_ix] * xnorm;
            d_ix++;
          }
        }

        c_ix++;
        iy += 2;
        d_ix = 2;
      }
    }
  }

  A[0] = b_atmp;
  tau[1] = 0.0;
}
