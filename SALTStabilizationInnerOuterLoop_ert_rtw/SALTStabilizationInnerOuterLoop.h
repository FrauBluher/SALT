/*
 * File: SALTStabilizationInnerOuterLoop.h
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

/* Block signals for system '<S5>/MATLAB Function' */
typedef struct {
  real32_T y;                          /* '<S5>/MATLAB Function' */
} rtB_MATLABFunction_SALTStabiliz;

/* Block signals for system '<S5>/MATLAB Function1' */
typedef struct {
  real32_T y;                          /* '<S5>/MATLAB Function1' */
} rtB_MATLABFunction1_SALTStabili;

/* Block signals for system '<S16>/Embedded MATLAB Function' */
typedef struct {
  real32_T y;                          /* '<S16>/Embedded MATLAB Function' */
} rtB_EmbeddedMATLABFunction_SALT;

/* Block states (auto storage) for system '<S16>/Embedded MATLAB Function' */
typedef struct {
  real_T a;                            /* '<S16>/Embedded MATLAB Function' */
  real_T b;                            /* '<S16>/Embedded MATLAB Function' */
  real32_T y_km1;                      /* '<S16>/Embedded MATLAB Function' */
  real32_T u_km1;                      /* '<S16>/Embedded MATLAB Function' */
  boolean_T a_not_empty;               /* '<S16>/Embedded MATLAB Function' */
} rtDW_EmbeddedMATLABFunction_SAL;

/* Block signals (auto storage) */
typedef struct {
  rtB_EmbeddedMATLABFunction_SALT sf_EmbeddedMATLABFunction_k;/* '<S24>/Embedded MATLAB Function' */
  rtB_EmbeddedMATLABFunction_SALT sf_EmbeddedMATLABFunction;/* '<S23>/Embedded MATLAB Function' */
  rtB_MATLABFunction1_SALTStabili sf_MATLABFunction2;/* '<S6>/MATLAB Function2' */
  rtB_MATLABFunction1_SALTStabili sf_MATLABFunction1;/* '<S6>/MATLAB Function1' */
  rtB_MATLABFunction_SALTStabiliz sf_MATLABFunction;/* '<S6>/MATLAB Function' */
  rtB_EmbeddedMATLABFunction_SALT sf_EmbeddedMATLABFunction_a;/* '<S17>/Embedded MATLAB Function' */
  rtB_EmbeddedMATLABFunction_SALT sf_EmbeddedMATLABFunction_e;/* '<S16>/Embedded MATLAB Function' */
  rtB_MATLABFunction1_SALTStabili sf_MATLABFunction2_j;/* '<S5>/MATLAB Function2' */
  rtB_MATLABFunction1_SALTStabili sf_MATLABFunction1_i;/* '<S5>/MATLAB Function1' */
  rtB_MATLABFunction_SALTStabiliz sf_MATLABFunction_c;/* '<S5>/MATLAB Function' */
  rtB_DutyCycles_SALTStabilizatio sf_DutyCycles1;/* '<Root>/Duty Cycles1' */
  rtB_DutyCycles_SALTStabilizatio sf_DutyCycles;/* '<Root>/Duty Cycles' */
} BlockIO_SALTStabilizationInnerO;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S12>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator1_DSTAT_o;/* '<S11>/Discrete-Time Integrator1' */
  real_T Memory1_PreviousInput;        /* '<S12>/Memory1' */
  real_T Memory1_PreviousInput_g;      /* '<S11>/Memory1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S6>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_f;/* '<S5>/Discrete-Time Integrator' */
  real32_T T3;                         /* '<Root>/Data Store Memory1' */
  real32_T Sector;                     /* '<Root>/Data Store Memory10' */
  real32_T T6;                         /* '<Root>/Data Store Memory2' */
  real32_T Sector2;                    /* '<Root>/Data Store Memory3' */
  real32_T T4;                         /* '<Root>/Data Store Memory4' */
  real32_T T5;                         /* '<Root>/Data Store Memory5' */
  real32_T T1;                         /* '<Root>/Data Store Memory7' */
  real32_T T2;                         /* '<Root>/Data Store Memory8' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S6>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_SYSTEM_;/* '<S12>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_c;/* '<S5>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_SYSTE_o;/* '<S11>/Discrete-Time Integrator1' */
  rtDW_EmbeddedMATLABFunction_SAL sf_EmbeddedMATLABFunction_k;/* '<S24>/Embedded MATLAB Function' */
  rtDW_EmbeddedMATLABFunction_SAL sf_EmbeddedMATLABFunction;/* '<S23>/Embedded MATLAB Function' */
  rtDW_EmbeddedMATLABFunction_SAL sf_EmbeddedMATLABFunction_a;/* '<S17>/Embedded MATLAB Function' */
  rtDW_EmbeddedMATLABFunction_SAL sf_EmbeddedMATLABFunction_e;/* '<S16>/Embedded MATLAB Function' */
} D_Work_SALTStabilizationInnerOu;

/* Parameters (auto storage) */
struct Parameters_SALTStabilizationInn_ {
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S11>/Constant5'
                                        */
  real_T Constant5_Value_j;            /* Expression: 0
                                        * Referenced by: '<S12>/Constant5'
                                        */
  real_T Constant_Value;               /* Expression: T
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: f
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T Constant_Value_p;             /* Expression: T
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: f
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Kp2_Value;                    /* Expression: 2
                                        * Referenced by: '<S2>/Kp 2'
                                        */
  real_T Ki2_Value;                    /* Expression: .5
                                        * Referenced by: '<S2>/Ki 2'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S12>/Memory1'
                                        */
  real_T Kp1_Value;                    /* Expression: 1
                                        * Referenced by: '<S2>/Kp 1'
                                        */
  real_T SaturationLimit1_Value;       /* Expression: 100 * (pi/180)
                                        * Referenced by: '<S12>/SaturationLimit1'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S12>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S12>/Discrete-Time Integrator1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 4*pi
                                        * Referenced by: '<S12>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -4*pi
                                        * Referenced by: '<S12>/Saturation1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Constant_Value_f;             /* Expression: T
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Constant1_Value_f;            /* Expression: f
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T Constant_Value_m;             /* Expression: T
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Constant1_Value_k;            /* Expression: f
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T Kp2_Value_f;                  /* Expression: 2
                                        * Referenced by: '<S1>/Kp 2'
                                        */
  real_T Ki2_Value_b;                  /* Expression: .5
                                        * Referenced by: '<S1>/Ki 2'
                                        */
  real_T Memory1_X0_k;                 /* Expression: 0
                                        * Referenced by: '<S11>/Memory1'
                                        */
  real_T Kp1_Value_e;                  /* Expression: 1
                                        * Referenced by: '<S1>/Kp 1'
                                        */
  real_T SaturationLimit1_Value_o;     /* Expression: 100 * (pi/180)
                                        * Referenced by: '<S11>/SaturationLimit1'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_g;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_g
                                          * Referenced by: '<S11>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_g; /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator1'
                                        */
  real_T Saturation1_UpperSat_j;       /* Expression: 4*pi
                                        * Referenced by: '<S11>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_c;       /* Expression: -4*pi
                                        * Referenced by: '<S11>/Saturation1'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real32_T Gain1_Gain_b;               /* Computed Parameter: Gain1_Gain_b
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                           * Referenced by: '<S6>/Discrete-Time Integrator'
                                           */
  real32_T DiscreteTimeIntegrator_IC;  /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S6>/Discrete-Time Integrator'
                                        */
  real32_T Gain4_Gain_b;               /* Computed Parameter: Gain4_Gain_b
                                        * Referenced by: '<S6>/Gain4'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S12>/Gain'
                                        */
  real32_T Gain_Gain_a[6];             /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S8>/Gain'
                                        */
  real32_T Gain1_Gain_k;               /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_e;/* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                                            * Referenced by: '<S5>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_a;/* Computed Parameter: DiscreteTimeIntegrator_IC_a
                                        * Referenced by: '<S5>/Discrete-Time Integrator'
                                        */
  real32_T Gain4_Gain_j;               /* Computed Parameter: Gain4_Gain_j
                                        * Referenced by: '<S5>/Gain4'
                                        */
  real32_T Gain_Gain_c;                /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S11>/Gain'
                                        */
  real32_T Gain_Gain_cl[6];            /* Computed Parameter: Gain_Gain_cl
                                        * Referenced by: '<S7>/Gain'
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
 * '<S1>'   : 'SALTStabilizationInnerOuterLoop/Controller'
 * '<S2>'   : 'SALTStabilizationInnerOuterLoop/Controller1'
 * '<S3>'   : 'SALTStabilizationInnerOuterLoop/Duty Cycles'
 * '<S4>'   : 'SALTStabilizationInnerOuterLoop/Duty Cycles1'
 * '<S5>'   : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop1'
 * '<S6>'   : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop2'
 * '<S7>'   : 'SALTStabilizationInnerOuterLoop/alphabeta-to-abc'
 * '<S8>'   : 'SALTStabilizationInnerOuterLoop/alphabeta-to-abc1'
 * '<S9>'   : 'SALTStabilizationInnerOuterLoop/dq-to-alphabeta'
 * '<S10>'  : 'SALTStabilizationInnerOuterLoop/dq-to-alphabeta1'
 * '<S11>'  : 'SALTStabilizationInnerOuterLoop/Controller/PID with External D and anti-windup4'
 * '<S12>'  : 'SALTStabilizationInnerOuterLoop/Controller1/PID with External D and anti-windup4'
 * '<S13>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop1/MATLAB Function'
 * '<S14>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop1/MATLAB Function1'
 * '<S15>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop1/MATLAB Function2'
 * '<S16>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop1/Tustin Lowpass, Auto Initial Condition'
 * '<S17>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop1/Tustin Lowpass, Auto Initial Condition1'
 * '<S18>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop1/Tustin Lowpass, Auto Initial Condition/Embedded MATLAB Function'
 * '<S19>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop1/Tustin Lowpass, Auto Initial Condition1/Embedded MATLAB Function'
 * '<S20>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop2/MATLAB Function'
 * '<S21>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop2/MATLAB Function1'
 * '<S22>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop2/MATLAB Function2'
 * '<S23>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop2/Tustin Lowpass, Auto Initial Condition'
 * '<S24>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop2/Tustin Lowpass, Auto Initial Condition1'
 * '<S25>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop2/Tustin Lowpass, Auto Initial Condition/Embedded MATLAB Function'
 * '<S26>'  : 'SALTStabilizationInnerOuterLoop/Y Axis Inner Outer Loop2/Tustin Lowpass, Auto Initial Condition1/Embedded MATLAB Function'
 * '<S27>'  : 'SALTStabilizationInnerOuterLoop/dq-to-alphabeta/vector mixer'
 * '<S28>'  : 'SALTStabilizationInnerOuterLoop/dq-to-alphabeta1/vector mixer'
 */
#endif                                 /* RTW_HEADER_SALTStabilizationInnerOuterLoop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
