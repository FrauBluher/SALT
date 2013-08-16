/* Include files */

#include "blascompat32.h"
#include "SALTStabilizationInnerOuterLoop_sfun.h"
#include "c4_SALTStabilizationInnerOuterLoop.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SALTStabilizationInnerOuterLoop_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[4] = { "nargin", "nargout", "u", "y" };

/* Function Declarations */
static void initialize_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void initialize_params_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void enable_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void disable_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void set_sim_state_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_st);
static void finalize_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void sf_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void initSimStructsc4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real32_T c4_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_y, const char_T *c4_identifier);
static real32_T c4_b_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_d_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_e_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_b_is_active_c4_SALTStabilizationInnerOuterLoop, const char_T
   *c4_identifier);
static uint8_T c4_f_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_SALTStabilizationInnerOuterLoop = 0U;
}

static void initialize_params_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

static void enable_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real32_T c4_hoistedGlobal;
  real32_T c4_u;
  const mxArray *c4_b_y = NULL;
  uint8_T c4_b_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real32_T *c4_d_y;
  c4_d_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2), FALSE);
  c4_hoistedGlobal = *c4_d_y;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal =
    chartInstance->c4_is_active_c4_SALTStabilizationInnerOuterLoop;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_st)
{
  const mxArray *c4_u;
  real32_T *c4_y;
  c4_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  *c4_y = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
    "y");
  chartInstance->c4_is_active_c4_SALTStabilizationInnerOuterLoop =
    c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
    "is_active_c4_SALTStabilizationInnerOuterLoop");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_SALTStabilizationInnerOuterLoop(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

static void sf_c4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  real32_T c4_hoistedGlobal;
  real32_T c4_u;
  uint32_T c4_debug_family_var_map[4];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real32_T c4_y;
  real32_T c4_A;
  real32_T c4_x;
  real32_T c4_b_x;
  real32_T c4_b_y;
  real32_T c4_a;
  real32_T c4_c_y;
  real32_T c4_b_a;
  real32_T *c4_b_u;
  real32_T *c4_d_y;
  c4_d_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_u = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c4_b_u, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c4_d_y, 1U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_u;
  c4_u = c4_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_u, 2U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_y, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_A = c4_u;
  c4_x = c4_A;
  c4_b_x = c4_x;
  c4_b_y = c4_b_x / 131.0F;
  c4_a = c4_b_y;
  c4_c_y = c4_a * 0.0174532924F;
  c4_b_a = c4_c_y;
  c4_y = c4_b_a * 5.0F;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  *c4_d_y = c4_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_SALTStabilizationInnerOuterLoopMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc4_SALTStabilizationInnerOuterLoop
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real32_T c4_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_y, const char_T *c4_identifier)
{
  real32_T c4_b_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_y), &c4_thisId);
  sf_mex_destroy(&c4_y);
  return c4_b_y;
}

static real32_T c4_b_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real32_T c4_y;
  real32_T c4_f0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_f0, 1, 1, 0U, 0, 0U, 0);
  c4_y = c4_f0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_y;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real32_T c4_b_y;
  SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c4_y = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_y), &c4_thisId);
  sf_mex_destroy(&c4_y);
  *(real32_T *)c4_outData = c4_b_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray
  *sf_c4_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[4];
  c4_ResolvedFunctionInfo (*c4_b_info)[4];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i0;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[4])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "mrdivide";
  (*c4_b_info)[0].dominantType = "single";
  (*c4_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[0].fileTimeLo = 1310169856U;
  (*c4_b_info)[0].fileTimeHi = 0U;
  (*c4_b_info)[0].mFileTimeLo = 1289552092U;
  (*c4_b_info)[0].mFileTimeHi = 0U;
  (*c4_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[1].name = "rdivide";
  (*c4_b_info)[1].dominantType = "single";
  (*c4_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[1].fileTimeLo = 1286851244U;
  (*c4_b_info)[1].fileTimeHi = 0U;
  (*c4_b_info)[1].mFileTimeLo = 0U;
  (*c4_b_info)[1].mFileTimeHi = 0U;
  (*c4_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[2].name = "eml_div";
  (*c4_b_info)[2].dominantType = "single";
  (*c4_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c4_b_info)[2].fileTimeLo = 1305350400U;
  (*c4_b_info)[2].fileTimeHi = 0U;
  (*c4_b_info)[2].mFileTimeLo = 0U;
  (*c4_b_info)[2].mFileTimeHi = 0U;
  (*c4_b_info)[3].context = "";
  (*c4_b_info)[3].name = "mtimes";
  (*c4_b_info)[3].dominantType = "single";
  (*c4_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[3].fileTimeLo = 1289552092U;
  (*c4_b_info)[3].fileTimeHi = 0U;
  (*c4_b_info)[3].mFileTimeLo = 0U;
  (*c4_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4), FALSE);
  for (c4_i0 = 0; c4_i0 < 4; c4_i0++) {
    c4_r0 = &c4_info[c4_i0];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i0);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_d_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i1;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i1, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_e_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_b_is_active_c4_SALTStabilizationInnerOuterLoop, const char_T
   *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_SALTStabilizationInnerOuterLoop), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_SALTStabilizationInnerOuterLoop);
  return c4_y;
}

static uint8_T c4_f_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_SALTStabilizationInnerOuterLoop_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(44922973U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4030279796U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3494153051U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3665938122U);
}

mxArray *sf_c4_SALTStabilizationInnerOuterLoop_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xG35iPbBEaGhACUEmUwYK");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c4_SALTStabilizationInnerOuterLoop
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c4_SALTStabilizationInnerOuterLoop\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_SALTStabilizationInnerOuterLoop_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
    chartInstance = (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SALTStabilizationInnerOuterLoopMachineNumber_,
           4,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_SALTStabilizationInnerOuterLoopMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_SALTStabilizationInnerOuterLoopMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_SALTStabilizationInnerOuterLoopMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,58);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          real32_T *c4_u;
          real32_T *c4_y;
          c4_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_u = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_SALTStabilizationInnerOuterLoopMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c4_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc4_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar)->S,
     0);
  initialize_params_c4_SALTStabilizationInnerOuterLoop
    ((SFc4_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
  initialize_c4_SALTStabilizationInnerOuterLoop
    ((SFc4_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  enable_c4_SALTStabilizationInnerOuterLoop
    ((SFc4_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  disable_c4_SALTStabilizationInnerOuterLoop
    ((SFc4_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  sf_c4_SALTStabilizationInnerOuterLoop
    ((SFc4_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c4_SALTStabilizationInnerOuterLoop(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_SALTStabilizationInnerOuterLoop
    ((SFc4_SALTStabilizationInnerOuterLoopInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_SALTStabilizationInnerOuterLoop();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c4_SALTStabilizationInnerOuterLoop
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_SALTStabilizationInnerOuterLoop();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_SALTStabilizationInnerOuterLoop
    ((SFc4_SALTStabilizationInnerOuterLoopInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_SALTStabilizationInnerOuterLoop
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c4_SALTStabilizationInnerOuterLoop(S);
}

static void sf_opaque_set_sim_state_c4_SALTStabilizationInnerOuterLoop(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c4_SALTStabilizationInnerOuterLoop(S, st);
}

static void sf_opaque_terminate_c4_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_SALTStabilizationInnerOuterLoopInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_SALTStabilizationInnerOuterLoop
      ((SFc4_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_SALTStabilizationInnerOuterLoop_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_SALTStabilizationInnerOuterLoop
    ((SFc4_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_SALTStabilizationInnerOuterLoop(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_SALTStabilizationInnerOuterLoop
      ((SFc4_SALTStabilizationInnerOuterLoopInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_SALTStabilizationInnerOuterLoop(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_SALTStabilizationInnerOuterLoop_optimization_info
      ();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,infoStruct,4,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(736698651U));
  ssSetChecksum1(S,(388711017U));
  ssSetChecksum2(S,(978960088U));
  ssSetChecksum3(S,(818443017U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_SALTStabilizationInnerOuterLoop(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_SALTStabilizationInnerOuterLoop(SimStruct *S)
{
  SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *)malloc
    (sizeof(SFc4_SALTStabilizationInnerOuterLoopInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c4_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c4_SALTStabilizationInnerOuterLoop_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_SALTStabilizationInnerOuterLoop(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_SALTStabilizationInnerOuterLoop(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_SALTStabilizationInnerOuterLoop(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_SALTStabilizationInnerOuterLoop_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
