/*
 * C:\Users\GERARD\Desktop\e-Tech\ETAS\Intecrio\slprj\irt\_sharedutils\xgeqp3_BPnHOoPT.c
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
#include "xnrm2_KgImAhi2.h"
#include "xnrm2_eCIH3nOp.h"
#include "xgeqp3_BPnHOoPT.h"

/* Function for MATLAB Function: '<S135>/Kamm_Circle LatD' */
void xgeqp3_BPnHOoPT(real_T A[12], real_T tau[3], int32_T jpvt[3])
{
  real_T work[3];
  real_T vn1[3];
  real_T vn2[3];
  int32_T k;
  int32_T i_i;
  int32_T pvt;
  int32_T ix;
  real_T smax;
  int32_T iy;
  real_T xnorm;
  int32_T coltop;
  int32_T ia;
  int32_T c_ix;
  real_T b_c;
  int32_T g;
  int32_T b_ia;
  int32_T d_ix;
  int32_T exitg1;
  boolean_T exitg2;
  jpvt[0] = 1;
  work[0] = 0.0;
  smax = xnrm2_KgImAhi2(A, 1);
  vn2[0] = smax;
  vn1[0] = smax;
  jpvt[1] = 2;
  work[1] = 0.0;
  smax = xnrm2_KgImAhi2(A, 5);
  vn2[1] = smax;
  vn1[1] = smax;
  jpvt[2] = 3;
  work[2] = 0.0;
  smax = xnrm2_KgImAhi2(A, 9);
  vn2[2] = smax;
  vn1[2] = smax;
  for (k = 0; k < 3; k++) {
    i_i = (k << 2) + k;
    pvt = 1;
    if (3 - k > 1) {
      ix = k;
      smax = fabs(vn1[k]);
      for (iy = 2; iy <= 3 - k; iy++) {
        ix++;
        b_c = fabs(vn1[ix]);
        if (b_c > smax) {
          pvt = iy;
          smax = b_c;
        }
      }
    }

    pvt = (k + pvt) - 1;
    if (pvt + 1 != k + 1) {
      ix = pvt << 2;
      iy = k << 2;
      smax = A[ix];
      A[ix] = A[iy];
      A[iy] = smax;
      ix++;
      iy++;
      smax = A[ix];
      A[ix] = A[iy];
      A[iy] = smax;
      ix++;
      iy++;
      smax = A[ix];
      A[ix] = A[iy];
      A[iy] = smax;
      ix++;
      iy++;
      smax = A[ix];
      A[ix] = A[iy];
      A[iy] = smax;
      ix = jpvt[pvt];
      jpvt[pvt] = jpvt[k];
      jpvt[k] = ix;
      vn1[pvt] = vn1[k];
      vn2[pvt] = vn2[k];
    }

    smax = A[i_i];
    b_c = 0.0;
    xnorm = xnrm2_eCIH3nOp(3 - k, A, i_i + 2);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(A[i_i], xnorm);
      if (A[i_i] >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        pvt = 0;
        ix = (i_i - k) + 4;
        do {
          pvt++;
          for (iy = i_i + 1; iy + 1 <= ix; iy++) {
            A[iy] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          smax *= 9.9792015476736E+291;
        } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

        xnorm = rt_hypotd_snf(smax, xnrm2_eCIH3nOp(3 - k, A, i_i + 2));
        if (smax >= 0.0) {
          xnorm = -xnorm;
        }

        b_c = (xnorm - smax) / xnorm;
        smax = 1.0 / (smax - xnorm);
        ix = (i_i - k) + 4;
        for (iy = i_i + 1; iy + 1 <= ix; iy++) {
          A[iy] *= smax;
        }

        for (ix = 1; ix <= pvt; ix++) {
          xnorm *= 1.0020841800044864E-292;
        }

        smax = xnorm;
      } else {
        b_c = (xnorm - A[i_i]) / xnorm;
        smax = 1.0 / (A[i_i] - xnorm);
        pvt = (i_i - k) + 4;
        for (ix = i_i + 1; ix + 1 <= pvt; ix++) {
          A[ix] *= smax;
        }

        smax = xnorm;
      }
    }

    tau[k] = b_c;
    A[i_i] = smax;
    if (k + 1 < 3) {
      smax = A[i_i];
      A[i_i] = 1.0;
      pvt = ((k + 1) << 2) + k;
      if (tau[k] != 0.0) {
        ix = 4 - k;
        iy = (i_i - k) + 3;
        while ((ix > 0) && (A[iy] == 0.0)) {
          ix--;
          iy--;
        }

        iy = 2 - k;
        exitg2 = false;
        while ((!exitg2) && (iy > 0)) {
          coltop = (((iy - 1) << 2) + pvt) + 1;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia <= (coltop + ix) - 1) {
              if (A[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia++;
              }
            } else {
              iy--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        ix = 0;
        iy = 0;
      }

      if (ix > 0) {
        if (iy != 0) {
          for (coltop = 1; coltop <= iy; coltop++) {
            work[coltop - 1] = 0.0;
          }

          coltop = 0;
          ia = (((iy - 1) << 2) + pvt) + 1;
          for (d_ix = pvt + 1; d_ix <= ia; d_ix += 4) {
            c_ix = i_i;
            b_c = 0.0;
            g = (d_ix + ix) - 1;
            for (b_ia = d_ix; b_ia <= g; b_ia++) {
              b_c += A[b_ia - 1] * A[c_ix];
              c_ix++;
            }

            work[coltop] += b_c;
            coltop++;
          }
        }

        if (!(-tau[k] == 0.0)) {
          coltop = 0;
          for (ia = 1; ia <= iy; ia++) {
            if (work[coltop] != 0.0) {
              b_c = work[coltop] * -tau[k];
              d_ix = i_i;
              c_ix = ix + pvt;
              for (g = pvt; g + 1 <= c_ix; g++) {
                A[g] += A[d_ix] * b_c;
                d_ix++;
              }
            }

            coltop++;
            pvt += 4;
          }
        }
      }

      A[i_i] = smax;
    }

    for (i_i = k + 1; i_i + 1 < 4; i_i++) {
      if (vn1[i_i] != 0.0) {
        smax = fabs(A[(i_i << 2) + k]) / vn1[i_i];
        smax = 1.0 - smax * smax;
        if (smax < 0.0) {
          smax = 0.0;
        }

        b_c = vn1[i_i] / vn2[i_i];
        b_c = b_c * b_c * smax;
        if (b_c <= 1.4901161193847656E-8) {
          vn1[i_i] = xnrm2_eCIH3nOp(3 - k, A, ((i_i << 2) + k) + 2);
          vn2[i_i] = vn1[i_i];
        } else {
          vn1[i_i] *= sqrt(smax);
        }
      }
    }
  }
}
