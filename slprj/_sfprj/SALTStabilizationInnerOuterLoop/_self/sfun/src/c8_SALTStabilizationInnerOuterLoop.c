/* Include files */

#include "blascompat32.h"
#include "SALTStabilizationInnerOuterLoop_sfun.h"
#include "c8_SALTStabilizationInnerOuterLoop.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SALTStabilizationInnerOuterLoop_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c8_debug_family_names[15] = { "PWM", "Ta", "T1", "T2", "Tc",
  "Tb", "nargin", "nargout", "Va", "Vb", "Vc", "PWM1", "PWM2", "PWM3", "sector"
};

/* Function Declarations */
static void initialize_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void initialize_params_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void enable_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void disable_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void set_sim_state_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c8_st);
static void finalize_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void sf_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void c8_chartstep_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void initSimStructsc8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static real32_T c8_emlrt_marshallIn
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c8_sector, const char_T *c8_identifier);
static real32_T c8_b_emlrt_marshallIn
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_c_emlrt_marshallIn
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_d_emlrt_marshallIn
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_e_emlrt_marshallIn
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c8_b_is_active_c8_SALTStabilizationInnerOuterLoop, const char_T
   *c8_identifier);
static uint8_T c8_f_emlrt_marshallIn
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_SALTStabilizationInnerOuterLoop = 0U;
}

static void initialize_params_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

static void enable_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  real32_T c8_hoistedGlobal;
  real32_T c8_u;
  const mxArray *c8_b_y = NULL;
  real32_T c8_b_hoistedGlobal;
  real32_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real32_T c8_c_hoistedGlobal;
  real32_T c8_c_u;
  const mxArray *c8_d_y = NULL;
  real32_T c8_d_hoistedGlobal;
  real32_T c8_d_u;
  const mxArray *c8_e_y = NULL;
  uint8_T c8_e_hoistedGlobal;
  uint8_T c8_e_u;
  const mxArray *c8_f_y = NULL;
  real32_T *c8_PWM1;
  real32_T *c8_PWM2;
  real32_T *c8_PWM3;
  real32_T *c8_sector;
  c8_sector = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_PWM3 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_PWM2 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_PWM1 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(5), FALSE);
  c8_hoistedGlobal = *c8_PWM1;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal = *c8_PWM2;
  c8_b_u = c8_b_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_c_hoistedGlobal = *c8_PWM3;
  c8_c_u = c8_c_hoistedGlobal;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  c8_d_hoistedGlobal = *c8_sector;
  c8_d_u = c8_d_hoistedGlobal;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_d_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 3, c8_e_y);
  c8_e_hoistedGlobal =
    chartInstance->c8_is_active_c8_SALTStabilizationInnerOuterLoop;
  c8_e_u = c8_e_hoistedGlobal;
  c8_f_y = NULL;
  sf_mex_assign(&c8_f_y, sf_mex_create("y", &c8_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 4, c8_f_y);
  sf_mex_assign(&c8_st, c8_y, FALSE);
  return c8_st;
}

static void set_sim_state_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c8_st)
{
  const mxArray *c8_u;
  real32_T *c8_PWM1;
  real32_T *c8_PWM2;
  real32_T *c8_PWM3;
  real32_T *c8_sector;
  c8_sector = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_PWM3 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_PWM2 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_PWM1 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  *c8_PWM1 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    0)), "PWM1");
  *c8_PWM2 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    1)), "PWM2");
  *c8_PWM3 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    2)), "PWM3");
  *c8_sector = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    3)), "sector");
  chartInstance->c8_is_active_c8_SALTStabilizationInnerOuterLoop =
    c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 4)),
    "is_active_c8_SALTStabilizationInnerOuterLoop");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_SALTStabilizationInnerOuterLoop(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

static void sf_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  real32_T *c8_PWM1;
  real32_T *c8_Va;
  real32_T *c8_PWM2;
  real32_T *c8_PWM3;
  real32_T *c8_sector;
  real32_T *c8_Vb;
  real32_T *c8_Vc;
  c8_Vc = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c8_Vb = (real32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_sector = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_PWM3 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_PWM2 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_Va = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c8_PWM1 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_PWM1, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_Va, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_PWM2, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_PWM3, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_sector, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_Vb, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_Vc, 6U);
  chartInstance->c8_sfEvent = CALL_EVENT;
  c8_chartstep_c8_SALTStabilizationInnerOuterLoop(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_SALTStabilizationInnerOuterLoopMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c8_chartstep_c8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
  real32_T c8_hoistedGlobal;
  real32_T c8_b_hoistedGlobal;
  real32_T c8_c_hoistedGlobal;
  real32_T c8_Va;
  real32_T c8_Vb;
  real32_T c8_Vc;
  uint32_T c8_debug_family_var_map[15];
  real32_T c8_PWM;
  real32_T c8_Ta;
  real32_T c8_T1;
  real32_T c8_T2;
  real32_T c8_Tc;
  real32_T c8_Tb;
  real_T c8_nargin = 3.0;
  real_T c8_nargout = 4.0;
  real32_T c8_PWM1;
  real32_T c8_PWM2;
  real32_T c8_PWM3;
  real32_T c8_sector;
  real32_T c8_a;
  real32_T c8_b_a;
  real32_T c8_A;
  real32_T c8_x;
  real32_T c8_b_x;
  real32_T c8_c_a;
  real32_T c8_d_a;
  real32_T c8_b_A;
  real32_T c8_c_x;
  real32_T c8_d_x;
  real32_T c8_e_a;
  real32_T c8_f_a;
  real32_T c8_c_A;
  real32_T c8_e_x;
  real32_T c8_f_x;
  real32_T c8_g_a;
  real32_T c8_h_a;
  real32_T c8_d_A;
  real32_T c8_g_x;
  real32_T c8_h_x;
  real32_T c8_i_a;
  real32_T c8_j_a;
  real32_T c8_e_A;
  real32_T c8_i_x;
  real32_T c8_j_x;
  real32_T c8_k_a;
  real32_T c8_l_a;
  real32_T c8_f_A;
  real32_T c8_k_x;
  real32_T c8_l_x;
  real32_T *c8_b_sector;
  real32_T *c8_b_PWM3;
  real32_T *c8_b_PWM2;
  real32_T *c8_b_PWM1;
  real32_T *c8_b_Vc;
  real32_T *c8_b_Vb;
  real32_T *c8_b_Va;
  c8_b_Vc = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c8_b_Vb = (real32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_b_sector = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_b_PWM3 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_b_PWM2 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_b_Va = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c8_b_PWM1 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  c8_hoistedGlobal = *c8_b_Va;
  c8_b_hoistedGlobal = *c8_b_Vb;
  c8_c_hoistedGlobal = *c8_b_Vc;
  c8_Va = c8_hoistedGlobal;
  c8_Vb = c8_b_hoistedGlobal;
  c8_Vc = c8_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 15U, 15U, c8_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c8_PWM, 0U, c8_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c8_Ta, 1U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_T1, 2U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_T2, 3U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_Tc, 4U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_Tb, 5U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c8_Va, 8U, c8_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_Vb, 9U, c8_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_Vc, 10U, c8_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c8_PWM1, 11U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_PWM2, 12U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_PWM3, 13U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_sector, 14U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 3);
  c8_PWM = 100.0F;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 5);
  c8_Ta = 0.0F;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 7);
  if (CV_EML_IF(0, 1, 0, c8_Va >= 0.0F)) {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 8);
    if (CV_EML_IF(0, 1, 1, c8_Vb >= 0.0F)) {
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 10);
      c8_T1 = c8_Vb;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 11);
      c8_T2 = c8_Va;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 13);
      c8_a = c8_T1;
      c8_T1 = c8_a * 100.0F;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 14);
      c8_b_a = c8_T2;
      c8_T2 = c8_b_a * 100.0F;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 15);
      c8_A = (c8_PWM - c8_T1) - c8_T2;
      c8_x = c8_A;
      c8_b_x = c8_x;
      c8_Tc = c8_b_x / 2.0F;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 16);
      c8_Tb = c8_Ta + c8_T1;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 17);
      c8_Ta = c8_Tb + c8_T2;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 19);
      c8_PWM1 = 0.0F;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 20);
      c8_PWM2 = c8_Tb;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 21);
      c8_PWM3 = c8_Ta;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 22);
      c8_sector = 3.0F;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 24);
      if (CV_EML_IF(0, 1, 2, c8_Vc >= 0.0F)) {
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 26);
        c8_T1 = c8_Va;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 27);
        c8_T2 = c8_Vc;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 29);
        c8_c_a = c8_T1;
        c8_T1 = c8_c_a * 100.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 30);
        c8_d_a = c8_T2;
        c8_T2 = c8_d_a * 100.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 31);
        c8_b_A = (c8_PWM - c8_T1) - c8_T2;
        c8_c_x = c8_b_A;
        c8_d_x = c8_c_x;
        c8_Tc = c8_d_x / 2.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 32);
        c8_Tb = c8_Ta + c8_T1;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 33);
        c8_Ta = c8_Tb + c8_T2;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 35);
        c8_PWM1 = c8_Ta;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 36);
        c8_PWM2 = 0.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 37);
        c8_PWM3 = c8_Tb;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 38);
        c8_sector = 5.0F;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 41);
        c8_T1 = -c8_Vb;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 42);
        c8_T2 = -c8_Vc;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 44);
        c8_e_a = c8_T1;
        c8_T1 = c8_e_a * 100.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 45);
        c8_f_a = c8_T2;
        c8_T2 = c8_f_a * 100.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 46);
        c8_c_A = (c8_PWM - c8_T1) - c8_T2;
        c8_e_x = c8_c_A;
        c8_f_x = c8_e_x;
        c8_Tc = c8_f_x / 2.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 47);
        c8_Tb = c8_Ta + c8_T1;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 48);
        c8_Ta = c8_Tb + c8_T2;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 50);
        c8_PWM1 = c8_Tb;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 51);
        c8_PWM2 = 0.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 52);
        c8_PWM3 = c8_Ta;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 53);
        c8_sector = 1.0F;
      }
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 57);
    if (CV_EML_IF(0, 1, 3, c8_Vb >= 0.0F)) {
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 58);
      if (CV_EML_IF(0, 1, 4, c8_Vc >= 0.0F)) {
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 60);
        c8_T1 = c8_Vc;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 61);
        c8_T2 = c8_Vb;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 63);
        c8_g_a = c8_T1;
        c8_T1 = c8_g_a * 100.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 64);
        c8_h_a = c8_T2;
        c8_T2 = c8_h_a * 100.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 65);
        c8_d_A = (c8_PWM - c8_T1) - c8_T2;
        c8_g_x = c8_d_A;
        c8_h_x = c8_g_x;
        c8_Tc = c8_h_x / 2.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 66);
        c8_Tb = c8_Ta + c8_T1;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 67);
        c8_Ta = c8_Tb + c8_T2;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 69);
        c8_PWM1 = c8_Tb;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 70);
        c8_PWM2 = c8_Ta;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 71);
        c8_PWM3 = 0.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 72);
        c8_sector = 6.0F;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 75);
        c8_T1 = -c8_Vc;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 76);
        c8_T2 = -c8_Va;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 78);
        c8_i_a = c8_T1;
        c8_T1 = c8_i_a * 100.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 79);
        c8_j_a = c8_T2;
        c8_T2 = c8_j_a * 100.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 80);
        c8_e_A = (c8_PWM - c8_T1) - c8_T2;
        c8_i_x = c8_e_A;
        c8_j_x = c8_i_x;
        c8_Tc = c8_j_x / 2.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 81);
        c8_Tb = c8_Ta + c8_T1;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 82);
        c8_Ta = c8_Tb + c8_T2;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 84);
        c8_PWM1 = 0.0F;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 85);
        c8_PWM2 = c8_Ta;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 86);
        c8_PWM3 = c8_Tb;
        _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 87);
        c8_sector = 2.0F;
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 91);
      c8_T1 = -c8_Va;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 92);
      c8_T2 = -c8_Vb;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 94);
      c8_k_a = c8_T1;
      c8_T1 = c8_k_a * 100.0F;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 95);
      c8_l_a = c8_T2;
      c8_T2 = c8_l_a * 100.0F;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 96);
      c8_f_A = (c8_PWM - c8_T1) - c8_T2;
      c8_k_x = c8_f_A;
      c8_l_x = c8_k_x;
      c8_Tc = c8_l_x / 2.0F;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 97);
      c8_Tb = c8_Ta + c8_T1;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 98);
      c8_Ta = c8_Tb + c8_T2;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 100);
      c8_PWM1 = c8_Ta;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 101);
      c8_PWM2 = c8_Tb;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 102);
      c8_PWM3 = 0.0F;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 103);
      c8_sector = 4.0F;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -103);
  sf_debug_symbol_scope_pop();
  *c8_b_PWM1 = c8_PWM1;
  *c8_b_PWM2 = c8_PWM2;
  *c8_b_PWM3 = c8_PWM3;
  *c8_b_sector = c8_sector;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
}

static void initSimStructsc8_SALTStabilizationInnerOuterLoop
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real32_T c8_emlrt_marshallIn
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c8_sector, const char_T *c8_identifier)
{
  real32_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_sector), &c8_thisId);
  sf_mex_destroy(&c8_sector);
  return c8_y;
}

static real32_T c8_b_emlrt_marshallIn
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real32_T c8_y;
  real32_T c8_f0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_f0, 1, 1, 0U, 0, 0U, 0);
  c8_y = c8_f0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_sector;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real32_T c8_y;
  SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c8_sector = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_sector), &c8_thisId);
  sf_mex_destroy(&c8_sector);
  *(real32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_c_emlrt_marshallIn
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_nargout;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c8_nargout = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_nargout), &c8_thisId);
  sf_mex_destroy(&c8_nargout);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray
  *sf_c8_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[4];
  c8_ResolvedFunctionInfo (*c8_b_info)[4];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i0;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_b_info = (c8_ResolvedFunctionInfo (*)[4])c8_info;
  (*c8_b_info)[0].context = "";
  (*c8_b_info)[0].name = "mtimes";
  (*c8_b_info)[0].dominantType = "single";
  (*c8_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c8_b_info)[0].fileTimeLo = 1289552092U;
  (*c8_b_info)[0].fileTimeHi = 0U;
  (*c8_b_info)[0].mFileTimeLo = 0U;
  (*c8_b_info)[0].mFileTimeHi = 0U;
  (*c8_b_info)[1].context = "";
  (*c8_b_info)[1].name = "mrdivide";
  (*c8_b_info)[1].dominantType = "single";
  (*c8_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c8_b_info)[1].fileTimeLo = 1310169856U;
  (*c8_b_info)[1].fileTimeHi = 0U;
  (*c8_b_info)[1].mFileTimeLo = 1289552092U;
  (*c8_b_info)[1].mFileTimeHi = 0U;
  (*c8_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c8_b_info)[2].name = "rdivide";
  (*c8_b_info)[2].dominantType = "single";
  (*c8_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c8_b_info)[2].fileTimeLo = 1286851244U;
  (*c8_b_info)[2].fileTimeHi = 0U;
  (*c8_b_info)[2].mFileTimeLo = 0U;
  (*c8_b_info)[2].mFileTimeHi = 0U;
  (*c8_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c8_b_info)[3].name = "eml_div";
  (*c8_b_info)[3].dominantType = "single";
  (*c8_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c8_b_info)[3].fileTimeLo = 1305350400U;
  (*c8_b_info)[3].fileTimeHi = 0U;
  (*c8_b_info)[3].mFileTimeLo = 0U;
  (*c8_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4), FALSE);
  for (c8_i0 = 0; c8_i0 < 4; c8_i0++) {
    c8_r0 = &c8_info[c8_i0];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i0);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0, FALSE);
  return c8_nameCaptureInfo;
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static int32_T c8_d_emlrt_marshallIn
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i1;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i1, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i1;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *)
    chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_e_emlrt_marshallIn
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c8_b_is_active_c8_SALTStabilizationInnerOuterLoop, const char_T
   *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_SALTStabilizationInnerOuterLoop), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_SALTStabilizationInnerOuterLoop);
  return c8_y;
}

static uint8_T c8_f_emlrt_marshallIn
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info
  (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c8_SALTStabilizationInnerOuterLoop_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2633938657U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(673744159U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4084778424U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2897188885U);
}

mxArray *sf_c8_SALTStabilizationInnerOuterLoop_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("kZK4X7qjA03J1D18S84apE");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c8_SALTStabilizationInnerOuterLoop
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"PWM1\",},{M[1],M[12],T\"PWM2\",},{M[1],M[13],T\"PWM3\",},{M[1],M[14],T\"sector\",},{M[8],M[0],T\"is_active_c8_SALTStabilizationInnerOuterLoop\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_SALTStabilizationInnerOuterLoop_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
    chartInstance = (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SALTStabilizationInnerOuterLoopMachineNumber_,
           8,
           1,
           1,
           7,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"PWM1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Va");
          _SFD_SET_DATA_PROPS(2,2,0,1,"PWM2");
          _SFD_SET_DATA_PROPS(3,2,0,1,"PWM3");
          _SFD_SET_DATA_PROPS(4,2,0,1,"sector");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Vb");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Vc");
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
        _SFD_CV_INIT_EML(0,1,1,5,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2211);
        _SFD_CV_INIT_EML_IF(0,1,0,112,124,1159,2206);
        _SFD_CV_INIT_EML_IF(0,1,1,129,141,430,1158);
        _SFD_CV_INIT_EML_IF(0,1,2,443,455,798,1150);
        _SFD_CV_INIT_EML_IF(0,1,3,1168,1180,1901,2202);
        _SFD_CV_INIT_EML_IF(0,1,4,1189,1201,1545,1896);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real32_T *c8_PWM1;
          real32_T *c8_Va;
          real32_T *c8_PWM2;
          real32_T *c8_PWM3;
          real32_T *c8_sector;
          real32_T *c8_Vb;
          real32_T *c8_Vc;
          c8_Vc = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c8_Vb = (real32_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c8_sector = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c8_PWM3 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c8_PWM2 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c8_Va = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c8_PWM1 = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_PWM1);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_Va);
          _SFD_SET_DATA_VALUE_PTR(2U, c8_PWM2);
          _SFD_SET_DATA_VALUE_PTR(3U, c8_PWM3);
          _SFD_SET_DATA_VALUE_PTR(4U, c8_sector);
          _SFD_SET_DATA_VALUE_PTR(5U, c8_Vb);
          _SFD_SET_DATA_VALUE_PTR(6U, c8_Vc);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_SALTStabilizationInnerOuterLoopMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c8_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc8_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar)->S,
     0);
  initialize_params_c8_SALTStabilizationInnerOuterLoop
    ((SFc8_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
  initialize_c8_SALTStabilizationInnerOuterLoop
    ((SFc8_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  enable_c8_SALTStabilizationInnerOuterLoop
    ((SFc8_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  disable_c8_SALTStabilizationInnerOuterLoop
    ((SFc8_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  sf_c8_SALTStabilizationInnerOuterLoop
    ((SFc8_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c8_SALTStabilizationInnerOuterLoop(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_SALTStabilizationInnerOuterLoop
    ((SFc8_SALTStabilizationInnerOuterLoopInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_SALTStabilizationInnerOuterLoop();/* state var info */
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

extern void sf_internal_set_sim_state_c8_SALTStabilizationInnerOuterLoop
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_SALTStabilizationInnerOuterLoop();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_SALTStabilizationInnerOuterLoop
    ((SFc8_SALTStabilizationInnerOuterLoopInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_SALTStabilizationInnerOuterLoop
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c8_SALTStabilizationInnerOuterLoop(S);
}

static void sf_opaque_set_sim_state_c8_SALTStabilizationInnerOuterLoop(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c8_SALTStabilizationInnerOuterLoop(S, st);
}

static void sf_opaque_terminate_c8_SALTStabilizationInnerOuterLoop(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_SALTStabilizationInnerOuterLoopInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c8_SALTStabilizationInnerOuterLoop
      ((SFc8_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_SALTStabilizationInnerOuterLoop_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_SALTStabilizationInnerOuterLoop
    ((SFc8_SALTStabilizationInnerOuterLoopInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_SALTStabilizationInnerOuterLoop(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_SALTStabilizationInnerOuterLoop
      ((SFc8_SALTStabilizationInnerOuterLoopInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_SALTStabilizationInnerOuterLoop(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_SALTStabilizationInnerOuterLoop_optimization_info
      ();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,8,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,8,3);
      sf_mark_chart_reusable_outputs(S,infoStruct,8,4);
    }

    sf_set_rtw_dwork_info(S,infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3775748335U));
  ssSetChecksum1(S,(2448524183U));
  ssSetChecksum2(S,(3075915615U));
  ssSetChecksum3(S,(2999563905U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_SALTStabilizationInnerOuterLoop(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_SALTStabilizationInnerOuterLoop(SimStruct *S)
{
  SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *chartInstance;
  chartInstance = (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct *)malloc
    (sizeof(SFc8_SALTStabilizationInnerOuterLoopInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc8_SALTStabilizationInnerOuterLoopInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c8_SALTStabilizationInnerOuterLoop;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_SALTStabilizationInnerOuterLoop;
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

void c8_SALTStabilizationInnerOuterLoop_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_SALTStabilizationInnerOuterLoop(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_SALTStabilizationInnerOuterLoop(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_SALTStabilizationInnerOuterLoop(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_SALTStabilizationInnerOuterLoop_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
