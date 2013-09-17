#ifndef __c5_SALTStabilizationInnerOuterLoop_h__
#define __c5_SALTStabilizationInnerOuterLoop_h__

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
} c5_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c5_a;
  real_T c5_b;
  int32_T c5_sfEvent;
  real32_T c5_u_km1;
  real32_T c5_y_km1;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c5_a_not_empty;
  boolean_T c5_b_not_empty;
  boolean_T c5_doneDoubleBufferReInit;
  boolean_T c5_isStable;
  boolean_T c5_u_km1_not_empty;
  boolean_T c5_y_km1_not_empty;
  uint8_T c5_is_active_c5_SALTStabilizationInnerOuterLoop;
  ChartInfoStruct chartInfo;
} SFc5_SALTStabilizationInnerOuterLoopInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c5_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_SALTStabilizationInnerOuterLoop_get_check_sum(mxArray *plhs[]);
extern void c5_SALTStabilizationInnerOuterLoop_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
