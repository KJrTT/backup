#pragma once
#include <iostream>
#include "Algorithm.h"
#include "File_handler.h"
#include <vector>
#include "BackObject.h"
#include "Restore_point.h"
using namespace std;

class SplitStorage : public Storage {
    BackupObject objects;
    Restore_point point;
public:
    SplitStorage(BackupObject objects, Restore_point point);
    void store(BackupObject object, Restore_point point) override; 
};