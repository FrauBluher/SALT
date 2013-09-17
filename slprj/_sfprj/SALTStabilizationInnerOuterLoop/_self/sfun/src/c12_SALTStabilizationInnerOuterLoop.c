/* Include files */

#include "blascompat32.h"
#include "SALTStabilizationInnerOuterLoop_sfun.h"
#include "c12_SALTStabilizationInnerOuterLoop.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SALTStabilizationInnerOuterLoop_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c12_debug_family_names[11] = { "omega", "nargin", "nargout",
  "u", "T", "f", "y", "a", "b", "y_km1", "u_km1" };

/* Function Declarations */
static void initialize_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void initialize_params_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void enable_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void disable_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void c12_update_debugger_state_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void set_sim_state_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_st);
static void finalize_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void sf_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void initSimStructsc12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real32_T c12_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_b_u_km1, const char_T *c12_identifier);
static real32_T c12_b_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real32_T c12_c_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_b_y_km1, const char_T *c12_identifier);
static real32_T c12_d_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_e_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_b_b, const char_T *c12_identifier);
static real_T c12_f_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_g_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_b_a, const char_T *c12_identifier);
static real_T c12_h_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real32_T c12_i_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_y, const char_T *c12_identifier);
static real32_T c12_j_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_k_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_g_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_l_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint8_T c12_m_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_b_is_active_c12_SALTStabilizationInnerOuterLoop, const char_T
   *c12_identifier);
static uint8_T c12_n_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c12_a_not_empty = FALSE;
  chartInstance->c12_b_not_empty = FALSE;
  chartInstance->c12_y_km1_not_empty = FALSE;
  chartInstance->c12_u_km1_not_empty = FALSE;
  chartInstance->c12_is_active_c12_SALTStabilizationInnerOuterLoop = 0U;
}

static void initialize_params_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

static void enable_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c12_update_debugger_state_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  real32_T c12_hoistedGlobal;
  real32_T c12_u;
  const mxArray *c12_b_y = NULL;
  real_T c12_b_hoistedGlobal;
  real_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  real_T c12_c_hoistedGlobal;
  real_T c12_c_u;
  const mxArray *c12_d_y = NULL;
  real32_T c12_d_hoistedGlobal;
  real32_T c12_d_u;
  const mxArray *c12_e_y = NULL;
  real32_T c12_e_hoistedGlobal;
  real32_T c12_e_u;
  const mxArray *c12_f_y = NULL;
  uint8_T c12_f_hoistedGlobal;
  uint8_T c12_f_u;
  const mxArray *c12_g_y = NULL;
  real32_T *c12_h_y;
  c12_h_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellarray(6), FALSE);
  c12_hoistedGlobal = *c12_h_y;
  c12_u = c12_hoistedGlobal;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_b_hoistedGlobal = chartInstance->c12_a;
  c12_b_u = c12_b_hoistedGlobal;
  c12_c_y = NULL;
  if (!chartInstance->c12_a_not_empty) {
    sf_mex_assign(&c12_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c12_y, 1, c12_c_y);
  c12_c_hoistedGlobal = chartInstance->c12_b;
  c12_c_u = c12_c_hoistedGlobal;
  c12_d_y = NULL;
  if (!chartInstance->c12_b_not_empty) {
    sf_mex_assign(&c12_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_c_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c12_y, 2, c12_d_y);
  c12_d_hoistedGlobal = chartInstance->c12_u_km1;
  c12_d_u = c12_d_hoistedGlobal;
  c12_e_y = NULL;
  if (!chartInstance->c12_u_km1_not_empty) {
    sf_mex_assign(&c12_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_e_y, sf_mex_create("y", &c12_d_u, 1, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c12_y, 3, c12_e_y);
  c12_e_hoistedGlobal = chartInstance->c12_y_km1;
  c12_e_u = c12_e_hoistedGlobal;
  c12_f_y = NULL;
  if (!chartInstance->c12_y_km1_not_empty) {
    sf_mex_assign(&c12_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_f_y, sf_mex_create("y", &c12_e_u, 1, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c12_y, 4, c12_f_y);
  c12_f_hoistedGlobal =
    chartInstance->c12_is_active_c12_SALTStabilizationInnerOuterLoop;
  c12_f_u = c12_f_hoistedGlobal;
  c12_g_y = NULL;
  sf_mex_assign(&c12_g_y, sf_mex_create("y", &c12_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 5, c12_g_y);
  sf_mex_assign(&c12_st, c12_y, FALSE);
  return c12_st;
}

static void set_sim_state_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_st)
{
  const mxArray *c12_u;
  real32_T *c12_y;
  c12_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c12_doneDoubleBufferReInit = TRUE;
  c12_u = sf_mex_dup(c12_st);
  *c12_y = c12_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u,
    0)), "y");
  chartInstance->c12_a = c12_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 1)), "a");
  chartInstance->c12_b = c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 2)), "b");
  chartInstance->c12_u_km1 = c12_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 3)), "u_km1");
  chartInstance->c12_y_km1 = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 4)), "y_km1");
  chartInstance->c12_is_active_c12_SALTStabilizationInnerOuterLoop =
    c12_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 5)),
    "is_active_c12_SALTStabilizationInnerOuterLoop");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_SALTStabilizationInnerOuterLoop(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

static void sf_c12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  real32_T c12_hoistedGlobal;
  real_T c12_b_hoistedGlobal;
  real_T c12_c_hoistedGlobal;
  real32_T c12_u;
  real_T c12_T;
  real_T c12_f;
  uint32_T c12_debug_family_var_map[11];
  real_T c12_omega;
  real_T c12_nargin = 3.0;
  real_T c12_nargout = 1.0;
  real32_T c12_y;
  real_T c12_b_b;
  real_T c12_b_a;
  real_T c12_c_b;
  real_T c12_b_y;
  real_T c12_c_a;
  real_T c12_d_b;
  real_T c12_c_y;
  real_T c12_A;
  real_T c12_B;
  real_T c12_x;
  real_T c12_d_y;
  real_T c12_b_x;
  real_T c12_e_y;
  real_T c12_d_a;
  real_T c12_e_b;
  real_T c12_f_y;
  real_T c12_e_a;
  real_T c12_f_b;
  real_T c12_g_y;
  real_T c12_b_A;
  real_T c12_b_B;
  real_T c12_c_x;
  real_T c12_h_y;
  real_T c12_d_x;
  real_T c12_i_y;
  real_T c12_d_hoistedGlobal;
  real32_T c12_e_hoistedGlobal;
  real_T c12_f_a;
  real32_T c12_g_b;
  real32_T c12_j_y;
  real_T c12_f_hoistedGlobal;
  real32_T c12_g_hoistedGlobal;
  real_T c12_g_a;
  real32_T c12_h_b;
  real32_T c12_k_y;
  real_T *c12_b_f;
  real_T *c12_b_T;
  real32_T *c12_b_u;
  real32_T *c12_l_y;
  c12_b_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c12_b_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c12_l_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_b_u = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c12_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c12_b_u, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c12_l_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c12_b_T, 2U);
  _SFD_DATA_RANGE_CHECK(*c12_b_f, 3U);
  chartInstance->c12_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c12_sfEvent);
  c12_hoistedGlobal = *c12_b_u;
  c12_b_hoistedGlobal = *c12_b_T;
  c12_c_hoistedGlobal = *c12_b_f;
  c12_u = c12_hoistedGlobal;
  c12_T = c12_b_hoistedGlobal;
  c12_f = c12_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 11U, 11U, c12_debug_family_names,
    c12_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c12_omega, 0U, c12_f_sf_marshallOut,
    c12_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_nargin, 1U, c12_f_sf_marshallOut,
    c12_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_nargout, 2U,
    c12_f_sf_marshallOut, c12_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c12_u, 3U, c12_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c12_T, 4U, c12_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c12_f, 5U, c12_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c12_y, 6U, c12_e_sf_marshallOut,
    c12_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c12_a, 7U,
    c12_d_sf_marshallOut, c12_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c12_b, 8U,
    c12_c_sf_marshallOut, c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c12_y_km1, 9U,
    c12_b_sf_marshallOut, c12_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c12_u_km1, 10U,
    c12_sf_marshallOut, c12_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 9);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c12_a_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 12);
    c12_b_b = c12_f;
    c12_omega = 6.2831853071795862 * c12_b_b;
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 13);
    c12_b_a = c12_T;
    c12_c_b = c12_omega;
    c12_b_y = c12_b_a * c12_c_b;
    c12_c_a = c12_T;
    c12_d_b = c12_omega;
    c12_c_y = c12_c_a * c12_d_b;
    c12_A = c12_b_y;
    c12_B = 2.0 + c12_c_y;
    c12_x = c12_A;
    c12_d_y = c12_B;
    c12_b_x = c12_x;
    c12_e_y = c12_d_y;
    chartInstance->c12_a = c12_b_x / c12_e_y;
    chartInstance->c12_a_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 14);
    c12_d_a = c12_T;
    c12_e_b = c12_omega;
    c12_f_y = c12_d_a * c12_e_b;
    c12_e_a = c12_T;
    c12_f_b = c12_omega;
    c12_g_y = c12_e_a * c12_f_b;
    c12_b_A = -(c12_f_y - 2.0);
    c12_b_B = c12_g_y + 2.0;
    c12_c_x = c12_b_A;
    c12_h_y = c12_b_B;
    c12_d_x = c12_c_x;
    c12_i_y = c12_h_y;
    chartInstance->c12_b = c12_d_x / c12_i_y;
    chartInstance->c12_b_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 15);
    chartInstance->c12_y_km1 = c12_u;
    chartInstance->c12_y_km1_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 16);
    chartInstance->c12_u_km1 = c12_u;
    chartInstance->c12_u_km1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 19);
  c12_d_hoistedGlobal = chartInstance->c12_a;
  c12_e_hoistedGlobal = chartInstance->c12_u_km1;
  c12_f_a = c12_d_hoistedGlobal;
  c12_g_b = c12_u + c12_e_hoistedGlobal;
  c12_j_y = (real32_T)c12_f_a * c12_g_b;
  c12_f_hoistedGlobal = chartInstance->c12_b;
  c12_g_hoistedGlobal = chartInstance->c12_y_km1;
  c12_g_a = c12_f_hoistedGlobal;
  c12_h_b = c12_g_hoistedGlobal;
  c12_k_y = (real32_T)c12_g_a * c12_h_b;
  c12_y = c12_j_y + c12_k_y;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 20);
  chartInstance->c12_y_km1 = c12_y;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 21);
  chartInstance->c12_u_km1 = c12_u;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -21);
  sf_debug_symbol_scope_pop();
  *c12_l_y = c12_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c12_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_SALTStabilizationInnerOuterLoopMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc12_SALTStabilizationInnerOuterLoop
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber)
{
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real32_T *)c12_inData;
  c12_y = NULL;
  if (!chartInstance->c12_u_km1_not_empty) {
    sf_mex_assign(&c12_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 1, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real32_T c12_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_b_u_km1, const char_T *c12_identifier)
{
  real32_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_u_km1),
    &c12_thisId);
  sf_mex_destroy(&c12_b_u_km1);
  return c12_y;
}

static real32_T c12_b_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real32_T c12_y;
  real32_T c12_f0;
  if (mxIsEmpty(c12_u)) {
    chartInstance->c12_u_km1_not_empty = FALSE;
  } else {
    chartInstance->c12_u_km1_not_empty = TRUE;
    sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_f0, 1, 1, 0U, 0, 0U, 0);
    c12_y = c12_f0;
  }

  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_u_km1;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real32_T c12_y;
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c12_b_u_km1 = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_u_km1),
    &c12_thisId);
  sf_mex_destroy(&c12_b_u_km1);
  *(real32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real32_T *)c12_inData;
  c12_y = NULL;
  if (!chartInstance->c12_y_km1_not_empty) {
    sf_mex_assign(&c12_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 1, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real32_T c12_c_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_b_y_km1, const char_T *c12_identifier)
{
  real32_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_y_km1),
    &c12_thisId);
  sf_mex_destroy(&c12_b_y_km1);
  return c12_y;
}

static real32_T c12_d_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real32_T c12_y;
  real32_T c12_f1;
  if (mxIsEmpty(c12_u)) {
    chartInstance->c12_y_km1_not_empty = FALSE;
  } else {
    chartInstance->c12_y_km1_not_empty = TRUE;
    sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_f1, 1, 1, 0U, 0, 0U, 0);
    c12_y = c12_f1;
  }

  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_y_km1;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real32_T c12_y;
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c12_b_y_km1 = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_y_km1),
    &c12_thisId);
  sf_mex_destroy(&c12_b_y_km1);
  *(real32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  if (!chartInstance->c12_b_not_empty) {
    sf_mex_assign(&c12_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real_T c12_e_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_b_b, const char_T *c12_identifier)
{
  real_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_b), &c12_thisId);
  sf_mex_destroy(&c12_b_b);
  return c12_y;
}

static real_T c12_f_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d0;
  if (mxIsEmpty(c12_u)) {
    chartInstance->c12_b_not_empty = FALSE;
  } else {
    chartInstance->c12_b_not_empty = TRUE;
    sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d0, 1, 0, 0U, 0, 0U, 0);
    c12_y = c12_d0;
  }

  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_b;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c12_b_b = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_b), &c12_thisId);
  sf_mex_destroy(&c12_b_b);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  if (!chartInstance->c12_a_not_empty) {
    sf_mex_assign(&c12_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real_T c12_g_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_b_a, const char_T *c12_identifier)
{
  real_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_a), &c12_thisId);
  sf_mex_destroy(&c12_b_a);
  return c12_y;
}

static real_T c12_h_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d1;
  if (mxIsEmpty(c12_u)) {
    chartInstance->c12_a_not_empty = FALSE;
  } else {
    chartInstance->c12_a_not_empty = TRUE;
    sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d1, 1, 0, 0U, 0, 0U, 0);
    c12_y = c12_d1;
  }

  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_a;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c12_b_a = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_a), &c12_thisId);
  sf_mex_destroy(&c12_b_a);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real32_T c12_i_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_y, const char_T *c12_identifier)
{
  real32_T c12_b_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_y = c12_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_y), &c12_thisId);
  sf_mex_destroy(&c12_y);
  return c12_b_y;
}

static real32_T c12_j_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real32_T c12_y;
  real32_T c12_f2;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_f2, 1, 1, 0U, 0, 0U, 0);
  c12_y = c12_f2;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_y;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real32_T c12_b_y;
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c12_y = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_y = c12_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_y), &c12_thisId);
  sf_mex_destroy(&c12_y);
  *(real32_T *)c12_outData = c12_b_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real_T c12_k_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d2;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d2, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d2;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_nargout;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c12_nargout = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_nargout),
    &c12_thisId);
  sf_mex_destroy(&c12_nargout);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray
  *sf_c12_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo;
  c12_ResolvedFunctionInfo c12_info[4];
  c12_ResolvedFunctionInfo (*c12_b_info)[4];
  const mxArray *c12_m0 = NULL;
  int32_T c12_i0;
  c12_ResolvedFunctionInfo *c12_r0;
  c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  c12_b_info = (c12_ResolvedFunctionInfo (*)[4])c12_info;
  (*c12_b_info)[0].context = "";
  (*c12_b_info)[0].name = "mtimes";
  (*c12_b_info)[0].dominantType = "double";
  (*c12_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c12_b_info)[0].fileTimeLo = 1289552092U;
  (*c12_b_info)[0].fileTimeHi = 0U;
  (*c12_b_info)[0].mFileTimeLo = 0U;
  (*c12_b_info)[0].mFileTimeHi = 0U;
  (*c12_b_info)[1].context = "";
  (*c12_b_info)[1].name = "mrdivide";
  (*c12_b_info)[1].dominantType = "double";
  (*c12_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c12_b_info)[1].fileTimeLo = 1310169856U;
  (*c12_b_info)[1].fileTimeHi = 0U;
  (*c12_b_info)[1].mFileTimeLo = 1289552092U;
  (*c12_b_info)[1].mFileTimeHi = 0U;
  (*c12_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c12_b_info)[2].name = "rdivide";
  (*c12_b_info)[2].dominantType = "double";
  (*c12_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c12_b_info)[2].fileTimeLo = 1286851244U;
  (*c12_b_info)[2].fileTimeHi = 0U;
  (*c12_b_info)[2].mFileTimeLo = 0U;
  (*c12_b_info)[2].mFileTimeHi = 0U;
  (*c12_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c12_b_info)[3].name = "eml_div";
  (*c12_b_info)[3].dominantType = "double";
  (*c12_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c12_b_info)[3].fileTimeLo = 1305350400U;
  (*c12_b_info)[3].fileTimeHi = 0U;
  (*c12_b_info)[3].mFileTimeLo = 0U;
  (*c12_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c12_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4), FALSE);
  for (c12_i0 = 0; c12_i0 < 4; c12_i0++) {
    c12_r0 = &c12_info[c12_i0];
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->context)), "context", "nameCaptureInfo",
                    c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->name)), "name", "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      c12_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->resolved)), "resolved",
                    "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      &c12_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      &c12_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c12_i0);
  }

  sf_mex_assign(&c12_nameCaptureInfo, c12_m0, FALSE);
  return c12_nameCaptureInfo;
}

static const mxArray *c12_g_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static int32_T c12_l_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i1;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i1, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i1;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static uint8_T c12_m_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_b_is_active_c12_SALTStabilizationInnerOuterLoop, const char_T
   *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_n_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_SALTStabilizationInnerOuterLoop), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_SALTStabilizationInnerOuterLoop);
  return c12_y;
}

static uint8_T c12_n_emlrt_marshallIn
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void init_dsm_address_info
  (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c12_SALTStabilizationInnerOuterLoop_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(600195861U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1481686670U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3850971951U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3227197664U);
}

mxArray *sf_c12_SALTStabilizationInnerOuterLoop_get_autoinheritance_info(void)
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

static const mxArray *sf_get_sim_state_info_c12_SALTStabilizationInnerOuterLoop
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[4],M[0],T\"a\",S'l','i','p'{{M1x2[137 138],M[0],}}},{M[4],M[0],T\"b\",S'l','i','p'{{M1x2[150 151],M[0],}}},{M[4],M[0],T\"u_km1\",S'l','i','p'{{M1x2[180 185],M[0],}}},{M[4],M[0],T\"y_km1\",S'l','i','p'{{M1x2[163 168],M[0],}}},{M[8],M[0],T\"is_active_c12_SALTStabilizationInnerOuterLoop\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_SALTStabilizationInnerOuterLoop_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
    chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SALTStabilizationInnerOuterLoopMachineNumber_,
           12,
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
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_f_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real32_T *c12_u;
          real32_T *c12_y;
          real_T *c12_T;
          real_T *c12_f;
          c12_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c12_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c12_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c12_u = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c12_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c12_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c12_T);
          _SFD_SET_DATA_VALUE_PTR(3U, c12_f);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_SALTStabilizationInnerOuterLoopMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c12_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc12_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar)
     ->S,0);
  initialize_params_c12_SALTStabilizationInnerOuterLoop
    ((SFc12_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
  initialize_c12_SALTStabilizationInnerOuterLoop
    ((SFc12_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c12_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  enable_c12_SALTStabilizationInnerOuterLoop
    ((SFc12_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c12_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  disable_c12_SALTStabilizationInnerOuterLoop
    ((SFc12_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c12_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  sf_c12_SALTStabilizationInnerOuterLoop
    ((SFc12_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c12_SALTStabilizationInnerOuterLoop(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c12_SALTStabilizationInnerOuterLoop
    ((SFc12_SALTStabilizationInnerOuterLoopInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_SALTStabilizationInnerOuterLoop
    ();                                /* state var info */
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

extern void sf_internal_set_sim_state_c12_SALTStabilizationInnerOuterLoop
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_SALTStabilizationInnerOuterLoop
    ();                                /* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c12_SALTStabilizationInnerOuterLoop
    ((SFc12_SALTStabilizationInnerOuterLoopInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c12_SALTStabilizationInnerOuterLoop(SimStruct* S)
{
  return sf_internal_get_sim_state_c12_SALTStabilizationInnerOuterLoop(S);
}

static void sf_opaque_set_sim_state_c12_SALTStabilizationInnerOuterLoop
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c12_SALTStabilizationInnerOuterLoop(S, st);
}

static void sf_opaque_terminate_c12_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_SALTStabilizationInnerOuterLoopInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c12_SALTStabilizationInnerOuterLoop
      ((SFc12_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_SALTStabilizationInnerOuterLoop_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_SALTStabilizationInnerOuterLoop
    ((SFc12_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_SALTStabilizationInnerOuterLoop(SimStruct
  *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c12_SALTStabilizationInnerOuterLoop
      ((SFc12_SALTStabilizationInnerOuterLoopInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_SALTStabilizationInnerOuterLoop(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_SALTStabilizationInnerOuterLoop_optimization_info
      ();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,12,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,12,3);
      sf_mark_chart_reusable_outputs(S,infoStruct,12,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,12);
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

static void mdlRTW_c12_SALTStabilizationInnerOuterLoop(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_SALTStabilizationInnerOuterLoop(SimStruct *S)
{
  SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct *)malloc
    (sizeof(SFc12_SALTStabilizationInnerOuterLoopInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc12_SALTStabilizationInnerOuterLoopInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c12_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c12_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c12_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c12_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c12_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c12_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c12_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c12_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c12_SALTStabilizationInnerOuterLoop;
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

void c12_SALTStabilizationInnerOuterLoop_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_SALTStabilizationInnerOuterLoop(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_SALTStabilizationInnerOuterLoop(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_SALTStabilizationInnerOuterLoop(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_SALTStabilizationInnerOuterLoop_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
