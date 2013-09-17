/* Include files */

#include "blascompat32.h"
#include "SALTStabilizationInnerOuterLoopSIM_sfun.h"
#include "c33_SALTStabilizationInnerOuterLoopSIM.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SALTStabilizationInnerOuterLoopSIM_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c33_debug_family_names[11] = { "omega", "nargin", "nargout",
  "u", "T", "f", "y", "a", "b", "y_km1", "u_km1" };

/* Function Declarations */
static void initialize_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance);
static void initialize_params_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance);
static void enable_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance);
static void disable_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance);
static void c33_update_debugger_state_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance);
static void set_sim_state_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_st);
static void finalize_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance);
static void sf_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance);
static void initSimStructsc33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c33_machineNumber, uint32_T
  c33_chartNumber);
static const mxArray *c33_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static real32_T c33_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_b_u_km1, const char_T *c33_identifier);
static real32_T c33_b_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_b_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static real32_T c33_c_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_b_y_km1, const char_T *c33_identifier);
static real32_T c33_d_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_c_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static real_T c33_e_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_b_b, const char_T *c33_identifier);
static real_T c33_f_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_d_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static real_T c33_g_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_b_a, const char_T *c33_identifier);
static real_T c33_h_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_e_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static real32_T c33_i_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_y, const char_T *c33_identifier);
static real32_T c33_j_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_f_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static real_T c33_k_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_g_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static int32_T c33_l_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static uint8_T c33_m_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_b_is_active_c33_SALTStabilizationInnerOuterLoopSIM, const char_T
   *c33_identifier);
static uint8_T c33_n_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void init_dsm_address_info
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance)
{
  chartInstance->c33_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c33_a_not_empty = FALSE;
  chartInstance->c33_b_not_empty = FALSE;
  chartInstance->c33_y_km1_not_empty = FALSE;
  chartInstance->c33_u_km1_not_empty = FALSE;
  chartInstance->c33_is_active_c33_SALTStabilizationInnerOuterLoopSIM = 0U;
}

static void initialize_params_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance)
{
}

static void enable_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c33_update_debugger_state_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance)
{
  const mxArray *c33_st;
  const mxArray *c33_y = NULL;
  real32_T c33_hoistedGlobal;
  real32_T c33_u;
  const mxArray *c33_b_y = NULL;
  real_T c33_b_hoistedGlobal;
  real_T c33_b_u;
  const mxArray *c33_c_y = NULL;
  real_T c33_c_hoistedGlobal;
  real_T c33_c_u;
  const mxArray *c33_d_y = NULL;
  real32_T c33_d_hoistedGlobal;
  real32_T c33_d_u;
  const mxArray *c33_e_y = NULL;
  real32_T c33_e_hoistedGlobal;
  real32_T c33_e_u;
  const mxArray *c33_f_y = NULL;
  uint8_T c33_f_hoistedGlobal;
  uint8_T c33_f_u;
  const mxArray *c33_g_y = NULL;
  real32_T *c33_h_y;
  c33_h_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c33_st = NULL;
  c33_st = NULL;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_createcellarray(6), FALSE);
  c33_hoistedGlobal = *c33_h_y;
  c33_u = c33_hoistedGlobal;
  c33_b_y = NULL;
  sf_mex_assign(&c33_b_y, sf_mex_create("y", &c33_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c33_y, 0, c33_b_y);
  c33_b_hoistedGlobal = chartInstance->c33_a;
  c33_b_u = c33_b_hoistedGlobal;
  c33_c_y = NULL;
  if (!chartInstance->c33_a_not_empty) {
    sf_mex_assign(&c33_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c33_c_y, sf_mex_create("y", &c33_b_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c33_y, 1, c33_c_y);
  c33_c_hoistedGlobal = chartInstance->c33_b;
  c33_c_u = c33_c_hoistedGlobal;
  c33_d_y = NULL;
  if (!chartInstance->c33_b_not_empty) {
    sf_mex_assign(&c33_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c33_d_y, sf_mex_create("y", &c33_c_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c33_y, 2, c33_d_y);
  c33_d_hoistedGlobal = chartInstance->c33_u_km1;
  c33_d_u = c33_d_hoistedGlobal;
  c33_e_y = NULL;
  if (!chartInstance->c33_u_km1_not_empty) {
    sf_mex_assign(&c33_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c33_e_y, sf_mex_create("y", &c33_d_u, 1, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c33_y, 3, c33_e_y);
  c33_e_hoistedGlobal = chartInstance->c33_y_km1;
  c33_e_u = c33_e_hoistedGlobal;
  c33_f_y = NULL;
  if (!chartInstance->c33_y_km1_not_empty) {
    sf_mex_assign(&c33_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c33_f_y, sf_mex_create("y", &c33_e_u, 1, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c33_y, 4, c33_f_y);
  c33_f_hoistedGlobal =
    chartInstance->c33_is_active_c33_SALTStabilizationInnerOuterLoopSIM;
  c33_f_u = c33_f_hoistedGlobal;
  c33_g_y = NULL;
  sf_mex_assign(&c33_g_y, sf_mex_create("y", &c33_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c33_y, 5, c33_g_y);
  sf_mex_assign(&c33_st, c33_y, FALSE);
  return c33_st;
}

static void set_sim_state_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_st)
{
  const mxArray *c33_u;
  real32_T *c33_y;
  c33_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c33_doneDoubleBufferReInit = TRUE;
  c33_u = sf_mex_dup(c33_st);
  *c33_y = c33_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u,
    0)), "y");
  chartInstance->c33_a = c33_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c33_u, 1)), "a");
  chartInstance->c33_b = c33_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c33_u, 2)), "b");
  chartInstance->c33_u_km1 = c33_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c33_u, 3)), "u_km1");
  chartInstance->c33_y_km1 = c33_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c33_u, 4)), "y_km1");
  chartInstance->c33_is_active_c33_SALTStabilizationInnerOuterLoopSIM =
    c33_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 5)),
    "is_active_c33_SALTStabilizationInnerOuterLoopSIM");
  sf_mex_destroy(&c33_u);
  c33_update_debugger_state_c33_SALTStabilizationInnerOuterLoopSIM(chartInstance);
  sf_mex_destroy(&c33_st);
}

static void finalize_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance)
{
}

static void sf_c33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance)
{
  real32_T c33_hoistedGlobal;
  real_T c33_b_hoistedGlobal;
  real_T c33_c_hoistedGlobal;
  real32_T c33_u;
  real_T c33_T;
  real_T c33_f;
  uint32_T c33_debug_family_var_map[11];
  real_T c33_omega;
  real_T c33_nargin = 3.0;
  real_T c33_nargout = 1.0;
  real32_T c33_y;
  real_T c33_b_b;
  real_T c33_b_a;
  real_T c33_c_b;
  real_T c33_b_y;
  real_T c33_c_a;
  real_T c33_d_b;
  real_T c33_c_y;
  real_T c33_A;
  real_T c33_B;
  real_T c33_x;
  real_T c33_d_y;
  real_T c33_b_x;
  real_T c33_e_y;
  real_T c33_d_a;
  real_T c33_e_b;
  real_T c33_f_y;
  real_T c33_e_a;
  real_T c33_f_b;
  real_T c33_g_y;
  real_T c33_b_A;
  real_T c33_b_B;
  real_T c33_c_x;
  real_T c33_h_y;
  real_T c33_d_x;
  real_T c33_i_y;
  real_T c33_d_hoistedGlobal;
  real32_T c33_e_hoistedGlobal;
  real_T c33_f_a;
  real32_T c33_g_b;
  real32_T c33_j_y;
  real_T c33_f_hoistedGlobal;
  real32_T c33_g_hoistedGlobal;
  real_T c33_g_a;
  real32_T c33_h_b;
  real32_T c33_k_y;
  real_T *c33_b_f;
  real_T *c33_b_T;
  real32_T *c33_b_u;
  real32_T *c33_l_y;
  c33_b_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c33_b_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c33_l_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c33_b_u = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c33_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c33_b_u, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c33_l_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c33_b_T, 2U);
  _SFD_DATA_RANGE_CHECK(*c33_b_f, 3U);
  chartInstance->c33_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c33_sfEvent);
  c33_hoistedGlobal = *c33_b_u;
  c33_b_hoistedGlobal = *c33_b_T;
  c33_c_hoistedGlobal = *c33_b_f;
  c33_u = c33_hoistedGlobal;
  c33_T = c33_b_hoistedGlobal;
  c33_f = c33_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 11U, 11U, c33_debug_family_names,
    c33_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c33_omega, 0U, c33_f_sf_marshallOut,
    c33_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c33_nargin, 1U, c33_f_sf_marshallOut,
    c33_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c33_nargout, 2U,
    c33_f_sf_marshallOut, c33_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c33_u, 3U, c33_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c33_T, 4U, c33_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c33_f, 5U, c33_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c33_y, 6U, c33_e_sf_marshallOut,
    c33_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c33_a, 7U,
    c33_d_sf_marshallOut, c33_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c33_b, 8U,
    c33_c_sf_marshallOut, c33_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c33_y_km1, 9U,
    c33_b_sf_marshallOut, c33_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c33_u_km1, 10U,
    c33_sf_marshallOut, c33_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 9);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c33_a_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 12);
    c33_b_b = c33_f;
    c33_omega = 6.2831853071795862 * c33_b_b;
    _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 13);
    c33_b_a = c33_T;
    c33_c_b = c33_omega;
    c33_b_y = c33_b_a * c33_c_b;
    c33_c_a = c33_T;
    c33_d_b = c33_omega;
    c33_c_y = c33_c_a * c33_d_b;
    c33_A = c33_b_y;
    c33_B = 2.0 + c33_c_y;
    c33_x = c33_A;
    c33_d_y = c33_B;
    c33_b_x = c33_x;
    c33_e_y = c33_d_y;
    chartInstance->c33_a = c33_b_x / c33_e_y;
    chartInstance->c33_a_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 14);
    c33_d_a = c33_T;
    c33_e_b = c33_omega;
    c33_f_y = c33_d_a * c33_e_b;
    c33_e_a = c33_T;
    c33_f_b = c33_omega;
    c33_g_y = c33_e_a * c33_f_b;
    c33_b_A = -(c33_f_y - 2.0);
    c33_b_B = c33_g_y + 2.0;
    c33_c_x = c33_b_A;
    c33_h_y = c33_b_B;
    c33_d_x = c33_c_x;
    c33_i_y = c33_h_y;
    chartInstance->c33_b = c33_d_x / c33_i_y;
    chartInstance->c33_b_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 15);
    chartInstance->c33_y_km1 = c33_u;
    chartInstance->c33_y_km1_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 16);
    chartInstance->c33_u_km1 = c33_u;
    chartInstance->c33_u_km1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 19);
  c33_d_hoistedGlobal = chartInstance->c33_a;
  c33_e_hoistedGlobal = chartInstance->c33_u_km1;
  c33_f_a = c33_d_hoistedGlobal;
  c33_g_b = c33_u + c33_e_hoistedGlobal;
  c33_j_y = (real32_T)c33_f_a * c33_g_b;
  c33_f_hoistedGlobal = chartInstance->c33_b;
  c33_g_hoistedGlobal = chartInstance->c33_y_km1;
  c33_g_a = c33_f_hoistedGlobal;
  c33_h_b = c33_g_hoistedGlobal;
  c33_k_y = (real32_T)c33_g_a * c33_h_b;
  c33_y = c33_j_y + c33_k_y;
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 20);
  chartInstance->c33_y_km1 = c33_y;
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 21);
  chartInstance->c33_u_km1 = c33_u;
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, -21);
  sf_debug_symbol_scope_pop();
  *c33_l_y = c33_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c33_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_SALTStabilizationInnerOuterLoopSIMMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc33_SALTStabilizationInnerOuterLoopSIM
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c33_machineNumber, uint32_T
  c33_chartNumber)
{
}

static const mxArray *c33_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  real32_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(real32_T *)c33_inData;
  c33_y = NULL;
  if (!chartInstance->c33_u_km1_not_empty) {
    sf_mex_assign(&c33_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 1, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c33_mxArrayOutData, c33_y, FALSE);
  return c33_mxArrayOutData;
}

static real32_T c33_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_b_u_km1, const char_T *c33_identifier)
{
  real32_T c33_y;
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_u_km1),
    &c33_thisId);
  sf_mex_destroy(&c33_b_u_km1);
  return c33_y;
}

static real32_T c33_b_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  real32_T c33_y;
  real32_T c33_f0;
  if (mxIsEmpty(c33_u)) {
    chartInstance->c33_u_km1_not_empty = FALSE;
  } else {
    chartInstance->c33_u_km1_not_empty = TRUE;
    sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_f0, 1, 1, 0U, 0, 0U, 0);
    c33_y = c33_f0;
  }

  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_b_u_km1;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real32_T c33_y;
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    chartInstanceVoid;
  c33_b_u_km1 = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_u_km1),
    &c33_thisId);
  sf_mex_destroy(&c33_b_u_km1);
  *(real32_T *)c33_outData = c33_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_b_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  real32_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(real32_T *)c33_inData;
  c33_y = NULL;
  if (!chartInstance->c33_y_km1_not_empty) {
    sf_mex_assign(&c33_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 1, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c33_mxArrayOutData, c33_y, FALSE);
  return c33_mxArrayOutData;
}

static real32_T c33_c_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_b_y_km1, const char_T *c33_identifier)
{
  real32_T c33_y;
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_y_km1),
    &c33_thisId);
  sf_mex_destroy(&c33_b_y_km1);
  return c33_y;
}

static real32_T c33_d_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  real32_T c33_y;
  real32_T c33_f1;
  if (mxIsEmpty(c33_u)) {
    chartInstance->c33_y_km1_not_empty = FALSE;
  } else {
    chartInstance->c33_y_km1_not_empty = TRUE;
    sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_f1, 1, 1, 0U, 0, 0U, 0);
    c33_y = c33_f1;
  }

  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_b_y_km1;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real32_T c33_y;
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    chartInstanceVoid;
  c33_b_y_km1 = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_y_km1),
    &c33_thisId);
  sf_mex_destroy(&c33_b_y_km1);
  *(real32_T *)c33_outData = c33_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_c_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  real_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(real_T *)c33_inData;
  c33_y = NULL;
  if (!chartInstance->c33_b_not_empty) {
    sf_mex_assign(&c33_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c33_mxArrayOutData, c33_y, FALSE);
  return c33_mxArrayOutData;
}

static real_T c33_e_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_b_b, const char_T *c33_identifier)
{
  real_T c33_y;
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_b), &c33_thisId);
  sf_mex_destroy(&c33_b_b);
  return c33_y;
}

static real_T c33_f_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  real_T c33_y;
  real_T c33_d0;
  if (mxIsEmpty(c33_u)) {
    chartInstance->c33_b_not_empty = FALSE;
  } else {
    chartInstance->c33_b_not_empty = TRUE;
    sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_d0, 1, 0, 0U, 0, 0U, 0);
    c33_y = c33_d0;
  }

  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_b_b;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y;
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    chartInstanceVoid;
  c33_b_b = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_b), &c33_thisId);
  sf_mex_destroy(&c33_b_b);
  *(real_T *)c33_outData = c33_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_d_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  real_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(real_T *)c33_inData;
  c33_y = NULL;
  if (!chartInstance->c33_a_not_empty) {
    sf_mex_assign(&c33_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c33_mxArrayOutData, c33_y, FALSE);
  return c33_mxArrayOutData;
}

static real_T c33_g_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_b_a, const char_T *c33_identifier)
{
  real_T c33_y;
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_a), &c33_thisId);
  sf_mex_destroy(&c33_b_a);
  return c33_y;
}

static real_T c33_h_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  real_T c33_y;
  real_T c33_d1;
  if (mxIsEmpty(c33_u)) {
    chartInstance->c33_a_not_empty = FALSE;
  } else {
    chartInstance->c33_a_not_empty = TRUE;
    sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_d1, 1, 0, 0U, 0, 0U, 0);
    c33_y = c33_d1;
  }

  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_b_a;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y;
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    chartInstanceVoid;
  c33_b_a = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_a), &c33_thisId);
  sf_mex_destroy(&c33_b_a);
  *(real_T *)c33_outData = c33_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_e_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  real32_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(real32_T *)c33_inData;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, FALSE);
  return c33_mxArrayOutData;
}

static real32_T c33_i_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_y, const char_T *c33_identifier)
{
  real32_T c33_b_y;
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_b_y = c33_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_y), &c33_thisId);
  sf_mex_destroy(&c33_y);
  return c33_b_y;
}

static real32_T c33_j_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  real32_T c33_y;
  real32_T c33_f2;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_f2, 1, 1, 0U, 0, 0U, 0);
  c33_y = c33_f2;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_y;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real32_T c33_b_y;
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    chartInstanceVoid;
  c33_y = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_b_y = c33_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_y), &c33_thisId);
  sf_mex_destroy(&c33_y);
  *(real32_T *)c33_outData = c33_b_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_f_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  real_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(real_T *)c33_inData;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, FALSE);
  return c33_mxArrayOutData;
}

static real_T c33_k_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  real_T c33_y;
  real_T c33_d2;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_d2, 1, 0, 0U, 0, 0U, 0);
  c33_y = c33_d2;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_nargout;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y;
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    chartInstanceVoid;
  c33_nargout = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_nargout),
    &c33_thisId);
  sf_mex_destroy(&c33_nargout);
  *(real_T *)c33_outData = c33_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

const mxArray
  *sf_c33_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c33_nameCaptureInfo;
  c33_ResolvedFunctionInfo c33_info[4];
  c33_ResolvedFunctionInfo (*c33_b_info)[4];
  const mxArray *c33_m0 = NULL;
  int32_T c33_i0;
  c33_ResolvedFunctionInfo *c33_r0;
  c33_nameCaptureInfo = NULL;
  c33_nameCaptureInfo = NULL;
  c33_b_info = (c33_ResolvedFunctionInfo (*)[4])c33_info;
  (*c33_b_info)[0].context = "";
  (*c33_b_info)[0].name = "mtimes";
  (*c33_b_info)[0].dominantType = "double";
  (*c33_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c33_b_info)[0].fileTimeLo = 1289552092U;
  (*c33_b_info)[0].fileTimeHi = 0U;
  (*c33_b_info)[0].mFileTimeLo = 0U;
  (*c33_b_info)[0].mFileTimeHi = 0U;
  (*c33_b_info)[1].context = "";
  (*c33_b_info)[1].name = "mrdivide";
  (*c33_b_info)[1].dominantType = "double";
  (*c33_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c33_b_info)[1].fileTimeLo = 1310169856U;
  (*c33_b_info)[1].fileTimeHi = 0U;
  (*c33_b_info)[1].mFileTimeLo = 1289552092U;
  (*c33_b_info)[1].mFileTimeHi = 0U;
  (*c33_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c33_b_info)[2].name = "rdivide";
  (*c33_b_info)[2].dominantType = "double";
  (*c33_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c33_b_info)[2].fileTimeLo = 1286851244U;
  (*c33_b_info)[2].fileTimeHi = 0U;
  (*c33_b_info)[2].mFileTimeLo = 0U;
  (*c33_b_info)[2].mFileTimeHi = 0U;
  (*c33_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c33_b_info)[3].name = "eml_div";
  (*c33_b_info)[3].dominantType = "double";
  (*c33_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c33_b_info)[3].fileTimeLo = 1305350400U;
  (*c33_b_info)[3].fileTimeHi = 0U;
  (*c33_b_info)[3].mFileTimeLo = 0U;
  (*c33_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c33_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4), FALSE);
  for (c33_i0 = 0; c33_i0 < 4; c33_i0++) {
    c33_r0 = &c33_info[c33_i0];
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", c33_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c33_r0->context)), "context", "nameCaptureInfo",
                    c33_i0);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", c33_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c33_r0->name)), "name", "nameCaptureInfo", c33_i0);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo",
      c33_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c33_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c33_i0);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", c33_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c33_r0->resolved)), "resolved",
                    "nameCaptureInfo", c33_i0);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", &c33_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c33_i0);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", &c33_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c33_i0);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo",
      &c33_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c33_i0);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo",
      &c33_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c33_i0);
  }

  sf_mex_assign(&c33_nameCaptureInfo, c33_m0, FALSE);
  return c33_nameCaptureInfo;
}

static const mxArray *c33_g_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(int32_T *)c33_inData;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, FALSE);
  return c33_mxArrayOutData;
}

static int32_T c33_l_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  int32_T c33_y;
  int32_T c33_i1;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_i1, 1, 6, 0U, 0, 0U, 0);
  c33_y = c33_i1;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_b_sfEvent;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  int32_T c33_y;
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    chartInstanceVoid;
  c33_b_sfEvent = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_sfEvent),
    &c33_thisId);
  sf_mex_destroy(&c33_b_sfEvent);
  *(int32_T *)c33_outData = c33_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

static uint8_T c33_m_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_b_is_active_c33_SALTStabilizationInnerOuterLoopSIM, const char_T
   *c33_identifier)
{
  uint8_T c33_y;
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_n_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c33_b_is_active_c33_SALTStabilizationInnerOuterLoopSIM), &c33_thisId);
  sf_mex_destroy(&c33_b_is_active_c33_SALTStabilizationInnerOuterLoopSIM);
  return c33_y;
}

static uint8_T c33_n_emlrt_marshallIn
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance, const
   mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  uint8_T c33_y;
  uint8_T c33_u0;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_u0, 1, 3, 0U, 0, 0U, 0);
  c33_y = c33_u0;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void init_dsm_address_info
  (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c33_SALTStabilizationInnerOuterLoopSIM_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(600195861U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1481686670U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3850971951U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3227197664U);
}

mxArray *sf_c33_SALTStabilizationInnerOuterLoopSIM_get_autoinheritance_info(void)
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

static const mxArray
  *sf_get_sim_state_info_c33_SALTStabilizationInnerOuterLoopSIM(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[4],M[0],T\"a\",S'l','i','p'{{M1x2[137 138],M[0],}}},{M[4],M[0],T\"b\",S'l','i','p'{{M1x2[150 151],M[0],}}},{M[4],M[0],T\"u_km1\",S'l','i','p'{{M1x2[180 185],M[0],}}},{M[4],M[0],T\"y_km1\",S'l','i','p'{{M1x2[163 168],M[0],}}},{M[8],M[0],T\"is_active_c33_SALTStabilizationInnerOuterLoopSIM\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c33_SALTStabilizationInnerOuterLoopSIM_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
    chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SALTStabilizationInnerOuterLoopSIMMachineNumber_,
           33,
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
            (_SALTStabilizationInnerOuterLoopSIMMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_SALTStabilizationInnerOuterLoopSIMMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_SALTStabilizationInnerOuterLoopSIMMachineNumber_,
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
          (MexFcnForType)c33_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_e_sf_marshallOut,(MexInFcnForType)
          c33_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_f_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real32_T *c33_u;
          real32_T *c33_y;
          real_T *c33_T;
          real_T *c33_f;
          c33_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c33_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c33_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c33_u = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c33_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c33_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c33_T);
          _SFD_SET_DATA_VALUE_PTR(3U, c33_f);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_SALTStabilizationInnerOuterLoopSIMMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c33_SALTStabilizationInnerOuterLoopSIM(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct*) chartInstanceVar)
     ->S,0);
  initialize_params_c33_SALTStabilizationInnerOuterLoopSIM
    ((SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct*) chartInstanceVar);
  initialize_c33_SALTStabilizationInnerOuterLoopSIM
    ((SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c33_SALTStabilizationInnerOuterLoopSIM(void
  *chartInstanceVar)
{
  enable_c33_SALTStabilizationInnerOuterLoopSIM
    ((SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c33_SALTStabilizationInnerOuterLoopSIM(void
  *chartInstanceVar)
{
  disable_c33_SALTStabilizationInnerOuterLoopSIM
    ((SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c33_SALTStabilizationInnerOuterLoopSIM(void
  *chartInstanceVar)
{
  sf_c33_SALTStabilizationInnerOuterLoopSIM
    ((SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c33_SALTStabilizationInnerOuterLoopSIM(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c33_SALTStabilizationInnerOuterLoopSIM
    ((SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c33_SALTStabilizationInnerOuterLoopSIM();/* state var info */
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

extern void sf_internal_set_sim_state_c33_SALTStabilizationInnerOuterLoopSIM
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c33_SALTStabilizationInnerOuterLoopSIM();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c33_SALTStabilizationInnerOuterLoopSIM
    ((SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c33_SALTStabilizationInnerOuterLoopSIM(SimStruct* S)
{
  return sf_internal_get_sim_state_c33_SALTStabilizationInnerOuterLoopSIM(S);
}

static void sf_opaque_set_sim_state_c33_SALTStabilizationInnerOuterLoopSIM
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c33_SALTStabilizationInnerOuterLoopSIM(S, st);
}

static void sf_opaque_terminate_c33_SALTStabilizationInnerOuterLoopSIM(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c33_SALTStabilizationInnerOuterLoopSIM
      ((SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct*)
       chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_SALTStabilizationInnerOuterLoopSIM_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc33_SALTStabilizationInnerOuterLoopSIM
    ((SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c33_SALTStabilizationInnerOuterLoopSIM
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c33_SALTStabilizationInnerOuterLoopSIM
      ((SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c33_SALTStabilizationInnerOuterLoopSIM(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_SALTStabilizationInnerOuterLoopSIM_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,33);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,33,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,33,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,33,3);
      sf_mark_chart_reusable_outputs(S,infoStruct,33,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,33);
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

static void mdlRTW_c33_SALTStabilizationInnerOuterLoopSIM(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c33_SALTStabilizationInnerOuterLoopSIM(SimStruct *S)
{
  SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *chartInstance;
  chartInstance = (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct *)
    malloc(sizeof(SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc33_SALTStabilizationInnerOuterLoopSIMInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c33_SALTStabilizationInnerOuterLoopSIM;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c33_SALTStabilizationInnerOuterLoopSIM;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c33_SALTStabilizationInnerOuterLoopSIM;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c33_SALTStabilizationInnerOuterLoopSIM;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c33_SALTStabilizationInnerOuterLoopSIM;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c33_SALTStabilizationInnerOuterLoopSIM;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c33_SALTStabilizationInnerOuterLoopSIM;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c33_SALTStabilizationInnerOuterLoopSIM;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c33_SALTStabilizationInnerOuterLoopSIM;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c33_SALTStabilizationInnerOuterLoopSIM;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c33_SALTStabilizationInnerOuterLoopSIM;
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

void c33_SALTStabilizationInnerOuterLoopSIM_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c33_SALTStabilizationInnerOuterLoopSIM(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c33_SALTStabilizationInnerOuterLoopSIM(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c33_SALTStabilizationInnerOuterLoopSIM(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c33_SALTStabilizationInnerOuterLoopSIM_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
