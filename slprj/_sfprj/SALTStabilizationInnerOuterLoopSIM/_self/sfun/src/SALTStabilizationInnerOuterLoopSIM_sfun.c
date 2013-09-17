/* Include files */

#include "SALTStabilizationInnerOuterLoopSIM_sfun.h"
#include "c1_SALTStabilizationInnerOuterLoopSIM.h"
#include "c2_SALTStabilizationInnerOuterLoopSIM.h"
#include "c3_SALTStabilizationInnerOuterLoopSIM.h"
#include "c4_SALTStabilizationInnerOuterLoopSIM.h"
#include "c7_SALTStabilizationInnerOuterLoopSIM.h"
#include "c33_SALTStabilizationInnerOuterLoopSIM.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _SALTStabilizationInnerOuterLoopSIMMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void SALTStabilizationInnerOuterLoopSIM_initializer(void)
{
}

void SALTStabilizationInnerOuterLoopSIM_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_SALTStabilizationInnerOuterLoopSIM_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_SALTStabilizationInnerOuterLoopSIM_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_SALTStabilizationInnerOuterLoopSIM_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_SALTStabilizationInnerOuterLoopSIM_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_SALTStabilizationInnerOuterLoopSIM_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_SALTStabilizationInnerOuterLoopSIM_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==33) {
    c33_SALTStabilizationInnerOuterLoopSIM_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_SALTStabilizationInnerOuterLoopSIM_process_check_sum_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2846767039U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(354458446U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1408460546U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(174647426U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1287913792U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2049489885U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1809225413U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(563403199U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_SALTStabilizationInnerOuterLoopSIM_get_check_sum
            (mxArray *plhs[]);
          sf_c1_SALTStabilizationInnerOuterLoopSIM_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_SALTStabilizationInnerOuterLoopSIM_get_check_sum
            (mxArray *plhs[]);
          sf_c2_SALTStabilizationInnerOuterLoopSIM_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_SALTStabilizationInnerOuterLoopSIM_get_check_sum
            (mxArray *plhs[]);
          sf_c3_SALTStabilizationInnerOuterLoopSIM_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_SALTStabilizationInnerOuterLoopSIM_get_check_sum
            (mxArray *plhs[]);
          sf_c4_SALTStabilizationInnerOuterLoopSIM_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_SALTStabilizationInnerOuterLoopSIM_get_check_sum
            (mxArray *plhs[]);
          sf_c7_SALTStabilizationInnerOuterLoopSIM_get_check_sum(plhs);
          break;
        }

       case 33:
        {
          extern void sf_c33_SALTStabilizationInnerOuterLoopSIM_get_check_sum
            (mxArray *plhs[]);
          sf_c33_SALTStabilizationInnerOuterLoopSIM_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2230951352U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3033329348U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1649596025U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2001809931U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2427918242U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2783066706U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2313029955U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2601838020U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SALTStabilizationInnerOuterLoopSIM_autoinheritance_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "Fiz0HabezT46yCsSuk4QTG") == 0) {
          extern mxArray
            *sf_c1_SALTStabilizationInnerOuterLoopSIM_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c1_SALTStabilizationInnerOuterLoopSIM_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "xG35iPbBEaGhACUEmUwYK") == 0) {
          extern mxArray
            *sf_c2_SALTStabilizationInnerOuterLoopSIM_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c2_SALTStabilizationInnerOuterLoopSIM_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "Fiz0HabezT46yCsSuk4QTG") == 0) {
          extern mxArray
            *sf_c3_SALTStabilizationInnerOuterLoopSIM_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c3_SALTStabilizationInnerOuterLoopSIM_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "xPSKulkZc4YItyxVKAHmVE") == 0) {
          extern mxArray
            *sf_c4_SALTStabilizationInnerOuterLoopSIM_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c4_SALTStabilizationInnerOuterLoopSIM_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "kZK4X7qjA03J1D18S84apE") == 0) {
          extern mxArray
            *sf_c7_SALTStabilizationInnerOuterLoopSIM_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c7_SALTStabilizationInnerOuterLoopSIM_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 33:
      {
        if (strcmp(aiChksum, "xPSKulkZc4YItyxVKAHmVE") == 0) {
          extern mxArray
            *sf_c33_SALTStabilizationInnerOuterLoopSIM_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c33_SALTStabilizationInnerOuterLoopSIM_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int
  sf_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 33:
      {
        extern const mxArray
          *sf_c33_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c33_SALTStabilizationInnerOuterLoopSIM_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void SALTStabilizationInnerOuterLoopSIM_debug_initialize(void)
{
  _SALTStabilizationInnerOuterLoopSIMMachineNumber_ =
    sf_debug_initialize_machine("SALTStabilizationInnerOuterLoopSIM","sfun",0,6,
    0,0,0);
  sf_debug_set_machine_event_thresholds
    (_SALTStabilizationInnerOuterLoopSIMMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_SALTStabilizationInnerOuterLoopSIMMachineNumber_,0);
}

void SALTStabilizationInnerOuterLoopSIM_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_SALTStabilizationInnerOuterLoopSIM_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "SALTStabilizationInnerOuterLoopSIM", "SALTStabilizationInnerOuterLoopSIM");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_SALTStabilizationInnerOuterLoopSIM_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
