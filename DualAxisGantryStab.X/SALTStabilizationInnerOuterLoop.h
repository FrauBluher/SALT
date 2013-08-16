/*
 * File: SALTStabilizationInnerOuterLoop.h
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

#ifndef RTW_HEADER_SALTStabilizationInnerOuterLoop_h_
#define RTW_HEADER_SALTStabilizationInnerOuterLoop_h_
#ifndef SALTStabilizationInnerOuterLoop_COMMON_INCLUDES_
# define SALTStabilizationInnerOuterLoop_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#endif                                 /* SALTStabilizationInnerOuterLoop_COMMON_INCLUDES_ */

#include "SALTStabilizationInnerOuterLoop_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<Root>/Duty Cycles' */
typedef struct {
  real32_T PWM1;                       /* '<Root>/Duty Cycles' */
  real32_T PWM2;                       /* '<Root>/Duty Cycles' */
  real32_T PWM3;                       /* '<Root>/Duty Cycles' */
  real32_T sector;                     /* '<Root>/Duty Cycles' */
} rtB_DutyCycles_SALTStabilizatio;

/* Block signals for system '<S3>/MATLAB Function' */
typedef struct {
  real32_T y;                          /* '<S3>/MATLAB Function' */
} rtB_MATLABFunction_SALTStabiliz;

/* Block signals for system '<S3>/MATLAB Function1' */
typedef struct {
  real32_T y;                          /* '<S3>/MATLAB Function1' */
} rtB_MATLABFunction1_SALTStabili;

/* Block signals (auto storage) */
typedef struct {
  rtB_MATLABFunction1_SALTStabili sf_MATLABFunction2_b;/* '<S4>/MATLAB Function2' */
  rtB_MATLABFunction1_SALTStabili sf_MATLABFunction1_i;/* '<S4>/MATLAB Function1' */
  rtB_MATLABFunction_SALTStabiliz sf_MATLABFunction_b;/* '<S4>/MATLAB Function' */
  rtB_MATLABFunction1_SALTStabili sf_MATLABFunction2;/* '<S3>/MATLAB Function2' */
  rtB_MATLABFunction1_SALTStabili sf_MATLABFunction1;/* '<S3>/MATLAB Function1' */
  rtB_MATLABFunction_SALTStabiliz sf_MATLABFunction;/* '<S3>/MATLAB Function' */
  rtB_DutyCycles_SALTStabilizatio sf_DutyCycles1;/* '<Root>/Duty Cycles1' */
  rtB_DutyCycles_SALTStabilizatio sf_DutyCycles;/* '<Root>/Duty Cycles' */
} BlockIO_SALTStabilizationInnerO;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S15>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator1_DSTAT_f;/* '<S14>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator1_DSTAT_j;/* '<S22>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator1_DSTAT_p;/* '<S21>/Discrete-Time Integrator1' */
  real_T Memory1_PreviousInput;        /* '<S15>/Memory1' */
  real_T Memory1_PreviousInput_i;      /* '<S14>/Memory1' */
  real_T Memory1_PreviousInput_a;      /* '<S22>/Memory1' */
  real_T Memory1_PreviousInput_g;      /* '<S21>/Memory1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S9>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_c;/* '<S10>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_f;/* '<S16>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_ft;/* '<S17>/Discrete-Time Integrator' */
  real32_T T3;                         /* '<Root>/Data Store Memory1' */
  real32_T Sector;                     /* '<Root>/Data Store Memory10' */
  real32_T T6;                         /* '<Root>/Data Store Memory2' */
  real32_T Sector2;                    /* '<Root>/Data Store Memory3' */
  real32_T T4;                         /* '<Root>/Data Store Memory4' */
  real32_T T5;                         /* '<Root>/Data Store Memory5' */
  real32_T T1;                         /* '<Root>/Data Store Memory7' */
  real32_T T2;                         /* '<Root>/Data Store Memory8' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S9>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_j;/* '<S10>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_SYSTEM_;/* '<S15>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_SYSTE_e;/* '<S14>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_g;/* '<S16>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_n;/* '<S17>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_SYSTE_c;/* '<S22>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_SYSTE_k;/* '<S21>/Discrete-Time Integrator1' */
} D_Work_SALTStabilizationInnerOu;

/* Parameters (auto storage) */
struct Parameters_SALTStabilizationInn_ {
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S14>/Constant5'
                                        */
  real_T Constant5_Value_g;            /* Expression: 0
                                        * Referenced by: '<S15>/Constant5'
                                        */
  real_T Constant5_Value_a;            /* Expression: 0
                                        * Referenced by: '<S21>/Constant5'
                                        */
  real_T Constant5_Value_n;            /* Expression: 0
                                        * Referenced by: '<S22>/Constant5'
                                        */
  real_T Kp1_Value;                    /* Expression: 1
                                        * Referenced by: '<S10>/Kp 1'
                                        */
  real_T Ki1_Value;                    /* Expression: 0
                                        * Referenced by: '<S10>/Ki 1'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S15>/Memory1'
                                        */
  real_T Kd1_Value;                    /* Expression: .1
                                        * Referenced by: '<S10>/Kd 1'
                                        */
  real_T SaturationLimit1_Value;       /* Expression: 100 * (pi/180)
                                        * Referenced by: '<S15>/SaturationLimit1'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S15>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S15>/Discrete-Time Integrator1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S15>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S15>/Saturation1'
                                        */
  real_T Kp2_Value;                    /* Expression: 1
                                        * Referenced by: '<S10>/Kp 2'
                                        */
  real_T Gain_Gain;                    /* Expression: T_step
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Ki2_Value;                    /* Expression: 0
                                        * Referenced by: '<S10>/Ki 2'
                                        */
  real_T Memory1_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S14>/Memory1'
                                        */
  real_T SaturationLimit1_Value_l;     /* Expression: 100 * (pi/180)
                                        * Referenced by: '<S14>/SaturationLimit1'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_l;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_l
                                          * Referenced by: '<S14>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_m; /* Expression: 0
                                        * Referenced by: '<S14>/Discrete-Time Integrator1'
                                        */
  real_T Saturation1_UpperSat_i;       /* Expression: pi
                                        * Referenced by: '<S14>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_b;       /* Expression: -pi
                                        * Referenced by: '<S14>/Saturation1'
                                        */
  real_T Kp1_Value_p;                  /* Expression: 1
                                        * Referenced by: '<S17>/Kp 1'
                                        */
  real_T Ki1_Value_b;                  /* Expression: 0
                                        * Referenced by: '<S17>/Ki 1'
                                        */
  real_T Memory1_X0_c;                 /* Expression: 0
                                        * Referenced by: '<S22>/Memory1'
                                        */
  real_T Kd1_Value_n;                  /* Expression: .1
                                        * Referenced by: '<S17>/Kd 1'
                                        */
  real_T SaturationLimit1_Value_d;     /* Expression: 100 * (pi/180)
                                        * Referenced by: '<S22>/SaturationLimit1'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_d;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_d
                                          * Referenced by: '<S22>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_k; /* Expression: 0
                                        * Referenced by: '<S22>/Discrete-Time Integrator1'
                                        */
  real_T Saturation1_UpperSat_ie;      /* Expression: pi
                                        * Referenced by: '<S22>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_m;       /* Expression: -pi
                                        * Referenced by: '<S22>/Saturation1'
                                        */
  real_T Kp2_Value_b;                  /* Expression: 1
                                        * Referenced by: '<S17>/Kp 2'
                                        */
  real_T Gain_Gain_j;                  /* Expression: T_step
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T Ki2_Value_d;                  /* Expression: 0
                                        * Referenced by: '<S17>/Ki 2'
                                        */
  real_T Memory1_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S21>/Memory1'
                                        */
  real_T SaturationLimit1_Value_o;     /* Expression: 100 * (pi/180)
                                        * Referenced by: '<S21>/SaturationLimit1'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_b;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_b
                                          * Referenced by: '<S21>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_i; /* Expression: 0
                                        * Referenced by: '<S21>/Discrete-Time Integrator1'
                                        */
  real_T Saturation1_UpperSat_h;       /* Expression: pi
                                        * Referenced by: '<S21>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_k;       /* Expression: -pi
                                        * Referenced by: '<S21>/Saturation1'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                           * Referenced by: '<S9>/Discrete-Time Integrator'
                                           */
  real32_T DiscreteTimeIntegrator_IC;  /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S9>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                            * Referenced by: '<S10>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_a;/* Computed Parameter: DiscreteTimeIntegrator_IC_a
                                        * Referenced by: '<S10>/Discrete-Time Integrator'
                                        */
  real32_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S15>/Gain'
                                        */
  real32_T Gain_Gain_a[6];             /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S6>/Gain'
                                        */
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S4>/Gain4'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_p;/* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                            * Referenced by: '<S16>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_f;/* Computed Parameter: DiscreteTimeIntegrator_IC_f
                                        * Referenced by: '<S16>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_c;/* Computed Parameter: DiscreteTimeIntegrator_gainva_c
                                            * Referenced by: '<S17>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_n;/* Computed Parameter: DiscreteTimeIntegrator_IC_n
                                        * Referenced by: '<S17>/Discrete-Time Integrator'
                                        */
  real32_T Gain_Gain_e;                /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S22>/Gain'
                                        */
  real32_T Gain_Gain_c[6];             /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S5>/Gain'
                                        */
  real32_T DataStoreMemory_InitialValue;/* Computed Parameter: DataStoreMemory_InitialValue
                                         * Referenced by: '<Root>/Data Store Memory'
                                         */
  real32_T DataStoreMemory1_InitialValue;/* Computed Parameter: DataStoreMemory1_InitialValue
                                          * Referenced by: '<Root>/Data Store Memory1'
                                          */
  real32_T DataStoreMemory10_InitialValue;/* Computed Parameter: DataStoreMemory10_InitialValue
                                           * Referenced by: '<Root>/Data Store Memory10'
                                           */
  real32_T DataStoreMemory11_InitialValue;/* Computed Parameter: DataStoreMemory11_InitialValue
                                           * Referenced by: '<Root>/Data Store Memory11'
                                           */
  real32_T DataStoreMemory12_InitialValue;/* Computed Parameter: DataStoreMemory12_InitialValue
                                           * Referenced by: '<Root>/Data Store Memory12'
                                           */
  real32_T DataStoreMemory13_InitialValue;/* Computed Parameter: DataStoreMemory13_InitialValue
                                           * Referenced by: '<Root>/Data Store Memory13'
                                           */
  real32_T DataStoreMemory14_InitialValue;/* Computed Parameter: DataStoreMemory14_InitialValue
                                           * Referenced by: '<Root>/Data Store Memory14'
                                           */
  real32_T DataStoreMemory15_InitialValue;/* Computed Parameter: DataStoreMemory15_InitialValue
                                           * Referenced by: '<Root>/Data Store Memory15'
                                           */
  real32_T DataStoreMemory16_InitialValue;/* Computed Parameter: DataStoreMemory16_InitialValue
                                           * Referenced by: '<Root>/Data Store Memory16'
                                           */
  real32_T DataStoreMemory17_InitialValue;/* Computed Parameter: DataStoreMemory17_InitialValue
                                           * Referenced by: '<Root>/Data Store Memory17'
                                           */
  real32_T DataStoreMemory18_InitialValue;/* Computed Parameter: DataStoreMemory18_InitialValue
                                           * Referenced by: '<Root>/Data Store Memory18'
                                           */
  real32_T DataStoreMemory19_InitialValue;/* Computed Parameter: DataStoreMemory19_InitialValue
                                           * Referenced by: '<Root>/Data Store Memory19'
                                           */
  real32_T DataStoreMemory2_InitialValue;/* Computed Parameter: DataStoreMemory2_InitialValue
                                          * Referenced by: '<Root>/Data Store Memory2'
                                          */
  real32_T DataStoreMemory3_InitialValue;/* Computed Parameter: DataStoreMemory3_InitialValue
                                          * Referenced by: '<Root>/Data Store Memory3'
                                          */
  real32_T DataStoreMemory4_InitialValue;/* Computed Parameter: DataStoreMemory4_InitialValue
                                          * Referenced by: '<Root>/Data Store Memory4'
                                          */
  real32_T DataStoreMemory5_InitialValue;/* Computed Parameter: DataStoreMemory5_InitialValue
                                          * Referenced by: '<Root>/Data Store Memory5'
                                          */
  real32_T DataStoreMemory6_InitialValue;/* Computed Parameter: DataStoreMemory6_InitialValue
                                          * Referenced by: '<Root>/Data Store Memory6'
                                          */
  real32_T DataStoreMemory7_InitialValue;/* Computed Parameter: DataStoreMemory7_InitialValue
                                          * Referenced by: '<Root>/Data Store Memory7'
                                          */
  real32_T DataStoreMemory8_InitialValue;/* Computed Parameter: DataStoreMemory8_InitialValue
                                          * Referenced by: '<Root>/Data Store Memory8'
                                          */
  real32_T DataStoreMemory9_InitialValue;/* Computed Parameter: DataStoreMemory9_InitialValue
                                          * Referenced by: '<Root>/Data Store Memory9'
                                          */
};

/* Real-time Model Data Structure */
struct RT_MODEL_SALTStabilizationInner {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_SALTStabilizationInn SALTStabilizationInnerOuterLo_P;

/* Block signals (auto storage) */
extern BlockIO_SALTStabilizationInnerO SALTStabilizationInnerOuterLo_B;

/* Block states (auto storage) */
extern D_Work_SALTStabilizationInnerOu SALTStabilizationInnerOut_DWork;

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern real32_T commandedAngle;        /* '<Root>/Data Store Memory' */
extern real32_T torqueInputX;          /* '<Root>/Data Store Memory11' */
extern real32_T AccelX;                /* '<Root>/Data Store Memory12' */
extern real32_T GyroX;                 /* '<Root>/Data Store Memory13' */
extern real32_T AccelZ;                /* '<Root>/Data Store Memory14' */
extern real32_T GyroZ;                 /* '<Root>/Data Store Memory15' */
extern real32_T CommandedY;            /* '<Root>/Data Store Memory16' */
extern real32_T AccelY;                /* '<Root>/Data Store Memory17' */
extern real32_T CommandedX;            /* '<Root>/Data Store Memory18' */
extern real32_T torqueInputY;          /* '<Root>/Data Store Memory19' */
extern real32_T GyroY;                 /* '<Root>/Data Store Memory6' */
extern real32_T fieldWeakening;        /* '<Root>/Data Store Memory9' */

/* Model entry point functions */
extern void SALTStabilizationInnerOuterLoop_initialize(void);
extern void SALTStabilizationInnerOuterLoop_step(void);
extern void SALTStabilizationInnerOuterLoop_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_SALTStabilizationInner *const
  SALTStabilizationInnerOuterL_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SALTStabilizationInnerOuterLoop'
 * '<S1>'   : 'SALTStabilizationInnerOuterLoop/Duty Cycles'
 * '<S2>'   : 'SALTStabilizationInnerOuterLoop/Duty Cycles1'
 * '<S3>'   : 'SALTStabilizationInnerOuterLoop/X Axis Inner Outer Loop'
 * '<S4>'   : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop'
 * '<S5>'   : 'SALTStabilizationInnerOuterLoop/alphabeta-to-abc'
 * '<S6>'   : 'SALTStabilizationInnerOuterLoop/alphabeta-to-abc1'
 * '<S7>'   : 'SALTStabilizationInnerOuterLoop/dq-to-alphabeta'
 * '<S8>'   : 'SALTStabilizationInnerOuterLoop/dq-to-alphabeta1'
 * '<S9>'   : 'SALTStabilizationInnerOuterLoop/X Axis Inner Outer Loop/Gyro Bias Calculation1'
 * '<S10>'  : 'SALTStabilizationInnerOuterLoop/X Axis Inner Outer Loop/Inner//outer loop'
 * '<S11>'  : 'SALTStabilizationInnerOuterLoop/X Axis Inner Outer Loop/MATLAB Function'
 * '<S12>'  : 'SALTStabilizationInnerOuterLoop/X Axis Inner Outer Loop/MATLAB Function1'
 * '<S13>'  : 'SALTStabilizationInnerOuterLoop/X Axis Inner Outer Loop/MATLAB Function2'
 * '<S14>'  : 'SALTStabilizationInnerOuterLoop/X Axis Inner Outer Loop/Inner//outer loop/PID with External D and anti-windup4'
 * '<S15>'  : 'SALTStabilizationInnerOuterLoop/X Axis Inner Outer Loop/Inner//outer loop/PID with External D and anti-windup5'
 * '<S16>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop/Gyro Bias Calculation1'
 * '<S17>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop/Inner//outer loop'
 * '<S18>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop/MATLAB Function'
 * '<S19>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop/MATLAB Function1'
 * '<S20>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop/MATLAB Function2'
 * '<S21>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop/Inner//outer loop/PID with External D and anti-windup4'
 * '<S22>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop/Inner//outer loop/PID with External D and anti-windup5'
 * '<S23>'  : 'SALTStabilizationInnerOuterLoop/dq-to-alphabeta/vector mixer'
 * '<S24>'  : 'SALTStabilizationInnerOuterLoop/dq-to-alphabeta1/vector mixer'
 */
#endif                                 /* RTW_HEADER_SALTStabilizationInnerOuterLoop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
