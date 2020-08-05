/*
 * Kalman_sid.h
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
 *
 * SOURCES: Kalman_sf.c
 */

/* statically allocated instance data for model: Kalman */
{
  extern const ConstB_Kalman_T Kalman_Invariant;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_Kalman_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_Kalman_T));
    }

    _ssSetConstBlockIO(rts, &Kalman_Invariant);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 1809586320U);
    ssSetChecksumVal(rts, 1, 4001684760U);
    ssSetChecksumVal(rts, 2, 4155278407U);
    ssSetChecksumVal(rts, 3, 1572624777U);
  }
}
