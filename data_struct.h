#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include "rtwtypes.h"

struct TransmOut
{
    TransmOut() {}
    TransmOut(real_T xcp, real_T zcp, real_T yrp)
        : xc{xcp}, zc{zcp}, yr{yrp} {}

    real_T xc;
    real_T zc;
    real_T yr;
};

#endif