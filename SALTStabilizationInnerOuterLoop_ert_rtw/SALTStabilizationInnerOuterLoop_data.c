/*
 * File: SALTStabilizationInnerOuterLoop_data.c
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

/* Block parameters (auto storage) */
Parameters_SALTStabilizationInn SALTStabilizationInnerOuterLo_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Constant5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Constant5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Constant5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/Constant5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Kp 1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Ki 1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Memory1'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S10>/Kd 1'
                                        */
  1.7453292519943295,                  /* Expression: 100 * (pi/180)
                                        * Referenced by: '<S15>/SaturationLimit1'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S15>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Discrete-Time Integrator1'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S15>/Saturation1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S15>/Saturation1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Kp 2'
                                        */
  0.001,                               /* Expression: T_step
                                        * Referenced by: '<S14>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Ki 2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Memory1'
                                        */
  1.7453292519943295,                  /* Expression: 100 * (pi/180)
                                        * Referenced by: '<S14>/SaturationLimit1'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator1_gainv_l
                                        * Referenced by: '<S14>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Discrete-Time Integrator1'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S14>/Saturation1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S14>/Saturation1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/Kp 1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Ki 1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/Memory1'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S17>/Kd 1'
                                        */
  1.7453292519943295,                  /* Expression: 100 * (pi/180)
                                        * Referenced by: '<S22>/SaturationLimit1'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator1_gainv_d
                                        * Referenced by: '<S22>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/Discrete-Time Integrator1'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S22>/Saturation1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S22>/Saturation1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/Kp 2'
                                        */
  0.001,                               /* Expression: T_step
                                        * Referenced by: '<S21>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Ki 2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Memory1'
                                        */
  1.7453292519943295,                  /* Expression: 100 * (pi/180)
                                        * Referenced by: '<S21>/SaturationLimit1'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator1_gainv_b
                                        * Referenced by: '<S21>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Discrete-Time Integrator1'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S21>/Saturation1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S21>/Saturation1'
                                        */
  0.0005F,                             /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S9>/Discrete-Time Integrator'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S9>/Discrete-Time Integrator'
                                        */
  0.0005F,                             /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                        * Referenced by: '<S10>/Discrete-Time Integrator'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator_IC_a
                                        * Referenced by: '<S10>/Discrete-Time Integrator'
                                        */
  0.001F,                              /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S15>/Gain'
                                        */

  /*  Computed Parameter: Gain_Gain_a
   * Referenced by: '<S6>/Gain'
   */
  { 1.0F, -0.5F, -0.5F, 0.0F, 0.866025388F, -0.866025388F },
  -1.0F,                               /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S4>/Gain4'
                                        */
  0.0005F,                             /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                        * Referenced by: '<S16>/Discrete-Time Integrator'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator_IC_f
                                        * Referenced by: '<S16>/Discrete-Time Integrator'
                                        */
  0.0005F,                             /* Computed Parameter: DiscreteTimeIntegrator_gainva_c
                                        * Referenced by: '<S17>/Discrete-Time Integrator'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator_IC_n
                                        * Referenced by: '<S17>/Discrete-Time Integrator'
                                        */
  0.001F,                              /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S22>/Gain'
                                        */

  /*  Computed Parameter: Gain_Gain_c
   * Referenced by: '<S5>/Gain'
   */
  { 1.0F, -0.5F, -0.5F, 0.0F, 0.866025388F, -0.866025388F },
  0.0F,                                /* Computed Parameter: DataStoreMemory_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory1_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory1'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory10_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory10'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory11_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory11'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory12_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory12'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory13_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory13'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory14_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory14'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory15_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory15'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory16_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory16'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory17_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory17'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory18_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory18'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory19_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory19'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory2_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory2'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory3_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory3'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory4_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory4'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory5_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory5'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory6_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory6'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory7_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory7'
                                        */
  0.0F,                                /* Computed Parameter: DataStoreMemory8_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory8'
                                        */
  0.0F                                 /* Computed Parameter: DataStoreMemory9_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory9'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
