/*
 * Copyright 2011 Alan Burlison, alan@bleaklow.com.  All rights reserved.
 * Use is subject to license terms.
 */

#include "Arduino.h"
#include "Task.h"

// Virtual.
bool TriggeredTask::canRun(uint32_t now) {
    return runFlag;
}

// Virtual.
bool TimedTask::canRun(uint32_t now) {
    return (int32_t)(now - runTime) > 0;
}

bool SingleShotTimedTask::canRun(uint32_t now) {
    if(runFlag && (int32_t)(now - runTime) > 0)
    {
        runFlag = false;
        return true;
    }
    return false;
}
