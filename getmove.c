#include <stdio.h>
#include "common.h"
#include "getmove.h"


int getMove( int algorithmIndex, char* copyboard, char marker ){
    switch ( algorithmIndex ){
        case 0: return algorithm0(marker, copyboard);
        case 1: return algorithm1(marker, copyboard);
        case 2: return algorithm2(marker, copyboard);
        default: return algorithm0(marker, copyboard);
    }
}

