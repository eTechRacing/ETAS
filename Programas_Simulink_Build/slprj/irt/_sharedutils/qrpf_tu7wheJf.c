/*
 * qrpf_tu7wheJf.c
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
#include "qrpf_tu7wheJf.h"
#include "xnrm2_5V7JofQH.h"
#include <math.h>
#include "rt_hypotd_snf.h"

/* Function for MATLAB Function: '<S137>/Kamm_Circle LatD' */
void qrpf_tu7wheJf(real_T A[12], int32_T ia0, int32_T m, int32_T n, real_T tau[3],
                   int32_T jpvt[3])
{
  real_T vn1[3];
  real_T vn2[3];
  real_T work[3];
  int32_T b_j;
  int32_T ia;
  int32_T ii_tmp;
  int32_T ix;
  int32_T iy;
  int32_T minmn;
  if (m <= n) {
    minmn = m;
  } else {
    minmn = n;
  }

  work[0] = 0.0;
  vn1[0] = 0.0;
  vn2[0] = 0.0;
  work[1] = 0.0;
  vn1[1] = 0.0;
  vn2[1] = 0.0;
  work[2] = 0.0;
  vn1[2] = 0.0;
  vn2[2] = 0.0;
  for (b_j = 0; b_j < n; b_j++) {
    vn1[b_j] = xnrm2_5V7JofQH(m, A, (b_j << 2) + ia0);
    vn2[b_j] = vn1[b_j];
  }

  for (b_j = 0; b_j < minmn; b_j++) {
    real_T s;
    real_T smax;
    int32_T c_j;
    int32_T ii;
    int32_T mmi;
    int32_T nmi;
    int32_T pvt;
    c_j = b_j + 1;
    ii_tmp = (b_j << 2) + ia0;
    ii = (ii_tmp + b_j) - 1;
    nmi = n - b_j;
    mmi = m - b_j;
    if (nmi < 1) {
      pvt = -1;
    } else {
      pvt = 0;
      if (nmi > 1) {
        ix = b_j;
        smax = fabs(vn1[b_j]);
        for (iy = 2; iy <= nmi; iy++) {
          ix++;
          s = fabs(vn1[ix]);
          if (s > smax) {
            pvt = iy - 1;
            smax = s;
          }
        }
      }
    }

    pvt += b_j;
    if (pvt + 1 != b_j + 1) {
      ix = ((pvt << 2) + ia0) - 1;
      iy = ii_tmp - 1;
      for (ii_tmp = 0; ii_tmp < m; ii_tmp++) {
        smax = A[ix];
        A[ix] = A[iy];
        A[iy] = smax;
        ix++;
        iy++;
      }

      ix = jpvt[pvt];
      jpvt[pvt] = jpvt[b_j];
      jpvt[b_j] = ix;
      vn1[pvt] = vn1[b_j];
      vn2[pvt] = vn2[b_j];
    }

    if (b_j + 1 < m) {
      s = A[ii];
      tau[b_j] = 0.0;
      if (mmi > 0) {
        smax = xnrm2_5V7JofQH(mmi - 1, A, ii + 2);
        if (smax != 0.0) {
          smax = rt_hypotd_snf(A[ii], smax);
          if (A[ii] >= 0.0) {
            smax = -smax;
          }

          if (fabs(smax) < 1.0020841800044864E-292) {
            pvt = 0;
            do {
              pvt++;
              ix = ii + mmi;
              for (iy = ii + 1; iy < ix; iy++) {
                A[iy] *= 9.9792015476736E+291;
              }

              smax *= 9.9792015476736E+291;
              s *= 9.9792015476736E+291;
            } while ((fabs(smax) < 1.0020841800044864E-292) && (pvt < 20));

            smax = rt_hypotd_snf(s, xnrm2_5V7JofQH(mmi - 1, A, ii + 2));
            if (s >= 0.0) {
              smax = -smax;
            }

            tau[b_j] = (smax - s) / smax;
            s = 1.0 / (s - smax);
            for (iy = ii + 1; iy < ix; iy++) {
              A[iy] *= s;
            }

            for (ix = 0; ix < pvt; ix++) {
              smax *= 1.0020841800044864E-292;
            }

            s = smax;
          } else {
            tau[b_j] = (smax - A[ii]) / smax;
            s = 1.0 / (A[ii] - smax);
            pvt = ii + mmi;
            for (ix = ii + 1; ix < pvt; ix++) {
              A[ix] *= s;
            }

            s = smax;
          }
        }
      }

      A[ii] = s;
    } else {
      tau[b_j] = 0.0;
    }

    if (b_j + 1 < n) {
      smax = A[ii];
      A[ii] = 1.0;
      if (tau[b_j] != 0.0) {
        boolean_T exitg2;
        pvt = mmi - 1;
        ix = (ii + mmi) - 1;
        while ((pvt + 1 > 0) && (A[ix] == 0.0)) {
          pvt--;
          ix--;
        }

        nmi -= 2;
        exitg2 = false;
        while ((!exitg2) && (nmi + 1 > 0)) {
          int32_T exitg1;
          ix = ((nmi << 2) + ii) + 5;
          iy = ix;
          do {
            exitg1 = 0;
            if (iy <= ix + pvt) {
              if (A[iy - 1] != 0.0) {
                exitg1 = 1;
              } else {
                iy++;
              }
            } else {
              nmi--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        pvt = -1;
        nmi = -1;
      }

      if (pvt + 1 > 0) {
        int32_T c_ix;
        int32_T e;
        if (nmi + 1 != 0) {
          for (ix = 0; ix <= nmi; ix++) {
            work[ix] = 0.0;
          }

          ix = 0;
          iy = ((nmi << 2) + ii) + 5;
          for (ii_tmp = ii + 5; ii_tmp <= iy; ii_tmp += 4) {
            c_ix = ii;
            s = 0.0;
            e = ii_tmp + pvt;
            for (ia = ii_tmp; ia <= e; ia++) {
              s += A[ia - 1] * A[c_ix];
              c_ix++;
            }

            work[ix] += s;
            ix++;
          }
        }

        if (!(-tau[b_j] == 0.0)) {
          ix = ii + 4;
          iy = 0;
          for (ii_tmp = 0; ii_tmp <= nmi; ii_tmp++) {
            if (work[iy] != 0.0) {
              s = work[iy] * -tau[b_j];
              c_ix = ii;
              e = ix;
              ia = pvt + ix;
              while (e + 1 <= ia + 1) {
                A[e] += A[c_ix] * s;
                c_ix++;
                e++;
              }
            }

            iy++;
            ix += 4;
          }
        }
      }

      A[ii] = smax;
    }

    while (c_j + 1 <= n) {
      ii = (ia0 + b_j) + (c_j << 2);
      if (vn1[c_j] != 0.0) {
        smax = fabs(A[ii - 1]) / vn1[c_j];
        smax = 1.0 - smax * smax;
        if (smax < 0.0) {
          smax = 0.0;
        }

        s = vn1[c_j] / vn2[c_j];
        s = s * s * smax;
        if (s <= 1.4901161193847656E-8) {
          if (b_j + 1 < m) {
            vn1[c_j] = xnrm2_5V7JofQH(mmi - 1, A, ii + 1);
            vn2[c_j] = vn1[c_j];
          } else {
            vn1[c_j] = 0.0;
            vn2[c_j] = 0.0;
          }
        } else {
          vn1[c_j] *= sqrt(smax);
        }
      }

      c_j++;
    }
  }
}
