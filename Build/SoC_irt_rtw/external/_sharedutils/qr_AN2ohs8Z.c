/*
 * qr_AN2ohs8Z.c
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
#include "qr_AN2ohs8Z.h"
#include <string.h>
#include "xnrm2_BUFaA6pd.h"
#include "rt_hypotd_snf.h"
#include <math.h>
#include <emmintrin.h>
#include "xgemv_qp73QypX.h"
#include "xgerc_FRu4rrSR.h"

/* Function for MATLAB Function: '<S14>/updatePx' */
void qr_AN2ohs8Z(const real_T A[12], real_T b_Q[12], real_T R[4])
{
  __m128d tmp;
  real_T b_A[12];
  real_T tau[2];
  real_T work[2];
  real_T atmp;
  real_T b_A_0;
  real_T beta1;
  int32_T b_lastv;
  int32_T exitg1;
  int32_T ii;
  int32_T itau;
  int32_T knt;
  int32_T lastc;
  int32_T scalarLB;
  int32_T vectorUB;
  int32_T vectorUB_tmp;
  memcpy(&b_A[0], &A[0], 12U * sizeof(real_T));
  tau[0] = 0.0;
  work[0] = 0.0;
  tau[1] = 0.0;
  work[1] = 0.0;
  for (itau = 0; itau < 2; itau++) {
    ii = itau * 6 + itau;
    atmp = b_A[ii];
    b_lastv = ii + 2;
    tau[itau] = 0.0;
    beta1 = xnrm2_BUFaA6pd(5 - itau, b_A, ii + 2);
    if (beta1 != 0.0) {
      b_A_0 = b_A[ii];
      beta1 = rt_hypotd_snf(b_A_0, beta1);
      if (b_A_0 >= 0.0) {
        beta1 = -beta1;
      }

      if (fabs(beta1) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          lastc = (ii - itau) + 6;
          vectorUB = (((((lastc - ii) - 1) / 2) << 1) + ii) + 2;
          vectorUB_tmp = vectorUB - 2;
          for (scalarLB = b_lastv; scalarLB <= vectorUB_tmp; scalarLB += 2) {
            tmp = _mm_loadu_pd(&b_A[scalarLB - 1]);
            _mm_storeu_pd(&b_A[scalarLB - 1], _mm_mul_pd(tmp, _mm_set1_pd
              (9.9792015476736E+291)));
          }

          for (scalarLB = vectorUB; scalarLB <= lastc; scalarLB++) {
            b_A[scalarLB - 1] *= 9.9792015476736E+291;
          }

          beta1 *= 9.9792015476736E+291;
          atmp *= 9.9792015476736E+291;
        } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

        beta1 = rt_hypotd_snf(atmp, xnrm2_BUFaA6pd(5 - itau, b_A, ii + 2));
        if (atmp >= 0.0) {
          beta1 = -beta1;
        }

        tau[itau] = (beta1 - atmp) / beta1;
        atmp = 1.0 / (atmp - beta1);
        for (scalarLB = b_lastv; scalarLB <= vectorUB_tmp; scalarLB += 2) {
          tmp = _mm_loadu_pd(&b_A[scalarLB - 1]);
          _mm_storeu_pd(&b_A[scalarLB - 1], _mm_mul_pd(tmp, _mm_set1_pd(atmp)));
        }

        for (scalarLB = vectorUB; scalarLB <= lastc; scalarLB++) {
          b_A[scalarLB - 1] *= atmp;
        }

        for (b_lastv = 0; b_lastv < knt; b_lastv++) {
          beta1 *= 1.0020841800044864E-292;
        }

        atmp = beta1;
      } else {
        tau[itau] = (beta1 - b_A_0) / beta1;
        atmp = 1.0 / (b_A_0 - beta1);
        knt = (ii - itau) + 6;
        scalarLB = (((((knt - ii) - 1) / 2) << 1) + ii) + 2;
        vectorUB = scalarLB - 2;
        for (lastc = b_lastv; lastc <= vectorUB; lastc += 2) {
          tmp = _mm_loadu_pd(&b_A[lastc - 1]);
          _mm_storeu_pd(&b_A[lastc - 1], _mm_mul_pd(tmp, _mm_set1_pd(atmp)));
        }

        for (lastc = scalarLB; lastc <= knt; lastc++) {
          b_A[lastc - 1] *= atmp;
        }

        atmp = beta1;
      }
    }

    b_A[ii] = atmp;
    if (itau + 1 < 2) {
      b_A[ii] = 1.0;
      if (tau[0] != 0.0) {
        b_lastv = 6;
        knt = ii + 5;
        while ((b_lastv > 0) && (b_A[knt] == 0.0)) {
          b_lastv--;
          knt--;
        }

        knt = 1;
        lastc = ii;
        do {
          exitg1 = 0;
          if (lastc + 7 <= (ii + b_lastv) + 6) {
            if (b_A[lastc + 6] != 0.0) {
              exitg1 = 1;
            } else {
              lastc++;
            }
          } else {
            knt = 0;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      } else {
        b_lastv = 0;
        knt = 0;
      }

      if (b_lastv > 0) {
        xgemv_qp73QypX(b_lastv, knt, b_A, ii + 7, b_A, ii + 1, work);
        xgerc_FRu4rrSR(b_lastv, knt, -tau[0], ii + 1, work, b_A, ii + 7);
      }

      b_A[ii] = atmp;
    }
  }

  for (itau = 0; itau < 2; itau++) {
    for (ii = 0; ii <= itau; ii++) {
      R[ii + (itau << 1)] = b_A[6 * itau + ii];
    }

    if (itau + 2 <= 2) {
      R[(itau << 1) + 1] = 0.0;
    }

    work[itau] = 0.0;
  }

  for (ii = 1; ii >= 0; ii--) {
    b_lastv = (ii * 6 + ii) + 7;
    if (ii + 1 < 2) {
      b_A[b_lastv - 7] = 1.0;
      if (tau[ii] != 0.0) {
        knt = 6;
        lastc = b_lastv;
        while ((knt > 0) && (b_A[lastc - 2] == 0.0)) {
          knt--;
          lastc--;
        }

        lastc = 1;
        scalarLB = b_lastv;
        do {
          exitg1 = 0;
          if (scalarLB <= (b_lastv + knt) - 1) {
            if (b_A[scalarLB - 1] != 0.0) {
              exitg1 = 1;
            } else {
              scalarLB++;
            }
          } else {
            lastc = 0;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      } else {
        knt = 0;
        lastc = 0;
      }

      if (knt > 0) {
        xgemv_qp73QypX(knt, lastc, b_A, b_lastv, b_A, b_lastv - 6, work);
        xgerc_FRu4rrSR(knt, lastc, -tau[ii], b_lastv - 6, work, b_A, b_lastv);
      }
    }

    knt = (b_lastv - ii) - 1;
    scalarLB = (((((knt - b_lastv) + 6) / 2) << 1) + b_lastv) - 5;
    vectorUB = scalarLB - 2;
    for (lastc = b_lastv - 5; lastc <= vectorUB; lastc += 2) {
      tmp = _mm_loadu_pd(&b_A[lastc - 1]);
      _mm_storeu_pd(&b_A[lastc - 1], _mm_mul_pd(tmp, _mm_set1_pd(-tau[ii])));
    }

    for (lastc = scalarLB; lastc <= knt; lastc++) {
      b_A[lastc - 1] *= -tau[ii];
    }

    b_A[b_lastv - 7] = 1.0 - tau[ii];
    if (ii - 1 >= 0) {
      b_A[b_lastv - 8] = 0.0;
    }
  }

  for (ii = 0; ii < 6; ii++) {
    b_Q[ii] = b_A[ii];
    b_Q[ii + 6] = b_A[ii + 6];
  }
}
