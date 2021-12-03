//
// File: ert_main.cpp
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
#include <stddef.h>
#include <stdio.h>                // This ert_main.c example uses printf/fflush
#include "System_Recv_io.h"            // Model's header file
#include "rtwtypes.h"
#include "builtin_typeid_types.h"

#include "processing.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <mutex>
#include <queue>
#include <thread>
#include <condition_variable>

using namespace std;

extern mutex queueMutex;
extern condition_variable queueCV;
extern bool recvDone;

ofstream csvout("out.csv");

real_T xc_temp;
real_T zc_temp;
real_T yr_temp;

//
// Associating rt_OneStep with a real-time clock or interrupt service routine
// is what makes the generated code "real-time".  The function rt_OneStep is
// always associated with the base rate of the model.  Subrates are managed
// by the base rate from inside the generated code.  Enabling/disabling
// interrupts and floating point context switches are target specific.  This
// example code indicates where these should take place relative to executing
// the generated code step function.  Overrun behavior should be tailored to
// your application needs.  This example simply sets an error status in the
// real-time model and returns from rt_OneStep.
//
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  // Disable interrupts here

  // Check for overrun
  if (OverrunFlag) {
    rtmSetErrorStatus(System_Recv_io_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  System_Recv_io_U.xc_in = xc_temp;
  System_Recv_io_U.zc_in = zc_temp;
  System_Recv_io_U.yr_in = yr_temp;

  // Step the model for base rate
  System_Recv_io_step();

  // Get model outputs here
  csvout << System_Recv_io_Y.u1h_out << "," << System_Recv_io_Y.u2h_out << "\n";

  // Indicate task complete
  OverrunFlag = false;

  // Disable interrupts here
  // Restore FPU context here (if necessary)
  // Enable interrupts here
}

//
// The example "main" function illustrates what is required by your
// application code to initialize, execute, and terminate the generated code.
// Attaching rt_OneStep to a real-time clock is target specific.  This example
// illustrates how you do this relative to initializing the model.
//
int_T main(int_T argc, const char *argv[])
{
  const string defIpAddr{ "127.0.0.1" };
  string ipAddr;

  if (argc == 1)
  {
    ipAddr = defIpAddr;
  }
  else
  {
    ipAddr = argv[1];
  }

  // queue<string>& entries = getEntriesQueue();
  queue<TransmOut>& entries = getEntriesQueue();

  csvout << setprecision(17);

  if (connectToServer(ipAddr) < 0)
  {
      cerr << "Could not connect to server\n";
      exit(EXIT_FAILURE);
  }

  // thread recvThread(receiveAndStore);
  receiveAndStore();

  // Initialize model
  System_Recv_io_initialize();

  // Simulating the model step behavior (in non real-time) to
  //   simulate model behavior at stop time.

  cout << "> Processing" << endl;

  while ((rtmGetErrorStatus(System_Recv_io_M) == (NULL)) && !rtmGetStopRequested
         (System_Recv_io_M))
  {
    // unique_lock<mutex> lck{queueMutex, defer_lock};
    // if (!recvDone)
    // {
    //   lck.lock();
    //   queueCV.wait(lck);
    // }
    // queueMutex.lock();
    if (entries.size() != 0)
    {
      //string temp = entries.front();
      TransmOut transmOut = entries.front();
      entries.pop();

      // TransmOut transmOut = parseEntry(temp);
      xc_temp = transmOut.xc;
      zc_temp = transmOut.zc;
      yr_temp = transmOut.yr;

      rt_OneStep();
    }
    else if (recvDone)
    {
      rtmSetStopRequested(System_Recv_io_M, true);
    }
    // queueMutex.unlock();
  }

  cout << "> Processing done, exiting" << endl;

  // recvThread.join();

  // Disable rt_OneStep() here

  // Terminate model
  System_Recv_io_terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
