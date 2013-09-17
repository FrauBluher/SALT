/*
 * File: SALTStabilizationInnerOuterLoop_data.c
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

/* Block parameters (auto storage) */
Parameters_SALTStabilizationInn SALTStabilizationInnerOuterLo_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Constant5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Constant5'
                                        */
  0.001,                               /* Expression: T
                                        * Referenced by: '<S23>/Constant'
                                        */
  3.0,                                 /* Expression: f
                                        * Referenced by: '<S23>/Constant1'
                                        */
  0.001,                               /* Expression: T
                                        * Referenced by: '<S24>/Constant'
                                        */
  3.0,                                 /* Expression: f
                                        * Referenced by: '<S24>/Constant1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S2>/Kp 2'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S2>/Ki 2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Memory1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Kp 1'
                                        */
  1.7453292519943295,                  /* Expression: 100 * (pi/180)
                                        * Referenced by: '<S12>/SaturationLimit1'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S12>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Discrete-Time Integrator1'
                                        */
  12.566370614359172,                  /* Expression: 4*pi
                                        * Referenced by: '<S12>/Saturation1'
                                        */
  -12.566370614359172,                 /* Expression: -4*pi
                                        * Referenced by: '<S12>/Saturation1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  0.001,                               /* Expression: T
                                        * Referenced by: '<S16>/Constant'
                                        */
  3.0,                                 /* Expression: f
                                        * Referenced by: '<S16>/Constant1'
                                        */
  0.001,                               /* Expression: T
                                        * Referenced by: '<S17>/Constant'
                                        */
  3.0,                                 /* Expression: f
                                        * Referenced by: '<S17>/Constant1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S1>/Kp 2'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S1>/Ki 2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Memory1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Kp 1'
                                        */
  1.7453292519943295,                  /* Expression: 100 * (pi/180)
                                        * Referenced by: '<S11>/SaturationLimit1'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator1_gainv_g
                                        * Referenced by: '<S11>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator1'
                                        */
  12.566370614359172,                  /* Expression: 4*pi
                                        * Referenced by: '<S11>/Saturation1'
                                        */
  -12.566370614359172,                 /* Expression: -4*pi
                                        * Referenced by: '<S11>/Saturation1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain4'
                                        */
  0.333333343F,                        /* Computed Parameter: Gain1_Gain_b
                                        * Referenced by: '<S6>/Gain1'
                                        */
  0.0005F,                             /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S6>/Discrete-Time Integrator'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S6>/Discrete-Time Integrator'
                                        */
  -1.0F,                               /* Computed Parameter: Gain4_Gain_b
                                        * Referenced by: '<S6>/Gain4'
                                        */
  0.001F,                              /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S12>/Gain'
                                        */

  /*  Computed Parameter: Gain_Gain_a
   * Referenced by: '<S8>/Gain'
   */
  { 1.0F, -0.5F, -0.5F, 0.0F, 0.866025388F, -0.866025388F },
  0.333333343F,                        /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S5>/Gain1'
                                        */
  0.0005F,                             /* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                                        * Referenced by: '<S5>/Discrete-Time Integrator'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator_IC_a
                                        * Referenced by: '<S5>/Discrete-Time Integrator'
                                        */
  -1.0F,                               /* Computed Parameter: Gain4_Gain_j
                                        * Referenced by: '<S5>/Gain4'
                                        */
  0.001F,                              /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S11>/Gain'
                                        */

  /*  Computed Parameter: Gain_Gain_cl
   * Referenced by: '<S7>/Gain'
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
