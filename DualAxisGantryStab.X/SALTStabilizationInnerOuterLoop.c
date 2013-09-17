/*
 * File: SALTStabilizationInnerOuterLoop.c
 *
 * Code generated for Simulink model 'SALTStabilizationInnerOuterLoop'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Jul  9 2011)
 * C/C++ source code generated on : Fri Aug 16 18:44:18 2013
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

  /* MATLAB Function 'Duty Cycles': '<S3>:1' */
  /* '<S3>:1:5' */
  if (rtu_Va >= 0.0F) {
    /* '<S3>:1:7' */
    if (rtu_Vb >= 0.0F) {
      /* '<S3>:1:8' */
      /* Sector 3, 0 - 60 Degrees */
      /* '<S3>:1:13' */
      T = rtu_Vb * 100.0F;

      /* '<S3>:1:14' */
      /* '<S3>:1:16' */
      /* '<S3>:1:17' */
      /* '<S3>:1:19' */
      localB->PWM1 = 0.0F;

      /* '<S3>:1:20' */
      localB->PWM2 = T;

      /* '<S3>:1:21' */
      localB->PWM3 = rtu_Va * 100.0F + T;

      /* '<S3>:1:22' */
      localB->sector = 3.0F;
    } else if (rtu_Vc >= 0.0F) {
      /* '<S3>:1:24' */
      /* Sector 5, 120 - 180 Degrees */
      /* '<S3>:1:29' */
      T = rtu_Va * 100.0F;

      /* '<S3>:1:30' */
      /* '<S3>:1:32' */
      /* '<S3>:1:33' */
      /* '<S3>:1:35' */
      localB->PWM1 = rtu_Vc * 100.0F + T;

      /* '<S3>:1:36' */
      localB->PWM2 = 0.0F;

      /* '<S3>:1:37' */
      localB->PWM3 = T;

      /* '<S3>:1:38' */
      localB->sector = 5.0F;
    } else {
      /* Sector 1, 60 - 120 Degrees */
      /* '<S3>:1:41' */
      /* '<S3>:1:42' */
      /* '<S3>:1:44' */
      T = -rtu_Vb * 100.0F;

      /* '<S3>:1:45' */
      /* '<S3>:1:47' */
      /* '<S3>:1:48' */
      /* '<S3>:1:50' */
      localB->PWM1 = T;

      /* '<S3>:1:51' */
      localB->PWM2 = 0.0F;

      /* '<S3>:1:52' */
      localB->PWM3 = -rtu_Vc * 100.0F + T;

      /* '<S3>:1:53' */
      localB->sector = 1.0F;
    }
  } else if (rtu_Vb >= 0.0F) {
    /* '<S3>:1:57' */
    if (rtu_Vc >= 0.0F) {
      /* '<S3>:1:58' */
      /* Sector 6, 240 - 300 Degrees */
      /* '<S3>:1:63' */
      T = rtu_Vc * 100.0F;

      /* '<S3>:1:64' */
      /* '<S3>:1:66' */
      /* '<S3>:1:67' */
      /* '<S3>:1:69' */
      localB->PWM1 = T;

      /* '<S3>:1:70' */
      localB->PWM2 = rtu_Vb * 100.0F + T;

      /* '<S3>:1:71' */
      localB->PWM3 = 0.0F;

      /* '<S3>:1:72' */
      localB->sector = 6.0F;
    } else {
      /* Sector 2, 300 - 0 Degrees */
      /* '<S3>:1:75' */
      /* '<S3>:1:76' */
      /* '<S3>:1:78' */
      T = -rtu_Vc * 100.0F;

      /* '<S3>:1:79' */
      /* '<S3>:1:81' */
      /* '<S3>:1:82' */
      /* '<S3>:1:84' */
      localB->PWM1 = 0.0F;

      /* '<S3>:1:85' */
      localB->PWM2 = -rtu_Va * 100.0F + T;

      /* '<S3>:1:86' */
      localB->PWM3 = T;

      /* '<S3>:1:87' */
      localB->sector = 2.0F;
    }
  } else {
    /* Sector 4, 180 - 240 Degrees */
    /* '<S3>:1:91' */
    /* '<S3>:1:92' */
    /* '<S3>:1:94' */
    T = -rtu_Va * 100.0F;

    /* '<S3>:1:95' */
    /* '<S3>:1:97' */
    /* '<S3>:1:98' */
    /* '<S3>:1:100' */
    localB->PWM1 = -rtu_Vb * 100.0F + T;

    /* '<S3>:1:101' */
    localB->PWM2 = T;

    /* '<S3>:1:102' */
    localB->PWM3 = 0.0F;

    /* '<S3>:1:103' */
    localB->sector = 4.0F;
  }
}

/*
 * Output and update for atomic system:
 *    '<S5>/MATLAB Function'
 *    '<S6>/MATLAB Function'
 */
void SALTStabilizatio_MATLABFunction(real32_T rtu_u,
  rtB_MATLABFunction_SALTStabiliz *localB)
{
  /* MATLAB Function 'Y Axis Inner Outer Loop1/MATLAB Function': '<S13>:1' */
  /* '<S13>:1:4' */
  localB->y = rtu_u / 131.0F * 0.0174532924F * 5.0F;
}

/*
 * Output and update for atomic system:
 *    '<S5>/MATLAB Function1'
 *    '<S5>/MATLAB Function2'
 *    '<S6>/MATLAB Function1'
 *    '<S6>/MATLAB Function2'
 */
void SALTStabilizati_MATLABFunction1(real32_T rtu_u,
  rtB_MATLABFunction1_SALTStabili *localB)
{
  /* MATLAB Function 'Y Axis Inner Outer Loop1/MATLAB Function1': '<S14>:1' */
  /* '<S14>:1:4' */
  localB->y = rtu_u / 32.8F;
}

/*
 * Initial conditions for atomic system:
 *    '<S16>/Embedded MATLAB Function'
 *    '<S17>/Embedded MATLAB Function'
 *    '<S23>/Embedded MATLAB Function'
 *    '<S24>/Embedded MATLAB Function'
 */
void SAL_EmbeddedMATLABFunction_Init(rtDW_EmbeddedMATLABFunction_SAL *localDW)
{
  localDW->a_not_empty = FALSE;
}

/*
 * Output and update for atomic system:
 *    '<S16>/Embedded MATLAB Function'
 *    '<S17>/Embedded MATLAB Function'
 *    '<S23>/Embedded MATLAB Function'
 *    '<S24>/Embedded MATLAB Function'
 */
void SALTStab_EmbeddedMATLABFunction(real32_T rtu_u, real_T rtu_T, real_T rtu_f,
  rtB_EmbeddedMATLABFunction_SALT *localB, rtDW_EmbeddedMATLABFunction_SAL
  *localDW)
{
  real_T omega;

  /* MATLAB Function 'Y Axis Inner Outer Loop1/Tustin Lowpass, Auto Initial Condition/Embedded MATLAB Function': '<S18>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  if (!localDW->a_not_empty) {
    /* '<S18>:1:9' */
    /* tf = [T*omega/(2+T*omega) T*omega/(2+T*omega)],[1 (T*omega-2)/(T*omega+2)] */
    /* tf = [a a],[1 -b] */
    /* '<S18>:1:12' */
    omega = 6.2831853071795862 * rtu_f;

    /* '<S18>:1:13' */
    localDW->a = rtu_T * omega / (rtu_T * omega + 2.0);
    localDW->a_not_empty = TRUE;

    /* '<S18>:1:14' */
    localDW->b = -(rtu_T * omega - 2.0) / (rtu_T * omega + 2.0);

    /* '<S18>:1:15' */
    localDW->y_km1 = rtu_u;

    /* '<S18>:1:16' */
    localDW->u_km1 = rtu_u;
  }

  /* '<S18>:1:19' */
  localB->y = (rtu_u + localDW->u_km1) * (real32_T)localDW->a + (real32_T)
    localDW->b * localDW->y_km1;

  /* '<S18>:1:20' */
  localDW->y_km1 = localB->y;

  /* '<S18>:1:21' */
  localDW->u_km1 = rtu_u;
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
  real_T rtb_AntiWindup_b;
  real32_T rtb_DataStoreRead7;
  real32_T rtb_Gain1_f;
  real32_T rtb_DataStoreRead8;
  real32_T rtb_DataStoreRead9;
  real32_T rtb_TrigonometricFunction;
  real32_T rtb_Gain[3];
  real32_T rtb_DataStoreRead3;
  real32_T rtb_Gain1_j;
  real32_T rtb_DataStoreRead4;
  real32_T rtb_DataStoreRead5;
  real32_T rtb_TrigonometricFunction_c;
  real32_T rtb_Gain_m[3];
  real_T sinOut;
  real32_T rtb_DataStoreRead1;
  real32_T rtb_Cy;
  real32_T rtb_Gain4_a;
  real_T rtb_Product3;
  real_T rtb_TrigonometricFunction_o1;
  real_T rtb_Add;
  real32_T DiscreteTimeIntegrator;
  real_T DiscreteTimeIntegrator_0;
  real32_T DiscreteTimeIntegrator_e;
  real_T DiscreteTimeIntegrator1_b;
  int16_T i;

  /* DataStoreRead: '<Root>/Data Store Read1' */
  rtb_DataStoreRead1 = fieldWeakening;

  /* DataStoreRead: '<Root>/Data Store Read10' */
  rtb_Cy = CommandedX;

  /* DataStoreRead: '<Root>/Data Store Read7' */
  rtb_DataStoreRead7 = GyroX;

  /* MATLAB Function: '<S6>/MATLAB Function' */
  SALTStabilizatio_MATLABFunction(rtb_DataStoreRead7,
    &SALTStabilizationInnerOuterLo_B.sf_MATLABFunction);

  /* Gain: '<S6>/Gain1' */
  rtb_Gain1_f = SALTStabilizationInnerOuterLo_P.Gain1_Gain_b *
    SALTStabilizationInnerOuterLo_B.sf_MATLABFunction.y;

  /* MATLAB Function: '<S23>/Embedded MATLAB Function' */
  SALTStab_EmbeddedMATLABFunction(rtb_Gain1_f,
    SALTStabilizationInnerOuterLo_P.Constant_Value,
    SALTStabilizationInnerOuterLo_P.Constant1_Value,
    &SALTStabilizationInnerOuterLo_B.sf_EmbeddedMATLABFunction,
    &SALTStabilizationInnerOut_DWork.sf_EmbeddedMATLABFunction);

  /* DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  if (SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_E != 0) {
    DiscreteTimeIntegrator =
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE;
  } else {
    DiscreteTimeIntegrator =
      SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_gainval *
      SALTStabilizationInnerOuterLo_B.sf_EmbeddedMATLABFunction.y +
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */

  /* DataStoreRead: '<Root>/Data Store Read8' */
  rtb_DataStoreRead8 = AccelY;

  /* MATLAB Function: '<S6>/MATLAB Function1' */
  SALTStabilizati_MATLABFunction1(rtb_DataStoreRead8,
    &SALTStabilizationInnerOuterLo_B.sf_MATLABFunction1);

  /* Gain: '<S6>/Gain4' */
  rtb_Gain4_a = SALTStabilizationInnerOuterLo_P.Gain4_Gain_b *
    SALTStabilizationInnerOuterLo_B.sf_MATLABFunction1.y;

  /* DataStoreRead: '<Root>/Data Store Read9' */
  rtb_DataStoreRead9 = AccelZ;

  /* MATLAB Function: '<S6>/MATLAB Function2' */
  SALTStabilizati_MATLABFunction1(rtb_DataStoreRead9,
    &SALTStabilizationInnerOuterLo_B.sf_MATLABFunction2);

  /* Trigonometry: '<S6>/Trigonometric Function' */
  rtb_TrigonometricFunction = rt_atan2f_snf(rtb_Gain4_a,
    SALTStabilizationInnerOuterLo_B.sf_MATLABFunction2.y);

  /* MATLAB Function: '<S24>/Embedded MATLAB Function' */
  SALTStab_EmbeddedMATLABFunction(rtb_TrigonometricFunction,
    SALTStabilizationInnerOuterLo_P.Constant_Value_p,
    SALTStabilizationInnerOuterLo_P.Constant1_Value_p,
    &SALTStabilizationInnerOuterLo_B.sf_EmbeddedMATLABFunction_k,
    &SALTStabilizationInnerOut_DWork.sf_EmbeddedMATLABFunction_k);

  /* Sum: '<S2>/Add4' incorporates:
   *  Sum: '<S6>/Add'
   */
  rtb_Gain4_a = (DiscreteTimeIntegrator +
                 SALTStabilizationInnerOuterLo_B.sf_EmbeddedMATLABFunction_k.y)
    + rtb_Cy;

  /* Product: '<S12>/Product1' incorporates:
   *  Constant: '<S2>/Kp 2'
   */
  rtb_Product3 = (real_T)rtb_Gain4_a * SALTStabilizationInnerOuterLo_P.Kp2_Value;

  /* Product: '<S12>/Product3' incorporates:
   *  Constant: '<S2>/Kp 1'
   */
  rtb_TrigonometricFunction_o1 = (real_T)
    SALTStabilizationInnerOuterLo_B.sf_EmbeddedMATLABFunction.y *
    SALTStabilizationInnerOuterLo_P.Kp1_Value;

  /* Switch: '<S12>/AntiWindup' incorporates:
   *  Abs: '<S12>/Abs'
   *  Constant: '<S12>/Constant5'
   *  Constant: '<S12>/SaturationLimit1'
   *  Constant: '<S2>/Ki 2'
   *  Gain: '<S12>/Gain'
   *  Memory: '<S12>/Memory1'
   *  Product: '<S12>/Product4'
   *  RelationalOperator: '<S12>/Relational Operator'
   *  Sum: '<S12>/Sum1'
   *  Sum: '<S12>/Sum2'
   */
  if (fabs(((real_T)(SALTStabilizationInnerOuterLo_P.Gain_Gain * rtb_Gain4_a) *
            SALTStabilizationInnerOuterLo_P.Ki2_Value +
            SALTStabilizationInnerOut_DWork.Memory1_PreviousInput) +
           (rtb_Product3 + rtb_TrigonometricFunction_o1)) <
      SALTStabilizationInnerOuterLo_P.SaturationLimit1_Value) {
    rtb_AntiWindup = rtb_Gain4_a;
  } else {
    rtb_AntiWindup = SALTStabilizationInnerOuterLo_P.Constant5_Value_j;
  }

  /* End of Switch: '<S12>/AntiWindup' */

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' */
  if (SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTEM_ != 0) {
    DiscreteTimeIntegrator_0 =
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTATE;
  } else {
    DiscreteTimeIntegrator_0 =
      SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_gainval *
      rtb_AntiWindup +
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' */

  /* Sum: '<S12>/Add' incorporates:
   *  Constant: '<S2>/Ki 2'
   *  Product: '<S12>/Product'
   */
  rtb_Add = (DiscreteTimeIntegrator_0 *
             SALTStabilizationInnerOuterLo_P.Ki2_Value + rtb_Product3) +
    rtb_TrigonometricFunction_o1;

  /* Gain: '<Root>/Gain1' incorporates:
   *  Saturate: '<S12>/Saturation1'
   *  Sum: '<S2>/Add8'
   */
  rtb_Product3 = ((rtb_Add >=
                   SALTStabilizationInnerOuterLo_P.Saturation1_UpperSat ?
                   SALTStabilizationInnerOuterLo_P.Saturation1_UpperSat :
                   rtb_Add <=
                   SALTStabilizationInnerOuterLo_P.Saturation1_LowerSat ?
                   SALTStabilizationInnerOuterLo_P.Saturation1_LowerSat :
                   rtb_Add) + (real_T)rtb_Cy) *
    SALTStabilizationInnerOuterLo_P.Gain1_Gain;

  /* Trigonometry: '<Root>/Trigonometric Function1' */
  sinOut = sin(rtb_Product3);
  rtb_Product3 = cos(rtb_Product3);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtGainInport1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read11'
   *  Product: '<S28>/AxBx'
   *  Product: '<S28>/AxBy'
   *  Product: '<S28>/AyBx'
   *  Product: '<S28>/AyBy'
   *  Sum: '<S28>/sumx'
   *  Sum: '<S28>/sumy'
   *  Trigonometry: '<Root>/Trigonometric Function1'
   */
  rtb_Cy = (real32_T)((real_T)rtb_DataStoreRead1 * rtb_Product3) - (real32_T)
    ((real_T)torqueInputX * sinOut);
  rtb_Gain4_a = (real32_T)((real_T)torqueInputX * rtb_Product3) + (real32_T)
    ((real_T)rtb_DataStoreRead1 * sinOut);

  /* Gain: '<S8>/Gain' */
  for (i = 0; i < 3; i++) {
    rtb_Gain[i] = 0.0F;
    rtb_Gain[i] += SALTStabilizationInnerOuterLo_P.Gain_Gain_a[i] * rtb_Cy;
    rtb_Gain[i] += SALTStabilizationInnerOuterLo_P.Gain_Gain_a[i + 3] *
      rtb_Gain4_a;
  }

  /* End of Gain: '<S8>/Gain' */

  /* MATLAB Function: '<Root>/Duty Cycles1' */
  SALTStabilizationInn_DutyCycles(rtb_Gain[0], rtb_Gain[1], rtb_Gain[2],
    &SALTStabilizationInnerOuterLo_B.sf_DutyCycles1);

  /* DataStoreWrite: '<Root>/Data Store Write1' */
  SALTStabilizationInnerOut_DWork.T4 =
    SALTStabilizationInnerOuterLo_B.sf_DutyCycles1.PWM3;

  /* DataStoreWrite: '<Root>/Data Store Write2' */
  SALTStabilizationInnerOut_DWork.T6 =
    SALTStabilizationInnerOuterLo_B.sf_DutyCycles1.PWM2;

  /* DataStoreRead: '<Root>/Data Store Read6' */
  rtb_Cy = CommandedY;

  /* DataStoreRead: '<Root>/Data Store Read3' */
  rtb_DataStoreRead3 = GyroY;

  /* MATLAB Function: '<S5>/MATLAB Function' */
  SALTStabilizatio_MATLABFunction(rtb_DataStoreRead3,
    &SALTStabilizationInnerOuterLo_B.sf_MATLABFunction_c);

  /* Gain: '<S5>/Gain1' */
  rtb_Gain1_j = SALTStabilizationInnerOuterLo_P.Gain1_Gain_k *
    SALTStabilizationInnerOuterLo_B.sf_MATLABFunction_c.y;

  /* MATLAB Function: '<S16>/Embedded MATLAB Function' */
  SALTStab_EmbeddedMATLABFunction(rtb_Gain1_j,
    SALTStabilizationInnerOuterLo_P.Constant_Value_f,
    SALTStabilizationInnerOuterLo_P.Constant1_Value_f,
    &SALTStabilizationInnerOuterLo_B.sf_EmbeddedMATLABFunction_e,
    &SALTStabilizationInnerOut_DWork.sf_EmbeddedMATLABFunction_e);

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  if (SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_c != 0) {
    DiscreteTimeIntegrator_e =
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE_f;
  } else {
    DiscreteTimeIntegrator_e =
      SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_gainva_e *
      SALTStabilizationInnerOuterLo_B.sf_EmbeddedMATLABFunction_e.y +
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE_f;
  }

  /* End of DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */

  /* DataStoreRead: '<Root>/Data Store Read4' */
  rtb_DataStoreRead4 = AccelX;

  /* MATLAB Function: '<S5>/MATLAB Function1' */
  SALTStabilizati_MATLABFunction1(rtb_DataStoreRead4,
    &SALTStabilizationInnerOuterLo_B.sf_MATLABFunction1_i);

  /* Gain: '<S5>/Gain4' */
  rtb_Gain4_a = SALTStabilizationInnerOuterLo_P.Gain4_Gain_j *
    SALTStabilizationInnerOuterLo_B.sf_MATLABFunction1_i.y;

  /* DataStoreRead: '<Root>/Data Store Read5' */
  rtb_DataStoreRead5 = AccelZ;

  /* MATLAB Function: '<S5>/MATLAB Function2' */
  SALTStabilizati_MATLABFunction1(rtb_DataStoreRead5,
    &SALTStabilizationInnerOuterLo_B.sf_MATLABFunction2_j);

  /* Trigonometry: '<S5>/Trigonometric Function' */
  rtb_TrigonometricFunction_c = rt_atan2f_snf(rtb_Gain4_a,
    SALTStabilizationInnerOuterLo_B.sf_MATLABFunction2_j.y);

  /* MATLAB Function: '<S17>/Embedded MATLAB Function' */
  SALTStab_EmbeddedMATLABFunction(rtb_TrigonometricFunction_c,
    SALTStabilizationInnerOuterLo_P.Constant_Value_m,
    SALTStabilizationInnerOuterLo_P.Constant1_Value_k,
    &SALTStabilizationInnerOuterLo_B.sf_EmbeddedMATLABFunction_a,
    &SALTStabilizationInnerOut_DWork.sf_EmbeddedMATLABFunction_a);

  /* Sum: '<S1>/Add4' incorporates:
   *  Sum: '<S5>/Add'
   */
  rtb_Gain4_a = (DiscreteTimeIntegrator_e +
                 SALTStabilizationInnerOuterLo_B.sf_EmbeddedMATLABFunction_a.y)
    + rtb_Cy;

  /* Product: '<S11>/Product1' incorporates:
   *  Constant: '<S1>/Kp 2'
   */
  rtb_TrigonometricFunction_o1 = (real_T)rtb_Gain4_a *
    SALTStabilizationInnerOuterLo_P.Kp2_Value_f;

  /* Product: '<S11>/Product3' incorporates:
   *  Constant: '<S1>/Kp 1'
   */
  rtb_Product3 = (real_T)
    SALTStabilizationInnerOuterLo_B.sf_EmbeddedMATLABFunction_e.y *
    SALTStabilizationInnerOuterLo_P.Kp1_Value_e;

  /* Switch: '<S11>/AntiWindup' incorporates:
   *  Abs: '<S11>/Abs'
   *  Constant: '<S11>/Constant5'
   *  Constant: '<S11>/SaturationLimit1'
   *  Constant: '<S1>/Ki 2'
   *  Gain: '<S11>/Gain'
   *  Memory: '<S11>/Memory1'
   *  Product: '<S11>/Product4'
   *  RelationalOperator: '<S11>/Relational Operator'
   *  Sum: '<S11>/Sum1'
   *  Sum: '<S11>/Sum2'
   */
  if (fabs(((real_T)(SALTStabilizationInnerOuterLo_P.Gain_Gain_c * rtb_Gain4_a) *
            SALTStabilizationInnerOuterLo_P.Ki2_Value_b +
            SALTStabilizationInnerOut_DWork.Memory1_PreviousInput_g) +
           (rtb_TrigonometricFunction_o1 + rtb_Product3)) <
      SALTStabilizationInnerOuterLo_P.SaturationLimit1_Value_o) {
    rtb_AntiWindup_b = rtb_Gain4_a;
  } else {
    rtb_AntiWindup_b = SALTStabilizationInnerOuterLo_P.Constant5_Value;
  }

  /* End of Switch: '<S11>/AntiWindup' */

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  if (SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTE_o != 0) {
    DiscreteTimeIntegrator1_b =
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_o;
  } else {
    DiscreteTimeIntegrator1_b =
      SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_gainv_g *
      rtb_AntiWindup_b +
      SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_o;
  }

  /* End of DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */

  /* Sum: '<S11>/Add' incorporates:
   *  Constant: '<S1>/Ki 2'
   *  Product: '<S11>/Product'
   */
  rtb_TrigonometricFunction_o1 = (DiscreteTimeIntegrator1_b *
    SALTStabilizationInnerOuterLo_P.Ki2_Value_b + rtb_TrigonometricFunction_o1)
    + rtb_Product3;

  /* Gain: '<Root>/Gain4' incorporates:
   *  Saturate: '<S11>/Saturation1'
   *  Sum: '<S1>/Add8'
   */
  rtb_Product3 = ((rtb_TrigonometricFunction_o1 >=
                   SALTStabilizationInnerOuterLo_P.Saturation1_UpperSat_j ?
                   SALTStabilizationInnerOuterLo_P.Saturation1_UpperSat_j :
                   rtb_TrigonometricFunction_o1 <=
                   SALTStabilizationInnerOuterLo_P.Saturation1_LowerSat_c ?
                   SALTStabilizationInnerOuterLo_P.Saturation1_LowerSat_c :
                   rtb_TrigonometricFunction_o1) + (real_T)rtb_Cy) *
    SALTStabilizationInnerOuterLo_P.Gain4_Gain;

  /* Trigonometry: '<Root>/Trigonometric Function' */
  sinOut = sin(rtb_Product3);
  rtb_Product3 = cos(rtb_Product3);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtGainInport1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read2'
   *  Product: '<S27>/AxBx'
   *  Product: '<S27>/AxBy'
   *  Product: '<S27>/AyBx'
   *  Product: '<S27>/AyBy'
   *  Sum: '<S27>/sumx'
   *  Sum: '<S27>/sumy'
   *  Trigonometry: '<Root>/Trigonometric Function'
   */
  rtb_Cy = (real32_T)((real_T)rtb_DataStoreRead1 * rtb_Product3) - (real32_T)
    ((real_T)torqueInputY * sinOut);
  rtb_Gain4_a = (real32_T)((real_T)torqueInputY * rtb_Product3) + (real32_T)
    ((real_T)rtb_DataStoreRead1 * sinOut);

  /* Gain: '<S7>/Gain' */
  for (i = 0; i < 3; i++) {
    rtb_Gain_m[i] = 0.0F;
    rtb_Gain_m[i] += SALTStabilizationInnerOuterLo_P.Gain_Gain_cl[i] * rtb_Cy;
    rtb_Gain_m[i] += SALTStabilizationInnerOuterLo_P.Gain_Gain_cl[i + 3] *
      rtb_Gain4_a;
  }

  /* End of Gain: '<S7>/Gain' */

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

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_E = 0U;
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_gainval *
    SALTStabilizationInnerOuterLo_B.sf_EmbeddedMATLABFunction.y +
    DiscreteTimeIntegrator;

  /* Update for Memory: '<S12>/Memory1' */
  SALTStabilizationInnerOut_DWork.Memory1_PreviousInput = rtb_Add;

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTEM_ = 0U;
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTATE =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_gainval *
    rtb_AntiWindup + DiscreteTimeIntegrator_0;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_c = 0U;
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE_f =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_gainva_e *
    SALTStabilizationInnerOuterLo_B.sf_EmbeddedMATLABFunction_e.y +
    DiscreteTimeIntegrator_e;

  /* Update for Memory: '<S11>/Memory1' */
  SALTStabilizationInnerOut_DWork.Memory1_PreviousInput_g =
    rtb_TrigonometricFunction_o1;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTE_o = 0U;
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_o =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_gainv_g *
    rtb_AntiWindup_b + DiscreteTimeIntegrator1_b;
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

  /* InitializeConditions for MATLAB Function: '<S23>/Embedded MATLAB Function' */
  SAL_EmbeddedMATLABFunction_Init
    (&SALTStabilizationInnerOut_DWork.sf_EmbeddedMATLABFunction);

  /* InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for MATLAB Function: '<S24>/Embedded MATLAB Function' */
  SAL_EmbeddedMATLABFunction_Init
    (&SALTStabilizationInnerOut_DWork.sf_EmbeddedMATLABFunction_k);

  /* InitializeConditions for Memory: '<S12>/Memory1' */
  SALTStabilizationInnerOut_DWork.Memory1_PreviousInput =
    SALTStabilizationInnerOuterLo_P.Memory1_X0;

  /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTATE =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for MATLAB Function: '<S16>/Embedded MATLAB Function' */
  SAL_EmbeddedMATLABFunction_Init
    (&SALTStabilizationInnerOut_DWork.sf_EmbeddedMATLABFunction_e);

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_DSTATE_f =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator_IC_a;

  /* InitializeConditions for MATLAB Function: '<S17>/Embedded MATLAB Function' */
  SAL_EmbeddedMATLABFunction_Init
    (&SALTStabilizationInnerOut_DWork.sf_EmbeddedMATLABFunction_a);

  /* InitializeConditions for Memory: '<S11>/Memory1' */
  SALTStabilizationInnerOut_DWork.Memory1_PreviousInput_g =
    SALTStabilizationInnerOuterLo_P.Memory1_X0_k;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_DSTAT_o =
    SALTStabilizationInnerOuterLo_P.DiscreteTimeIntegrator1_IC_g;

  /* Enable for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* Enable for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTEM_ = 1U;

  /* Enable for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator_SYSTEM_c = 1U;

  /* Enable for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  SALTStabilizationInnerOut_DWork.DiscreteTimeIntegrator1_SYSTE_o = 1U;
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
