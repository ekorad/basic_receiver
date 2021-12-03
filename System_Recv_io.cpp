//
// File: System_Recv_io.cpp
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
#include "System_Recv_io_capi.h"
#include "System_Recv_io.h"
#include "System_Recv_io_private.h"

#include "cmath"

// Block signals (default storage)
B_System_Recv_io_T System_Recv_io_B;

// Continuous states
X_System_Recv_io_T System_Recv_io_X;

// External inputs (root inport signals with default storage)
ExtU_System_Recv_io_T System_Recv_io_U;

// External outputs (root outports fed by signals with default storage)
ExtY_System_Recv_io_T System_Recv_io_Y;

// Real-time model
RT_MODEL_System_Recv_io_T System_Recv_io_M_ = RT_MODEL_System_Recv_io_T();
RT_MODEL_System_Recv_io_T *const System_Recv_io_M = &System_Recv_io_M_;

//
// This function updates continuous states using the ODE1 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = static_cast<ODE1_IntgData *>(rtsiGetSolverData(si));
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 38;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  System_Recv_io_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

// Model step function
void System_Recv_io_step(void)
{
  real_T tmp;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(System_Recv_io_M)) {
    // set solver stop time
    if (!(System_Recv_io_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&System_Recv_io_M->solverInfo,
                            ((System_Recv_io_M->Timing.clockTickH0 + 1) *
        System_Recv_io_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&System_Recv_io_M->solverInfo,
                            ((System_Recv_io_M->Timing.clockTick0 + 1) *
        System_Recv_io_M->Timing.stepSize0 +
        System_Recv_io_M->Timing.clockTickH0 *
        System_Recv_io_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(System_Recv_io_M)) {
    System_Recv_io_M->Timing.t[0] = rtsiGetT(&System_Recv_io_M->solverInfo);
  }

  // TransferFcn: '<Root>/Transfer Fcn1'
  System_Recv_io_B.TransferFcn1 = 0.0;
  System_Recv_io_B.TransferFcn1 += 0.0 * System_Recv_io_X.TransferFcn1_CSTATE[0];
  System_Recv_io_B.TransferFcn1 += 1.577536E+8 *
    System_Recv_io_X.TransferFcn1_CSTATE[1];

  // Integrator: '<Root>/Integrator7'
  System_Recv_io_B.Integrator7 = System_Recv_io_X.Integrator7_CSTATE;

  // Integrator: '<Root>/Integrator8'
  System_Recv_io_B.Integrator8 = System_Recv_io_X.Integrator8_CSTATE;

  // Fcn: '<Root>/Fcn11' incorporates:
  //   Inport: '<Root>/xc_in'
  //   Inport: '<Root>/zc_in'

  System_Recv_io_B.Fcn11 = ((((10.0 * System_Recv_io_U.xc_in *
    System_Recv_io_U.zc_in + System_Recv_io_B.Integrator8 / 10.0) - 28.0 *
    System_Recv_io_U.xc_in) + System_Recv_io_B.Integrator7 / 10.0) +
    System_Recv_io_U.xc_in) + System_Recv_io_B.Integrator7;
  if (rtmIsMajorTimeStep(System_Recv_io_M)) {
    // Outport: '<Root>/u1h_out' incorporates:
    //   ZeroOrderHold: '<Root>/Zero-Order Hold'

    System_Recv_io_Y.u1h_out = System_Recv_io_B.TransferFcn1;
  }

  // TransferFcn: '<Root>/Transfer Fcn13'
  System_Recv_io_B.TransferFcn13 = 0.0;
  System_Recv_io_B.TransferFcn13 += 0.0 * System_Recv_io_X.TransferFcn13_CSTATE
    [0];
  System_Recv_io_B.TransferFcn13 += 1.577536E+8 *
    System_Recv_io_X.TransferFcn13_CSTATE[1];
  if (rtmIsMajorTimeStep(System_Recv_io_M)) {
    // Outport: '<Root>/u1hnf_out' incorporates:
    //   ZeroOrderHold: '<Root>/Zero-Order Hold1'

    System_Recv_io_Y.u1hnf_out = System_Recv_io_B.Fcn11;

    // Outport: '<Root>/yrh_out' incorporates:
    //   ZeroOrderHold: '<Root>/Zero-Order Hold2'

    System_Recv_io_Y.yrh_out = System_Recv_io_B.TransferFcn13;
  }

  // Integrator: '<Root>/Integrator14'
  // Limited  Integrator
  if (System_Recv_io_X.Integrator14_CSTATE >= 800.0) {
    if (System_Recv_io_X.Integrator14_CSTATE > 800.0) {
      rtsiSetBlockStateForSolverChangedAtMajorStep(&System_Recv_io_M->solverInfo,
        true);
    }

    System_Recv_io_X.Integrator14_CSTATE = 800.0;
  } else {
    if (System_Recv_io_X.Integrator14_CSTATE <= (-800.0)) {
      if (System_Recv_io_X.Integrator14_CSTATE < (-800.0)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&System_Recv_io_M->solverInfo, true);
      }

      System_Recv_io_X.Integrator14_CSTATE = (-800.0);
    }
  }

  System_Recv_io_B.Integrator14 = System_Recv_io_X.Integrator14_CSTATE;

  // End of Integrator: '<Root>/Integrator14'

  // Integrator: '<Root>/Integrator12'
  // Limited  Integrator
  if (System_Recv_io_X.Integrator12_CSTATE >= 800.0) {
    if (System_Recv_io_X.Integrator12_CSTATE > 800.0) {
      rtsiSetBlockStateForSolverChangedAtMajorStep(&System_Recv_io_M->solverInfo,
        true);
    }

    System_Recv_io_X.Integrator12_CSTATE = 800.0;
  } else {
    if (System_Recv_io_X.Integrator12_CSTATE <= (-800.0)) {
      if (System_Recv_io_X.Integrator12_CSTATE < (-800.0)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&System_Recv_io_M->solverInfo, true);
      }

      System_Recv_io_X.Integrator12_CSTATE = (-800.0);
    }
  }

  System_Recv_io_B.Integrator12 = System_Recv_io_X.Integrator12_CSTATE;

  // End of Integrator: '<Root>/Integrator12'

  // Integrator: '<Root>/Integrator13'
  // Limited  Integrator
  if (System_Recv_io_X.Integrator13_CSTATE >= 800.0) {
    if (System_Recv_io_X.Integrator13_CSTATE > 800.0) {
      rtsiSetBlockStateForSolverChangedAtMajorStep(&System_Recv_io_M->solverInfo,
        true);
    }

    System_Recv_io_X.Integrator13_CSTATE = 800.0;
  } else {
    if (System_Recv_io_X.Integrator13_CSTATE <= (-800.0)) {
      if (System_Recv_io_X.Integrator13_CSTATE < (-800.0)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&System_Recv_io_M->solverInfo, true);
      }

      System_Recv_io_X.Integrator13_CSTATE = (-800.0);
    }
  }

  System_Recv_io_B.Integrator13 = System_Recv_io_X.Integrator13_CSTATE;

  // End of Integrator: '<Root>/Integrator13'

  // Integrator: '<Root>/Integrator15'
  // Limited  Integrator
  if (System_Recv_io_X.Integrator15_CSTATE >= 800.0) {
    if (System_Recv_io_X.Integrator15_CSTATE > 800.0) {
      rtsiSetBlockStateForSolverChangedAtMajorStep(&System_Recv_io_M->solverInfo,
        true);
    }

    System_Recv_io_X.Integrator15_CSTATE = 800.0;
  } else {
    if (System_Recv_io_X.Integrator15_CSTATE <= (-800.0)) {
      if (System_Recv_io_X.Integrator15_CSTATE < (-800.0)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&System_Recv_io_M->solverInfo, true);
      }

      System_Recv_io_X.Integrator15_CSTATE = (-800.0);
    }
  }

  System_Recv_io_B.Integrator15 = System_Recv_io_X.Integrator15_CSTATE;

  // End of Integrator: '<Root>/Integrator15'

  // Fcn: '<Root>/Fcn22'
  System_Recv_io_B.Fcn22 = ((((System_Recv_io_B.Integrator12 - 0.15 *
    System_Recv_io_B.Integrator14) - 10.0) * ((-System_Recv_io_B.Integrator13 -
    System_Recv_io_B.Integrator14) + 0.15 * System_Recv_io_B.Integrator12) +
    ((System_Recv_io_B.Integrator15 + System_Recv_io_B.Integrator12) + 0.2)) +
    (((System_Recv_io_B.Integrator14 - System_Recv_io_B.Integrator13) -
      System_Recv_io_B.Integrator14) + 0.15 * System_Recv_io_B.Integrator12) *
    0.15) - 0.0225 * System_Recv_io_B.Integrator12;
  if (rtmIsMajorTimeStep(System_Recv_io_M)) {
    // Outport: '<Root>/u2h_out' incorporates:
    //   ZeroOrderHold: '<Root>/Zero-Order Hold3'

    System_Recv_io_Y.u2h_out = System_Recv_io_B.Fcn22;
  }

  // Clock: '<Root>/Clock'
  System_Recv_io_B.Clock = System_Recv_io_M->Timing.t[0];

  // Switch: '<Root>/Switch' incorporates:
  //   Constant: '<Root>/Constant1'

  if (System_Recv_io_B.Clock >= 0.5) {
    // Saturate: '<Root>/Saturation4' incorporates:
    //   Inport: '<Root>/yr_in'

    tmp = System_Recv_io_U.yr_in;
    u1 = (-800.0);
    u2 = 80.0;
    if (tmp > u2) {
      System_Recv_io_B.Saturation4 = u2;
    } else if (tmp < u1) {
      System_Recv_io_B.Saturation4 = u1;
    } else {
      System_Recv_io_B.Saturation4 = tmp;
    }

    // End of Saturate: '<Root>/Saturation4'
    System_Recv_io_B.Switch = System_Recv_io_B.Saturation4;
  } else {
    System_Recv_io_B.Switch = 1.0;
  }

  // End of Switch: '<Root>/Switch'

  // Sum: '<Root>/Sum3'
  System_Recv_io_B.Sum3 = System_Recv_io_B.Switch -
    System_Recv_io_B.Integrator14;

  // Fcn: '<Root>/Fcn10'
  System_Recv_io_B.Fcn10 = std::abs(System_Recv_io_B.Sum3);

  // Integrator: '<Root>/Integrator9'
  System_Recv_io_B.Integrator9 = System_Recv_io_X.Integrator9_CSTATE;

  // Sum: '<Root>/Sum2' incorporates:
  //   Inport: '<Root>/zc_in'

  System_Recv_io_B.Sum2 = System_Recv_io_U.zc_in - System_Recv_io_B.Integrator9;

  // Fcn: '<Root>/Fcn13'
  System_Recv_io_B.Fcn13 = std::abs(System_Recv_io_B.Sum2);

  // Integrator: '<Root>/Integrator10'
  System_Recv_io_B.Integrator10 = System_Recv_io_X.Integrator10_CSTATE;

  // Integrator: '<Root>/Integrator11'
  System_Recv_io_B.Integrator11 = System_Recv_io_X.Integrator11_CSTATE;

  // Gain: '<Root>/Gain1'
  System_Recv_io_B.Gain1 = 1.0E+12 * System_Recv_io_B.Sum2;

  // Saturate: '<Root>/Saturation1'
  tmp = System_Recv_io_B.Gain1;
  u1 = (-1.0);
  u2 = 1.0;
  if (tmp > u2) {
    System_Recv_io_B.Saturation1 = u2;
  } else if (tmp < u1) {
    System_Recv_io_B.Saturation1 = u1;
  } else {
    System_Recv_io_B.Saturation1 = tmp;
  }

  // End of Saturate: '<Root>/Saturation1'

  // Fcn: '<Root>/Fcn14'
  tmp = System_Recv_io_B.Fcn13;
  if (tmp < 0.0) {
    tmp = -pow(-tmp, 0.66666666666666663);
  } else {
    tmp = pow(tmp, 0.66666666666666663);
  }

  System_Recv_io_B.Fcn14 = 41.7859226170808 * tmp * System_Recv_io_B.Saturation1
    + System_Recv_io_B.Integrator10;

  // End of Fcn: '<Root>/Fcn14'

  // Fcn: '<Root>/Fcn15'
  tmp = System_Recv_io_B.Fcn13;
  if (tmp < 0.0) {
    tmp = -pow(-tmp, 0.33333333333333326);
  } else {
    tmp = pow(tmp, 0.33333333333333326);
  }

  System_Recv_io_B.Fcn15 = 925.41356434915224 * tmp *
    System_Recv_io_B.Saturation1 + System_Recv_io_B.Integrator11;

  // End of Fcn: '<Root>/Fcn15'

  // Fcn: '<Root>/Fcn16'
  tmp = System_Recv_io_B.Fcn13;
  tmp = pow(tmp, 0.0);
  System_Recv_io_B.Fcn16 = 11000.0 * tmp * System_Recv_io_B.Saturation1;

  // TransferFcn: '<Root>/Transfer Fcn5'
  System_Recv_io_B.TransferFcn5 = 0.0;
  System_Recv_io_B.TransferFcn5 += 0.0 * System_Recv_io_X.TransferFcn5_CSTATE[0];
  System_Recv_io_B.TransferFcn5 += 1.577536E+8 *
    System_Recv_io_X.TransferFcn5_CSTATE[1];

  // TransferFcn: '<Root>/Transfer Fcn7'
  System_Recv_io_B.TransferFcn7 = 0.0;
  System_Recv_io_B.TransferFcn7 += 0.0 * System_Recv_io_X.TransferFcn7_CSTATE[0];
  System_Recv_io_B.TransferFcn7 += 1.577536E+8 *
    System_Recv_io_X.TransferFcn7_CSTATE[1];

  // TransferFcn: '<Root>/Transfer Fcn3'
  System_Recv_io_B.TransferFcn3 = 0.0;
  System_Recv_io_B.TransferFcn3 += 0.0 * System_Recv_io_X.TransferFcn3_CSTATE[0];
  System_Recv_io_B.TransferFcn3 += 1.577536E+8 *
    System_Recv_io_X.TransferFcn3_CSTATE[1];

  // TransferFcn: '<Root>/Transfer Fcn9'
  System_Recv_io_B.TransferFcn9 = 0.0;
  System_Recv_io_B.TransferFcn9 += 0.0 * System_Recv_io_X.TransferFcn9_CSTATE[0];
  System_Recv_io_B.TransferFcn9 += 1.577536E+8 *
    System_Recv_io_X.TransferFcn9_CSTATE[1];

  // Gain: '<Root>/Gain2'
  System_Recv_io_B.Gain2 = 1.0E+12 * System_Recv_io_B.Sum3;

  // Saturate: '<Root>/Saturation2'
  tmp = System_Recv_io_B.Gain2;
  u1 = (-1.0);
  u2 = 1.0;
  if (tmp > u2) {
    System_Recv_io_B.Saturation2 = u2;
  } else if (tmp < u1) {
    System_Recv_io_B.Saturation2 = u1;
  } else {
    System_Recv_io_B.Saturation2 = tmp;
  }

  // End of Saturate: '<Root>/Saturation2'

  // Fcn: '<Root>/Fcn18'
  tmp = System_Recv_io_B.Fcn10;
  if (tmp < 0.0) {
    tmp = -pow(-tmp, 0.75);
  } else {
    tmp = pow(tmp, 0.75);
  }

  System_Recv_io_B.Fcn18 = 11000.0 * tmp * System_Recv_io_B.Saturation2 +
    System_Recv_io_B.Integrator12;

  // End of Fcn: '<Root>/Fcn18'

  // Fcn: '<Root>/Fcn19'
  tmp = System_Recv_io_B.Fcn10;
  if (tmp < 0.0) {
    tmp = -pow(-tmp, 0.5);
  } else {
    tmp = pow(tmp, 0.5);
  }

  System_Recv_io_B.Fcn19 = 3060.0 * tmp * System_Recv_io_B.Saturation2 +
    System_Recv_io_B.Integrator13;

  // End of Fcn: '<Root>/Fcn19'

  // Fcn: '<Root>/Fcn20'
  tmp = System_Recv_io_B.Fcn10;
  if (tmp < 0.0) {
    tmp = -pow(-tmp, 0.25);
  } else {
    tmp = pow(tmp, 0.25);
  }

  System_Recv_io_B.Fcn20 = 416.0 * tmp * System_Recv_io_B.Saturation2 +
    System_Recv_io_B.Integrator15;

  // End of Fcn: '<Root>/Fcn20'

  // Fcn: '<Root>/Fcn21'
  System_Recv_io_B.Fcn21 = 30.0 * System_Recv_io_B.Saturation2;

  // Integrator: '<Root>/Integrator6'
  System_Recv_io_B.Integrator6 = System_Recv_io_X.Integrator6_CSTATE;

  // Sum: '<Root>/Sum1' incorporates:
  //   Inport: '<Root>/xc_in'

  System_Recv_io_B.Sum1 = System_Recv_io_U.xc_in - System_Recv_io_B.Integrator6;

  // Fcn: '<Root>/Fcn6'
  System_Recv_io_B.Fcn6 = std::abs(System_Recv_io_B.Sum1);

  // Gain: '<Root>/Gain'
  System_Recv_io_B.Gain = 1.0E+12 * System_Recv_io_B.Sum1;

  // Saturate: '<Root>/Saturation'
  tmp = System_Recv_io_B.Gain;
  u1 = (-1.0);
  u2 = 1.0;
  if (tmp > u2) {
    System_Recv_io_B.Saturation = u2;
  } else if (tmp < u1) {
    System_Recv_io_B.Saturation = u1;
  } else {
    System_Recv_io_B.Saturation = tmp;
  }

  // End of Saturate: '<Root>/Saturation'

  // Fcn: '<Root>/Fcn7'
  tmp = System_Recv_io_B.Fcn6;
  if (tmp < 0.0) {
    tmp = -pow(-tmp, 0.66666666666666663);
  } else {
    tmp = pow(tmp, 0.66666666666666663);
  }

  System_Recv_io_B.Fcn7 = 41.7859226170808 * tmp * System_Recv_io_B.Saturation +
    System_Recv_io_B.Integrator7;

  // End of Fcn: '<Root>/Fcn7'

  // Fcn: '<Root>/Fcn8'
  tmp = System_Recv_io_B.Fcn6;
  if (tmp < 0.0) {
    tmp = -pow(-tmp, 0.33333333333333326);
  } else {
    tmp = pow(tmp, 0.33333333333333326);
  }

  System_Recv_io_B.Fcn8 = 925.41356434915224 * tmp * System_Recv_io_B.Saturation
    + System_Recv_io_B.Integrator8;

  // End of Fcn: '<Root>/Fcn8'

  // Fcn: '<Root>/Fcn9'
  tmp = System_Recv_io_B.Fcn6;
  tmp = pow(tmp, 0.0);
  System_Recv_io_B.Fcn9 = 11000.0 * tmp * System_Recv_io_B.Saturation;

  // Switch: '<Root>/Switch1' incorporates:
  //   Constant: '<Root>/Constant2'

  if (System_Recv_io_B.Clock >= 0.5) {
    // Fcn: '<Root>/Fcn17'
    System_Recv_io_B.Fcn17 = ((System_Recv_io_B.TransferFcn3 -
      (System_Recv_io_B.TransferFcn7 / 10.0 + System_Recv_io_B.TransferFcn5) *
      (10.0 * System_Recv_io_B.TransferFcn5)) + 2.6666666666666665 *
      System_Recv_io_B.TransferFcn9) / System_Recv_io_B.TransferFcn1;

    // Saturate: '<Root>/Saturation3'
    tmp = System_Recv_io_B.Fcn17;
    u1 = (-800.0);
    u2 = 800.0;
    if (tmp > u2) {
      System_Recv_io_B.Saturation3 = u2;
    } else if (tmp < u1) {
      System_Recv_io_B.Saturation3 = u1;
    } else {
      System_Recv_io_B.Saturation3 = tmp;
    }

    // End of Saturate: '<Root>/Saturation3'
    System_Recv_io_B.Switch1 = System_Recv_io_B.Saturation3;
  } else {
    System_Recv_io_B.Switch1 = 0.0;
  }

  // End of Switch: '<Root>/Switch1'

  // TransferFcn: '<Root>/Transfer Fcn'
  System_Recv_io_B.TransferFcn = 0.0;
  System_Recv_io_B.TransferFcn += 0.0 * System_Recv_io_X.TransferFcn_CSTATE[0];
  System_Recv_io_B.TransferFcn += 1.577536E+8 *
    System_Recv_io_X.TransferFcn_CSTATE[1];

  // TransferFcn: '<Root>/Transfer Fcn10'
  System_Recv_io_B.TransferFcn10 = 0.0;
  System_Recv_io_B.TransferFcn10 += 0.0 * System_Recv_io_X.TransferFcn10_CSTATE
    [0];
  System_Recv_io_B.TransferFcn10 += 1.577536E+8 *
    System_Recv_io_X.TransferFcn10_CSTATE[1];

  // TransferFcn: '<Root>/Transfer Fcn11'
  System_Recv_io_B.TransferFcn11 = 0.0;
  System_Recv_io_B.TransferFcn11 += 0.0 * System_Recv_io_X.TransferFcn11_CSTATE
    [0];
  System_Recv_io_B.TransferFcn11 += 1.577536E+8 *
    System_Recv_io_X.TransferFcn11_CSTATE[1];

  // TransferFcn: '<Root>/Transfer Fcn12'
  System_Recv_io_B.TransferFcn12 = 0.0;
  System_Recv_io_B.TransferFcn12 += 0.0 * System_Recv_io_X.TransferFcn12_CSTATE
    [0];
  System_Recv_io_B.TransferFcn12 += 1.577536E+8 *
    System_Recv_io_X.TransferFcn12_CSTATE[1];

  // TransferFcn: '<Root>/Transfer Fcn2'
  System_Recv_io_B.TransferFcn2 = 0.0;
  System_Recv_io_B.TransferFcn2 += 0.0 * System_Recv_io_X.TransferFcn2_CSTATE[0];
  System_Recv_io_B.TransferFcn2 += 1.577536E+8 *
    System_Recv_io_X.TransferFcn2_CSTATE[1];

  // TransferFcn: '<Root>/Transfer Fcn4'
  System_Recv_io_B.TransferFcn4 = 0.0;
  System_Recv_io_B.TransferFcn4 += 0.0 * System_Recv_io_X.TransferFcn4_CSTATE[0];
  System_Recv_io_B.TransferFcn4 += 1.577536E+8 *
    System_Recv_io_X.TransferFcn4_CSTATE[1];

  // TransferFcn: '<Root>/Transfer Fcn6'
  System_Recv_io_B.TransferFcn6 = 0.0;
  System_Recv_io_B.TransferFcn6 += 0.0 * System_Recv_io_X.TransferFcn6_CSTATE[0];
  System_Recv_io_B.TransferFcn6 += 1.577536E+8 *
    System_Recv_io_X.TransferFcn6_CSTATE[1];

  // TransferFcn: '<Root>/Transfer Fcn8'
  System_Recv_io_B.TransferFcn8 = 0.0;
  System_Recv_io_B.TransferFcn8 += 0.0 * System_Recv_io_X.TransferFcn8_CSTATE[0];
  System_Recv_io_B.TransferFcn8 += 1.577536E+8 *
    System_Recv_io_X.TransferFcn8_CSTATE[1];
  if (rtmIsMajorTimeStep(System_Recv_io_M)) {
    rt_ertODEUpdateContinuousStates(&System_Recv_io_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.
    //  Timer of this task consists of two 32 bit unsigned integers.
    //  The two integers represent the low bits Timing.clockTick0 and the high bits
    //  Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.

    if (!(++System_Recv_io_M->Timing.clockTick0)) {
      ++System_Recv_io_M->Timing.clockTickH0;
    }

    System_Recv_io_M->Timing.t[0] = rtsiGetSolverStopTime
      (&System_Recv_io_M->solverInfo);

    {
      // Update absolute timer for sample time: [1.0E-6s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 1.0E-6, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.
      //  Timer of this task consists of two 32 bit unsigned integers.
      //  The two integers represent the low bits Timing.clockTick1 and the high bits
      //  Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.

      System_Recv_io_M->Timing.clockTick1++;
      if (!System_Recv_io_M->Timing.clockTick1) {
        System_Recv_io_M->Timing.clockTickH1++;
      }
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void System_Recv_io_derivatives(void)
{
  boolean_T lsat;
  boolean_T usat;
  XDot_System_Recv_io_T *_rtXdot;
  _rtXdot = ((XDot_System_Recv_io_T *) System_Recv_io_M->derivs);

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn1'
  _rtXdot->TransferFcn1_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += (-20322.08) *
    System_Recv_io_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += (-1.577536E+8) *
    System_Recv_io_X.TransferFcn1_CSTATE[1];
  _rtXdot->TransferFcn1_CSTATE[1] += System_Recv_io_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[0] += System_Recv_io_B.TransferFcn;

  // Derivatives for Integrator: '<Root>/Integrator7'
  _rtXdot->Integrator7_CSTATE = System_Recv_io_B.Fcn8;

  // Derivatives for Integrator: '<Root>/Integrator8'
  _rtXdot->Integrator8_CSTATE = System_Recv_io_B.Fcn9;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn13'
  _rtXdot->TransferFcn13_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn13_CSTATE[0] += (-20322.08) *
    System_Recv_io_X.TransferFcn13_CSTATE[0];
  _rtXdot->TransferFcn13_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn13_CSTATE[0] += (-1.577536E+8) *
    System_Recv_io_X.TransferFcn13_CSTATE[1];
  _rtXdot->TransferFcn13_CSTATE[1] += System_Recv_io_X.TransferFcn13_CSTATE[0];
  _rtXdot->TransferFcn13_CSTATE[0] += System_Recv_io_B.TransferFcn12;

  // Derivatives for Integrator: '<Root>/Integrator14'
  lsat = (System_Recv_io_X.Integrator14_CSTATE <= (-800.0));
  usat = (System_Recv_io_X.Integrator14_CSTATE >= 800.0);
  if (((!lsat) && (!usat)) || (lsat && (System_Recv_io_B.Fcn18 > 0.0)) || (usat &&
       (System_Recv_io_B.Fcn18 < 0.0))) {
    _rtXdot->Integrator14_CSTATE = System_Recv_io_B.Fcn18;
  } else {
    // in saturation
    _rtXdot->Integrator14_CSTATE = 0.0;
  }

  // End of Derivatives for Integrator: '<Root>/Integrator14'

  // Derivatives for Integrator: '<Root>/Integrator12'
  lsat = (System_Recv_io_X.Integrator12_CSTATE <= (-800.0));
  usat = (System_Recv_io_X.Integrator12_CSTATE >= 800.0);
  if (((!lsat) && (!usat)) || (lsat && (System_Recv_io_B.Fcn19 > 0.0)) || (usat &&
       (System_Recv_io_B.Fcn19 < 0.0))) {
    _rtXdot->Integrator12_CSTATE = System_Recv_io_B.Fcn19;
  } else {
    // in saturation
    _rtXdot->Integrator12_CSTATE = 0.0;
  }

  // End of Derivatives for Integrator: '<Root>/Integrator12'

  // Derivatives for Integrator: '<Root>/Integrator13'
  lsat = (System_Recv_io_X.Integrator13_CSTATE <= (-800.0));
  usat = (System_Recv_io_X.Integrator13_CSTATE >= 800.0);
  if (((!lsat) && (!usat)) || (lsat && (System_Recv_io_B.Fcn20 > 0.0)) || (usat &&
       (System_Recv_io_B.Fcn20 < 0.0))) {
    _rtXdot->Integrator13_CSTATE = System_Recv_io_B.Fcn20;
  } else {
    // in saturation
    _rtXdot->Integrator13_CSTATE = 0.0;
  }

  // End of Derivatives for Integrator: '<Root>/Integrator13'

  // Derivatives for Integrator: '<Root>/Integrator15'
  lsat = (System_Recv_io_X.Integrator15_CSTATE <= (-800.0));
  usat = (System_Recv_io_X.Integrator15_CSTATE >= 800.0);
  if (((!lsat) && (!usat)) || (lsat && (System_Recv_io_B.Fcn21 > 0.0)) || (usat &&
       (System_Recv_io_B.Fcn21 < 0.0))) {
    _rtXdot->Integrator15_CSTATE = System_Recv_io_B.Fcn21;
  } else {
    // in saturation
    _rtXdot->Integrator15_CSTATE = 0.0;
  }

  // End of Derivatives for Integrator: '<Root>/Integrator15'

  // Derivatives for Integrator: '<Root>/Integrator9'
  _rtXdot->Integrator9_CSTATE = System_Recv_io_B.Fcn14;

  // Derivatives for Integrator: '<Root>/Integrator10'
  _rtXdot->Integrator10_CSTATE = System_Recv_io_B.Fcn15;

  // Derivatives for Integrator: '<Root>/Integrator11'
  _rtXdot->Integrator11_CSTATE = System_Recv_io_B.Fcn16;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn5'
  _rtXdot->TransferFcn5_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn5_CSTATE[0] += (-20322.08) *
    System_Recv_io_X.TransferFcn5_CSTATE[0];
  _rtXdot->TransferFcn5_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn5_CSTATE[0] += (-1.577536E+8) *
    System_Recv_io_X.TransferFcn5_CSTATE[1];
  _rtXdot->TransferFcn5_CSTATE[1] += System_Recv_io_X.TransferFcn5_CSTATE[0];
  _rtXdot->TransferFcn5_CSTATE[0] += System_Recv_io_B.TransferFcn4;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn7'
  _rtXdot->TransferFcn7_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn7_CSTATE[0] += (-20322.08) *
    System_Recv_io_X.TransferFcn7_CSTATE[0];
  _rtXdot->TransferFcn7_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn7_CSTATE[0] += (-1.577536E+8) *
    System_Recv_io_X.TransferFcn7_CSTATE[1];
  _rtXdot->TransferFcn7_CSTATE[1] += System_Recv_io_X.TransferFcn7_CSTATE[0];
  _rtXdot->TransferFcn7_CSTATE[0] += System_Recv_io_B.TransferFcn6;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn3'
  _rtXdot->TransferFcn3_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += (-20322.08) *
    System_Recv_io_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += (-1.577536E+8) *
    System_Recv_io_X.TransferFcn3_CSTATE[1];
  _rtXdot->TransferFcn3_CSTATE[1] += System_Recv_io_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[0] += System_Recv_io_B.TransferFcn2;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn9'
  _rtXdot->TransferFcn9_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn9_CSTATE[0] += (-20322.08) *
    System_Recv_io_X.TransferFcn9_CSTATE[0];
  _rtXdot->TransferFcn9_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn9_CSTATE[0] += (-1.577536E+8) *
    System_Recv_io_X.TransferFcn9_CSTATE[1];
  _rtXdot->TransferFcn9_CSTATE[1] += System_Recv_io_X.TransferFcn9_CSTATE[0];
  _rtXdot->TransferFcn9_CSTATE[0] += System_Recv_io_B.TransferFcn8;

  // Derivatives for Integrator: '<Root>/Integrator6'
  _rtXdot->Integrator6_CSTATE = System_Recv_io_B.Fcn7;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn'
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += (-9608.4) *
    System_Recv_io_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += (-1.577536E+8) *
    System_Recv_io_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] += System_Recv_io_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += System_Recv_io_B.Fcn11;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn10'
  _rtXdot->TransferFcn10_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn10_CSTATE[0] += (-9608.4) *
    System_Recv_io_X.TransferFcn10_CSTATE[0];
  _rtXdot->TransferFcn10_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn10_CSTATE[0] += (-1.577536E+8) *
    System_Recv_io_X.TransferFcn10_CSTATE[1];
  _rtXdot->TransferFcn10_CSTATE[1] += System_Recv_io_X.TransferFcn10_CSTATE[0];
  _rtXdot->TransferFcn10_CSTATE[0] += System_Recv_io_B.Switch1;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn11'
  _rtXdot->TransferFcn11_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn11_CSTATE[0] += (-20322.08) *
    System_Recv_io_X.TransferFcn11_CSTATE[0];
  _rtXdot->TransferFcn11_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn11_CSTATE[0] += (-1.577536E+8) *
    System_Recv_io_X.TransferFcn11_CSTATE[1];
  _rtXdot->TransferFcn11_CSTATE[1] += System_Recv_io_X.TransferFcn11_CSTATE[0];
  _rtXdot->TransferFcn11_CSTATE[0] += System_Recv_io_B.TransferFcn10;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn12'
  _rtXdot->TransferFcn12_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn12_CSTATE[0] += (-9608.4) *
    System_Recv_io_X.TransferFcn12_CSTATE[0];
  _rtXdot->TransferFcn12_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn12_CSTATE[0] += (-1.577536E+8) *
    System_Recv_io_X.TransferFcn12_CSTATE[1];
  _rtXdot->TransferFcn12_CSTATE[1] += System_Recv_io_X.TransferFcn12_CSTATE[0];
  _rtXdot->TransferFcn12_CSTATE[0] += System_Recv_io_B.TransferFcn11;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn2'
  _rtXdot->TransferFcn2_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn2_CSTATE[0] += (-9608.4) *
    System_Recv_io_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn2_CSTATE[0] += (-1.577536E+8) *
    System_Recv_io_X.TransferFcn2_CSTATE[1];
  _rtXdot->TransferFcn2_CSTATE[1] += System_Recv_io_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[0] += System_Recv_io_B.Integrator10;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn4' incorporates:
  //   Inport: '<Root>/xc_in'

  _rtXdot->TransferFcn4_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn4_CSTATE[0] += (-9608.4) *
    System_Recv_io_X.TransferFcn4_CSTATE[0];
  _rtXdot->TransferFcn4_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn4_CSTATE[0] += (-1.577536E+8) *
    System_Recv_io_X.TransferFcn4_CSTATE[1];
  _rtXdot->TransferFcn4_CSTATE[1] += System_Recv_io_X.TransferFcn4_CSTATE[0];
  _rtXdot->TransferFcn4_CSTATE[0] += System_Recv_io_U.xc_in;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn6'
  _rtXdot->TransferFcn6_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn6_CSTATE[0] += (-9608.4) *
    System_Recv_io_X.TransferFcn6_CSTATE[0];
  _rtXdot->TransferFcn6_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn6_CSTATE[0] += (-1.577536E+8) *
    System_Recv_io_X.TransferFcn6_CSTATE[1];
  _rtXdot->TransferFcn6_CSTATE[1] += System_Recv_io_X.TransferFcn6_CSTATE[0];
  _rtXdot->TransferFcn6_CSTATE[0] += System_Recv_io_B.Integrator7;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn8'
  _rtXdot->TransferFcn8_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn8_CSTATE[0] += (-9608.4) *
    System_Recv_io_X.TransferFcn8_CSTATE[0];
  _rtXdot->TransferFcn8_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn8_CSTATE[0] += (-1.577536E+8) *
    System_Recv_io_X.TransferFcn8_CSTATE[1];
  _rtXdot->TransferFcn8_CSTATE[1] += System_Recv_io_X.TransferFcn8_CSTATE[0];
  _rtXdot->TransferFcn8_CSTATE[0] += System_Recv_io_B.Integrator9;
}

// Model initialize function
void System_Recv_io_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&System_Recv_io_M->solverInfo,
                          &System_Recv_io_M->Timing.simTimeStep);
    rtsiSetTPtr(&System_Recv_io_M->solverInfo, &rtmGetTPtr(System_Recv_io_M));
    rtsiSetStepSizePtr(&System_Recv_io_M->solverInfo,
                       &System_Recv_io_M->Timing.stepSize0);
    rtsiSetdXPtr(&System_Recv_io_M->solverInfo, &System_Recv_io_M->derivs);
    rtsiSetContStatesPtr(&System_Recv_io_M->solverInfo, (real_T **)
                         &System_Recv_io_M->contStates);
    rtsiSetNumContStatesPtr(&System_Recv_io_M->solverInfo,
      &System_Recv_io_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&System_Recv_io_M->solverInfo,
      &System_Recv_io_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&System_Recv_io_M->solverInfo,
      &System_Recv_io_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&System_Recv_io_M->solverInfo,
      &System_Recv_io_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&System_Recv_io_M->solverInfo, (&rtmGetErrorStatus
      (System_Recv_io_M)));
    rtsiSetRTModelPtr(&System_Recv_io_M->solverInfo, System_Recv_io_M);
  }

  rtsiSetSimTimeStep(&System_Recv_io_M->solverInfo, MAJOR_TIME_STEP);
  System_Recv_io_M->intgData.f[0] = System_Recv_io_M->odeF[0];
  System_Recv_io_M->contStates = ((X_System_Recv_io_T *) &System_Recv_io_X);
  rtsiSetSolverData(&System_Recv_io_M->solverInfo, static_cast<void *>
                    (&System_Recv_io_M->intgData));
  rtsiSetSolverName(&System_Recv_io_M->solverInfo,"ode1");
  rtmSetTPtr(System_Recv_io_M, &System_Recv_io_M->Timing.tArray[0]);
  System_Recv_io_M->Timing.stepSize0 = 1.0E-6;

  // Initialize DataMapInfo substructure containing ModelMap for C API
  System_Recv_io_InitializeDataMapInfo();

  // InitializeConditions for Integrator: '<Root>/Integrator7'
  System_Recv_io_X.Integrator7_CSTATE = 1.0;

  // InitializeConditions for Integrator: '<Root>/Integrator8'
  System_Recv_io_X.Integrator8_CSTATE = 1.0;

  // InitializeConditions for Integrator: '<Root>/Integrator14'
  System_Recv_io_X.Integrator14_CSTATE = 0.0;

  // InitializeConditions for Integrator: '<Root>/Integrator12'
  System_Recv_io_X.Integrator12_CSTATE = 0.0;

  // InitializeConditions for Integrator: '<Root>/Integrator13'
  System_Recv_io_X.Integrator13_CSTATE = 0.0;

  // InitializeConditions for Integrator: '<Root>/Integrator15'
  System_Recv_io_X.Integrator15_CSTATE = 0.0;

  // InitializeConditions for Integrator: '<Root>/Integrator9'
  System_Recv_io_X.Integrator9_CSTATE = 1.0;

  // InitializeConditions for Integrator: '<Root>/Integrator10'
  System_Recv_io_X.Integrator10_CSTATE = 1.0;

  // InitializeConditions for Integrator: '<Root>/Integrator11'
  System_Recv_io_X.Integrator11_CSTATE = 1.0;

  // InitializeConditions for Integrator: '<Root>/Integrator6'
  System_Recv_io_X.Integrator6_CSTATE = 1.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1'
  System_Recv_io_X.TransferFcn1_CSTATE[0] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn13'
  System_Recv_io_X.TransferFcn13_CSTATE[0] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn5'
  System_Recv_io_X.TransferFcn5_CSTATE[0] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn7'
  System_Recv_io_X.TransferFcn7_CSTATE[0] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn3'
  System_Recv_io_X.TransferFcn3_CSTATE[0] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn9'
  System_Recv_io_X.TransferFcn9_CSTATE[0] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn'
  System_Recv_io_X.TransferFcn_CSTATE[0] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn10'
  System_Recv_io_X.TransferFcn10_CSTATE[0] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn11'
  System_Recv_io_X.TransferFcn11_CSTATE[0] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn12'
  System_Recv_io_X.TransferFcn12_CSTATE[0] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2'
  System_Recv_io_X.TransferFcn2_CSTATE[0] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn4'
  System_Recv_io_X.TransferFcn4_CSTATE[0] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn6'
  System_Recv_io_X.TransferFcn6_CSTATE[0] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn8'
  System_Recv_io_X.TransferFcn8_CSTATE[0] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1'
  System_Recv_io_X.TransferFcn1_CSTATE[1] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn13'
  System_Recv_io_X.TransferFcn13_CSTATE[1] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn5'
  System_Recv_io_X.TransferFcn5_CSTATE[1] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn7'
  System_Recv_io_X.TransferFcn7_CSTATE[1] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn3'
  System_Recv_io_X.TransferFcn3_CSTATE[1] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn9'
  System_Recv_io_X.TransferFcn9_CSTATE[1] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn'
  System_Recv_io_X.TransferFcn_CSTATE[1] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn10'
  System_Recv_io_X.TransferFcn10_CSTATE[1] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn11'
  System_Recv_io_X.TransferFcn11_CSTATE[1] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn12'
  System_Recv_io_X.TransferFcn12_CSTATE[1] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2'
  System_Recv_io_X.TransferFcn2_CSTATE[1] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn4'
  System_Recv_io_X.TransferFcn4_CSTATE[1] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn6'
  System_Recv_io_X.TransferFcn6_CSTATE[1] = 0.0;

  // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn8'
  System_Recv_io_X.TransferFcn8_CSTATE[1] = 0.0;
}

// Model terminate function
void System_Recv_io_terminate(void)
{
  // (no terminate code required)
}

//
// File trailer for generated code.
//
// [EOF]
//
