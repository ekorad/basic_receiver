//
// File: System_Recv_io.h
//
// Code generated for Simulink model 'System_Recv_io'.
//
// Model version                  : 1.39
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Sat Oct 16 14:19:11 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: 32-bit Generic
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_System_Recv_io_h_
#define RTW_HEADER_System_Recv_io_h_
#include <cmath>
#include <math.h>
#include "rtw_modelmap.h"
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "System_Recv_io_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

// Block signals (default storage)
typedef struct {
  real_T TransferFcn1;                 // '<Root>/Transfer Fcn1'
  real_T Integrator7;                  // '<Root>/Integrator7'
  real_T Integrator8;                  // '<Root>/Integrator8'
  real_T Fcn11;                        // '<Root>/Fcn11'
  real_T TransferFcn13;                // '<Root>/Transfer Fcn13'
  real_T Integrator14;                 // '<Root>/Integrator14'
  real_T Integrator12;                 // '<Root>/Integrator12'
  real_T Integrator13;                 // '<Root>/Integrator13'
  real_T Integrator15;                 // '<Root>/Integrator15'
  real_T Fcn22;                        // '<Root>/Fcn22'
  real_T Clock;                        // '<Root>/Clock'
  real_T Switch;                       // '<Root>/Switch'
  real_T Sum3;                         // '<Root>/Sum3'
  real_T Fcn10;                        // '<Root>/Fcn10'
  real_T Integrator9;                  // '<Root>/Integrator9'
  real_T Sum2;                         // '<Root>/Sum2'
  real_T Fcn13;                        // '<Root>/Fcn13'
  real_T Integrator10;                 // '<Root>/Integrator10'
  real_T Integrator11;                 // '<Root>/Integrator11'
  real_T Gain1;                        // '<Root>/Gain1'
  real_T Saturation1;                  // '<Root>/Saturation1'
  real_T Fcn14;                        // '<Root>/Fcn14'
  real_T Fcn15;                        // '<Root>/Fcn15'
  real_T Fcn16;                        // '<Root>/Fcn16'
  real_T TransferFcn5;                 // '<Root>/Transfer Fcn5'
  real_T TransferFcn7;                 // '<Root>/Transfer Fcn7'
  real_T TransferFcn3;                 // '<Root>/Transfer Fcn3'
  real_T TransferFcn9;                 // '<Root>/Transfer Fcn9'
  real_T Gain2;                        // '<Root>/Gain2'
  real_T Saturation2;                  // '<Root>/Saturation2'
  real_T Fcn18;                        // '<Root>/Fcn18'
  real_T Fcn19;                        // '<Root>/Fcn19'
  real_T Fcn20;                        // '<Root>/Fcn20'
  real_T Fcn21;                        // '<Root>/Fcn21'
  real_T Integrator6;                  // '<Root>/Integrator6'
  real_T Sum1;                         // '<Root>/Sum1'
  real_T Fcn6;                         // '<Root>/Fcn6'
  real_T Gain;                         // '<Root>/Gain'
  real_T Saturation;                   // '<Root>/Saturation'
  real_T Fcn7;                         // '<Root>/Fcn7'
  real_T Fcn8;                         // '<Root>/Fcn8'
  real_T Fcn9;                         // '<Root>/Fcn9'
  real_T Switch1;                      // '<Root>/Switch1'
  real_T TransferFcn;                  // '<Root>/Transfer Fcn'
  real_T TransferFcn10;                // '<Root>/Transfer Fcn10'
  real_T TransferFcn11;                // '<Root>/Transfer Fcn11'
  real_T TransferFcn12;                // '<Root>/Transfer Fcn12'
  real_T TransferFcn2;                 // '<Root>/Transfer Fcn2'
  real_T TransferFcn4;                 // '<Root>/Transfer Fcn4'
  real_T TransferFcn6;                 // '<Root>/Transfer Fcn6'
  real_T TransferFcn8;                 // '<Root>/Transfer Fcn8'
  real_T Saturation4;                  // '<Root>/Saturation4'
  real_T Fcn17;                        // '<Root>/Fcn17'
  real_T Saturation3;                  // '<Root>/Saturation3'
} B_System_Recv_io_T;

// Continuous states (default storage)
typedef struct {
  real_T TransferFcn1_CSTATE[2];       // '<Root>/Transfer Fcn1'
  real_T Integrator7_CSTATE;           // '<Root>/Integrator7'
  real_T Integrator8_CSTATE;           // '<Root>/Integrator8'
  real_T TransferFcn13_CSTATE[2];      // '<Root>/Transfer Fcn13'
  real_T Integrator14_CSTATE;          // '<Root>/Integrator14'
  real_T Integrator12_CSTATE;          // '<Root>/Integrator12'
  real_T Integrator13_CSTATE;          // '<Root>/Integrator13'
  real_T Integrator15_CSTATE;          // '<Root>/Integrator15'
  real_T Integrator9_CSTATE;           // '<Root>/Integrator9'
  real_T Integrator10_CSTATE;          // '<Root>/Integrator10'
  real_T Integrator11_CSTATE;          // '<Root>/Integrator11'
  real_T TransferFcn5_CSTATE[2];       // '<Root>/Transfer Fcn5'
  real_T TransferFcn7_CSTATE[2];       // '<Root>/Transfer Fcn7'
  real_T TransferFcn3_CSTATE[2];       // '<Root>/Transfer Fcn3'
  real_T TransferFcn9_CSTATE[2];       // '<Root>/Transfer Fcn9'
  real_T Integrator6_CSTATE;           // '<Root>/Integrator6'
  real_T TransferFcn_CSTATE[2];        // '<Root>/Transfer Fcn'
  real_T TransferFcn10_CSTATE[2];      // '<Root>/Transfer Fcn10'
  real_T TransferFcn11_CSTATE[2];      // '<Root>/Transfer Fcn11'
  real_T TransferFcn12_CSTATE[2];      // '<Root>/Transfer Fcn12'
  real_T TransferFcn2_CSTATE[2];       // '<Root>/Transfer Fcn2'
  real_T TransferFcn4_CSTATE[2];       // '<Root>/Transfer Fcn4'
  real_T TransferFcn6_CSTATE[2];       // '<Root>/Transfer Fcn6'
  real_T TransferFcn8_CSTATE[2];       // '<Root>/Transfer Fcn8'
} X_System_Recv_io_T;

// State derivatives (default storage)
typedef struct {
  real_T TransferFcn1_CSTATE[2];       // '<Root>/Transfer Fcn1'
  real_T Integrator7_CSTATE;           // '<Root>/Integrator7'
  real_T Integrator8_CSTATE;           // '<Root>/Integrator8'
  real_T TransferFcn13_CSTATE[2];      // '<Root>/Transfer Fcn13'
  real_T Integrator14_CSTATE;          // '<Root>/Integrator14'
  real_T Integrator12_CSTATE;          // '<Root>/Integrator12'
  real_T Integrator13_CSTATE;          // '<Root>/Integrator13'
  real_T Integrator15_CSTATE;          // '<Root>/Integrator15'
  real_T Integrator9_CSTATE;           // '<Root>/Integrator9'
  real_T Integrator10_CSTATE;          // '<Root>/Integrator10'
  real_T Integrator11_CSTATE;          // '<Root>/Integrator11'
  real_T TransferFcn5_CSTATE[2];       // '<Root>/Transfer Fcn5'
  real_T TransferFcn7_CSTATE[2];       // '<Root>/Transfer Fcn7'
  real_T TransferFcn3_CSTATE[2];       // '<Root>/Transfer Fcn3'
  real_T TransferFcn9_CSTATE[2];       // '<Root>/Transfer Fcn9'
  real_T Integrator6_CSTATE;           // '<Root>/Integrator6'
  real_T TransferFcn_CSTATE[2];        // '<Root>/Transfer Fcn'
  real_T TransferFcn10_CSTATE[2];      // '<Root>/Transfer Fcn10'
  real_T TransferFcn11_CSTATE[2];      // '<Root>/Transfer Fcn11'
  real_T TransferFcn12_CSTATE[2];      // '<Root>/Transfer Fcn12'
  real_T TransferFcn2_CSTATE[2];       // '<Root>/Transfer Fcn2'
  real_T TransferFcn4_CSTATE[2];       // '<Root>/Transfer Fcn4'
  real_T TransferFcn6_CSTATE[2];       // '<Root>/Transfer Fcn6'
  real_T TransferFcn8_CSTATE[2];       // '<Root>/Transfer Fcn8'
} XDot_System_Recv_io_T;

// State disabled
typedef struct {
  boolean_T TransferFcn1_CSTATE[2];    // '<Root>/Transfer Fcn1'
  boolean_T Integrator7_CSTATE;        // '<Root>/Integrator7'
  boolean_T Integrator8_CSTATE;        // '<Root>/Integrator8'
  boolean_T TransferFcn13_CSTATE[2];   // '<Root>/Transfer Fcn13'
  boolean_T Integrator14_CSTATE;       // '<Root>/Integrator14'
  boolean_T Integrator12_CSTATE;       // '<Root>/Integrator12'
  boolean_T Integrator13_CSTATE;       // '<Root>/Integrator13'
  boolean_T Integrator15_CSTATE;       // '<Root>/Integrator15'
  boolean_T Integrator9_CSTATE;        // '<Root>/Integrator9'
  boolean_T Integrator10_CSTATE;       // '<Root>/Integrator10'
  boolean_T Integrator11_CSTATE;       // '<Root>/Integrator11'
  boolean_T TransferFcn5_CSTATE[2];    // '<Root>/Transfer Fcn5'
  boolean_T TransferFcn7_CSTATE[2];    // '<Root>/Transfer Fcn7'
  boolean_T TransferFcn3_CSTATE[2];    // '<Root>/Transfer Fcn3'
  boolean_T TransferFcn9_CSTATE[2];    // '<Root>/Transfer Fcn9'
  boolean_T Integrator6_CSTATE;        // '<Root>/Integrator6'
  boolean_T TransferFcn_CSTATE[2];     // '<Root>/Transfer Fcn'
  boolean_T TransferFcn10_CSTATE[2];   // '<Root>/Transfer Fcn10'
  boolean_T TransferFcn11_CSTATE[2];   // '<Root>/Transfer Fcn11'
  boolean_T TransferFcn12_CSTATE[2];   // '<Root>/Transfer Fcn12'
  boolean_T TransferFcn2_CSTATE[2];    // '<Root>/Transfer Fcn2'
  boolean_T TransferFcn4_CSTATE[2];    // '<Root>/Transfer Fcn4'
  boolean_T TransferFcn6_CSTATE[2];    // '<Root>/Transfer Fcn6'
  boolean_T TransferFcn8_CSTATE[2];    // '<Root>/Transfer Fcn8'
} XDis_System_Recv_io_T;

#ifndef ODE1_INTG
#define ODE1_INTG

// ODE1 Integration Data
typedef struct {
  real_T *f[1];                        // derivatives
} ODE1_IntgData;

#endif

// External inputs (root inport signals with default storage)
typedef struct {
  real_T xc_in;                        // '<Root>/xc_in'
  real_T zc_in;                        // '<Root>/zc_in'
  real_T yr_in;                        // '<Root>/yr_in'
} ExtU_System_Recv_io_T;

// External outputs (root outports fed by signals with default storage)
typedef struct {
  real_T u1h_out;                      // '<Root>/u1h_out'
  real_T u1hnf_out;                    // '<Root>/u1hnf_out'
  real_T yrh_out;                      // '<Root>/yrh_out'
  real_T u2h_out;                      // '<Root>/u2h_out'
} ExtY_System_Recv_io_T;

// Real-time Model Data Structure
struct tag_RTM_System_Recv_io_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_System_Recv_io_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][38];
  ODE1_IntgData intgData;

  //
  //  DataMapInfo:
  //  The following substructure contains information regarding
  //  structures generated in the model's C API.

  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_System_Recv_io_T System_Recv_io_B;

#ifdef __cplusplus

}
#endif

// Continuous states (default storage)
extern X_System_Recv_io_T System_Recv_io_X;

#ifdef __cplusplus

extern "C" {

#endif

  // External inputs (root inport signals with default storage)
  extern ExtU_System_Recv_io_T System_Recv_io_U;

  // External outputs (root outports fed by signals with default storage)
  extern ExtY_System_Recv_io_T System_Recv_io_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void System_Recv_io_initialize(void);
  extern void System_Recv_io_step(void);
  extern void System_Recv_io_terminate(void);

#ifdef __cplusplus

}
#endif

// Function to get C API Model Mapping Static Info
extern const rtwCAPI_ModelMappingStaticInfo*
  System_Recv_io_GetCAPIStaticMap(void);

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_System_Recv_io_T *const System_Recv_io_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'System_Recv_io'

#endif                                 // RTW_HEADER_System_Recv_io_h_

//
// File trailer for generated code.
//
// [EOF]
//
