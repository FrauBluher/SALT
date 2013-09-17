/* Include files */

#include "SALTStabilizationInnerOuterLoop_sfun.h"
#include "c1_SALTStabilizationInnerOuterLoop.h"
#include "c2_SALTStabilizationInnerOuterLoop.h"
#include "c3_SALTStabilizationInnerOuterLoop.h"
#include "c4_SALTStabilizationInnerOuterLoop.h"
#include "c5_SALTStabilizationInnerOuterLoop.h"
#include "c7_SALTStabilizationInnerOuterLoop.h"
#include "c8_SALTStabilizationInnerOuterLoop.h"
#include "c9_SALTStabilizationInnerOuterLoop.h"
#include "c10_SALTStabilizationInnerOuterLoop.h"
#include "c11_SALTStabilizationInnerOuterLoop.h"
#include "c12_SALTStabilizationInnerOuterLoop.h"
#include "c33_SALTStabilizationInnerOuterLoop.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _SALTStabilizationInnerOuterLoopMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void SALTStabilizationInnerOuterLoop_initializer(void)
{
}

void SALTStabilizationInnerOuterLoop_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_SALTStabilizationInnerOuterLoop_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_SALTStabilizationInnerOuterLoop_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_SALTStabilizationInnerOuterLoop_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_SALTStabilizationInnerOuterLoop_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_SALTStabilizationInnerOuterLoop_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_SALTStabilizationInnerOuterLoop_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_SALTStabilizationInnerOuterLoop_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_SALTStabilizationInnerOuterLoop_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_SALTStabilizationInnerOuterLoop_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_SALTStabilizationInnerOuterLoop_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_SALTStabilizationInnerOuterLoop_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_SALTStabilizationInnerOuterLoop_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==33) {
    c33_SALTStabilizationInnerOuterLoop_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_SALTStabilizationInnerOuterLoop_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3576577614U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1473068954U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(865491240U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2771728627U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(448767413U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3473931649U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3316997116U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3919156135U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_SALTStabilizationInnerOuterLoop_get_check_sum
            (mxArray *plhs[]);
          sf_c1_SALTStabilizationInnerOuterLoop_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_SALTStabilizationInnerOuterLoop_get_check_sum
            (mxArray *plhs[]);
          sf_c2_SALTStabilizationInnerOuterLoop_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_SALTStabilizationInnerOuterLoop_get_check_sum
            (mxArray *plhs[]);
          sf_c3_SALTStabilizationInnerOuterLoop_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_SALTStabilizationInnerOuterLoop_get_check_sum
            (mxArray *plhs[]);
          sf_c4_SALTStabilizationInnerOuterLoop_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_SALTStabilizationInnerOuterLoop_get_check_sum
            (mxArray *plhs[]);
          sf_c5_SALTStabilizationInnerOuterLoop_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_SALTStabilizationInnerOuterLoop_get_check_sum
            (mxArray *plhs[]);
          sf_c7_SALTStabilizationInnerOuterLoop_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_SALTStabilizationInnerOuterLoop_get_check_sum
            (mxArray *plhs[]);
          sf_c8_SALTStabilizationInnerOuterLoop_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_SALTStabilizationInnerOuterLoop_get_check_sum
            (mxArray *plhs[]);
          sf_c9_SALTStabilizationInnerOuterLoop_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_SALTStabilizationInnerOuterLoop_get_check_sum
            (mxArray *plhs[]);
          sf_c10_SALTStabilizationInnerOuterLoop_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_SALTStabilizationInnerOuterLoop_get_check_sum
            (mxArray *plhs[]);
          sf_c11_SALTStabilizationInnerOuterLoop_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_SALTStabilizationInnerOuterLoop_get_check_sum
            (mxArray *plhs[]);
          sf_c12_SALTStabilizationInnerOuterLoop_get_check_sum(plhs);
          break;
        }

       case 33:
        {
          extern void sf_c33_SALTStabilizationInnerOuterLoop_get_check_sum
            (mxArray *plhs[]);
          sf_c33_SALTStabilizationInnerOuterLoop_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(198062696U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2720385510U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1841444216U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1456639490U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SALTStabilizationInnerOuterLoop_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "xG35iPbBEaGhACUEmUwYK") == 0) {
          extern mxArray
            *sf_c1_SALTStabilizationInnerOuterLoop_get_autoinheritance_info(void);
          plhs[0] =
            sf_c1_SALTStabilizationInnerOuterLoop_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "Fiz0HabezT46yCsSuk4QTG") == 0) {
          extern mxArray
            *sf_c2_SALTStabilizationInnerOuterLoop_get_autoinheritance_info(void);
          plhs[0] =
            sf_c2_SALTStabilizationInnerOuterLoop_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "Fiz0HabezT46yCsSuk4QTG") == 0) {
          extern mxArray
            *sf_c3_SALTStabilizationInnerOuterLoop_get_autoinheritance_info(void);
          plhs[0] =
            sf_c3_SALTStabilizationInnerOuterLoop_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "xPSKulkZc4YItyxVKAHmVE") == 0) {
          extern mxArray
            *sf_c4_SALTStabilizationInnerOuterLoop_get_autoinheritance_info(void);
          plhs[0] =
            sf_c4_SALTStabilizationInnerOuterLoop_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "xPSKulkZc4YItyxVKAHmVE") == 0) {
          extern mxArray
            *sf_c5_SALTStabilizationInnerOuterLoop_get_autoinheritance_info(void);
          plhs[0] =
            sf_c5_SALTStabilizationInnerOuterLoop_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "kZK4X7qjA03J1D18S84apE") == 0) {
          extern mxArray
            *sf_c7_SALTStabilizationInnerOuterLoop_get_autoinheritance_info(void);
          plhs[0] =
            sf_c7_SALTStabilizationInnerOuterLoop_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "kZK4X7qjA03J1D18S84apE") == 0) {
          extern mxArray
            *sf_c8_SALTStabilizationInnerOuterLoop_get_autoinheritance_info(void);
          plhs[0] =
            sf_c8_SALTStabilizationInnerOuterLoop_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "xG35iPbBEaGhACUEmUwYK") == 0) {
          extern mxArray
            *sf_c9_SALTStabilizationInnerOuterLoop_get_autoinheritance_info(void);
          plhs[0] =
            sf_c9_SALTStabilizationInnerOuterLoop_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "Fiz0HabezT46yCsSuk4QTG") == 0) {
          extern mxArray
            *sf_c10_SALTStabilizationInnerOuterLoop_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c10_SALTStabilizationInnerOuterLoop_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "Fiz0HabezT46yCsSuk4QTG") == 0) {
          extern mxArray
            *sf_c11_SALTStabilizationInnerOuterLoop_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c11_SALTStabilizationInnerOuterLoop_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "xPSKulkZc4YItyxVKAHmVE") == 0) {
          extern mxArray
            *sf_c12_SALTStabilizationInnerOuterLoop_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c12_SALTStabilizationInnerOuterLoop_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 33:
      {
        if (strcmp(aiChksum, "xPSKulkZc4YItyxVKAHmVE") == 0) {
          extern mxArray
            *sf_c33_SALTStabilizationInnerOuterLoop_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c33_SALTStabilizationInnerOuterLoop_get_autoinheritance_info();
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

unsigned int sf_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info(
  int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
          *sf_c1_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 33:
      {
        extern const mxArray
          *sf_c33_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c33_SALTStabilizationInnerOuterLoop_get_eml_resolved_functions_info
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

void SALTStabilizationInnerOuterLoop_debug_initialize(void)
{
  _SALTStabilizationInnerOuterLoopMachineNumber_ = sf_debug_initialize_machine(
    "SALTStabilizationInnerOuterLoop","sfun",0,12,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_SALTStabilizationInnerOuterLoopMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_SALTStabilizationInnerOuterLoopMachineNumber_,0);
}

void SALTStabilizationInnerOuterLoop_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_SALTStabilizationInnerOuterLoop_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "SALTStabilizationInnerOuterLoop", "SALTStabilizationInnerOuterLoop");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_SALTStabilizationInnerOuterLoop_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
