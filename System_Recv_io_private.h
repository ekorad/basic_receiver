//
// File: System_Recv_io_private.h
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
#ifndef RTW_HEADER_System_Recv_io_private_h_
#define RTW_HEADER_System_Recv_io_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern real_T rt_powd_snf(real_T u0, real_T u1);

// private model entry point functions
extern void System_Recv_io_derivatives(void);

#endif                                 // RTW_HEADER_System_Recv_io_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
