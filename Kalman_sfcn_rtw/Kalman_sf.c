/*
 * Kalman_sf.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Kalman_sf".
 *
 * Model version              : 1.16
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Aug  5 07:06:10 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <math.h>
#include "Kalman_sf.h"
#include "Kalman_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *Kalman_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* System initialize for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  if (ssIsFirstInitCond(S)) {
    B_Kalman_T *_rtB;
    X_Kalman_T *_rtX;
    _rtX = ((X_Kalman_T *) ssGetContStates(S));
    _rtB = ((B_Kalman_T *) ssGetLocalBlockIO(S));

    /* InitializeConditions for Integrator: '<S1>/MemoryX' */
    if (ssIsFirstInitCond(S)) {
      _rtX->MemoryX_CSTATE = 0.0;
    }

    ((int_T *)ssGetDWork(S, 0))[0] = 1;

    /* End of InitializeConditions for Integrator: '<S1>/MemoryX' */

    /* SystemInitialize for Enabled SubSystem: '<S22>/MeasurementUpdate' */
    /* SystemInitialize for Outport: '<S51>/L*(y[k]-yhat[k|k-1])' */
    _rtB->Product3 = 0.0;

    /* End of SystemInitialize for SubSystem: '<S22>/MeasurementUpdate' */
  } else {
    X_Kalman_T *_rtX;
    _rtX = ((X_Kalman_T *) ssGetContStates(S));

    /* InitializeConditions for Integrator: '<S1>/MemoryX' */
    if (ssIsFirstInitCond(S)) {
      _rtX->MemoryX_CSTATE = 0.0;
    }

    ((int_T *)ssGetDWork(S, 0))[0] = 1;

    /* End of InitializeConditions for Integrator: '<S1>/MemoryX' */
  }
}

/* Disable for root system: '<Root>' */
#define RTW_GENERATED_DISABLE

static void mdlDisable(SimStruct *S)
{
  B_Kalman_T *_rtB;
  _rtB = ((B_Kalman_T *) ssGetLocalBlockIO(S));

  /* Disable for Enabled SubSystem: '<S22>/MeasurementUpdate' */
  if (((boolean_T *)ssGetDWork(S, 1))[0]) {
    /* Disable for Outport: '<S51>/L*(y[k]-yhat[k|k-1])' */
    _rtB->Product3 = 0.0;
    ((boolean_T *)ssGetDWork(S, 1))[0] = false;
  }

  /* End of Disable for SubSystem: '<S22>/MeasurementUpdate' */
}

/* Start for root system: '<Root>' */
#define MDL_START

static void mdlStart(SimStruct *S)
{
  /* instance underlying S-Function data */
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  if defined(MATLAB_MEX_FILE)

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Check for invalid switching between solver types */
  if (ssIsVariableStepSolver(S)) {
    ssSetErrorStatus(S, "This Simulink Coder generated "
                     "S-Function cannot be used in a simulation with "
                     "a solver type of variable-step "
                     "because this S-Function was created from a model with "
                     "solver type of fixed-step and it has continuous time blocks. "
                     "See the Solver page of the simulation parameters dialog.");
    return;
  }

  if (ssGetSolverMode(S) == SOLVER_MODE_MULTITASKING) {
    ssSetErrorStatus(S, "This Simulink Coder generated "
                     "S-Function cannot be used in a simulation with "
                     "solver mode set to auto or multitasking "
                     "because this S-Function was created from a model with "
                     "solver mode set to singletasking. "
                     "See the Solver page of the simulation parameters dialog.");
    return;
  }

#  endif

  Kalman_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
    /* Start for Enabled SubSystem: '<S22>/MeasurementUpdate' */
    ((boolean_T *)ssGetDWork(S, 1))[0] = false;
    ssSetBlockStateForSolverChangedAtMajorStep(S);

    /* End of Start for SubSystem: '<S22>/MeasurementUpdate' */
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  real_T rtb_MemoryX;
  real_T rtb_Bkuk;
  real_T rtb_Akxhatkk1;
  B_Kalman_T *_rtB;
  X_Kalman_T *_rtX;
  _rtX = ((X_Kalman_T *) ssGetContStates(S));
  _rtB = ((B_Kalman_T *) ssGetLocalBlockIO(S));
  if (1) {
    /* Integrator: '<S1>/MemoryX' */
    if (((int_T *)ssGetDWork(S, 0))[0] != 0) {
      _rtX->MemoryX_CSTATE = Kalman_rtC(S)->X0;
    }

    rtb_MemoryX = _rtX->MemoryX_CSTATE;

    /* Outport: '<Root>/xhat' incorporates:
     *  Integrator: '<S1>/MemoryX'
     */
    ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtX->MemoryX_CSTATE;

    /* Product: '<S22>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S1>/A'
     *  Integrator: '<S1>/MemoryX'
     */
    rtb_Akxhatkk1 = -200.0 * _rtX->MemoryX_CSTATE;

    /* Product: '<S22>/B[k]*u[k]' incorporates:
     *  Constant: '<S1>/B'
     */
    rtb_Bkuk = 33.3333 * *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0];
  }

  /* Outputs for Enabled SubSystem: '<S22>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S51>/Enable'
   */
  if (ssIsSampleHit(S, 1, 0) && ssIsMajorTimeStep(S) && (!((boolean_T *)
        ssGetDWork(S, 1))[0])) {
    if (ssGetTaskTime(S,1) != ssGetTStart(S)) {
      ssSetBlockStateForSolverChangedAtMajorStep(S);
    }

    ((boolean_T *)ssGetDWork(S, 1))[0] = true;
  }

  if (((boolean_T *)ssGetDWork(S, 1))[0] && 1) {
    /* Product: '<S51>/Product3' incorporates:
     *  Constant: '<S1>/D'
     *  Constant: '<S2>/KalmanGainL'
     *  Product: '<S51>/C[k]*xhat[k|k-1]'
     *  Product: '<S51>/D[k]*u[k]'
     *  Sum: '<S51>/Add1'
     *  Sum: '<S51>/Sum'
     */
    _rtB->Product3 = (*((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] -
                      (0.0 * *((const real_T **)ssGetInputPortSignalPtrs(S, 0))
                       [0] + rtb_MemoryX)) * -0.0;
  }

  /* End of Outputs for SubSystem: '<S22>/MeasurementUpdate' */
  if (1) {
    /* Sum: '<S22>/Add' */
    _rtB->Add = (rtb_Bkuk + rtb_Akxhatkk1) + _rtB->Product3;
  }

  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  if (1) {
    /* Update for Integrator: '<S1>/MemoryX' */
    ((int_T *)ssGetDWork(S, 0))[0] = 0;
  }

  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES

static void mdlDerivatives(SimStruct *S)
{
  B_Kalman_T *_rtB;
  XDot_Kalman_T *_rtXdot;
  _rtXdot = ((XDot_Kalman_T *) ssGetdX(S));
  _rtB = ((B_Kalman_T *) ssGetLocalBlockIO(S));

  /* Derivatives for Integrator: '<S1>/MemoryX' */
  _rtXdot->MemoryX_CSTATE = _rtB->Add;
}

/* Termination for root system: '<Root>' */
static void mdlTerminate(SimStruct *S)
{

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

  if (ssGetUserData(S) != (NULL) ) {
    rt_FREE(ssGetLocalBlockIO(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "Kalman_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 2);           /* Number of sample times */
  ssSetNumContStates(S, 1);            /* Number of continuous states */
  ssSetNumPeriodicContStates(S, 0);   /* Number of periodic continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 1))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 0.0);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 2))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortSampleTime(S, 0, 0.0);
    ssSetInputPortOffsetTime(S, 0, 0.0);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 1 */
  {
    if (!ssSetInputPortVectorDimension(S, 1, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 1, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortSampleTime(S, 1, 0.0);
    ssSetInputPortOffsetTime(S, 1, 0.0);
    ssSetInputPortOverWritable(S, 1, 0);
    ssSetInputPortOptimOpts(S, 1, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 2)) {
    return;
  }

  /* '<S1>/MemoryX': IWORK */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);
  ssSetDWorkDataType(S, 0, SS_INTEGER);

  /* '<S22>/MeasurementUpdate': MODE */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 1);
  ssSetDWorkDataType(S, 1, SS_BOOLEAN);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 0);

  /* Number of expected parameters */
#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif                                 /* MDL_CHECK_PARAMETERS */

    if (ssGetErrorStatus(S) != (NULL) ) {
      return;
    }
  } else {
    return;                /* Parameter mismatch will be reported by Simulink */
  }

#endif                                 /* MATLAB_MEX_FILE */

  /* Options */
  ssSetOptions(S, (SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE |
                   SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED ));

#if SS_SFCN_FOR_SIM

  {
    ssSupportsMultipleExecInstances(S, true);
    ssHasStateInsideForEachSS(S, false);
  }

#endif

}

/* Function to initialize sample times. */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* task periods */
  ssSetSampleTime(S, 0, 0.0);
  ssSetSampleTime(S, 1, 0.001);

  /* task offsets */
  ssSetOffsetTime(S, 0, 0.0);
  ssSetOffsetTime(S, 1, 0.0);
}

#if defined(MATLAB_MEX_FILE)
# include "fixedpoint.c"
# include "simulink.c"
#else
# undef S_FUNCTION_NAME
# define S_FUNCTION_NAME               Kalman_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
