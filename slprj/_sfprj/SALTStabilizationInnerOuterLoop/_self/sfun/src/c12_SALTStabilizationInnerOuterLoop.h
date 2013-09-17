#ifndef __c12_SALTStabilizationInnerOuterLoop_h__
#define __c12_SALTStabilizationInnerOuterLoop_h__

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
} c12_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c12_a;
  real_T c12_b;
  int32_T c12_sfEvent;
  real32_T c12_u_km1;
  real32_T c12_y_km1;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c12_a_not_empty;
  boolean_T c12_b_not_empty;
  boolean_T c12_doneDoubleBufferReInit;
  boolean_T c12_isStable;
  boolean_T c12_u_km1_not_empty;
  boolean_T c12_y_km1_not_empty;
  uint8_T c12_is_active_c12_SALTStabilizationInnerOuterLoop;
  ChartInfoStruct chartInfo;
} SFc12_SALTStabilizationInnerOuterLoopInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c12_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c12_SALTStabilizationInnerOuterLoop_get_check_sum(mxArray *plhs[]);
extern void c12_SALTStabilizationInnerOuterLoop_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
