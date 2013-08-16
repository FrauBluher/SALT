/*
 * File: SALTStabilizationInnerOuterLoop.c
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

#include "SALTStabilizationInnerOuterLoop.h"
#include "SALTStabilizationInnerOuterLoop_private.h"

/* Exported block states */
real32_T commandedAngle;               /* '<Root>/Data Store Memory' */
real32_T torqueInputX;                 /* '<Root>/Data Store Memory11' */
real32_T AccelX;                       /* '<Root>/Data Store Memory12' */
real32_T GyroX;                        /* '<Root>/Data Store Memory13' */
real32_T AccelZ;                       /* '<Root>/Data Store Memory14' */
real32_T GyroZ;                        /* '<Root>/Data Store Memory15' */
real32_T CommandedY;                   /* '<Root>/Data Store Memory16' */
real32_T AccelY;                       /* '<Root>/Data Store Memory17' */
real32_T CommandedX;                   /* '<Root>/Data Store Memory18' */
real32_T torqueInputY;                 /* '<Root>/Data Store Memory19' */
real32_T GyroY;                        /* '<Root>/Data Store Memory6' */
real32_T fieldWeakening;               /* '<Root>/Data Store Memory9' */

/* Block signals (auto storage) */
BlockIO_SALTStabilizationInnerO SALTStabilizationInnerOuterLo_B;

/* Block states (auto storage) */
D_Work_SALTStabilizationInnerOu SALTStabilizationInnerOut_DWork;

/* Real-time model */
RT_MODEL_SALTStabilizationInner SALTStabilizationInnerOuterL_M_;
RT_MODEL_SALTStabilizationInner *const SALTStabilizationInnerOuterL_M =
  &SALTStabilizationInnerOuterL_M_;

/*
 * Output and update for atomic system:
 *    '<Root>/Duty Cycles'
 *    '<Root>/Duty Cycles1'
 */
void SALTStabilizationInn_DutyCycles(real32_T rtu_Va, real32_T rtu_Vb, real32_T
  rtu_Vc, rtB_DutyCycles_SALTStabilizatio *localB)
{
  real32_T T;

  /* MATLAB Function 'Duty Cycles': '<S1>:1' */
  /* '<S1>:1:5' */
  if (rtu_Va >= 0.0F) {
    /* '<S1>:1:7' */
    if (rtu_Vb >= 0.0F) {
      /* '<S1>:1:8' */
      /* Sector 3, 0 - 60 Degrees */
      /* '<S1>:1:13' */
      T = rtu_Vb * 100.0F;

      /* '<S1>:1:14' */
      /* '<S1>:1:16' */
      /* '<S1>:1:17' */
      /* '<S1>:1:19' */
      localB->PWM1 = 0.0F;

      /* '<S1>:1:20' */
      localB->PWM2 = T;

      /* '<S1>:1:21' */
      localB->PWM3 = rtu_Va * 100.0F + T;

      /* '<S1>:1:22' */
      localB->sector = 3.0F;
    } else if (rtu_Vc >= 0.0F) {
      /* '<S1>:1:24' */
      /* Sector 5, 120 - 180 Degrees */
      /* '<S1>:1:29' */
      T = rtu_Va * 100.0F;

      /* '<S1>:1:30' */
      /* '<S1>:1:32' */
      /* '<S1>:1:33' */
      /* '<S1>:1:35' */
      localB->PWM1 = rtu_Vc * 100.0F + T;

      /* '<S1>:1:36' */
      localB->PWM2 = 0.0F;

      /* '<S1>:1:37' */
      localB->PWM3 = T;

      /* '<S1>:1:38' */
      localB->sector = 5.0F;
    } else {
      /* Sector 1, 60 - 120 Degrees */
      /* '<S1>:1:41' */
      /* '<S1>:1:42' */
      /* '<S1>:1:44' */
      T = -rtu_Vb * 100.0F;

      /* '<S1>:1:45' */
      /* '<S1>:1:47' */
      /* '<S1>:1:48' */
      /* '<S1>:1:50' */
      localB->PWM1 = T;

      /* '<S1>:1:51' */
      localB->PWM2 = 0.0F;

      /* '<S1>:1:52' */
      localB->PWM3 = -rtu_Vc * 100.0F + T;

      /* '<S1>:1:53' */
      localB->sector = 1.0F;
    }
  } else if (rtu_Vb >= 0.0F) {
    /* '<S1>:1:57' */
    if (rtu_Vc >= 0.0F) {
      /* '<S1>:1:58' */
      /* Sector 6, 240 - 300 Degrees */
      /* '<S1>:1:63' */
      T = rtu_Vc * 100.0F;

      /* '<S1>:1:64' */
      /* '<S1>:1:66' */
      /* '<S1>:1:67' */
      /* '<S1>:1:69' */
      localB->PWM1 = T;

      /* '<S1>:1:70' */
      localB->PWM2 = rtu_Vb * 100.0F + T;

      /* '<S1>:1:71' */
      localB->PWM3 = 0.0F;

      /* '<S1>:1:72' */
      localB->sector = 6.0F;
    } else {
      /* Sector 2, 300 - 0 Degrees */
      /* '<S1>:1:75' */
      /* '<S1>:1:76' */
      /* '<S1>:1:78' */
      T = -rtu_Vc * 100.0F;

      /* '<S1>:1:79' */
      /* '<S1>:1:81' */
      /* '<S1>:1:82' */
      /* '<S1>:1:84' */
      localB->PWM1 = 0.0F;

      /* '<S1>:1:85' */
      localB->PWM2 = -rtu_Va * 100.0F + T;

      /* '<S1>:1:86' */
      localB->PWM3 = T;

      /* '<S1>:1:87' */
      localB->sector = 2.0F;
    }
  } else {
    /* Sector 4, 180 - 240 Degrees */
    /* '<S1>:1:91' */
    /* '<S1>:1:92' */
    /* '<S1>:1:94' */
    T = -rtu_Va * 100.0F;

    /* '<S1>:1:95' */
    /* '<S1>:1:97' */
    /* '<S1>:1:98' */
    /* '<S1>:1:100' */
    localB->PWM1 = -rtu_Vb * 100.0F + T;

    /* '<S1>:1:101' */
    localB->PWM2 = T;

    /* '<S1>:1:102' */
    localB->PWM3 = 0.0F;

    /* '<S1>:1:103' */
    localB->sector = 4.0F;
  }
}

/*
 * Output and update for atomic system:
 *    '<S3>/MATLAB Function'
 *    '<S4>/MATLAB Function'
 */
void SALTStabilizatio_MATLABFunction(real32_T rtu_u,
  rtB_MATLABFunction_SALTStabiliz *localB)
{
  /* MATLAB Function 'X Axis Inner Outer Loop/MATLAB Function': '<S11>:1' */
  /* '<S11>:1:4' */
  localB->y = rtu_u / 131.0F * 0.0174532924F * 5.0F;
}

/*
 * Output and update for atomic system:
 *    '<S3>/MATLAB Function1'
 *    '<S3>/MATLAB Function2'
 *    '<S4>/MATLAB Function1'
 *    '<S4>/MATLAB Function2'
 */
void SALTStabilizati_MATLABFunction1(real32_T rtu_u,
  rtB_MATLABFunction1_SALTStabili *localB)
{
  /* MATLAB Function 'X Axis Inner Outer Loop/MATLAB Function1': '<S12>:1' */
  /* '<S12>:1:4' */
  localB->y = rtu_u / 32.8F;
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    y = (real32_T)atan2(u0 > 0.0F ? 1.0F : -1.0F, u1 > 0.0F ? 1.0F : -1.0F);
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = (real32_T)atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void SALTStabilizationInnerOuterLoop_step(void)
{
  /* local block i/o variables */
  real_T rtb_AntiWindup;
  real_T rtb_AntiWindup_a;
  real_T rtb_AntiWindup_i;
  real_T rtb_AntiWindup_m;
  real32_T rtb_DataStoreRead8;
  real32_T rtb_DataStoreRead9;
  real32_T rtb_DataStoreRead7;
  real32_T rtb_Gain_i[3];
  real32_T rtb_DataStoreRead4;
  real32_T rtb_DataStoreRead5;
  real32_T rtb_DataStoreRead3;
  real32_T rtb_Gain_m[3];
  real32_T rtb_DataStoreRead1;
  real32_T rtb_Gain_c;
  real32_T rtb_Cy;
  real32_T rtb_AxBy;
  real_T rtb_Product3;
  real32_T rtb_Cx;
  real_T rtb_TrigonometricFunction_o2;
  real_T rtb_TrigonometricFunction_o1;
  real_T rtb_Add;
  real_T rtb_Add_h;
  real_T rtb_Add_p;
  real32_T DiscreteTimeIntegrator;
  real32_T DiscreteTimeIntegrator_j;
  real_T DiscreteTimeIntegrator_0;
  real_T DiscreteTimeIntegrator1_e;
  real32_T DiscreteTimeIntegrator_c;
  real_T DiscreteTimeIntegrator1_k;
  real_T DiscreteTimeIntegrator1_f;
  int16_T i;

  /* DataStoreRead: '<Root>/Data Store Read1' */
  rtb_DataStoreRead1 = fieldWeakening;

  /* DataStoreRead: '<Root>/Data Store Read10' */
  rtb_Gain_c = CommandedX;

  /* DataStoreRead: '<Root>/Data Store Read8' */
  rtb_DataStoreRead8 = AccelY;

  /* MATLAB Function: '<S3>/MATLAB Function1' */
  SALTStabilizati_MATLABFunction1(rtb_DataStoreRead8,
    &SALTStabilizationInnerOuterLo_B.sf_MATLABFunction1);

  /* DataStoreRead: '<Root>/Data Store Read9' */
  rtb_DataStoreRead9 = AccelZ;

  /* MATLAB Function: '<S3>/MATLAB Function2' */
  SALTStabilizati_MATLABFunction1(rtb_DataStoreRead9,
    &SALTStabilizationInnerOuterLo_B.sf_MATLABFunction2);

  /* Trigonometry: '<S3>/Trigonometric Function' */
  rtb_Cy = rt_atan2f_snf(SALTStabilizationInnerOuterLo_B.sf_MATLABFunction1.y,
    SALTStabilizationInnerOuterLo_B.sf_MATLABFunction2.y);

  /* DataStoreRead: '<Root>/Data Store Read7' */
  rtb_DataStoreRead7 = GyroX;

  /* MATLAB Function: '<S3>/MATLAB Function' */
  SALTStabilizatio_MATLABFunction(rtb_DataStoreRead7,
    &SALTStabilizationInnerOuterLo_B.sf_MATLABFunction);

  /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  if (SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_E != 0) {
    DiscreteTimeIntegrator =
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE;
  } else {
    DiscreteTimeIntegrator =
      SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_gainval *
      SALTStabilizationInnerOuterLo_B.sf_MATLABFunction.y +
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */

  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  if (SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_j != 0) {
    DiscreteTimeIntegrator_j =
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE_c;
  } else {
    DiscreteTimeIntegrator_j =
      SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_gainva_j *
      SALTStabilizationInnerOuterLo_B.sf_MATLABFunction.y +
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE_c;
  }

  /* End of DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */

  /* Sum: '<S10>/Add' incorporates:
   *  Sum: '<S10>/Add1'
   *  Sum: '<S9>/Add'
   */
  rtb_AxBy = ((DiscreteTimeIntegrator - rtb_Cy) + DiscreteTimeIntegrator_j) +
    rtb_Gain_c;

  /* Product: '<S15>/Product1' incorporates:
   *  Constant: '<S10>/Kp 1'
   */
  rtb_Product3 = (real_T)rtb_AxBy * SALTStabilizationInnerOuterLo_P.Kp1_Value;

  /* Product: '<S15>/Product3' incorporates:
   *  Constant: '<S10>/Kd 1'
   */
  rtb_TrigonometricFunction_o1 = 0.0 * SALTStabilizationInnerOuterLo_P.Kd1_Value;

  /* Switch: '<S15>/AntiWindup' incorporates:
   *  Abs: '<S15>/Abs'
   *  Constant: '<S10>/Ki 1'
   *  Constant: '<S15>/Constant5'
   *  Constant: '<S15>/SaturationLimit1'
   *  Gain: '<S15>/Gain'
   *  Memory: '<S15>/Memory1'
   *  Product: '<S15>/Product4'
   *  RelationalOperator: '<S15>/Relational Operator'
   *  Sum: '<S15>/Sum1'
   *  Sum: '<S15>/Sum2'
   */
  if (fabs(((real_T)(SALTStabilizationInnerOuterLo_P.Gain_Gain_o * rtb_AxBy) *
            SALTStabilizationInnerOuterLo_P.Ki1_Value +
            SALTStabilizationInnerOut_DWork.Memory1_PreviousInput) +
           (rtb_Product3 + rtb_TrigonometricFunction_o1)) <
      SALTStabilizationInnerOuterLo_P.SaturationLimit1_Value) {
    rtb_AntiWindup = rtb_AxBy;
  } else {
    rtb_AntiWindup = SALTStabilizationInnerOuterLo_P.Constant5_Value_g;
  }

  /* End of Switch: '<S15>/AntiWindup' */

  /* DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' */
  if (SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTEM_ != 0) {
    DiscreteTimeIntegrator_0 =
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTATE;
  } else {
    DiscreteTimeIntegrator_0 =
      SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_gainval *
      rtb_AntiWindup +
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' */

  /* Sum: '<S15>/Add' incorporates:
   *  Constant: '<S10>/Ki 1'
   *  Product: '<S15>/Product'
   */
  rtb_Add = (DiscreteTimeIntegrator_0 *
             SALTStabilizationInnerOuterLo_P.Ki1_Value + rtb_Product3) +
    rtb_TrigonometricFunction_o1;

  /* Sum: '<S10>/Add4' incorporates:
   *  Saturate: '<S15>/Saturation1'
   */
  rtb_TrigonometricFunction_o1 = (rtb_Add >=
    SALTStabilizationInnerOuterLo_P.Saturation1_UpperSat ?
    SALTStabilizationInnerOuterLo_P.Saturation1_UpperSat : rtb_Add <=
    SALTStabilizationInnerOuterLo_P.Saturation1_LowerSat ?
    SALTStabilizationInnerOuterLo_P.Saturation1_LowerSat : rtb_Add) + (real_T)
    rtb_Cy;

  /* Product: '<S14>/Product1' incorporates:
   *  Constant: '<S10>/Kp 2'
   */
  rtb_TrigonometricFunction_o2 = rtb_TrigonometricFunction_o1 *
    SALTStabilizationInnerOuterLo_P.Kp2_Value;

  /* Product: '<S14>/Product3' */
  rtb_Product3 = 0.0 * 0.0;

  /* Switch: '<S14>/AntiWindup' incorporates:
   *  Abs: '<S14>/Abs'
   *  Constant: '<S10>/Ki 2'
   *  Constant: '<S14>/Constant5'
   *  Constant: '<S14>/SaturationLimit1'
   *  Gain: '<S14>/Gain'
   *  Memory: '<S14>/Memory1'
   *  Product: '<S14>/Product4'
   *  RelationalOperator: '<S14>/Relational Operator'
   *  Sum: '<S14>/Sum1'
   *  Sum: '<S14>/Sum2'
   */
  if (fabs((SALTStabilizationInnerOuterLo_P.Gain_Gain *
            rtb_TrigonometricFunction_o1 *
            SALTStabilizationInnerOuterLo_P.Ki2_Value +
            SALTStabilizationInnerOut_DWork.Memory1_PreviousInput_i) +
           (rtb_TrigonometricFunction_o2 + rtb_Product3)) <
      SALTStabilizationInnerOuterLo_P.SaturationLimit1_Value_l) {
    rtb_AntiWindup_a = rtb_TrigonometricFunction_o1;
  } else {
    rtb_AntiWindup_a = SALTStabilizationInnerOuterLo_P.Constant5_Value;
  }

  /* End of Switch: '<S14>/AntiWindup' */

  /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
  if (SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTE_e != 0) {
    DiscreteTimeIntegrator1_e =
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_f;
  } else {
    DiscreteTimeIntegrator1_e =
      SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_gainv_l *
      rtb_AntiWindup_a +
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_f;
  }

  /* End of DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */

  /* Sum: '<S14>/Add' incorporates:
   *  Constant: '<S10>/Ki 2'
   *  Product: '<S14>/Product'
   */
  rtb_Add_h = (DiscreteTimeIntegrator1_e *
               SALTStabilizationInnerOuterLo_P.Ki2_Value +
               rtb_TrigonometricFunction_o2) + rtb_Product3;

  /* Sum: '<S10>/Add8' incorporates:
   *  Saturate: '<S14>/Saturation1'
   */
  rtb_TrigonometricFunction_o1 = (rtb_Add_h >=
    SALTStabilizationInnerOuterLo_P.Saturation1_UpperSat_i ?
    SALTStabilizationInnerOuterLo_P.Saturation1_UpperSat_i : rtb_Add_h <=
    SALTStabilizationInnerOuterLo_P.Saturation1_LowerSat_b ?
    SALTStabilizationInnerOuterLo_P.Saturation1_LowerSat_b : rtb_Add_h) +
    (real_T)rtb_Gain_c;

  /* Trigonometry: '<Root>/Trigonometric Function1' */
  rtb_TrigonometricFunction_o2 = sin(rtb_TrigonometricFunction_o1);
  rtb_TrigonometricFunction_o1 = cos(rtb_TrigonometricFunction_o1);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtGainInport1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read11'
   *  Product: '<S24>/AxBx'
   *  Product: '<S24>/AxBy'
   *  Product: '<S24>/AyBx'
   *  Product: '<S24>/AyBy'
   *  Sum: '<S24>/sumx'
   *  Sum: '<S24>/sumy'
   *  Trigonometry: '<Root>/Trigonometric Function1'
   */
  rtb_Cy = (real32_T)((real_T)rtb_DataStoreRead1 * rtb_TrigonometricFunction_o1)
    - (real32_T)((real_T)torqueInputX * rtb_TrigonometricFunction_o2);
  rtb_AxBy = (real32_T)((real_T)torqueInputX * rtb_TrigonometricFunction_o1) +
    (real32_T)((real_T)rtb_DataStoreRead1 * rtb_TrigonometricFunction_o2);

  /* Gain: '<S6>/Gain' */
  for (i = 0; i < 3; i++) {
    rtb_Gain_i[i] = 0.0F;
    rtb_Gain_i[i] += SALTStabilizationInnerOuterLo_P.Gain_Gain_a[i] * rtb_Cy;
    rtb_Gain_i[i] += SALTStabilizationInnerOuterLo_P.Gain_Gain_a[i + 3] *
      rtb_AxBy;
  }

  /* End of Gain: '<S6>/Gain' */

  /* MATLAB Function: '<Root>/Duty Cycles1' */
  SALTStabilizationInn_DutyCycles(rtb_Gain_i[0], rtb_Gain_i[1], rtb_Gain_i[2],
    &SALTStabilizationInnerOuterLo_B.sf_DutyCycles1);

  /* DataStoreWrite: '<Root>/Data Store Write1' */
  SALTStabilizationInnerOut_DWork.T4 =
    SALTStabilizationInnerOuterLo_B.sf_DutyCycles1.PWM3;

  /* DataStoreWrite: '<Root>/Data Store Write2' */
  SALTStabilizationInnerOut_DWork.T6 =
    SALTStabilizationInnerOuterLo_B.sf_DutyCycles1.PWM2;

  /* DataStoreRead: '<Root>/Data Store Read6' */
  rtb_Cx = CommandedY;

  /* DataStoreRead: '<Root>/Data Store Read4' */
  rtb_DataStoreRead4 = AccelX;

  /* MATLAB Function: '<S4>/MATLAB Function1' */
  SALTStabilizati_MATLABFunction1(rtb_DataStoreRead4,
    &SALTStabilizationInnerOuterLo_B.sf_MATLABFunction1_i);

  /* Gain: '<S4>/Gain4' */
  rtb_Gain_c = SALTStabilizationInnerOuterLo_P.Gain4_Gain *
    SALTStabilizationInnerOuterLo_B.sf_MATLABFunction1_i.y;

  /* DataStoreRead: '<Root>/Data Store Read5' */
  rtb_DataStoreRead5 = AccelZ;

  /* MATLAB Function: '<S4>/MATLAB Function2' */
  SALTStabilizati_MATLABFunction1(rtb_DataStoreRead5,
    &SALTStabilizationInnerOuterLo_B.sf_MATLABFunction2_b);

  /* Trigonometry: '<S4>/Trigonometric Function' */
  rtb_AxBy = rt_atan2f_snf(rtb_Gain_c,
    SALTStabilizationInnerOuterLo_B.sf_MATLABFunction2_b.y);

  /* DataStoreRead: '<Root>/Data Store Read3' */
  rtb_DataStoreRead3 = GyroY;

  /* MATLAB Function: '<S4>/MATLAB Function' */
  SALTStabilizatio_MATLABFunction(rtb_DataStoreRead3,
    &SALTStabilizationInnerOuterLo_B.sf_MATLABFunction_b);

  /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  if (SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_g != 0) {
    rtb_Gain_c = SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE_f;
  } else {
    rtb_Gain_c = SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_gainva_p
      * SALTStabilizationInnerOuterLo_B.sf_MATLABFunction_b.y +
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE_f;
  }

  /* End of DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */

  /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  if (SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_n != 0) {
    DiscreteTimeIntegrator_c =
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTAT_ft;
  } else {
    DiscreteTimeIntegrator_c =
      SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_gainva_c *
      SALTStabilizationInnerOuterLo_B.sf_MATLABFunction_b.y +
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTAT_ft;
  }

  /* End of DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */

  /* Sum: '<S17>/Add' incorporates:
   *  Sum: '<S16>/Add'
   *  Sum: '<S17>/Add1'
   */
  rtb_Cy = ((rtb_Gain_c - rtb_AxBy) + DiscreteTimeIntegrator_c) + rtb_Cx;

  /* Product: '<S22>/Product1' incorporates:
   *  Constant: '<S17>/Kp 1'
   */
  rtb_TrigonometricFunction_o1 = (real_T)rtb_Cy *
    SALTStabilizationInnerOuterLo_P.Kp1_Value_p;

  /* Product: '<S22>/Product3' incorporates:
   *  Constant: '<S17>/Kd 1'
   */
  rtb_Product3 = 0.0 * SALTStabilizationInnerOuterLo_P.Kd1_Value_n;

  /* Switch: '<S22>/AntiWindup' incorporates:
   *  Abs: '<S22>/Abs'
   *  Constant: '<S17>/Ki 1'
   *  Constant: '<S22>/Constant5'
   *  Constant: '<S22>/SaturationLimit1'
   *  Gain: '<S22>/Gain'
   *  Memory: '<S22>/Memory1'
   *  Product: '<S22>/Product4'
   *  RelationalOperator: '<S22>/Relational Operator'
   *  Sum: '<S22>/Sum1'
   *  Sum: '<S22>/Sum2'
   */
  if (fabs(((real_T)(SALTStabilizationInnerOuterLo_P.Gain_Gain_e * rtb_Cy) *
            SALTStabilizationInnerOuterLo_P.Ki1_Value_b +
            SALTStabilizationInnerOut_DWork.Memory1_PreviousInput_a) +
           (rtb_TrigonometricFunction_o1 + rtb_Product3)) <
      SALTStabilizationInnerOuterLo_P.SaturationLimit1_Value_d) {
    rtb_AntiWindup_i = rtb_Cy;
  } else {
    rtb_AntiWindup_i = SALTStabilizationInnerOuterLo_P.Constant5_Value_n;
  }

  /* End of Switch: '<S22>/AntiWindup' */

  /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  if (SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTE_c != 0) {
    DiscreteTimeIntegrator1_k =
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_j;
  } else {
    DiscreteTimeIntegrator1_k =
      SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_gainv_d *
      rtb_AntiWindup_i +
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_j;
  }

  /* End of DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */

  /* Sum: '<S22>/Add' incorporates:
   *  Constant: '<S17>/Ki 1'
   *  Product: '<S22>/Product'
   */
  rtb_Add_p = (DiscreteTimeIntegrator1_k *
               SALTStabilizationInnerOuterLo_P.Ki1_Value_b +
               rtb_TrigonometricFunction_o1) + rtb_Product3;

  /* Sum: '<S17>/Add4' incorporates:
   *  Saturate: '<S22>/Saturation1'
   */
  rtb_TrigonometricFunction_o1 = (rtb_Add_p >=
    SALTStabilizationInnerOuterLo_P.Saturation1_UpperSat_ie ?
    SALTStabilizationInnerOuterLo_P.Saturation1_UpperSat_ie : rtb_Add_p <=
    SALTStabilizationInnerOuterLo_P.Saturation1_LowerSat_m ?
    SALTStabilizationInnerOuterLo_P.Saturation1_LowerSat_m : rtb_Add_p) +
    (real_T)rtb_AxBy;

  /* Product: '<S21>/Product1' incorporates:
   *  Constant: '<S17>/Kp 2'
   */
  rtb_TrigonometricFunction_o2 = rtb_TrigonometricFunction_o1 *
    SALTStabilizationInnerOuterLo_P.Kp2_Value_b;

  /* Product: '<S21>/Product3' */
  rtb_Product3 = 0.0 * 0.0;

  /* Switch: '<S21>/AntiWindup' incorporates:
   *  Abs: '<S21>/Abs'
   *  Constant: '<S17>/Ki 2'
   *  Constant: '<S21>/Constant5'
   *  Constant: '<S21>/SaturationLimit1'
   *  Gain: '<S21>/Gain'
   *  Memory: '<S21>/Memory1'
   *  Product: '<S21>/Product4'
   *  RelationalOperator: '<S21>/Relational Operator'
   *  Sum: '<S21>/Sum1'
   *  Sum: '<S21>/Sum2'
   */
  if (fabs((SALTStabilizationInnerOuterLo_P.Gain_Gain_j *
            rtb_TrigonometricFunction_o1 *
            SALTStabilizationInnerOuterLo_P.Ki2_Value_d +
            SALTStabilizationInnerOut_DWork.Memory1_PreviousInput_g) +
           (rtb_TrigonometricFunction_o2 + rtb_Product3)) <
      SALTStabilizationInnerOuterLo_P.SaturationLimit1_Value_o) {
    rtb_AntiWindup_m = rtb_TrigonometricFunction_o1;
  } else {
    rtb_AntiWindup_m = SALTStabilizationInnerOuterLo_P.Constant5_Value_a;
  }

  /* End of Switch: '<S21>/AntiWindup' */

  /* DiscreteIntegrator: '<S21>/Discrete-Time Integrator1' */
  if (SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTE_k != 0) {
    DiscreteTimeIntegrator1_f =
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_p;
  } else {
    DiscreteTimeIntegrator1_f =
      SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_gainv_b *
      rtb_AntiWindup_m +
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_p;
  }

  /* End of DiscreteIntegrator: '<S21>/Discrete-Time Integrator1' */

  /* Sum: '<S21>/Add' incorporates:
   *  Constant: '<S17>/Ki 2'
   *  Product: '<S21>/Product'
   */
  rtb_Product3 += DiscreteTimeIntegrator1_f *
    SALTStabilizationInnerOuterLo_P.Ki2_Value_d + rtb_TrigonometricFunction_o2;

  /* Sum: '<S17>/Add8' incorporates:
   *  Saturate: '<S21>/Saturation1'
   */
  rtb_TrigonometricFunction_o1 = (rtb_Product3 >=
    SALTStabilizationInnerOuterLo_P.Saturation1_UpperSat_h ?
    SALTStabilizationInnerOuterLo_P.Saturation1_UpperSat_h : rtb_Product3 <=
    SALTStabilizationInnerOuterLo_P.Saturation1_LowerSat_k ?
    SALTStabilizationInnerOuterLo_P.Saturation1_LowerSat_k : rtb_Product3) +
    (real_T)rtb_Cx;

  /* Trigonometry: '<Root>/Trigonometric Function' */
  rtb_TrigonometricFunction_o2 = sin(rtb_TrigonometricFunction_o1);
  rtb_TrigonometricFunction_o1 = cos(rtb_TrigonometricFunction_o1);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtGainInport1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read2'
   *  Product: '<S23>/AxBx'
   *  Product: '<S23>/AxBy'
   *  Product: '<S23>/AyBx'
   *  Product: '<S23>/AyBy'
   *  Sum: '<S23>/sumx'
   *  Sum: '<S23>/sumy'
   *  Trigonometry: '<Root>/Trigonometric Function'
   */
  rtb_Cy = (real32_T)((real_T)rtb_DataStoreRead1 * rtb_TrigonometricFunction_o1)
    - (real32_T)((real_T)torqueInputY * rtb_TrigonometricFunction_o2);
  rtb_AxBy = (real32_T)((real_T)torqueInputY * rtb_TrigonometricFunction_o1) +
    (real32_T)((real_T)rtb_DataStoreRead1 * rtb_TrigonometricFunction_o2);

  /* Gain: '<S5>/Gain' */
  for (i = 0; i < 3; i++) {
    rtb_Gain_m[i] = 0.0F;
    rtb_Gain_m[i] += SALTStabilizationInnerOuterLo_P.Gain_Gain_c[i] * rtb_Cy;
    rtb_Gain_m[i] += SALTStabilizationInnerOuterLo_P.Gain_Gain_c[i + 3] *
      rtb_AxBy;
  }

  /* End of Gain: '<S5>/Gain' */

  /* MATLAB Function: '<Root>/Duty Cycles' */
  SALTStabilizationInn_DutyCycles(rtb_Gain_m[0], rtb_Gain_m[1], rtb_Gain_m[2],
    &SALTStabilizationInnerOuterLo_B.sf_DutyCycles);

  /* DataStoreWrite: '<Root>/Data Store Write3' */
  SALTStabilizationInnerOut_DWork.T1 =
    SALTStabilizationInnerOuterLo_B.sf_DutyCycles.PWM3;

  /* DataStoreWrite: '<Root>/Data Store Write4' */
  SALTStabilizationInnerOut_DWork.T5 =
    SALTStabilizationInnerOuterLo_B.sf_DutyCycles1.PWM1;

  /* DataStoreWrite: '<Root>/Data Store Write5' */
  SALTStabilizationInnerOut_DWork.Sector2 =
    SALTStabilizationInnerOuterLo_B.sf_DutyCycles1.sector;

  /* DataStoreWrite: '<Root>/Data Store Write6' */
  SALTStabilizationInnerOut_DWork.T3 =
    SALTStabilizationInnerOuterLo_B.sf_DutyCycles.PWM2;

  /* DataStoreWrite: '<Root>/Data Store Write7' */
  SALTStabilizationInnerOut_DWork.T2 =
    SALTStabilizationInnerOuterLo_B.sf_DutyCycles.PWM1;

  /* DataStoreWrite: '<Root>/Data Store Write8' */
  SALTStabilizationInnerOut_DWork.Sector =
    SALTStabilizationInnerOuterLo_B.sf_DutyCycles.sector;

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_E = 0U;
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_gainval *
    SALTStabilizationInnerOuterLo_B.sf_MATLABFunction.y + DiscreteTimeIntegrator;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_j = 0U;
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE_c =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_gainva_j *
    SALTStabilizationInnerOuterLo_B.sf_MATLABFunction.y +
    DiscreteTimeIntegrator_j;

  /* Update for Memory: '<S15>/Memory1' */
  SALTStabilizationInnerOut_DWork.Memory1_PreviousInput = rtb_Add;

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTEM_ = 0U;
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTATE =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_gainval *
    rtb_AntiWindup + DiscreteTimeIntegrator_0;

  /* Update for Memory: '<S14>/Memory1' */
  SALTStabilizationInnerOut_DWork.Memory1_PreviousInput_i = rtb_Add_h;

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTE_e = 0U;
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_f =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_gainv_l *
    rtb_AntiWindup_a + DiscreteTimeIntegrator1_e;

  /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_g = 0U;
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE_f =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_gainva_p *
    SALTStabilizationInnerOuterLo_B.sf_MATLABFunction_b.y + rtb_Gain_c;

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_n = 0U;
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTAT_ft =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_gainva_c *
    SALTStabilizationInnerOuterLo_B.sf_MATLABFunction_b.y +
    DiscreteTimeIntegrator_c;

  /* Update for Memory: '<S22>/Memory1' */
  SALTStabilizationInnerOut_DWork.Memory1_PreviousInput_a = rtb_Add_p;

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTE_c = 0U;
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_j =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_gainv_d *
    rtb_AntiWindup_i + DiscreteTimeIntegrator1_k;

  /* Update for Memory: '<S21>/Memory1' */
  SALTStabilizationInnerOut_DWork.Memory1_PreviousInput_g = rtb_Product3;

  /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTE_k = 0U;
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_p =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_gainv_b *
    rtb_AntiWindup_m + DiscreteTimeIntegrator1_f;
}

/* Model initialize function */
void SALTStabilizationInnerOuterLoop_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(SALTStabilizationInnerOuterL_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &SALTStabilizationInnerOuterLo_B), 0,
                sizeof(BlockIO_SALTStabilizationInnerO));

  /* states (dwork) */
  (void) memset((void *)&SALTStabilizationInnerOut_DWork, 0,
                sizeof(D_Work_SALTStabilizationInnerOu));

  /* exported global states */
  commandedAngle = 0.0F;
  torqueInputX = 0.0F;
  AccelX = 0.0F;
  GyroX = 0.0F;
  AccelZ = 0.0F;
  GyroZ = 0.0F;
  CommandedY = 0.0F;
  AccelY = 0.0F;
  CommandedX = 0.0F;
  torqueInputY = 0.0F;
  GyroY = 0.0F;
  fieldWeakening = 0.0F;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  commandedAngle = SALTStabilizationInnerOuterLo_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  SALTStabilizationInnerOut_DWork.T3 =
    SALTStabilizationInnerOuterLo_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory10' */
  SALTStabilizationInnerOut_DWork.Sector =
    SALTStabilizationInnerOuterLo_P.DataStoreMemory10_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory11' */
  torqueInputX = SALTStabilizationInnerOuterLo_P.DataStoreMemory11_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory12' */
  AccelX = SALTStabilizationInnerOuterLo_P.DataStoreMemory12_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory13' */
  GyroX = SALTStabilizationInnerOuterLo_P.DataStoreMemory13_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory14' */
  AccelZ = SALTStabilizationInnerOuterLo_P.DataStoreMemory14_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory15' */
  GyroZ = SALTStabilizationInnerOuterLo_P.DataStoreMemory15_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory16' */
  CommandedY = SALTStabilizationInnerOuterLo_P.DataStoreMemory16_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory17' */
  AccelY = SALTStabilizationInnerOuterLo_P.DataStoreMemory17_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory18' */
  CommandedX = SALTStabilizationInnerOuterLo_P.DataStoreMemory18_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory19' */
  torqueInputY = SALTStabilizationInnerOuterLo_P.DataStoreMemory19_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  SALTStabilizationInnerOut_DWork.T6 =
    SALTStabilizationInnerOuterLo_P.DataStoreMemory2_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  SALTStabilizationInnerOut_DWork.Sector2 =
    SALTStabilizationInnerOuterLo_P.DataStoreMemory3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
  SALTStabilizationInnerOut_DWork.T4 =
    SALTStabilizationInnerOuterLo_P.DataStoreMemory4_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
  SALTStabilizationInnerOut_DWork.T5 =
    SALTStabilizationInnerOuterLo_P.DataStoreMemory5_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
  GyroY = SALTStabilizationInnerOuterLo_P.DataStoreMemory6_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
  SALTStabilizationInnerOut_DWork.T1 =
    SALTStabilizationInnerOuterLo_P.DataStoreMemory7_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
  SALTStabilizationInnerOut_DWork.T2 =
    SALTStabilizationInnerOuterLo_P.DataStoreMemory8_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory9' */
  fieldWeakening = SALTStabilizationInnerOuterLo_P.DataStoreMemory9_InitialValue;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE_c =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_IC_a;

  /* InitializeConditions for Memory: '<S15>/Memory1' */
  SALTStabilizationInnerOut_DWork.Memory1_PreviousInput =
    SALTStabilizationInnerOuterLo_P.Memory1_X0;

  /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTATE =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for Memory: '<S14>/Memory1' */
  SALTStabilizationInnerOut_DWork.Memory1_PreviousInput_i =
    SALTStabilizationInnerOuterLo_P.Memory1_X0_j;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_f =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_IC_m;

  /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE_f =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_IC_f;

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTAT_ft =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_IC_n;

  /* InitializeConditions for Memory: '<S22>/Memory1' */
  SALTStabilizationInnerOut_DWork.Memory1_PreviousInput_a =
    SALTStabilizationInnerOuterLo_P.Memory1_X0_c;

  /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_j =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_IC_k;

  /* InitializeConditions for Memory: '<S21>/Memory1' */
  SALTStabilizationInnerOut_DWork.Memory1_PreviousInput_g =
    SALTStabilizationInnerOuterLo_P.Memory1_X0_f;

  /* InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_p =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_IC_i;

  /* Enable for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* Enable for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_j = 1U;

  /* Enable for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTEM_ = 1U;

  /* Enable for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTE_e = 1U;

  /* Enable for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_g = 1U;

  /* Enable for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_n = 1U;

  /* Enable for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTE_c = 1U;

  /* Enable for DiscreteIntegrator: '<S21>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTE_k = 1U;
}

/* Model terminate function */
void SALTStabilizationInnerOuterLoop_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
