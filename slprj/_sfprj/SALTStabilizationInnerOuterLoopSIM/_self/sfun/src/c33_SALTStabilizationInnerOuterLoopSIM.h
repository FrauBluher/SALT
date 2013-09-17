#ifndef __c33_SALTStabilizationInnerOuterLoopSIM_h__
#define __c33_SALTStabilizationInnerOuterLoopSIM_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c33_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c33_a;
  real_T c33_b;
  int32_T c33_sfEvent;
  real32_T c33_u_km1;
  real32_T c33_y_km1;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c33_a_not_empty;
  boolean_T c33_b_not_empty;
  boolean_T c33_doneDoubleBufferReInit;
  boolean_T c33_isStable;
  boolean_T c33_u_km1_not_empty;
  boolean_T c33_y_km1_not_empty;
  uint8_T c33_is_active_c33_SALTStabilizationInnerOuterLoopSIM;
  ChartInfoStruct chartInfo;
} SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c33_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c33_SALTStabilizationInnerOuterLoopSIM_get_check_sum(mxArray
  *plhs[]);
extern void c33_SALTStabilizationInnerOuterLoopSIM_method_dispatcher(SimStruct
  *S, int_T method, void *data);

#endif
