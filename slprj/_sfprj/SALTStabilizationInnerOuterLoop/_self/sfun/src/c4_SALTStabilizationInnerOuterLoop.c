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
static const char * c4_debug_family_names[11] = { "omega", "nargin", "nargout",
  "u", "T", "f", "y", "a", "b", "y_km1", "u_km1" };

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
   mxArray *c4_b_u_km1, const char_T *c4_identifier);
static real32_T c4_b_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real32_T c4_c_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_b_y_km1, const char_T *c4_identifier);
static real32_T c4_d_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_e_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_b_b, const char_T *c4_identifier);
static real_T c4_f_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_g_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_b_a, const char_T *c4_identifier);
static real_T c4_h_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real32_T c4_i_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_y, const char_T *c4_identifier);
static real32_T c4_j_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_k_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_l_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_m_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_b_is_active_c4_SALTStabilizationInnerOuterLoop, const char_T
   *c4_identifier);
static uint8_T c4_n_emlrt_marshallIn
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
  chartInstance->c4_a_not_empty = FALSE;
  chartInstance->c4_b_not_empty = FALSE;
  chartInstance->c4_y_km1_not_empty = FALSE;
  chartInstance->c4_u_km1_not_empty = FALSE;
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
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real32_T c4_d_hoistedGlobal;
  real32_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  real32_T c4_e_hoistedGlobal;
  real32_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  uint8_T c4_f_hoistedGlobal;
  uint8_T c4_f_u;
  const mxArray *c4_g_y = NULL;
  real32_T *c4_h_y;
  c4_h_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(6), FALSE);
  c4_hoistedGlobal = *c4_h_y;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = chartInstance->c4_a;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  if (!chartInstance->c4_a_not_empty) {
    sf_mex_assign(&c4_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = chartInstance->c4_b;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  if (!chartInstance->c4_b_not_empty) {
    sf_mex_assign(&c4_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = chartInstance->c4_u_km1;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  if (!chartInstance->c4_u_km1_not_empty) {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 1, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = chartInstance->c4_y_km1;
  c4_e_u = c4_e_hoistedGlobal;
  c4_f_y = NULL;
  if (!chartInstance->c4_y_km1_not_empty) {
    sf_mex_assign(&c4_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 1, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_f_hoistedGlobal =
    chartInstance->c4_is_active_c4_SALTStabilizationInnerOuterLoop;
  c4_f_u = c4_f_hoistedGlobal;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 5, c4_g_y);
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
  *c4_y = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
    "y");
  chartInstance->c4_a = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "a");
  chartInstance->c4_b = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 2)), "b");
  chartInstance->c4_u_km1 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 3)), "u_km1");
  chartInstance->c4_y_km1 = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 4)), "y_km1");
  chartInstance->c4_is_active_c4_SALTStabilizationInnerOuterLoop =
    c4_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 5)),
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
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real32_T c4_u;
  real_T c4_T;
  real_T c4_f;
  uint32_T c4_debug_family_var_map[11];
  real_T c4_omega;
  real_T c4_nargin = 3.0;
  real_T c4_nargout = 1.0;
  real32_T c4_y;
  real_T c4_b_b;
  real_T c4_b_a;
  real_T c4_c_b;
  real_T c4_b_y;
  real_T c4_c_a;
  real_T c4_d_b;
  real_T c4_c_y;
  real_T c4_A;
  real_T c4_B;
  real_T c4_x;
  real_T c4_d_y;
  real_T c4_b_x;
  real_T c4_e_y;
  real_T c4_d_a;
  real_T c4_e_b;
  real_T c4_f_y;
  real_T c4_e_a;
  real_T c4_f_b;
  real_T c4_g_y;
  real_T c4_b_A;
  real_T c4_b_B;
  real_T c4_c_x;
  real_T c4_h_y;
  real_T c4_d_x;
  real_T c4_i_y;
  real_T c4_d_hoistedGlobal;
  real32_T c4_e_hoistedGlobal;
  real_T c4_f_a;
  real32_T c4_g_b;
  real32_T c4_j_y;
  real_T c4_f_hoistedGlobal;
  real32_T c4_g_hoistedGlobal;
  real_T c4_g_a;
  real32_T c4_h_b;
  real32_T c4_k_y;
  real_T *c4_b_f;
  real_T *c4_b_T;
  real32_T *c4_b_u;
  real32_T *c4_l_y;
  c4_b_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_l_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_u = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c4_b_u, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c4_l_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_b_T, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_b_f, 3U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_u;
  c4_b_hoistedGlobal = *c4_b_T;
  c4_c_hoistedGlobal = *c4_b_f;
  c4_u = c4_hoistedGlobal;
  c4_T = c4_b_hoistedGlobal;
  c4_f = c4_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 11U, 11U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c4_omega, 0U, c4_f_sf_marshallOut,
    c4_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 1U, c4_f_sf_marshallOut,
    c4_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 2U, c4_f_sf_marshallOut,
    c4_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_u, 3U, c4_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_T, 4U, c4_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_f, 5U, c4_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_y, 6U, c4_e_sf_marshallOut,
    c4_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c4_a, 7U,
    c4_d_sf_marshallOut, c4_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c4_b, 8U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c4_y_km1, 9U,
    c4_b_sf_marshallOut, c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c4_u_km1, 10U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c4_a_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
    c4_b_b = c4_f;
    c4_omega = 6.2831853071795862 * c4_b_b;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
    c4_b_a = c4_T;
    c4_c_b = c4_omega;
    c4_b_y = c4_b_a * c4_c_b;
    c4_c_a = c4_T;
    c4_d_b = c4_omega;
    c4_c_y = c4_c_a * c4_d_b;
    c4_A = c4_b_y;
    c4_B = 2.0 + c4_c_y;
    c4_x = c4_A;
    c4_d_y = c4_B;
    c4_b_x = c4_x;
    c4_e_y = c4_d_y;
    chartInstance->c4_a = c4_b_x / c4_e_y;
    chartInstance->c4_a_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
    c4_d_a = c4_T;
    c4_e_b = c4_omega;
    c4_f_y = c4_d_a * c4_e_b;
    c4_e_a = c4_T;
    c4_f_b = c4_omega;
    c4_g_y = c4_e_a * c4_f_b;
    c4_b_A = -(c4_f_y - 2.0);
    c4_b_B = c4_g_y + 2.0;
    c4_c_x = c4_b_A;
    c4_h_y = c4_b_B;
    c4_d_x = c4_c_x;
    c4_i_y = c4_h_y;
    chartInstance->c4_b = c4_d_x / c4_i_y;
    chartInstance->c4_b_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
    chartInstance->c4_y_km1 = c4_u;
    chartInstance->c4_y_km1_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
    chartInstance->c4_u_km1 = c4_u;
    chartInstance->c4_u_km1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
  c4_d_hoistedGlobal = chartInstance->c4_a;
  c4_e_hoistedGlobal = chartInstance->c4_u_km1;
  c4_f_a = c4_d_hoistedGlobal;
  c4_g_b = c4_u + c4_e_hoistedGlobal;
  c4_j_y = (real32_T)c4_f_a * c4_g_b;
  c4_f_hoistedGlobal = chartInstance->c4_b;
  c4_g_hoistedGlobal = chartInstance->c4_y_km1;
  c4_g_a = c4_f_hoistedGlobal;
  c4_h_b = c4_g_hoistedGlobal;
  c4_k_y = (real32_T)c4_g_a * c4_h_b;
  c4_y = c4_j_y + c4_k_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
  chartInstance->c4_y_km1 = c4_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
  chartInstance->c4_u_km1 = c4_u;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -21);
  sf_debug_symbol_scope_pop();
  *c4_l_y = c4_y;
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
  if (!chartInstance->c4_u_km1_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 1, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real32_T c4_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_b_u_km1, const char_T *c4_identifier)
{
  real32_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_u_km1), &c4_thisId);
  sf_mex_destroy(&c4_b_u_km1);
  return c4_y;
}

static real32_T c4_b_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real32_T c4_y;
  real32_T c4_f0;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_u_km1_not_empty = FALSE;
  } else {
    chartInstance->c4_u_km1_not_empty = TRUE;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_f0, 1, 1, 0U, 0, 0U, 0);
    c4_y = c4_f0;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_u_km1;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real32_T c4_y;
  SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c4_b_u_km1 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_u_km1), &c4_thisId);
  sf_mex_destroy(&c4_b_u_km1);
  *(real32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
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
  if (!chartInstance->c4_y_km1_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 1, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real32_T c4_c_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_b_y_km1, const char_T *c4_identifier)
{
  real32_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_y_km1), &c4_thisId);
  sf_mex_destroy(&c4_b_y_km1);
  return c4_y;
}

static real32_T c4_d_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real32_T c4_y;
  real32_T c4_f1;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_y_km1_not_empty = FALSE;
  } else {
    chartInstance->c4_y_km1_not_empty = TRUE;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_f1, 1, 1, 0U, 0, 0U, 0);
    c4_y = c4_f1;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_y_km1;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real32_T c4_y;
  SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c4_b_y_km1 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_y_km1), &c4_thisId);
  sf_mex_destroy(&c4_b_y_km1);
  *(real32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
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
  if (!chartInstance->c4_b_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_e_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_b_b, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_b), &c4_thisId);
  sf_mex_destroy(&c4_b_b);
  return c4_y;
}

static real_T c4_f_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_b_not_empty = FALSE;
  } else {
    chartInstance->c4_b_not_empty = TRUE;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d0;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_b;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c4_b_b = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_b), &c4_thisId);
  sf_mex_destroy(&c4_b_b);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
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
  if (!chartInstance->c4_a_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_g_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_b_a, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_a), &c4_thisId);
  sf_mex_destroy(&c4_b_a);
  return c4_y;
}

static real_T c4_h_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d1;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_a_not_empty = FALSE;
  } else {
    chartInstance->c4_a_not_empty = TRUE;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d1, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d1;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_a;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c4_b_a = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_a), &c4_thisId);
  sf_mex_destroy(&c4_b_a);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
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

static real32_T c4_i_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_y, const char_T *c4_identifier)
{
  real32_T c4_b_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_y), &c4_thisId);
  sf_mex_destroy(&c4_y);
  return c4_b_y;
}

static real32_T c4_j_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real32_T c4_y;
  real32_T c4_f2;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_f2, 1, 1, 0U, 0, 0U, 0);
  c4_y = c4_f2;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
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
  c4_b_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_y), &c4_thisId);
  sf_mex_destroy(&c4_y);
  *(real32_T *)c4_outData = c4_b_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
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

static real_T c4_k_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d2;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d2, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d2;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
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
  c4_y = c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
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
  (*c4_b_info)[0].name = "mtimes";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[0].fileTimeLo = 1289552092U;
  (*c4_b_info)[0].fileTimeHi = 0U;
  (*c4_b_info)[0].mFileTimeLo = 0U;
  (*c4_b_info)[0].mFileTimeHi = 0U;
  (*c4_b_info)[1].context = "";
  (*c4_b_info)[1].name = "mrdivide";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[1].fileTimeLo = 1310169856U;
  (*c4_b_info)[1].fileTimeHi = 0U;
  (*c4_b_info)[1].mFileTimeLo = 1289552092U;
  (*c4_b_info)[1].mFileTimeHi = 0U;
  (*c4_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[2].name = "rdivide";
  (*c4_b_info)[2].dominantType = "double";
  (*c4_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[2].fileTimeLo = 1286851244U;
  (*c4_b_info)[2].fileTimeHi = 0U;
  (*c4_b_info)[2].mFileTimeLo = 0U;
  (*c4_b_info)[2].mFileTimeHi = 0U;
  (*c4_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[3].name = "eml_div";
  (*c4_b_info)[3].dominantType = "double";
  (*c4_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c4_b_info)[3].fileTimeLo = 1305350400U;
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

static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
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

static int32_T c4_l_emlrt_marshallIn
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

static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
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
  c4_y = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_m_emlrt_marshallIn
  (SFc4_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c4_b_is_active_c4_SALTStabilizationInnerOuterLoop, const char_T
   *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_n_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_SALTStabilizationInnerOuterLoop), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_SALTStabilizationInnerOuterLoop);
  return c4_y;
}

static uint8_T c4_n_emlrt_marshallIn
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
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(600195861U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1481686670U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3850971951U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3227197664U);
}

mxArray *sf_c4_SALTStabilizationInnerOuterLoop_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xPSKulkZc4YItyxVKAHmVE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
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
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[4],M[0],T\"a\",S'l','i','p'{{M1x2[137 138],M[0],}}},{M[4],M[0],T\"b\",S'l','i','p'{{M1x2[150 151],M[0],}}},{M[4],M[0],T\"u_km1\",S'l','i','p'{{M1x2[180 185],M[0],}}},{M[4],M[0],T\"y_km1\",S'l','i','p'{{M1x2[163 168],M[0],}}},{M[8],M[0],T\"is_active_c4_SALTStabilizationInnerOuterLoop\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
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
           4,
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
          _SFD_SET_DATA_PROPS(2,1,1,0,"T");
          _SFD_SET_DATA_PROPS(3,1,1,0,"f");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,455);
        _SFD_CV_INIT_EML_IF(0,1,0,186,199,-1,411);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_e_sf_marshallOut,(MexInFcnForType)c4_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_f_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real32_T *c4_u;
          real32_T *c4_y;
          real_T *c4_T;
          real_T *c4_f;
          c4_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_u = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_T);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_f);
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
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,4,3);
      sf_mark_chart_reusable_outputs(S,infoStruct,4,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(58949766U));
  ssSetChecksum1(S,(92660768U));
  ssSetChecksum2(S,(2673891774U));
  ssSetChecksum3(S,(3176145421U));
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
