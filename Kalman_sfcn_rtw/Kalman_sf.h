/*
 * Kalman_sf.h
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

#ifndef RTW_HEADER_Kalman_sf_h_
#define RTW_HEADER_Kalman_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef Kalman_sf_COMMON_INCLUDES_
# define Kalman_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                Kalman_sf
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                                 /* Kalman_sf_COMMON_INCLUDES_ */

#include "Kalman_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (default storage) */
typedef struct {
  real_T Add;                          /* '<S22>/Add' */
  real_T Product3;                     /* '<S51>/Product3' */
} B_Kalman_T;

/* Continuous states (default storage) */
typedef struct {
  real_T MemoryX_CSTATE;               /* '<S1>/MemoryX' */
} X_Kalman_T;

/* State derivatives (default storage) */
typedef struct {
  real_T MemoryX_CSTATE;               /* '<S1>/MemoryX' */
} XDot_Kalman_T;

/* State disabled  */
typedef struct {
  boolean_T MemoryX_CSTATE;            /* '<S1>/MemoryX' */
} XDis_Kalman_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T X0;                     /* '<S1>/X0' */
} ConstB_Kalman_T;

/* For easy access from the SimStruct */
#define Kalman_rtC(rts)                ((ConstB_Kalman_T *) _ssGetConstBlockIO(rts))

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T *u;                           /* '<Root>/u' */
  real_T *y;                           /* '<Root>/y' */
} ExternalUPtrs_Kalman_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T *xhat;                        /* '<Root>/xhat' */
} ExtY_Kalman_T;

extern const ConstB_Kalman_T Kalman_Invariant;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('test1/Kalman Filter')    - opens subsystem test1/Kalman Filter
 * hilite_system('test1/Kalman Filter/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'test1'
 * '<S1>'   : 'test1/Kalman Filter'
 * '<S2>'   : 'test1/Kalman Filter/CalculatePL'
 * '<S3>'   : 'test1/Kalman Filter/CalculateYhat'
 * '<S4>'   : 'test1/Kalman Filter/CovarianceOutputConfigurator'
 * '<S5>'   : 'test1/Kalman Filter/DataTypeConversionA'
 * '<S6>'   : 'test1/Kalman Filter/DataTypeConversionB'
 * '<S7>'   : 'test1/Kalman Filter/DataTypeConversionC'
 * '<S8>'   : 'test1/Kalman Filter/DataTypeConversionD'
 * '<S9>'   : 'test1/Kalman Filter/DataTypeConversionEnable'
 * '<S10>'  : 'test1/Kalman Filter/DataTypeConversionG'
 * '<S11>'  : 'test1/Kalman Filter/DataTypeConversionH'
 * '<S12>'  : 'test1/Kalman Filter/DataTypeConversionN'
 * '<S13>'  : 'test1/Kalman Filter/DataTypeConversionP'
 * '<S14>'  : 'test1/Kalman Filter/DataTypeConversionP0'
 * '<S15>'  : 'test1/Kalman Filter/DataTypeConversionQ'
 * '<S16>'  : 'test1/Kalman Filter/DataTypeConversionR'
 * '<S17>'  : 'test1/Kalman Filter/DataTypeConversionReset'
 * '<S18>'  : 'test1/Kalman Filter/DataTypeConversionX'
 * '<S19>'  : 'test1/Kalman Filter/DataTypeConversionX0'
 * '<S20>'  : 'test1/Kalman Filter/DataTypeConversionu'
 * '<S21>'  : 'test1/Kalman Filter/MemoryP'
 * '<S22>'  : 'test1/Kalman Filter/Observer'
 * '<S23>'  : 'test1/Kalman Filter/ReducedQRN'
 * '<S24>'  : 'test1/Kalman Filter/Reset'
 * '<S25>'  : 'test1/Kalman Filter/Reshapeyhat'
 * '<S26>'  : 'test1/Kalman Filter/ScalarExpansionP0'
 * '<S27>'  : 'test1/Kalman Filter/ScalarExpansionQ'
 * '<S28>'  : 'test1/Kalman Filter/ScalarExpansionR'
 * '<S29>'  : 'test1/Kalman Filter/UseCurrentEstimator'
 * '<S30>'  : 'test1/Kalman Filter/checkA'
 * '<S31>'  : 'test1/Kalman Filter/checkB'
 * '<S32>'  : 'test1/Kalman Filter/checkC'
 * '<S33>'  : 'test1/Kalman Filter/checkD'
 * '<S34>'  : 'test1/Kalman Filter/checkEnable'
 * '<S35>'  : 'test1/Kalman Filter/checkG'
 * '<S36>'  : 'test1/Kalman Filter/checkH'
 * '<S37>'  : 'test1/Kalman Filter/checkN'
 * '<S38>'  : 'test1/Kalman Filter/checkP0'
 * '<S39>'  : 'test1/Kalman Filter/checkQ'
 * '<S40>'  : 'test1/Kalman Filter/checkR'
 * '<S41>'  : 'test1/Kalman Filter/checkReset'
 * '<S42>'  : 'test1/Kalman Filter/checkX0'
 * '<S43>'  : 'test1/Kalman Filter/checku'
 * '<S44>'  : 'test1/Kalman Filter/checky'
 * '<S45>'  : 'test1/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S46>'  : 'test1/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S47>'  : 'test1/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S48>'  : 'test1/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S49>'  : 'test1/Kalman Filter/CalculatePL/Ground'
 * '<S50>'  : 'test1/Kalman Filter/CalculateYhat/Ground'
 * '<S51>'  : 'test1/Kalman Filter/Observer/MeasurementUpdate'
 * '<S52>'  : 'test1/Kalman Filter/ReducedQRN/Ground'
 */
#endif                                 /* RTW_HEADER_Kalman_sf_h_ */
