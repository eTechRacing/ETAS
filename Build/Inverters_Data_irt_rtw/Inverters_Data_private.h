/*
 * Inverters_Data_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Inverters_Data".
 *
 * Model version              : 13.21
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Jul 29 16:11:39 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Inverters_Data_private_h_
#define RTW_HEADER_Inverters_Data_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Inverters_Data_types.h"
#include "Inverters_Data.h"

extern const real_T rtCP_pooled_mpFrepPHolRC[100];
extern const real_T rtCP_pooled_WBlvnMM8xbHh[100];
extern const real_T rtCP_pooled_PuC9JhhY74Rz[54];
extern const real_T rtCP_pooled_JOqMvXAXZOeU[54];

#define rtCP_uDLookupTable_tableData   rtCP_pooled_mpFrepPHolRC  /* Expression: [-10.01	-8.877	-7.746	-6.701	-5.57	-4.439	-3.307	-2.263	-1.131	0	1.131	2.176	3.307	4.439	5.57	6.701	7.746	8.877	10.01	11.14	12.18	13.32	14.45	15.58	16.62	17.75	18.89	20.02	21.06	22.19	23.32	24.46	25.59	26.63	27.76	28.89	30.03	31.07	32.20	33.33	34.46	35.51	36.64	37.77	38.90	40.03	41.08	42.21	43.34	44.47	45.52	46.65	47.78	48.91	49.96	51.09	52.22	53.35	54.48	55.53	56.66	57.79	58.92	59.97	61.10	62.23	63.36	64.40	65.54	66.67	67.80	68.93	69.97	71.11	72.24	73.37	74.41	75.54	76.68	77.81	78.85	79.98	81.11	82.25	83.29	84.42	85.55	86.68	87.82	88.86	89.99	91.12	92.25	93.30	94.43	95.56	96.69	97.74	98.87	100]
                                                                  * Referenced by: '<S8>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data    rtCP_pooled_WBlvnMM8xbHh  /* Expression: [15610	15640	15680	15730	15780	15830	15880	15910	15960	16000	16070	16130	16180	16250	16320	16390	16440	16520	16590	16670	16740	16810	16890	16980	17060	17150	17230	17330	17440	17520	17620	17720	17830	17930	18030	18130	18250	18350	18470	18590	18690	18810	18940	19060	19180	19300	19420	19550	19690	19810	19940	20080	20210	20330	20470	20600	20740	20870	21020	21160	21300	21410	21550	21680	21820	21960	22110	22240	22380	22510	22650	22790	22920	23060	23190	23330	23460	23580	23720	23830	23970	24090	24210	24340	24460	24580	24700	24820	24930	25050	25170	25290	25390	25510	25630	25730	25830	25930	26040	26140]
                                                                  * Referenced by: '<S8>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData_e rtCP_pooled_mpFrepPHolRC  /* Expression: [-10.01	-8.877	-7.746	-6.701	-5.57	-4.439	-3.307	-2.263	-1.131	0	1.131	2.176	3.307	4.439	5.57	6.701	7.746	8.877	10.01	11.14	12.18	13.32	14.45	15.58	16.62	17.75	18.89	20.02	21.06	22.19	23.32	24.46	25.59	26.63	27.76	28.89	30.03	31.07	32.20	33.33	34.46	35.51	36.64	37.77	38.90	40.03	41.08	42.21	43.34	44.47	45.52	46.65	47.78	48.91	49.96	51.09	52.22	53.35	54.48	55.53	56.66	57.79	58.92	59.97	61.10	62.23	63.36	64.40	65.54	66.67	67.80	68.93	69.97	71.11	72.24	73.37	74.41	75.54	76.68	77.81	78.85	79.98	81.11	82.25	83.29	84.42	85.55	86.68	87.82	88.86	89.99	91.12	92.25	93.30	94.43	95.56	96.69	97.74	98.87	100]
                                                                  * Referenced by: '<S9>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_g  rtCP_pooled_WBlvnMM8xbHh  /* Expression: [15610	15640	15680	15730	15780	15830	15880	15910	15960	16000	16070	16130	16180	16250	16320	16390	16440	16520	16590	16670	16740	16810	16890	16980	17060	17150	17230	17330	17440	17520	17620	17720	17830	17930	18030	18130	18250	18350	18470	18590	18690	18810	18940	19060	19180	19300	19420	19550	19690	19810	19940	20080	20210	20330	20470	20600	20740	20870	21020	21160	21300	21410	21550	21680	21820	21960	22110	22240	22380	22510	22650	22790	22920	23060	23190	23330	23460	23580	23720	23830	23970	24090	24210	24340	24460	24580	24700	24820	24930	25050	25170	25290	25390	25510	25630	25730	25830	25930	26040	26140]
                                                                  * Referenced by: '<S9>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData_p rtCP_pooled_PuC9JhhY74Rz  /* Expression: [1.31000000000000	7.10000000000000	9.99000000000000	15.2000000000000	18.1000000000000	23.9000000000000	29.1000000000000	32	34.9000000000000	40.1000000000000	45.9000000000000	50.5000000000000	55.7000000000000	60.4000000000000	62.7000000000000	66.7000000000000	69	71.4000000000000	75.4000000000000	77.7000000000000	80	81.8000000000000	83.5000000000000	85.2000000000000	87	88.7000000000000	93.3000000000000	95.1000000000000	100	101	103	108	110	112	114	119	121	123	125	126	128	130	132	133	135	137	143	144	146	152	154	159	165	168]
                                                                  * Referenced by: '<S7>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_d  rtCP_pooled_JOqMvXAXZOeU  /* Expression: [3788.96122400000	3945.57846400000	4023.49466600000	4178.54223400000	4249.74970600000	4403.26785000000	4555.73954600000	4631.58297600000	4701.36009600000	4851.77914400000	5001.15174400000	5143.79239400000	5291.11234600000	5437.38585000000	5504.54375400000	5649.28783400000	5721.26745600000	5792.98546600000	5930.16941600000	6001.12271400000	6071.81440000000	6142.24447400000	6207.02465000000	6276.95162400000	6346.61698600000	6416.02073600000	6548.75418600000	6617.39322400000	6712	6816.53040000000	6868.56340000000	7075.14740000000	7126.40640000000	7228.46000000000	7279.25460000000	7480.88500000000	7530.90560000000	7580.77140000000	7680.03860000000	7729.44000000000	7778.68660000000	7827.77840000000	7925.49760000000	7974.12500000000	8022.59760000000	8119.07840000000	8262.63860000000	8357.57140000000	8404.80560000000	8592.19440000000	8638.65460000000	8822.94740000000	8914.16500000000	9004.76340000000]
                                                                  * Referenced by: '<S7>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData_a rtCP_pooled_PuC9JhhY74Rz  /* Expression: [1.31000000000000	7.10000000000000	9.99000000000000	15.2000000000000	18.1000000000000	23.9000000000000	29.1000000000000	32	34.9000000000000	40.1000000000000	45.9000000000000	50.5000000000000	55.7000000000000	60.4000000000000	62.7000000000000	66.7000000000000	69	71.4000000000000	75.4000000000000	77.7000000000000	80	81.8000000000000	83.5000000000000	85.2000000000000	87	88.7000000000000	93.3000000000000	95.1000000000000	100	101	103	108	110	112	114	119	121	123	125	126	128	130	132	133	135	137	143	144	146	152	154	159	165	168]
                                                                  * Referenced by: '<S10>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_o  rtCP_pooled_JOqMvXAXZOeU  /* Expression: [3788.96122400000	3945.57846400000	4023.49466600000	4178.54223400000	4249.74970600000	4403.26785000000	4555.73954600000	4631.58297600000	4701.36009600000	4851.77914400000	5001.15174400000	5143.79239400000	5291.11234600000	5437.38585000000	5504.54375400000	5649.28783400000	5721.26745600000	5792.98546600000	5930.16941600000	6001.12271400000	6071.81440000000	6142.24447400000	6207.02465000000	6276.95162400000	6346.61698600000	6416.02073600000	6548.75418600000	6617.39322400000	6712	6816.53040000000	6868.56340000000	7075.14740000000	7126.40640000000	7228.46000000000	7279.25460000000	7480.88500000000	7530.90560000000	7580.77140000000	7680.03860000000	7729.44000000000	7778.68660000000	7827.77840000000	7925.49760000000	7974.12500000000	8022.59760000000	8119.07840000000	8262.63860000000	8357.57140000000	8404.80560000000	8592.19440000000	8638.65460000000	8822.94740000000	8914.16500000000	9004.76340000000]
                                                                  * Referenced by: '<S10>/1-D Lookup Table'
                                                                  */

extern void Inverters_Data_Error_Counter(real_T *rty_Out1, const real_T
  *rtd_Tot_Errors);
extern void Inverters_Data_CAN_OK(real_T rtu_RegID, real_T *rty_u, real_T
  *rtd_Last_alive);
extern void Inverters_Data_Signal_Failure(real_T *rty_u);
extern void Inverters_Data_Signal_OK(real_T *rty_u);

#endif                                /* RTW_HEADER_Inverters_Data_private_h_ */
