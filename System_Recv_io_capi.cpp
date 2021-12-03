//
// File: System_Recv_io_capi.cpp
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
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "System_Recv_io_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  // HOST_CAPI_BUILD
#include "builtin_typeid_types.h"
#include "System_Recv_io.h"
#include "System_Recv_io_capi.h"
#include "System_Recv_io_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 // HOST_CAPI_BUILD

// Block output signal information
static const rtwCAPI_Signals rtBlockSignals[] = {
  // addrMapIndex, sysNum, blockPath,
  //  signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex

  { 0, 0, TARGET_STRING("System_Recv_io/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("System_Recv_io/Fcn10"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 2, 0, TARGET_STRING("System_Recv_io/Fcn11"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 3, 0, TARGET_STRING("System_Recv_io/Fcn13"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 4, 0, TARGET_STRING("System_Recv_io/Fcn14"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 5, 0, TARGET_STRING("System_Recv_io/Fcn15"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 6, 0, TARGET_STRING("System_Recv_io/Fcn16"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 7, 1, TARGET_STRING("System_Recv_io/Fcn17"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 8, 0, TARGET_STRING("System_Recv_io/Fcn18"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 9, 0, TARGET_STRING("System_Recv_io/Fcn19"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 10, 0, TARGET_STRING("System_Recv_io/Fcn20"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 11, 0, TARGET_STRING("System_Recv_io/Fcn21"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 12, 0, TARGET_STRING("System_Recv_io/Fcn22"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 13, 0, TARGET_STRING("System_Recv_io/Fcn6"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 14, 0, TARGET_STRING("System_Recv_io/Fcn7"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 15, 0, TARGET_STRING("System_Recv_io/Fcn8"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 16, 0, TARGET_STRING("System_Recv_io/Fcn9"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 17, 0, TARGET_STRING("System_Recv_io/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 18, 0, TARGET_STRING("System_Recv_io/Gain1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 19, 0, TARGET_STRING("System_Recv_io/Gain2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 20, 0, TARGET_STRING("System_Recv_io/Integrator10"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 21, 0, TARGET_STRING("System_Recv_io/Integrator11"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 22, 0, TARGET_STRING("System_Recv_io/Integrator12"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 23, 0, TARGET_STRING("System_Recv_io/Integrator13"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 24, 0, TARGET_STRING("System_Recv_io/Integrator14"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 25, 0, TARGET_STRING("System_Recv_io/Integrator15"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 26, 0, TARGET_STRING("System_Recv_io/Integrator6"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 27, 0, TARGET_STRING("System_Recv_io/Integrator7"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 28, 0, TARGET_STRING("System_Recv_io/Integrator8"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 29, 0, TARGET_STRING("System_Recv_io/Integrator9"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 30, 0, TARGET_STRING("System_Recv_io/Saturation"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 31, 0, TARGET_STRING("System_Recv_io/Saturation1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 32, 0, TARGET_STRING("System_Recv_io/Saturation2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 33, 1, TARGET_STRING("System_Recv_io/Saturation3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 34, 2, TARGET_STRING("System_Recv_io/Saturation4"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 35, 0, TARGET_STRING("System_Recv_io/Sum1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 36, 0, TARGET_STRING("System_Recv_io/Sum2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 37, 0, TARGET_STRING("System_Recv_io/Sum3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 38, 0, TARGET_STRING("System_Recv_io/Switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 39, 0, TARGET_STRING("System_Recv_io/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 40, 0, TARGET_STRING("System_Recv_io/Transfer Fcn"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 41, 0, TARGET_STRING("System_Recv_io/Transfer Fcn1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 42, 0, TARGET_STRING("System_Recv_io/Transfer Fcn10"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 43, 0, TARGET_STRING("System_Recv_io/Transfer Fcn11"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 44, 0, TARGET_STRING("System_Recv_io/Transfer Fcn12"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 45, 0, TARGET_STRING("System_Recv_io/Transfer Fcn13"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 46, 0, TARGET_STRING("System_Recv_io/Transfer Fcn2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 47, 0, TARGET_STRING("System_Recv_io/Transfer Fcn3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 48, 0, TARGET_STRING("System_Recv_io/Transfer Fcn4"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 49, 0, TARGET_STRING("System_Recv_io/Transfer Fcn5"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 50, 0, TARGET_STRING("System_Recv_io/Transfer Fcn6"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 51, 0, TARGET_STRING("System_Recv_io/Transfer Fcn7"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 52, 0, TARGET_STRING("System_Recv_io/Transfer Fcn8"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 53, 0, TARGET_STRING("System_Recv_io/Transfer Fcn9"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

#ifndef HOST_CAPI_BUILD

// Declare Data Addresses statically
static void* rtDataAddrMap[] = {
  &System_Recv_io_B.Clock,             // 0: Signal
  &System_Recv_io_B.Fcn10,             // 1: Signal
  &System_Recv_io_B.Fcn11,             // 2: Signal
  &System_Recv_io_B.Fcn13,             // 3: Signal
  &System_Recv_io_B.Fcn14,             // 4: Signal
  &System_Recv_io_B.Fcn15,             // 5: Signal
  &System_Recv_io_B.Fcn16,             // 6: Signal
  &System_Recv_io_B.Fcn17,             // 7: Signal
  &System_Recv_io_B.Fcn18,             // 8: Signal
  &System_Recv_io_B.Fcn19,             // 9: Signal
  &System_Recv_io_B.Fcn20,             // 10: Signal
  &System_Recv_io_B.Fcn21,             // 11: Signal
  &System_Recv_io_B.Fcn22,             // 12: Signal
  &System_Recv_io_B.Fcn6,              // 13: Signal
  &System_Recv_io_B.Fcn7,              // 14: Signal
  &System_Recv_io_B.Fcn8,              // 15: Signal
  &System_Recv_io_B.Fcn9,              // 16: Signal
  &System_Recv_io_B.Gain,              // 17: Signal
  &System_Recv_io_B.Gain1,             // 18: Signal
  &System_Recv_io_B.Gain2,             // 19: Signal
  &System_Recv_io_B.Integrator10,      // 20: Signal
  &System_Recv_io_B.Integrator11,      // 21: Signal
  &System_Recv_io_B.Integrator12,      // 22: Signal
  &System_Recv_io_B.Integrator13,      // 23: Signal
  &System_Recv_io_B.Integrator14,      // 24: Signal
  &System_Recv_io_B.Integrator15,      // 25: Signal
  &System_Recv_io_B.Integrator6,       // 26: Signal
  &System_Recv_io_B.Integrator7,       // 27: Signal
  &System_Recv_io_B.Integrator8,       // 28: Signal
  &System_Recv_io_B.Integrator9,       // 29: Signal
  &System_Recv_io_B.Saturation,        // 30: Signal
  &System_Recv_io_B.Saturation1,       // 31: Signal
  &System_Recv_io_B.Saturation2,       // 32: Signal
  &System_Recv_io_B.Saturation3,       // 33: Signal
  &System_Recv_io_B.Saturation4,       // 34: Signal
  &System_Recv_io_B.Sum1,              // 35: Signal
  &System_Recv_io_B.Sum2,              // 36: Signal
  &System_Recv_io_B.Sum3,              // 37: Signal
  &System_Recv_io_B.Switch,            // 38: Signal
  &System_Recv_io_B.Switch1,           // 39: Signal
  &System_Recv_io_B.TransferFcn,       // 40: Signal
  &System_Recv_io_B.TransferFcn1,      // 41: Signal
  &System_Recv_io_B.TransferFcn10,     // 42: Signal
  &System_Recv_io_B.TransferFcn11,     // 43: Signal
  &System_Recv_io_B.TransferFcn12,     // 44: Signal
  &System_Recv_io_B.TransferFcn13,     // 45: Signal
  &System_Recv_io_B.TransferFcn2,      // 46: Signal
  &System_Recv_io_B.TransferFcn3,      // 47: Signal
  &System_Recv_io_B.TransferFcn4,      // 48: Signal
  &System_Recv_io_B.TransferFcn5,      // 49: Signal
  &System_Recv_io_B.TransferFcn6,      // 50: Signal
  &System_Recv_io_B.TransferFcn7,      // 51: Signal
  &System_Recv_io_B.TransferFcn8,      // 52: Signal
  &System_Recv_io_B.TransferFcn9,      // 53: Signal
};

// Declare Data Run-Time Dimension Buffer Addresses statically
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

// Data Type Map - use dataTypeMapIndex to access this structure
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  // cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
  //  isComplex, isPointer, enumStorageType
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

// Structure Element Map - use elemMapIndex to access this structure
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  // elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex
  { (NULL), 0, 0, 0, 0 },
};

// Dimension Map - use dimensionMapIndex to access elements of ths structure
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  // dataOrientation, dimArrayIndex, numDims, vardimsIndex
  { rtwCAPI_SCALAR, 0, 2, 0 }
};

// Dimension Array- use dimArrayIndex to access elements of this array
static const uint_T rtDimensionArray[] = {
  1,                                   // 0
  1                                    // 1
};

// C-API stores floating point values in an array. The elements of this  *
//  are unique. This ensures that values which are shared across the model*
//  are stored in the most efficient way. These values are referenced by  *
//            - rtwCAPI_FixPtMap.fracSlopePtr,                            *
//            - rtwCAPI_FixPtMap.biasPtr,                                 *
//            - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
//            - rtwCAPI_SampleTimeMap.sampleOffsetPtr
static const real_T rtcapiStoredFloats[] = {
  0.0
};

// Fixed Point Map
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  // fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

// Sample Time Map - use sTimeIndex to access elements of ths structure
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  // samplePeriodPtr, sampleOffsetPtr, tid, samplingMode
  { static_cast<const void *>(&rtcapiStoredFloats[0]), static_cast<const void *>
    (&rtcapiStoredFloats[0]), 0, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  // Signals:{signals, numSignals,
  //            rootInputs, numRootInputs,
  //            rootOutputs, numRootOutputs},
  //  Params: {blockParameters, numBlockParameters,
  //           modelParameters, numModelParameters},
  //  States: {states, numStates},
  //  Maps:   {dataTypeMap, dimensionMap, fixPtMap,
  //           elementMap, sampleTimeMap, dimensionArray},
  //  TargetType: targetType

  { rtBlockSignals, 54,
    (NULL), 0,
    (NULL), 0 },

  { (NULL), 0,
    (NULL), 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3808048085U,
    438995589U,
    1639585037U,
    4026374148U },
  (NULL), 0,
  0
};

// Function to get C API Model Mapping Static Info
const rtwCAPI_ModelMappingStaticInfo*
  System_Recv_io_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

// Cache pointers into DataMapInfo substructure of RTModel
#ifndef HOST_CAPI_BUILD

void System_Recv_io_InitializeDataMapInfo(void)
{
  // Set C-API version
  rtwCAPI_SetVersion(System_Recv_io_M->DataMapInfo.mmi, 1);

  // Cache static C-API data into the Real-time Model Data structure
  rtwCAPI_SetStaticMap(System_Recv_io_M->DataMapInfo.mmi, &mmiStatic);

  // Cache static C-API logging data into the Real-time Model Data structure
  rtwCAPI_SetLoggingStaticMap(System_Recv_io_M->DataMapInfo.mmi, (NULL));

  // Cache C-API Data Addresses into the Real-Time Model Data structure
  rtwCAPI_SetDataAddressMap(System_Recv_io_M->DataMapInfo.mmi, rtDataAddrMap);

  // Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure 
  rtwCAPI_SetVarDimsAddressMap(System_Recv_io_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  // Cache the instance C-API logging pointer
  rtwCAPI_SetInstanceLoggingInfo(System_Recv_io_M->DataMapInfo.mmi, (NULL));

  // Set reference to submodels
  rtwCAPI_SetChildMMIArray(System_Recv_io_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(System_Recv_io_M->DataMapInfo.mmi, 0);
}

#else                                  // HOST_CAPI_BUILD
#ifdef __cplusplus

extern "C" {

#endif

  void System_Recv_io_host_InitializeDataMapInfo
    (System_Recv_io_host_DataMapInfo_T *dataMap, const char *path)
  {
    // Set C-API version
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    // Cache static C-API data into the Real-time Model Data structure
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    // host data address map is NULL
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    // host vardims address map is NULL
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    // Set Instance specific path
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    // Set reference to submodels
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 // HOST_CAPI_BUILD

//
// File trailer for generated code.
//
// [EOF]
//
