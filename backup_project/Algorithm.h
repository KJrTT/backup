#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BackObject.h"
#include "Restore_point.h"

class Storage {
public:
    virtual void store(BackupObject object, Restore_point point) = 0;
    virtual ~Storage() {}
}; 