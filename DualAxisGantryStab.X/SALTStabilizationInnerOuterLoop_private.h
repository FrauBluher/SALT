/*
 * File: SALTStabilizationInnerOuterLoop_private.h
 *
 * Code generated for Simulink model 'SALTStabilizationInnerOuterLoop'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Jul  9 2011)
 * C/C++ source code generated on : Thu Aug 15 17:30:24 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Microchip->dsPIC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SALTStabilizationInnerOuterLoop_private_h_
#define RTW_HEADER_SALTStabilizationInnerOuterLoop_private_h_
#include "rtwtypes.h"
#define CALL_EVENT                     (-1)
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I16L32N16F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I16L32N16F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);

/* Exported functions */
extern void SALTStabilizationInn_DutyCycles(real32_T rtu_Va, real32_T rtu_Vb,
  real32_T rtu_Vc, rtB_DutyCycles_SALTStabilizatio *localB);
extern void SALTStabilizatio_MATLABFunction(real32_T rtu_u,
  rtB_MATLABFunction_SALTStabiliz *localB);
extern void SALTStabilizati_MATLABFunction1(real32_T rtu_u,
  rtB_MATLABFunction1_SALTStabili *localB);

#endif                                 /* RTW_HEADER_SALTStabilizationInnerOuterLoop_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
